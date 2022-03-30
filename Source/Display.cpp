//������ ������ ���������� � �������������
#include "Header.h"
#include "ES_DataBase.h"

extern char exitcode;
extern SBORKA temp;
extern HANDLE out_handle;
extern COORD crd;
extern SMALL_RECT src;

void StartDisplay() {
	char key = '+';
	MBoard mb; EBlock eb; Processor proc; Fan fn; SSD ssd;
	HDD hdd; VCard vc; Printer prnt; Box box; RAM ram;
	while (key != exitcode) {
		DisplayMenu();
		key = _getch();
		switch (key) {
		case 49:
			system("cls");
			Display(mb, "       ����������� �����  ", "Motherboards");
			key = '+';
			break;
		case 50:
			system("cls");
			Display(eb, "          ���� �������    ", "EnergyBlocks");
			key = '+';
			break;
		case 51:
			system("cls");
			Display(proc, "           ���������      ", "Processors");
			key = '+';
			break;
		case 52:
			system("cls");
			Display(fn, "            �����         ", "Fans");
			key = '+';
			break;
		case 53:
			system("cls");
			Display(hdd, "             HDD          ", "HardDiskDrives");
			key = '+';
			break;
		case 54:
			system("cls");
			Display(vc, "          ����������      ", "VideoCards");
			key = '+';
			break;
		case 55:
			system("cls");
			Display(prnt, "        ������� � ���     ", "Printers");
			key = '+';
			break;
		case 56:
			system("cls");
			Display(box, "            ������        ", "Boxes");
			key = '+';
			break;
		case 57:
			system("cls");
			Display(ram, "       ����������� ������ ", "Mem");
			key = '+';
			break;
		case 48:
			system("cls");
			Display(ssd, "              SSD         ", "SSD");
			key = '+';
			break;
		}
		system("cls");
		cin.clear();
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
		obj.Info();
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