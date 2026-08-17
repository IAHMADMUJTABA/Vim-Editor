
#include "Section.h"
#include"Paragraph.h"

using namespace std;
Section::Section() {
	p = nullptr;
	totalparagraphs = 0;
}

Section::Section(const Section& other) {
	totalparagraphs = other.totalparagraphs;

	p = new Paragraph * [totalparagraphs] {};
	for (int i = 0; i < totalparagraphs; i++) {
		p[i] = new Paragraph{ *other.p[i] };
	}

}
int Section::getTotalParagraphs() const
{
	return totalparagraphs;
}
void Section::add_paragraph(const Paragraph& other) {


	Paragraph** temp = new Paragraph * [totalparagraphs + 1];


	for (int i = 0; i < totalparagraphs; i++)
	{
		temp[i] = p[i];
	}


	temp[totalparagraphs] = new Paragraph(other);

	delete[] p;
	p = temp;

	totalparagraphs++;


}

Paragraph* Section::getParagraph(int index)
{
	if (index < 0 || index >= totalparagraphs) {
		return nullptr;
	}
		

	return p[index];
}

void Section::display_section_number(std::ostream& out) {

	for (int i = 0; i < totalparagraphs; i++) {

		p[i]->display_paragraph_number(out);
		out << endl;
	}



}
void Section::display_section(std::ostream& out) {

	for (int i = 0; i < totalparagraphs; i++) {

		p[i]->display_paragraph(out);
		out << endl;
	}



}

Section::~Section()
{
	for (int i = 0; i < totalparagraphs; i++)
	{
		delete p[i];
	}

	delete[] p;
}

Section& Section::operator=(const Section& other) {

	if (this != &other) {

		if (p != nullptr) {
			for (int i = 0; i < totalparagraphs; i++)
			{
				delete p[i];
			}

			delete[] p;
		}

		totalparagraphs = other.totalparagraphs;

		p = new Paragraph * [totalparagraphs] {};
		for (int i = 0; i < totalparagraphs; i++) {
			p[i] = new Paragraph{ *other.p[i] };
		}

	}


	return *this;
}