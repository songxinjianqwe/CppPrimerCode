/*
 * Sample.cpp
 *
 *  Created on: 2016年9月13日
 *      Author: songx
 */

#include <set>
#include <string>
#include <utility>

using namespace std;

//有两个类Message邮件和Folder消息目录 是多对多的关系
//一个message可以出现在多个folder中，一个folder、中也有多个message
//但是一个message是唯一的，如果修改，那么该message在所有folder的版本都要修改
//message有一个set，保存了所有有当前message的folder指针
//folder有一个set，保存了当前目录下的所有message的指针

//message有一个save方法，接受一个folder，将自己添加到这个folder中，并将folder加入到自己的set
//有一个remove方法，接受一个folder，将自己从这个folder中删除，并将folder从自己的set中删除

//folder有两个方法，addMsg()和removeMsg()

//Message拷贝控制：
//拷贝构造函数：将右侧运算对象的值拷贝到自己中，并将自己添加到所有右侧运算对象所在的folder中
//析构函数：将自己从所有所在的folder中删除

//析构函数和拷贝赋值运算符都需要从包含一条Message的所有folder中删除它
//拷贝构造函数和拷贝赋值都要讲这个Message添加到给定的一组folder中
//因此，我们定义两个private的工具函数来完成这些工作。
//addToFolder()  removeFromFolder()

//可以将Message中关于操作Folder的代码抽象为私有方法。为了方便访问set的方法，设置Folder为Message的友元类。
class Message;
class Folder {
public:
	Folder(const string & n = "") :
			name(n) {
	}
	void addMsg(Message * msg) {
		msgs.insert(msg);
	}
	void removeMsg(Message *msg) {
		msgs.erase(msg);
	}
private:
	string name;
	set<Message*> msgs;
};

class Message {
	friend void swap(Message&, Message&);
	friend class Folder;
public:
	Message(const string & s = "") :
			contents(s) {
	}
	void save(Folder & folder) {
		folder.addMsg(this);
		addFolder(&folder);
	}
	void remove(Folder & folder) {
		folder.removeMsg(this);
		removeFolder(&folder);
	}
	Message(const Message & msg) :
			contents(msg.contents), folders(msg.folders) {
		addToFolder(msg);
	}
	~Message() {
		removeFromFolder();
	}
	Message& operator=(const Message & msg);

	//移动构造函数
	Message(Message &&);
	//移动赋值运算符
	Message &operator=(Message &&);
private:
	string contents;
	set<Folder*> folders;
	//用于拷贝
	void addToFolder(const Message &msg) {
		for (auto folder : msg.folders) {
			folder->addMsg(this);
		}
	}
	//用于析构
	void removeFromFolder() {
		for (auto folder : folders) {
			folder->removeMsg(this);
		}
	}
	//操纵Folder的方法
	void addFolder(Folder *folder) {
		folders.insert(folder);
	}
	void removeFolder(Folder *folder) {
		folders.erase(folder);
	}
	void moveFolders(Message &);

};

Message& Message::operator=(const Message & msg) {
	removeFromFolder();
	contents = msg.contents;
	folders = msg.folders;
	addToFolder(msg);
	return *this;
}

void swap(Message& lhs, Message&rhs) {
	//需要先将各自从持有的Folders中删除，交换后，再重新加入到新的folders中
	for (auto folder : lhs.folders) {
		folder->removeMsg(&lhs);
	}
	for (auto folder : rhs.folders) {
		folder->removeMsg(&rhs);
	}
	swap(lhs.contents, rhs.contents);
	swap(lhs.folders, lhs.folders);
	for (auto folder : lhs.folders) {
		folder->addMsg(&lhs);
	}
	for (auto folder : rhs.folders) {
		folder->addMsg(&rhs);
	}
}

//总结移动构造函数和移动赋值运算符的写法：将拷贝操作改为移动操作，代码上就是右值为move函数的返回值；另外需要清理传入参数的资源
//当然，如果是指针的拷贝，那么没有必要移动；移动就是将拷贝元素转为拷贝指针，如果本身就是指针就不必拷贝了。
//因为在移动构造函数和移动赋值运算符都会用到移动set，因此将这段代码抽出来写成一个方法：

//set中插入操作可能会抛出内存分配异常，因此不设置为noexcept
void Message::moveFolders(Message & msg) {
	folders = move(folders);
	for (auto folder : folders) {
		folder->removeMsg(&msg);
		folder->addMsg(this);
	}
	msg.folders.clear();
}

Message::Message(Message && msg) :
		contents(move(msg.contents)) {
	moveFolders(msg);
}
Message & Message::operator =(Message && msg) {
	if (&msg != this) {
		removeFromFolder();
		contents = move(msg.contents);
		moveFolders(msg);
	}
	return *this;
}

