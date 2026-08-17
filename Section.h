#pragma once

#include "Paragraph.h"
#include <iostream>
class Section
{
	Paragraph** p;
	int totalparagraphs;

public:

	Paragraph* getParagraph(int index);
	int getTotalParagraphs() const;

	Section();
	Section(const Section& other);
	void add_paragraph(const Paragraph& other);
	void display_section(std::ostream& out);
	void display_section_number(std::ostream& out);
	~Section();
	Section& operator=(const Section& other);
};

