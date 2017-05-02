#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//在C++中使用c中的字符串函数需要include cstring
//strlen strcmp strcpy strcat
void testString1() {
	const char ca[] = { 'h','e','l','l','o' };
	const char *cp = ca;
	while (*cp) {
		cout << *cp << endl;
		cp++;
	}
	//这段代码有问题，字符数组没有定义\0结束符，所以会访问越界直至遇到其他内存区域的一个\0
}
int strcmp(char a[], char b[]) {
	int i;
	for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
		if (a[i] != b[i]) {
			return a[i] - b[i];
		}
	}
	return a[i] != '\0' ? a[i] : b[i];
}

int main(void) {
	char a[] = "Hello";
	char b[] = "World";
	cout << strcmp(a, b) << endl;
	constexpr size_t size = strlen(a) + strlen(b) + 1;
	char result[size];
	return 0;
}
