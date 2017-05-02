/*
 * Sample.cpp
 *
 *  Created on: 2016��9��13��
 *      Author: songx
 */

#include <set>
#include <string>
#include <utility>

using namespace std;

//��������Message�ʼ���Folder��ϢĿ¼ �Ƕ�Զ�Ĺ�ϵ
//һ��message���Գ����ڶ��folder�У�һ��folder����Ҳ�ж��message
//����һ��message��Ψһ�ģ�����޸ģ���ô��message������folder�İ汾��Ҫ�޸�
//message��һ��set�������������е�ǰmessage��folderָ��
//folder��һ��set�������˵�ǰĿ¼�µ�����message��ָ��

//message��һ��save����������һ��folder�����Լ���ӵ����folder�У�����folder���뵽�Լ���set
//��һ��remove����������һ��folder�����Լ������folder��ɾ��������folder���Լ���set��ɾ��

//folder������������addMsg()��removeMsg()

//Message�������ƣ�
//�������캯�������Ҳ���������ֵ�������Լ��У������Լ���ӵ������Ҳ�����������ڵ�folder��
//�������������Լ����������ڵ�folder��ɾ��

//���������Ϳ�����ֵ���������Ҫ�Ӱ���һ��Message������folder��ɾ����
//�������캯���Ϳ�����ֵ��Ҫ�����Message��ӵ�������һ��folder��
//��ˣ����Ƕ�������private�Ĺ��ߺ����������Щ������
//addToFolder()  removeFromFolder()

//���Խ�Message�й��ڲ���Folder�Ĵ������Ϊ˽�з�����Ϊ�˷������set�ķ���������FolderΪMessage����Ԫ�ࡣ
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

	//�ƶ����캯��
	Message(Message &&);
	//�ƶ���ֵ�����
	Message &operator=(Message &&);
private:
	string contents;
	set<Folder*> folders;
	//���ڿ���
	void addToFolder(const Message &msg) {
		for (auto folder : msg.folders) {
			folder->addMsg(this);
		}
	}
	//��������
	void removeFromFolder() {
		for (auto folder : folders) {
			folder->removeMsg(this);
		}
	}
	//����Folder�ķ���
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
	//��Ҫ�Ƚ����Դӳ��е�Folders��ɾ���������������¼��뵽�µ�folders��
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

//�ܽ��ƶ����캯�����ƶ���ֵ�������д����������������Ϊ�ƶ������������Ͼ�����ֵΪmove�����ķ���ֵ��������Ҫ�������������Դ
//��Ȼ�������ָ��Ŀ�������ôû�б�Ҫ�ƶ����ƶ����ǽ�����Ԫ��תΪ����ָ�룬����������ָ��Ͳ��ؿ����ˡ�
//��Ϊ���ƶ����캯�����ƶ���ֵ����������õ��ƶ�set����˽���δ�������д��һ��������

//set�в���������ܻ��׳��ڴ�����쳣����˲�����Ϊnoexcept
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

