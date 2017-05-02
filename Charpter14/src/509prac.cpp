/*
 * 509prac.cpp
 *
 *  Created on: 2016Äê9ÔÂ16ÈÕ
 *      Author: songx
 */

#include <stddef.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

class LengthEqual {
public:
	LengthEqual(size_t sz) :
			size(sz) {
	}
	bool operator()(const string & word) {
		return word.size() == size;
	}
private:
	size_t size;
};
class LengthSmallerThan {
public:
	LengthSmallerThan(size_t sz) :
			size(sz) {
	}
	bool operator()(const string & word) {
		return word.size() <= size;
	}
private:
	size_t size;
};

void wordCount(ifstream & ifstrm) {
	vector<vector<string>> text;
	string line;
	map<int, int> lenFreq;
	while (getline(ifstrm, line)) {
		istringstream is(line);
		string word;
		vector<string> words;
		while (is >> word) {
			words.push_back(word);
		}
		text.push_back(words);
	}
	for (const auto & line : text) {
		for (int i = 1; i != 11; i++) {
			lenFreq[i] += count_if(line.begin(), line.end(), LengthEqual(i));
		}
	}
	for (const auto & pair : lenFreq) {
		cout << "Length " << pair.first << " occur " << pair.second << " times"
				<< endl;
	}
}

void wordCountSamller(ifstream & ifstrm) {
	vector<vector<string>> text;
	string line;
	map<int, int> lenFreq;
	while (getline(ifstrm, line)) {
		istringstream is(line);
		string word;
		vector<string> words;
		while (is >> word) {
			words.push_back(word);
		}
		text.push_back(words);
	}
	for (const auto & line : text) {
		size_t cnt = count_if(line.begin(), line.end(), LengthSmallerThan(9));
		lenFreq[0] += cnt;
		lenFreq[1] += line.size() - cnt;
	}
	for (const auto & pair : lenFreq) {
		cout << "Length " << pair.first+9 << " occur " << pair.second << " times"
				<< endl;
	}
}

int main(void) {
	ifstream ifstrm("D:/text.txt");
	wordCount(ifstrm);
	wordCountSamller(ifstrm);
	return 0;
}

