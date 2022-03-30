//МОДУЛЬ ВЕДЕНИЯ ДИАЛОГА
#include "Header.h"
#include "ES_DataBase.h"

extern SBORKA temp;

void Dialog(string name) {
	FACT fact;
	char answer = '/';
	if (name == "Стоимость") {
		fact.Set(name);
		cout << fact.q << endl;
		int cost = 0;
		while (cost < 1) {
			cout << fact.i << "\n" << "> ";
			cin >> cost;
			if (cost < 1) {
				cout << "ERROR: Некорректный ввод\n> ";
				cost = 0;
			}
			else {
				temp.Budjet = cost;
			}
		}
	}
	else {
		fact.Set(name);
		cout << fact.q << endl;
		cout << "[ ";
		for (int i = 0; i < fact.list.size(); i++) {
			cout << i+1 << "." << fact.list[i] << " ";
		}
		cout << "]" << endl;
		cout << "> ";
		while ((int(answer)-48 <= 0) || (int(answer)-48 > fact.list.size())) {
			answer = toupper(_getch());
			cout << answer << endl;
			if ((int(answer)-48 < 1) || (int(answer)-48 > fact.list.size())) {
				if (answer == 'I') {
					cout << fact.i << endl << "> ";
				}
				else {
					cout << "ERROR: Некорректный ввод\n> ";
					answer = '/';
				}
			}
			else {
				RULE rule;
				int index = int(answer) - 49;
				rule.Set(fact.list[index]);
				cout << endl;
				Instructions(rule.to);
			}
		}
	}
}