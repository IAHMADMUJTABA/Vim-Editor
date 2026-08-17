
#include"Editor.h"

#include"Document.h"
#include"console.h"
#include<vector>



Editor::Editor()
{
    console s;
    int rows = 39;
    int cols = 120;
	chapter = 0;
	section = 0;
	paragraph = 0;
    lineNo = 0;
	column = 0;
    cursorRow = 0;
    s.gotoRowCol(rows * 0.40, cols * 0.50);
    cout << "(1)Open New Document";
    s.gotoRowCol(rows * 0.42, cols * 0.50);
    cout << "(2)Open Saved Document";

    char a = _getch();

    if (a == '1')
    {
        doc.createdocument();
    }
    else if (a == '2')
    {
        doc.loadFromFile("Text.txt");
    }
    system("cls");
}


//normal mode
///.....................///
void Editor::NormalMode()
{
    console c;

    Document temp;

    system("cls");
    doc.display_Document(cout);
    c.color(25);
   
    c.gotoRowCol(29, 10);
    cout << "=== N O R M A L - M O D E ===";
    c.printaline(39, 0, 39, 152, 223, 0.001);

    c.printaline(40, 0, 40, 154, 205, 0.001);

    c.printaline(0, 152, 39, 152, 219, 0.001);

    c.printaline(0, 154, 40, 154, 186, 0.001);
    c.color(16);



    chapter = 0;
    section = 0;
    paragraph = 0;
    lineNo = 0;
    column = 0;
    cursorRow = 0;

    c.gotoRowCol(cursorRow, column);

    while (true)
    {
        int key = _getch();
       

        if (key == 0 || key == 224)
        {
            key = _getch();

            switch (key)
            {
            case 72:        // Up
                Up();
                break;

            case 80:        // Down
                Down();
                break;

            case 75:        // Left
                Left();
                break;

            case 77:        // Right
                Right();
                break;
            }
        }

        else if (key == 'u') {
           
            doc = temp;
        }


        else if (key == 'h')
        {
            Left();
        }

        else if (key == 'j')
        {
            Down();
        }

        else if (key == 'k')
        {
            Up();
        }

        else if (key == 'l')
        {
            Right();
        }

        else if (key == 'w')
        {
            NextWord();
        }

        else if (key == 'b')
        {
            PreviousWord();
        }

        else if (key == '0')
        {
            LineStart();
        }

        else if (key == '$')
        {
            LineEnd();
        }

        else if (key == 'g')
        {
            int second = _getch();

            if (second == 'g')
                FileStart();
        }

        else if (key == 'G')
        {
            FileEnd();
        }

       

        else if (key == 'x')
        {
            temp = doc;
            deleteCharacter();
        }

        else if (key == 'D')
        {
            temp = doc;
            delete_toend_Line();
            
        }

        else if (key == 'd')
        {
            int second = _getch();

            if (second == 'd') {
                temp = doc;
                delete_current_line();
               
            }
              


        }



        else if (key == 'y')
        {
            int second = _getch();

            if (second == 'y') {
                yankLine();
            }
                
        }

        else if (key == 'p')
        {
            temp = doc;
            pasteAfter();
           
        }

        else if (key == 'P')
        {
            temp = doc;
            pasteBefore();
           
        }

     

        else if (key == '~')
        {
            temp = doc;
            toggleCase();
            
        }

      
      
        else if (key == 'i')
        {
            c.color(25);

            c.gotoRowCol(29, 10);
            cout << "=== I N S E R T - M O D E ===";
            c.printaline(39, 0, 39, 152, 223, 0.001);

            c.printaline(40, 0, 40, 154, 205, 0.001);

            c.printaline(0, 152, 39, 152, 219, 0.001);

            c.printaline(0, 154, 40, 154, 186, 0.001);
            c.color(16);
            InsertMode();

            system("cls");
            doc.display_Document(cout);
            
        }
        
       

        else if (key == ':')
        {
            c.color(25);

            c.gotoRowCol(29, 10);
            cout << "=== C O M M A N D - M O D E ===";
            c.printaline(39, 0, 39, 152, 223, 0.001);

            c.printaline(40, 0, 40, 154, 205, 0.001);

            c.printaline(0, 152, 39, 152, 219, 0.001);

            c.printaline(0, 154, 40, 154, 186, 0.001);
            c.color(16);
            CommandMode();

            system("cls");
            doc.display_Document(cout);
            
        }

        else if (key == 4) {
            downpage();
            c.gotoRowCol(cursorRow, column);
            continue;
        }

        else if (key == 21) {
            upapage();
            c.gotoRowCol(cursorRow, column);
            continue;
            }
     

       

       

        system("cls");
        doc.display_Document(cout);
        c.color(25);

        c.gotoRowCol(29, 10);
        cout << "=== N O R M A L - M O D E ===";
        c.printaline(39, 0, 39, 152, 223, 0.001);

        c.printaline(40, 0, 40, 154, 205, 0.001);

        c.printaline(0, 152, 39, 152, 219, 0.001);

        c.printaline(0, 154, 40, 154, 186, 0.001);
        c.color(16);
        cursorRow = getScreenRow();

        c.gotoRowCol(cursorRow, column);


     
    }
}
///................///


