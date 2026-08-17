#pragma once
#include "Chapter.h"
class Document
{
	Chapter** chapters;
	int totalchapters;

public:
	Document();
	Document(const Document& other);
	void add_chapter(const	Chapter& other);
	void display_Document(std::ostream& out);
	void display_Document_with_number(std::ostream& out);
	~Document();
	Document& operator=(const Document& other);
	Chapter* getChapter(int index);
	int getTotalChapters() const;
	void loadFromFile(const char* filename);
	void saveToFile(const char* filename);
	void createdocument();
};

