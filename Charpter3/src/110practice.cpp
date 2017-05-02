#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//��C++��ʹ��c�е��ַ���������Ҫinclude cstring
//strlen strcmp strcpy strcat
void testString1() {
	const char ca[] = { 'h','e','l','l','o' };
	const char *cp = ca;
	while (*cp) {
		cout << *cp << endl;
		cp++;
	}
	//��δ��������⣬�ַ�����û�ж���\0�����������Ի����Խ��ֱ�����������ڴ������һ��\0
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
