#include"console.h"
#include"Section.h"
#include"Line.h"
#include"Paragraph.h"
#include"Chapter.h"
#include"Document.h"
#include"Editor.h"

#include <windows.h>

void SetConsoleSettings()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

   
    SetConsoleTextAttribute(
        hConsole,
        BACKGROUND_RED |
        BACKGROUND_GREEN |
        BACKGROUND_BLUE |
        BACKGROUND_INTENSITY
    );

    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 10;
    cfi.dwFontSize.Y = 20;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;

    wcscpy_s(cfi.FaceName, L"Consolas");

    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);

    system("cls");
}

void Welcome()
{
  
    console c;
    c.color(25);
    _getch();
    system("cls");
    c.printaline(1, 2, 39, 2, 219, 0.001);
    
  
    c.printaline(39, 2, 39, 152, 223, 0.001);

    c.printaline(1, 2, 1, 152, 223, 0.001);
   

    c.printaline(1, 152, 39, 152, 219, 0.001);

   
    c.color(16);


   
    int rows = 39;
    int cols = 119;
    c.color(25);
    //system("cls");
    console t;
    t.gotoRowCol(rows * 0.40, cols * 0.50);
    cout << "=== W E L C O M E ===";
   
    Sleep(1500);
    c.printaline(rows * 0.40, 10, rows * 0.40, 100, ' ', 0.001);
    //system("cls");
  
    t.gotoRowCol(rows * 0.40, cols * 0.50);
    cout << "\t=== T O ===";
  
    Sleep(1500);
    c.printaline(rows * 0.40, 10, rows * 0.40, 100, ' ', 0.001);
    //system("cls");
    
    t.gotoRowCol(rows * 0.40, cols * 0.50);
    cout << "\t=== V I M - E D I T O R ===";
   
    Sleep(1500);
    c.printaline(rows * 0.40, 10, rows * 0.40, 100, ' ', 0.001);
    
    c.color(16);
}


int main() {
  

    SetConsoleSettings();
    Welcome();
   
	line l;
	Paragraph p;
	int cursor = 0;
	int lines = 0;
	int row = 0;
	int cols = 100;
	Editor e;

	//Document d;

	
	e.NormalMode();

	

	
	

	return 0;
}