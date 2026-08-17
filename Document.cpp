#include "Document.h"
#include"Chapter.h"


#include<fstream>
using namespace std;
int Document::getTotalChapters() const
{
	return totalchapters;
}
Document::Document() {
	chapters = nullptr;
	totalchapters = 0;
}
Document::Document(const Document& other) {
	totalchapters = other.totalchapters;

	chapters = new Chapter * [totalchapters] {};
	for (int i = 0; i < totalchapters; i++) {
		chapters[i] = new Chapter{ *other.chapters[i] };
	}
}
void Document::add_chapter(const	Chapter& other) {
	Chapter** temp = new Chapter * [totalchapters + 1];


	for (int i = 0; i < totalchapters; i++)
	{
		temp[i] = chapters[i];
	}


	temp[totalchapters] = new Chapter(other);

	delete[]chapters;
	chapters = temp;

	totalchapters++;
}
void Document::display_Document_with_number(std::ostream& out) {
	for (int i = 0; i < totalchapters; i++) {

		chapters[i]->display_Chapter_number(out);
		out << endl;

	}
	
}

void Document::display_Document(std::ostream& out) {
	for (int i = 0; i < totalchapters; i++) {

		chapters[i]->display_Chapter(out);
		out << endl;

	}
	
}
Document::~Document() {
	for (int i = 0; i < totalchapters; i++)
	{
		delete chapters[i];
	}

	delete[] chapters;
}
Document& Document::operator=(const Document& other) {

	if (this != &other) {

		if (chapters != nullptr) {
			for (int i = 0; i < totalchapters; i++)
			{
				delete chapters[i];
			}

			delete[] chapters;
		}
		totalchapters = other.totalchapters;

		chapters = new Chapter * [totalchapters] {};
		for (int i = 0; i < totalchapters; i++) {
			chapters[i] = new Chapter{ *other.chapters[i] };
		}

	}


	return *this;

}


void Document::loadFromFile(const char* filename)
{
	ifstream rdr(filename);

	if (!rdr)
	{
		cout << "File not found!\n";
		return;
	}

	Chapter chapter;
	Section section;
	Paragraph para;

	char buffer[1000];

	while (rdr.getline(buffer, 1000))
	{
		if (buffer[0] == '\0')
		{
			if (para.get_totallines() > 0)
			{
				section.add_paragraph(para);
				para = Paragraph();
			}
		}
		else
		{
			line temp;

			for (int i = 0; buffer[i] != '\0'; i++)
			{
				temp.insert(temp.getlenght(), buffer[i]);
			}

			para.addline(temp);
		}
	}

	if (para.get_totallines() > 0)
	{
		section.add_paragraph(para);
	}

	chapter.add_section(section);
	add_chapter(chapter);

	rdr.close();
}

void Document::saveToFile(const char* filename) {


	ofstream w(filename);

	display_Document(w);


}


Chapter* Document::getChapter(int index) {

	if (index < 0 || index >= totalchapters) {
		return nullptr;
	}
		

	return chapters[index];


}

void Document::createdocument()
{
	Chapter ch;
	Section sec;
	Paragraph para;
	line l;

	para.addline(l);          
	sec.add_paragraph(para);
	ch.add_section(sec);
	add_chapter(ch);
}

///................///