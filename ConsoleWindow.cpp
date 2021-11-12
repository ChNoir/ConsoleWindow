#include "ConsoleWindow.h"

ConsoleWindow::ConsoleWindow(int X, int Y){
	std::string tamp = "mode " + std::to_string(X) + " , " + std::to_string(Y);
	ConsoleWindow::cursor_Ymax = Y;
	ConsoleWindow::cursor_Xmax = X;
	system(tamp.c_str());
}

COORD ConsoleWindow::GetCursorPosition(){
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
	return csbiInfo.dwCursorPosition ;
}

void ConsoleWindow::SetSizeConsoleWindow(int X, int Y){
	ConsoleWindow::cursorDefault();
	system("cls");
	std::string tamp = "mode " + std::to_string(X) + " , " + std::to_string(Y);
	ConsoleWindow::cursor_Ymax = Y;
	ConsoleWindow::cursor_Xmax = X;
	system(tamp.c_str());
}

void ConsoleWindow::cursorCout(std::string text){
	std::cout << text;
	int x = text.length();

	COORD CRD;
	CRD.X = x + cursor_X;
	CRD.Y = cursor_Y;

	cursor_X += x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::cursorCout(int i){
	std::cout << i;
	int x = std::to_string(i).length();
	
	COORD CRD;
	CRD.X = x + cursor_X;
	CRD.Y = cursor_Y;
	cursor_X += x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::cursorCout(long int i){
	std::cout << i;
	int x = std::to_string(i).length();

	COORD CRD;
	CRD.X = x + cursor_X;
	CRD.Y = cursor_Y;
	cursor_X += x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::cursorCout(double i , int precision ){
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(precision) << i;
	std::string t = ss.str();
	std::cout << t ;
	int x = t.size();

	COORD CRD;
	CRD.X = x + cursor_X;
	CRD.Y = cursor_Y;

	cursor_X += x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::cursorDefault(){
	COORD CRD;
	CRD.X = 0;
	CRD.Y = 0;

	cursor_X = 0;
	cursor_Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::cursorDefaultDown(){
	COORD CRD;
	CRD.X = 0;
	CRD.Y = cursor_Ymax;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::cursorToMove(int x, int y){
	COORD CRD;
	CRD.X = x;
	CRD.Y = y;

	cursor_X = x;
	cursor_Y = y;

	if (x >= cursor_Xmax) { 
		CRD.X = cursor_Xmax;
		cursor_X = cursor_Xmax;
	}
	if (y >= cursor_Ymax) { 
		CRD.Y = cursor_Ymax; 
		cursor_Y = cursor_Ymax;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::cursorToMove(COORD coord){
	cursor_X = coord.X;
	cursor_Y = coord.Y;

	if (coord.X >= cursor_Xmax) {
		coord.X = cursor_Xmax;
		cursor_X = cursor_Xmax;
	}
	if (coord.Y >= cursor_Ymax) {
		coord.Y = cursor_Ymax;
		cursor_Y = cursor_Ymax;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleWindow::cursorMove(int x, int y){
	COORD CRD;
	CRD.X = x + cursor_X;
	CRD.Y = y + cursor_Y;

	cursor_X += x;
	cursor_Y += y;

	if (CRD.X >= cursor_Xmax) {
		CRD.X = cursor_Xmax;
		cursor_X = cursor_Xmax;
	}
	if (CRD.Y >= cursor_Ymax) {
		CRD.Y = cursor_Ymax;
		cursor_Y = cursor_Ymax;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::cursorMove(COORD coord){
	coord.X = coord.X + cursor_X;
	coord.Y = coord.Y + cursor_Y;

	cursor_X = coord.X;
	cursor_Y = coord.Y;

	if (coord.X >= cursor_Xmax) {
		coord.X = cursor_Xmax;
		cursor_X = cursor_Xmax;
	}
	if (coord.Y >= cursor_Ymax) {
		coord.Y = cursor_Ymax;
		cursor_Y = cursor_Ymax;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleWindow::cursorMoveLin(int y){
	COORD CRD;
	CRD.X = cursor_X;
	CRD.Y = y + cursor_Y;

	cursor_Y += y;

	if (CRD.Y >= cursor_Ymax) {
		CRD.Y = cursor_Ymax;
		cursor_Y = cursor_Ymax;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::cursorMoveLin(COORD coord){
	COORD CRD;
	CRD.X = cursor_X;
	CRD.Y = coord.Y + cursor_Y;

	cursor_Y += coord.Y;

	if (CRD.Y >= cursor_Ymax) {
		CRD.Y = cursor_Ymax;
		cursor_Y = cursor_Ymax;
	}
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::cursorMoveCol(int x){
	COORD CRD;
	CRD.X = x + cursor_X;
	CRD.Y = cursor_Y;

	cursor_X += x;

	if (CRD.X >= cursor_Xmax) {
		CRD.X = cursor_Xmax;
		cursor_X = cursor_Xmax;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::cursorMoveCol(COORD coord){
	COORD CRD;
	CRD.X = coord.X + cursor_X;
	CRD.Y = cursor_Y;

	cursor_X += coord.X;

	if (CRD.X >= cursor_Xmax) {
		CRD.X = cursor_Xmax;
		cursor_X = cursor_Xmax;
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CRD);
}

void ConsoleWindow::clearConsole(){
	system("cls");
	ConsoleWindow::cursorDefault();
}



