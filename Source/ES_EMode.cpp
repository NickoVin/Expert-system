//ÃŒƒ”À‹ –≈∆»Ã¿ –¿«–¿¡Œ“◊» ¿
#include "Header.h"
#include "ES_DataBase.h"

extern char exitcode;

void DevMod() {
	MBoard mb; EBlock eb; Processor proc; Fan fn; SSD ssd;
	HDD hdd; VCard vc; Printer prnt; Box box; RAM ram;
	RULE rl; FACT fc;
	char rkey = '+';
	while (rkey != 77) {
		system("cls");
		DevMenu();
		rkey = toupper(_getch());
		switch (rkey) {
		case 49:
			system("cls");
			mb.Add();
			rkey = '+';
			break;
		case 50:
			system("cls");
			eb.Add();
			rkey = '+';
			break;
		case 51:
			system("cls");
			proc.Add();
			rkey = '+';
			break;
		case 52:
			system("cls");
			fn.Add();
			rkey = '+';
			break;
		case 53:
			system("cls");
			hdd.Add();
			rkey = '+';
			break;
		case 54:
			system("cls");
			vc.Add();
			rkey = '+';
			break;
		case 55:
			system("cls");
			prnt.Add();
			rkey = '+';
			break;
		case 56:
			system("cls");
			box.Add();
			rkey = '+';
			break;
		case 57:
			system("cls");
			ram.Add();
			rkey = '+';
			break;
		case 48:
			system("cls");
			ssd.Add();
			rkey = '+';
			break;
////////////////////////////////////////////
		case 80:
			system("cls");
			Display(rl, "           œ–¿¬»ÀŒ        ", "Rules");
			rkey = '+';
			break;
		case 70:
			system("cls");
			Display(fc, "            ‘¿ “          ", "Facts");
			rkey = '+';
			break;
		}
	}
}

template <typename type> void Display(type obj, string name, string file) {
	int id = 0;
	string line = " ";
	ifstream fin;
	fin.open("Data Base\\" + file + ".txt");
	while (!fin.eof()) {
		getline(fin, line);
	}
	int maxID = Str2Int(line);
	fin.close();
	char key = '+';
	while (key != exitcode) {
		DisplayHat(name);
		printf("%32s%i", "ID: ", id); cout << endl;
		obj.Get(id);
		DisplayFooter();
		_getch();
		key = _getch();
		switch (key) {
		case 77:
			if (id != maxID) {
				id++;
			}
			break;
		case 75:
			if (id != 0) {
				id--;
			}
			break;
		}
		system("cls");
		cin.clear();
	}
}