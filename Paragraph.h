#pragma once
#include"Line.h"
class Paragraph
{
	line**l;
	int totalline;

public:

	Paragraph();
	Paragraph(const Paragraph& other);
	void addline(const line& other);

	line *getline(int row);
	int get_totallines()const;
	void display_paragraph(std::ostream& out);
	void display_paragraph_number(std::ostream& out);
	void removeLine(int index);
	~Paragraph();
	void insertLine(int index, const line&);
};
