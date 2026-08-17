#pragma once
#include"Section.h"
class Chapter
{
	Section** sections;
	int totalSections;

public:
	Section* getSection(int index);
	Chapter();
	Chapter(const Chapter& other);
	void add_section(const Section& other);
	void display_Chapter(std::ostream& out);
	void display_Chapter_number(std::ostream& out);
	~Chapter();
	Chapter& operator=(const Chapter& other);

	int getTotalSections() const;
};

