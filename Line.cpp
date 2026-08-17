#include "Line.h"
#include<iostream>
using namespace std;

void line::removeFrom(int index)
{
    while (size > index)
    {
        remove(index);
    }
}

line::line() {
	alpha = new char[1];
	size = 0;
    alpha[size] = '\0';
}
line::line(const line& other) {
	alpha = new char[other.size + 1];
	for (int i = 0; i <= other.size; i++) {
		alpha[i] = other.alpha[i];
	}

	this->size = other.size;

}
void line::insert(int index,char a) {
    if (index < 0 || index > size)
        return;
    char* temp = new char[size + 2];

    
    for (int i = 0; i < index; i++) {
        temp[i] = alpha[i];
    }
       

    temp[index] = a;

    for (int i = index; i <= size; i++) {
        temp[i + 1] = alpha[i];
    }
        

    delete[] alpha;
    alpha = temp;
    this->size++;
}



void line::replace(int index,char a) {
    if (index < 0 || index >= size)
        return;

    alpha[index] = a;
    
}
void line::remove(int index) {
    if (index < 0 || index >= size) {
        return;
    }
       

    char* temp = new char[size];  

    int j = 0;

    for (int i = 0; i < size; i++)
    {
        if (i != index)
        {
            temp[j] = alpha[i];
            j++;
        }
    }

    temp[j] = '\0';

    delete[] alpha;
    alpha = temp;

    size--;
}
line::~line() {
    delete[]alpha;
}
int line::getlenght()const {

    return size;
}
void line::display(std::ostream& out)const {


    out << alpha;

}



void line::clearline() {

    for (int i = 0; i < size; i++) {

        remove(i);
    }

    delete[]alpha;
    alpha = new char[1];
    size = 0;
    alpha[size] = '\0';

}
line& line::operator=(const line& other) {
    
    if (this != &other) {
        delete[] alpha;
        alpha = new char[other.size + 1];
        for (int i = 0; i <= other.size; i++) {
            alpha[i] = other.alpha[i];
        }

        this->size = other.size;
    }
   
    return *this;
}


char line::getChar(int index) const
{
    if (index < 0 || index >= size)
    {
        return '\0';
    }

    return alpha[index];
}


void line::setChar(int index, char ch)
{
    if (index < 0 || index >= size)
    {
        return;
    }

    alpha[index] = ch;
}