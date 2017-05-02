#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

//流迭代器
//虽然iostream不是容器，但标准库定义了可以用于这些IO类型对象的迭代器 
//istream_iterator 读取输入流，ostream_iterator 向输出流写数据
//因此我们可以使用泛型算法从流对象中读取数据以及向其写入数据

//定义流的时候要加上类型参数

//一个istream_iterator 使用>>来读取流，因此istream_iterator 要读取的类型必须定义了输入运算符
//当创建一个istream_iterator ，我们可以将它绑定到一个流。还可以对其进行默认初始化，相当于尾后迭代器
//使用++来移动到下一个位置，使用*来取得值
//val = *it 表示从流中读出数据

//当我们已经有了一个迭代器，可以利用迭代器构造一个容器
void test39(){
	istream_iterator<int> isIter(cin),eof;
	vector<int> iVec;
	while(isIter != eof){
		iVec.push_back(*isIter++);
	}
	
	//使用输出流+copy函数+容器，可以实现将容器中的值拷贝到输出流，也就是打印出来
	ostream_iterator<int> osIter(cout,"\t");
	copy(iVec.cbegin(),iVec.cend(),osIter);
	cout<<endl;
}

//简化后的代码如下：
void test40(){
	istream_iterator<int> it(cin),eof;
	vector<int> iVec(it,eof);//利用两个迭代器来构造一个容器，不过这里的迭代器不是以往的容器迭代器，而是流迭代器	

	ostream_iterator<int> osIter(cout,"\t");
	copy(iVec.cbegin(),iVec.cend(),osIter);
	cout<<endl;
}

//使用算法来操作流迭代器，流迭代器支持某些迭代器操作
//accumulate操作
void test41(){
	istream_iterator<int> isIter(cin),eof;
	cout<<accumulate(isIter,eof,0)<<endl;
}
//惰性求值
//当我们将一个istream_iterator绑定到一个流上之后，标准库并不保证迭代器立即从流中读取数据，具体实现可以推迟到我们使用迭代器时才真正读取。
//标准库的实现所保证的是，在我们第一次解引用迭代器之前，从流中读取数据的操作已经完成了。


//ostream_iterator的操作
//我们可以对任何具有输出运算符的类型定义ostream_iterator，构造迭代器的时候可以提供可选的第二个参数（第一个是输出流），是一个字符串，在输出每个元素之后都会打印这个字符串
//这个字符串必须是一个C风格字符串（字面量或者字符数组的指针）
//必须将ostream_iterator绑定到一个输出流，不允许空
//*it = val;写入到流中
//和输入流迭代器不同，*it,++it,it++ 这些运算都没有效果，返回it
//写入到输出流没有必要递增
void test42(){
	ostream_iterator<int> osIter(cout,"  ");
	vector<int> iVec = {2,3,4,5,6,7};
	//将一个容器的内容写到流中
	for(auto i:iVec){
		*osIter++ = i;//输出流没有必要递增，为了保持一致性，也可以加上
	}
	cout<<endl;
	//可以通过调用copy来打印容器的元素
	copy(iVec.cbegin(),iVec.cend(),osIter);
	cout<<endl;
}
//*iter = val; 这是写入到流中
//val = *iter; 这是从流中读出来

class SalesItem;
void test43(){
	istream_iterator<SalesItem> isIter(cin),eof;
	ostream_iterator<SalesItem> osIter(cout,"\t");
	SalesItem sum = *isIter++//*表示读出一条记录，存入到sum，然后移动到下一条记录
	while(isIter != eof){
		if(isIter->isbn() == sum.isbn()){
			sum += *isIter++;
		}else{
			//输出，也就是写入到输出流
			*osIter++ = sum;
			sum = *isIter++;
		}
	}
	*osIter = sum;
}



