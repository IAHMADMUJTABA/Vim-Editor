#include "Paragraph.h"

using namespace std;
Paragraph ::Paragraph() {
	l = nullptr;
	totalline = 0;
}
Paragraph::Paragraph(const Paragraph& other) {
	totalline = other.totalline;
	l = new line * [totalline] {};
	for (int i = 0; i < totalline; i++) {
		l[i] = new line{ *other.l[i] };
	}

}

void Paragraph::addline(const line& other) {


	line** temp = new line * [totalline + 1];


	for (int i = 0; i < totalline; i++)
	{
		temp[i] = l[i];
	}


	temp[totalline] = new line(other);

	delete[] l;
	l = temp;

	totalline++;


}

int  Paragraph::get_totallines()const {



	return totalline;
}



void Paragraph::display_paragraph_number(std::ostream& out) {

	static int r = 1;




	for (int i = 0; i < totalline; i++) {

		cout << "[" << r << "] ";

		l[i]->display(out);
		out << endl;

		r++;
	}



}


void Paragraph::display_paragraph(std::ostream& out) {
	


	


	for (int i = 0; i < totalline; i++) {


		
		l[i]->display(out);
		out << endl;
	
		
	}



}
line* Paragraph::getline(int row) {
	if (row < 0 || row >= totalline) {

		return nullptr;
	}

	return l[row];
}
Paragraph ::~Paragraph()
{
	for (int i = 0; i < totalline; i++)
	{
		delete l[i];
	}

	delete[] l;
}

void Paragraph::removeLine(int index)
{
	if (index < 0 || index >= totalline)
		return;

	
	delete l[index];

	
	if (totalline == 1)
	{
		delete[] l;

		l = new line * [1];
		l[0] = new line();

		totalline = 1;
		return;
	}

	
	line** temp = new line * [totalline - 1];

	int j = 0;

	for (int i = 0; i < totalline; i++)
	{
		if (i != index)
		{
			temp[j] = l[i];
			j++;
		}
	}

	delete[] l;

	l = temp;

	totalline--;
}

void Paragraph::insertLine(int index, const line& other)
{
	if (index < 0)
		index = 0;

	if (index > totalline)
		index = totalline;

	line** temp = new line * [totalline + 1];

	
	for (int i = 0; i < index; i++)
	{
		temp[i] = l[i];
	}


	temp[index] = new line(other);

	
	for (int i = index; i < totalline; i++)
	{
		temp[i + 1] = l[i];
	}

	delete[] l;

	l = temp;

	totalline++;
	
}