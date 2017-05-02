#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> readLines(string file) {
	ifstream input(file);
	string line;
	vector<string> lines;
	while (getline(input, line)) {
		lines.push_back(line);
	}
	input.close();
	return lines;
 }
vector<string> readWords(string file) {
	ifstream input(file);
	string line;
	vector<string> lines;
	while (input>>line) {
		lines.push_back(line);
	}
	input.close();
	return lines;
}
void copy(string in, string out) {
	ifstream input(in);
	ofstream output(out,ofstream::app);
	string line;
	vector<string> lines;
	while (getline(input, line)) {
		output << line << endl;
	}
	input.close();
	output.close();
}
int main(void) {
	vector<string> sVec = readWords("D:/codepeasant.txt");
	for (auto s : sVec) {
		cout << s;
	}
	copy("D:/codepeasant.txt", "D:/temp.txt");
	return 0;
}
