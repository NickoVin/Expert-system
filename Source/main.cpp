//√À¿¬Õ¿ﬂ œ–Œ√–¿ÃÃ¿
#include "Header.h"
#include "ES_DataBase.h"
extern char exitcode;
extern char readkey;
extern string password;
extern string label;


int main() {

	setlocale(LC_ALL, "rus");
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { 65, 40 };
	SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);

	StartMes();

	while (readkey != exitcode) {
		system("cls");
		MainMenu();
		readkey = toupper(_getch());
		switch (readkey) {
		case 68:
			system("cls");
			cin.clear();
			cout << "¬‚Â‰ËÚÂ Ô‡ÓÎ¸: ";
			cin >> label;
			cout << endl;
			if (label == password) {
				system("cls");
				WARNING();
				system("cls");
				DevMod();
			}
			else {
				cout << "¬ ƒŒ—“”œ≈ Œ“ ¿«¿ÕŒ\n\nÌ‡ÊÏËÚÂ Î˛·Û˛ ÍÌÓÔÍÛ ‰Îˇ ÔÓ‰ÓÎÊÂÌËˇ";
				_getch();
			}
			break;
		case 83:
			cin.clear();
			system("cls");
			GialogMenun();
			system("cls");
			Dialog("–‡·ÓÚ‡");
			break;
		case 86:
			cin.clear();
			system("cls");
			StartDisplay();
			break;
		case 81:
			cin.clear();
			system("cls");
			Constructor();
			break;
		}
	}
	return 0;
}