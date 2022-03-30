#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <cmath>
#include <conio.h>
#include <cctype>
#include <windows.h>
using namespace std;

string Int2Str(int);
int Str2Int(string);
struct SBORKA;
void DevMod();
void MainMenu();
void DevMenu();
void Dialog(string);
void Instructions(string);
void Office(SBORKA&);
void Internet(SBORKA&);
void Graphic(SBORKA&);
void Program(SBORKA&);
void Game(SBORKA&);
void GialogMenun();
void DisplayHat(string);
template <typename type> void Display(type, string, string);
void StartDisplay();
void DisplayMenu();
void DisplayFooter();
void Constructor();
void StartMes();