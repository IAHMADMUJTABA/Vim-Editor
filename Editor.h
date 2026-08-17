#pragma once

#include"Document.h"

class Editor
{
private:
    Document doc;
    int chapter;
    int section;
    int paragraph;
    int  lineNo;
    int column;
    int cursorRow;
    line clipboard;

public:
    Editor();
    void NormalMode();


    int getScreenRow();
    
    void InsertMode();
    void CommandMode();

    void Left();          
    void Right();         
    void Up();            
    void Down();          



    void NextWord();     

    void PreviousWord();    

    void LineStart();      
    void LineEnd();        
    void FileStart();  


    void FileEnd();         

    void delete_current_line();        

    void delete_toend_Line();       

    void deleteCharacter();         

    void toggleCase();              



    void yankLine();               

    void pasteAfter();              

    void pasteBefore();

    void downpage();
    void upapage();
  
    line* currentLine();

    Chapter* currentChapter();

    Section* currentSection();

    Paragraph* currentParagraph();

  


}; 