int Editor::getScreenRow()
{
    int row = 0;


    for (int c = 0; c < chapter; c++)
    {
        Chapter* ch = doc.getChapter(c);
        for (int s = 0; s < ch->getTotalSections(); s++)
        {
            Section* sec = ch->getSection(s);
            for (int p = 0; p < sec->getTotalParagraphs(); p++)
            {
                row += sec->getParagraph(p)->get_totallines();
                row++; 
            }
            row++; 
        }
        row++; 
    }

   
    Chapter* ch = currentChapter();
    if (ch != nullptr)
    {
        for (int s = 0; s < section; s++)
        {
            Section* sec = ch->getSection(s);
            for (int p = 0; p < sec->getTotalParagraphs(); p++)
            {
                row += sec->getParagraph(p)->get_totallines();
                row++; 
            }
            row++;
        }
    }

    
    Section* sec = currentSection();
    if (sec != nullptr)
    {
        for (int p = 0; p < paragraph; p++)
        {
            row += sec->getParagraph(p)->get_totallines();
            row++;
        }
    }

   
    row += lineNo;

    return row;
}

void Editor::FileStart() {

    chapter = 0;
    section = 0;
    paragraph = 0;
    lineNo = 0;
    column = 0;
    cursorRow = 0;
}

void Editor::LineStart() {

    column = 0;
    cursorRow = 0;

}


void Editor::downpage() {
    cursorRow += 5;

}

void Editor::upapage() {
    cursorRow -= 5;

   
    if (cursorRow < 0) {
        cursorRow = 0;
    }
}

void Editor::FileEnd()
{
    chapter = doc.getTotalChapters() - 1;

    section = doc.getChapter(chapter)->getTotalSections() - 1;

    paragraph =doc.getChapter(chapter)->getSection(section)->getTotalParagraphs() - 1;

    lineNo =doc.getChapter(chapter)->getSection(section)->getParagraph(paragraph)->get_totallines() - 1;

    column = currentLine()->getlenght();

    Section* sec =doc.getChapter(chapter)->getSection(section);
    cursorRow = 0;
    for (int i = 0; i < paragraph; i++)
    {
        cursorRow += sec->getParagraph(i)->get_totallines();

        cursorRow++;       
    }

    cursorRow += lineNo;
}



line* Editor::currentLine()
{
    return doc.getChapter(chapter)->getSection(section)->getParagraph(paragraph) ->getline(lineNo);
}

void  Editor::LineEnd() {
    column = currentLine()->getlenght();
}

void Editor::Left()
{
    if (column > 0)
        column--;
}

void Editor::Right()
{
    if (column < currentLine()->getlenght()) {
        column++;
    }
        
}

void Editor::Up()
{
    if (lineNo > 0)
    {
        lineNo--;
        cursorRow--;
    }
    else if (paragraph > 0)
    {
        paragraph--;

        lineNo = currentParagraph()->get_totallines() - 1;

        cursorRow--;
    }

    if (column > currentLine()->getlenght())
    {
        column = currentLine()->getlenght();
    }
       
}

void Editor::Down()
{
    if (lineNo < currentParagraph()->get_totallines() - 1)
    {
        lineNo++;
        cursorRow++;
    }
    else if (paragraph < currentSection()->getTotalParagraphs() - 1)
    {
        paragraph++;
        lineNo = 0;
        cursorRow++;
    }

    if (column > currentLine()->getlenght()) {
        column = currentLine()->getlenght();
    }
        
}


void Editor::NextWord()
{
    line* l = currentLine();

    while (column < l->getlenght() && l->getChar(column) != ' ')
    {
        column++;
    }

    while (column < l->getlenght() &&  l->getChar(column) == ' ')
    {
        column++;
    }
}


