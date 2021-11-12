#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
#include <sstream>

class ConsoleWindow
{

public:
	
	/// <summary>
	/// /!\ Defini la taille maximal da la console de X colonne et Y ligne, le curseur ne poura pas depasse la limite.
	/// Si l'envoi de caractère depase les limite de Y, la ligne 0 sera supprime et tout sera deplace de -1 Y.  
	/// </summary>
	ConsoleWindow(int X, int Y);

	/// Retourne une struct avec les coordonne du curseur.
	COORD GetCursorPosition();

	/// Defini la taille da la console de X colonne et Y ligne.
	void SetSizeConsoleWindow(int X, int Y);

	/// Fait deplace le cureur avec l'ecriture du "cout".
	void cursorCout(std::string text);
	void cursorCout(int i);
	void cursorCout(long int i);
	void cursorCout(double i, int precision = 12 );

	/// Deplace le curseur en [ X = 0 ; Y = 0] 
	void cursorDefault();

	/// Deplace le curseur en [ X = 0 ; Y = max ]
	void cursorDefaultDown();

	/// Deplace le curseur a la position demande, ne peux pas depasse les limite de la console 
	void cursorToMove(int x, int y);
	void cursorToMove(COORD coord);

	/// Deplace le curseur de X et de Y depuis sa position actuelle, ne peux pas depasse les limite de la console   
	void cursorMove(int x, int y);
	void cursorMove(COORD coord);

	/// Deplace le curseur de Y depuis sa position actuelle, ne peux pas depasse les limite de la console  
	void cursorMoveLin(int y);
	void cursorMoveLin(COORD coord);

	/// Deplace le curseur de X depuis sa position actuelle, ne peux pas depasse les limite de la console  
	void cursorMoveCol(int x);
	void cursorMoveCol(COORD coord);

	/// Clear la console 
	void clearConsole();
	
private:

	int cursor_Y = 0;
	int cursor_X = 0;
	int cursor_Ymax;
	int cursor_Xmax;

};

