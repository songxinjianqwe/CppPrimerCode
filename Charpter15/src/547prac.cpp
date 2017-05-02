/*
 * 547prac.cpp
 *
 *  Created on: 2016年9月23日
 *      Author: songx
 */


#include <iostream>
using namespace std;

//有虚函数就应该有虚析构函数
class Graph{
public:
	Graph() = default;
	Graph(double size):size(size){}
	virtual void draw()const = 0;
	virtual ~Graph() = default;
protected:
	double size = 0;
};
class Rectangle:public Graph{
public:
	Rectangle() = default;
	Rectangle(int width,int height):width(width),height(height){}
	void draw()const override{
		cout<<"Draw a Square!"<<endl;
	}
private:
	int width = 0 ;
	int height = 0 ;
};
class Ball:public Graph{
public:
	Ball() = default;
	Ball(int radius):radius(radius){}
	void draw()const override{
		cout<<"Draw a Ball!"<<endl;
	}
private:
	int radius = 0;
};