void Editor::PreviousWord()
{
    line* l = currentLine();

    if (column == 0) {
        return;
    }

       

    column--;

    while (column > 0 && l->getChar(column) == ' ')
    {
        column--;
    }

    while (column > 0 &&  l->getChar(column - 1) != ' ')
    {
        column--;
    }
}

void Editor::deleteCharacter()
{
    if (column >= currentLine()->getlenght()) {
        return;
    }
     

    currentLine()->remove(column);
}

void Editor::delete_toend_Line()
{
    currentLine()->removeFrom(column);
}

void Editor::delete_current_line()
{
    currentParagraph()->removeLine(lineNo);

    if (lineNo >= currentParagraph()->get_totallines()) {
        lineNo--;
    }
     

    if (lineNo < 0) {
        lineNo = 0;
    }
       

    column = 0;
}

void Editor::yankLine()
{
    clipboard = *currentLine();
}

void Editor::pasteAfter()
{
    currentParagraph()->insertLine(lineNo + 1, clipboard);
}

void Editor::pasteBefore()
{
    currentParagraph()->insertLine(lineNo, clipboard);
}


void Editor::toggleCase()
{
    char ch = currentLine()->getChar(column);

    if (ch >= 'a' && ch <= 'z') {
        currentLine()->setChar(column, ch - 32);
    }
       

    else if (ch >= 'A' && ch <= 'Z') {
        currentLine()->setChar(column, ch + 32);
    }
       
}

Paragraph* Editor::currentParagraph()
{
    return doc.getChapter(chapter) ->getSection(section) ->getParagraph(paragraph);
}

Section* Editor::currentSection()
{
    return doc.getChapter(chapter)->getSection(section);
}

Chapter* Editor::currentChapter()
{
    return doc.getChapter(chapter);
}

//insert mode
///................///
void Editor::InsertMode()
{
    line copy;
    while (true)
    {
        int key = _getch();

       

        if (key == 0 || key == 224)
        {
            key = _getch();

            switch (key)
            {
            case 72:        // Up
                Up();
                break;

            case 80:        // Down
                Down();
                break;

            case 75:        // Left
                Left();
                break;

            case 77:        // Right
                Right();
                break;

            case 83:   // Delete
                if (column < currentLine()->getlenght())
                {
                    currentLine()->remove(column);
                }
                break;


            case 82:
                for (int i = 0; i < copy.getlenght(); i++) {

                    currentLine()->insert(column, copy.getChar(i));
                    column++;
                }
                break;
            }
        }



        else if (key == 8)
        {
            if (column > 0)
            {
                currentLine()->remove(column - 1);
                column--;
            }
        }


        else if (key == 13)
        {
            line* t = currentLine();
            line c;
            int s = 0;;
            for (int i = column; i < t->getlenght(); i++) {

                c.insert(s, t->getChar(i));
                s++;
            }
            for (int i = t->getlenght() - 1; i >= column; i--)
            {
                currentLine()->remove(i);
            }

            currentParagraph()->insertLine(lineNo + 1, c);
            lineNo++;
            cursorRow++;
            column = 0;
        }

        else if (key == 9) {
            for (int i = 1; i <= 4; i++) {
                currentLine()->insert(column, ' ');
                column++;
            }


        }


        else if (key == 3) {


            copy.clearline();
            int s = 0;;
            int i = column;
            while (i < currentLine()->getlenght()) {

                copy.insert(s, currentLine()->getChar(i));
                key = _getch();
                if (key == 0 || key == 224) {
                    key = _getch();
                    if (key == 77) {
                        Right();
                        s++;
                        i++;

                    }

                }
                else if (key == 99) {
                    break;
                }
                system("cls");
                console c;
                doc.display_Document(cout);
                c.color(25);

                c.gotoRowCol(29, 10);
                cout << "=== I N S E R T - M O D E ===";
                c.printaline(39, 0, 39, 152, 223, 0.001);

                c.printaline(40, 0, 40, 154, 205, 0.001);

                c.printaline(0, 152, 39, 152, 219, 0.001);

                c.printaline(0, 154, 40, 154, 186, 0.001);
                c.color(16);
                
                c.gotoRowCol(getScreenRow(), column);



            }




        }

        else if (key == 24) {

            int start = column;
            int end = 0;
            copy.clearline();
            int s = 0;;
            int i = column;
            while (i < currentLine()->getlenght()) {

                copy.insert(s, currentLine()->getChar(i));
                key = _getch();
                if (key == 0 || key == 224) {
                    key = _getch();
                    if (key == 77) {
                        Right();
                        s++;
                        i++;

                    }

                }
                else if (key == 120) {
                    break;
                }
                system("cls");
                console c;
                doc.display_Document(cout);
                c.color(25);

                c.gotoRowCol(29, 10);
                cout << "=== I N S E R T - M O D E ===";
                c.printaline(39, 0, 39, 152, 223, 0.001);

                c.printaline(40, 0, 40, 154, 205, 0.001);

                c.printaline(0, 152, 39, 152, 219, 0.001);

                c.printaline(0, 154, 40, 154, 186, 0.001);
                c.color(16);
               
                c.gotoRowCol(getScreenRow(), column);



            }
            end = i;
            for (int i =end; i >=start ; i--) {

                currentLine()->remove(i);

            }



         }

        else if (key == 27) {
            system("cls");
            //doc.display_Document();
            NormalMode();
            
        }
        else if (key == 58) {
            system("cls");
            //doc.display_Document();
           CommandMode();

            }
        else {


            currentLine()->insert(column, char(key));
            column++;

        }

        console c;
        system("cls");
        doc.display_Document(cout);
        c.color(25);

        c.gotoRowCol(29, 10);
        cout << "=== I N S E R T - M O D E ===";
        c.printaline(39, 0, 39, 152, 223, 0.001);

        c.printaline(40, 0, 40, 154, 205, 0.001);

        c.printaline(0, 152, 39, 152, 219, 0.001);

        c.printaline(0, 154, 40, 154, 186, 0.001);
        c.color(16);
       
        c.gotoRowCol(getScreenRow(), column);

        continue;
    }

}
///................../...///

