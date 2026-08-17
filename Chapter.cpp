#include "Chapter.h"
#include"Section.h"

using namespace std;
Section* Chapter::getSection(int index)
{
	if (index < 0 || index >= totalSections) {
		return nullptr;
	}
		

	return sections[index];
}

int Chapter::getTotalSections() const
{
	return totalSections;
}
Chapter::Chapter() {
	sections = nullptr;
	totalSections = 0;

}
Chapter::Chapter(const Chapter& other) {
	totalSections = other.totalSections;

	sections= new Section * [totalSections] {};
	for (int i = 0; i < totalSections; i++) {
		sections[i] = new Section{ *other.sections[i]};
	}
}
void Chapter::add_section(const Section& other) {

	Section** temp = new Section * [totalSections + 1];


	for (int i = 0; i < totalSections; i++)
	{
		temp[i] = sections[i];
	}


	temp[totalSections] = new Section(other);

	delete[]sections;
	sections = temp;

	totalSections++;
}

void Chapter::display_Chapter_number(std::ostream& out) {
	for (int i = 0; i < totalSections; i++) {

		sections[i]->display_section_number(out);
		out << endl;
	}
}
void Chapter::display_Chapter(std::ostream& out) {
	for (int i = 0; i < totalSections; i++) {

		sections[i]->display_section(out);
		out << endl;
	}
}
Chapter::~Chapter() {
	for (int i = 0; i < totalSections; i++)
	{
		delete sections[i];
	}

	delete[] sections;
}
Chapter& Chapter::operator=(const Chapter& other) {

	if (this != &other) {

		if (sections != nullptr) {
			for (int i = 0; i < totalSections; i++)
			{
				delete sections[i];
			}

			delete[] sections;
		}

		totalSections = other.totalSections;

		sections = new Section * [totalSections] {};
		for (int i = 0; i < totalSections; i++) {
			sections[i] = new Section{ *other.sections[i] };
		}

	}


	return *this;
}
