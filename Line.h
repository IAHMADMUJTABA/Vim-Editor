#pragma once
#include<iostream>

class line
{
	char* alpha;
	int size;
public:
	char getChar(int index) const;
	line();
	line(const line& other);
	line &operator=(const line& other);
	void insert(int index,char a);
	void replace(int index,char a);
	void remove(int index);
	void display(std::ostream& out)const;
	
	int getlenght()const;
	void clearline();
	~line();
	void removeFrom(int index);
	
	void setChar(int, char);
};