struct search_location
{
    int chapter;
    int section;
    int paragraph;
    int line;
    int column;
};

int compare(line* l, char arr[]) {
    int length = 0;
    while (arr[length] != '\0') {
        length++;
    }

    if (length <= 0 || length > l->getlenght()) {
        return -1;
    }

    for (int i = 0; i <= l->getlenght() - length; i++) {
        bool match = true;
        for (int j = 0; j < length; j++) {
            if (l->getChar(i + j) != arr[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return i; 
        }
    }

    return -1;
}
//Command mode


void replace(line* l, char old[], char newarr[])
{
    int pos = compare(l, old);

    while (pos != -1)
    {
     
        int i = 0;
        while (old[i] != '\0')
        {
            l->remove(pos);
            i++;
        }

       
        i = 0;
        while (newarr[i] != '\0')
        {
            l->insert(pos + i, newarr[i]);
            i++;
        }

       
        pos = compare(l, old);
    }
}


///.......//Command mode.........///
void Editor::CommandMode() {
    vector<search_location> m;
    int fw_search = 0;
    console c;
    system("cls");
    doc.display_Document(cout);
    c.color(25);

    c.gotoRowCol(29, 10);
    cout << "=== C O M M A N D - M O D E ===";
    c.printaline(39, 0, 39, 152, 223, 0.001);

    c.printaline(40, 0, 40, 154, 205, 0.001);

    c.printaline(0, 152, 39, 152, 219, 0.001);

    c.printaline(0, 154, 40, 154, 186, 0.001);
    c.color(16);

    char old[50];
    while (true) {
        int key = _getch();

        if (key == 0 || key == 224) {
            key = _getch();
            if (key == 71) {
                doc.saveToFile("Text.txt");
                exit(0);
            }
        }
        else if (key == '!') {
            c.color(25);

            c.gotoRowCol(29, 10);
            cout << "=== E X I T I N G - P R O G R A M ===";
            _getch();
            exit(0);
        }
        else if (key == 'w') {
            doc.saveToFile("Text.txt");
        }
        else if (key == 'q') {
            system("cls");
            doc.display_Document(cout);

            exit(0);
        }
        else if (key == '/') {


            m.clear();
            fw_search = 0;
            char arr[50];
            int size = 0;


            key = _getch();

            while (key != 13) {


                if (key == 8 && size > 0) { 


                    size--;
                }
                else if (key != 8) {


                    arr[size] = char(key);
                    old[size] = char(key);
                    size++;
                }


                key = _getch();
            }
            arr[size] = '\0';



            old[size] = '\0';

           
            for (int i = 0; i < doc.getTotalChapters(); i++) {

                for (int j = 0; j < doc.getChapter(i)->getTotalSections(); j++) {

                    for (int k = 0; k < doc.getChapter(i)->getSection(j)->getTotalParagraphs(); k++) {

                        for (int l = 0; l < doc.getChapter(i)->getSection(j)->getParagraph(k)->get_totallines(); l++) {

                            int comp = compare(doc.getChapter(i)->getSection(j)->getParagraph(k)->getline(l), arr);
                            if (comp != -1) {
                                search_location temp;
                                temp.chapter = i;

                                temp.section = j;
                                temp.paragraph = k;

                                temp.line = l;
                                temp.column = comp;
                                m.push_back(temp);

                            }
                        }
                    }
                }
            }

            if (!m.empty()) {

                fw_search = 0;
                chapter = m[0].chapter;

                section = m[0].section;

                paragraph = m[0].paragraph;
                lineNo = m[0].line;

                column = m[0].column;
            }
        }
        else if (key == 'n') {


            if (!m.empty()) {

                fw_search = (fw_search + 1) % m.size();

                chapter = m[fw_search].chapter;
                section = m[fw_search].section;


                paragraph = m[fw_search].paragraph;
                lineNo = m[fw_search].line;


                column = m[fw_search].column;
            }
        }
        else if (key == 'N') {

            if (!m.empty()) {

                fw_search--;

                if (fw_search < 0) {
                    fw_search = (int)m.size() - 1;
                }

                chapter = m[fw_search].chapter;


                section = m[fw_search].section;
                paragraph = m[fw_search].paragraph;
                lineNo = m[fw_search].line;

                column = m[fw_search].column;
            }
        }

        else if (key == 'r') {


            char newarr[50];

            int size = 0;
            key = _getch();

            
            while (key != 13 && size < 49) {

                if (key == 8 && size > 0) { 
                    size--;
                }
                else if (key != 8) { 
                    newarr[size] = char(key);
                    size++;
                }
                key = _getch();
            }
            newarr[size] = '\0'; 

           
            if (old[0] != '\0') {

                for (int i = 0; i < doc.getTotalChapters(); i++) {

                    Chapter* chobj = doc.getChapter(i);

                    for (int j = 0; j < chobj->getTotalSections(); j++) {

                        Section* secobj = chobj->getSection(j);

                        for (int k = 0; k < secobj->getTotalParagraphs(); k++) {

                            Paragraph* pobj = secobj->getParagraph(k);

                            for (int l = 0; l < pobj->get_totallines(); l++) {

                                line* linePtr = pobj->getline(l);

                                if (linePtr != nullptr) {
                                    replace(linePtr, old, newarr);
                                }
                            }
                        }
                    }
                }
            }
        }


        else if (key == 27) {
            system("cls");
            //doc.display_Document();
            NormalMode();

        }
        else if (key == 'i')
        {
            c.color(25);

            c.gotoRowCol(29, 10);
            cout << "=== I N S E R T - M O D E ===";
            c.printaline(39, 0, 39, 152, 223, 0.001);

            c.printaline(40, 0, 40, 154, 205, 0.001);

            c.printaline(0, 152, 39, 152, 219, 0.001);

            c.printaline(0, 154, 40, 154, 186, 0.001);
            c.color(16);
            InsertMode();

            system("cls");
            doc.display_Document(cout);
         }

        else if (key=='e') {

            system("cls");
            doc.display_Document_with_number(cout);
            c.color(25);

            c.gotoRowCol(29, 10);
            cout << "=== C O M M A N D - M O D E ===";
            c.printaline(39, 0, 39, 152, 223, 0.001);

            c.printaline(40, 0, 40, 154, 205, 0.001);

            c.printaline(0, 152, 39, 152, 219, 0.001);

            c.printaline(0, 154, 40, 154, 186, 0.001);
            c.color(16);

            char a=_getch();
        }
        
        system("cls");
        doc.display_Document(cout);
        c.color(25);

        c.gotoRowCol(29, 10);
        cout << "=== C O M M A N D - M O D E ===";
        c.printaline(39, 0, 39, 152, 223, 0.001);

        c.printaline(40, 0, 40, 154, 205, 0.001);

        c.printaline(0, 152, 39, 152, 219, 0.001);

        c.printaline(0, 154, 40, 154, 186, 0.001);
        c.color(16);
        cursorRow = getScreenRow(); 

        console c;
        c.gotoRowCol(cursorRow, column);
    }
}




    
