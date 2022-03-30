#include "ES_DataBase.h"
#include "Header.h"

extern SBORKA temp;
extern SBORKA production;

////////////////////////////////////////////////////////////////////////////////////////////////
//            ITEMS           //////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

ifstream Items::EDIT(string file, int id) {
	//считывающая строка
	string line = " ";
	//создание объекта файла для чтения
	ifstream fin;
	//строка для поиска ID
	string id_line = "#";

	//Устанавливаем нужный нам ID в строке поиска ID
	id_line += Int2Str(id);
	fin.open("Data Base\\" + file + ".txt");

	//Ищем нужный ID и...
	while (line != (id_line)) {
		getline(fin, line);
	}

	return fin;
}

int Items::GETID(string file) {
	string line;
	ifstream fin;
	fin.open("Data Base\\" + file + ".txt");
	while (!fin.eof()) {
		getline(fin, line);
	}
	int id = Str2Int(line);
	fin.close();

	id++;
	return id;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//     МАТЕРИНСКАЯ  ПЛАТА     //////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void MBoard::Get(int id) {
	string line;
	ifstream fin = Items::EDIT("Motherboards", id);
	//...и записываем в объект Processor данные процессора с текущим ID
	for (int i = 0; i < 10; i++) {
		getline(fin, line);
		switch (i) {
		case 0:
			this->SetModel(line);
			break;
		case 1:
			this->FormFactor = line;
			break;
		case 2:
			this->Soket = line;
			break;
		case 3:
			this->Chipset = line;
			break;
		case 4:
			this->MemType = line;
			break;
		case 5:
			this->MemFF = line;
			break;
		case 6:
			this->MemSlots = Str2Int(line);
			break;
		case 7:
			this->MemFreq = Str2Int(line);
			break;
		case 8:
			this->PCI_Ex16 = Str2Int(line);;
			break;
		case 9:
			this->SetCost(Str2Int(line));
			break;
		}
	}
	fin.close();
}

void MBoard::Add() {
	string line;
	ofstream fout;
	fout.open("Data Base\\Motherboards.txt", ios_base::app);
	int id = GETID("Motherboards");
	fout << "\n\n#" << id << '\n';
	getline(cin, line);
	cout << "Модель: "; getline(cin, line); fout << line << '\n';
	cout << "Форм-фактор: "; getline(cin, line); fout << line << '\n';
	cout << "Сокет: "; getline(cin, line); fout << line << '\n';
	cout << "Чипсет: "; getline(cin, line); fout << line << '\n';
	cout << "Тип памяти: "; getline(cin, line); fout << line << '\n';
	cout << "Форм-фактор памяти: "; getline(cin, line); fout << line << '\n';
	cout << "Кол-во слотов памяти: "; getline(cin, line); fout << line << '\n';
	cout << "Максимальная частота памяти (МГц): "; getline(cin, line); fout << line << '\n';
	cout << "Кол-во слотов PCI-E x16: "; getline(cin, line); fout << line << '\n';
	cout << "Цена (Руб.): "; getline(cin, line); fout << line << '\n';
	fout << "*********************************\n" << id;

	fout.close();
}

void MBoard::Info() {
	cout << "Модель: " << this->GetModel() << endl;
	cout << "Форм-фактор: " << this->FormFactor << endl;
	cout << "Сокет: " << this->Soket << endl;
	cout << "Чипсет: " << this->Chipset << endl;
	cout << "Тип памяти: " << this->MemType << endl;
	cout << "Форм-фактор памяти: " << this->MemFF << endl;
	cout << "Кол-во слотов памяти: " << this->MemSlots << endl;
	cout << "Максимальная частота памяти: " << this->MemFreq << " МГц" << endl;
	cout << "Кол-во слотов PCI-E x16: " << this->PCI_Ex16 << endl;
	cout << "Цена: " << this->GetCost() << " Руб." << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//        БЛОКИ ПИТАНИЯ       //////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

void EBlock::Get(int id) {
	string line;
	ifstream fin = Items::EDIT("EnergyBlocks", id);
	//...и записываем в объект Processor данные процессора с текущим ID
	for (int i = 0; i < 9; i++) {
		getline(fin, line);
		switch (i) {
		case 0:
			this->SetModel(line);
			break;
		case 1:
			this->FormFactor = line;
			break;
		case 2:
			this->Sertif = line;
			break;
		case 3:
			this->Power = Str2Int(line);
			break;
		case 4:
			this->MBPower = line;
			break;
		case 5:
			this->VCPower = line;
			break;
		case 6:
			this->pin_SATA = Str2Int(line);
			break;
		case 7:
			this->CSystem = line;
			break;
		case 8:
			this->SetCost(Str2Int(line));
			break;
		}
	}
	fin.close();
}

void EBlock::Add() {
	string line;
	ofstream fout;
	fout.open("Data Base\\EnergyBlocks.txt", ios_base::app);
	int id = GETID("EnergyBlocks");

	fout << "\n\n#" << id << '\n';
	getline(cin, line);
	cout << "Модель: "; getline(cin, line); fout << line << '\n';
	cout << "Форм-фактор: "; getline(cin, line); fout << line << '\n';
	cout << "Сертификат: "; getline(cin, line); fout << line << '\n';
	cout << "Мощность (Вт): "; getline(cin, line); fout << line << '\n';
	cout << "Разъёмы для питания процессора: "; getline(cin, line); fout << line << '\n';
	cout << "Разъёмы для питания видеокарты: "; getline(cin, line); fout << line << '\n';
	cout << "Количество разъемов 15-pin SATA: "; getline(cin, line); fout << line << '\n';
	cout << "Система охлаждения: "; getline(cin, line); fout << line << '\n';
	cout << "Цена (Руб.): "; getline(cin, line); fout << line << '\n';
	fout << "*********************************\n" << id;

	fout.close();
}

void EBlock::Info() {
	cout << "Модель: " << this->GetModel() << endl;
	cout << "Форм-фактор: " << this->FormFactor << endl;
	cout << "Сертификат: " << this->Sertif << endl;
	cout << "Мощность: " << this->Power << " Вт" << endl;
	cout << "Разъёмы для питания процессора: " << this->MBPower << endl;
	cout << "Разъёмы для питания видеокарты: " << this->VCPower << endl;
	cout << "Количество разъемов 15-pin SATA: " << this->pin_SATA << endl;
	cout << "Система охлаждения: " << this->CSystem << endl;
	cout << "Цена: " << this->GetCost() << " Руб." << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//          ПРОЦЕССОР          //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void Processor::Get(int id) {
	string line;
	ifstream fin = Items::EDIT("Processors", id);
	//...и записываем в объект Processor данные процессора с текущим ID
	for (int i = 0; i < 9; i++) {
		getline(fin, line);
		switch (i) {
		case 0:
			this->SetModel(line);
			break;
		case 1:
			this->Soket = line;
			break;
		case 2:
			this->Core = line;
			break;
		case 3:
			this->Core_Num = Str2Int(line);
			break;
		case 4:
			this->Cache = Str2Int(line);
			break;
		case 5:
			this->Flows_Num = Str2Int(line);
			break;
		case 6:
			this->Freq = Str2Int(line);
			break;
		case 7:
			this->MemType = line;
			break;
		case 8:
			this->SetCost(Str2Int(line));
			break;
		}
	}
	fin.close();
}

void Processor::Add() {
	string line;
	ofstream fout;
	fout.open("Data Base\\Processors.txt", ios_base::app);
	int id = GETID("Processors");
	fout << "\n\n#" << id << '\n';
	getline(cin, line);
	cout << "Модель: "; getline(cin, line); fout << line << '\n';
	cout << "Сокет: "; getline(cin, line); fout << line << '\n';
	cout << "Ядро: "; getline(cin, line); fout << line << '\n';
	cout << "Кол-во ядер: "; getline(cin, line); fout << line << '\n';
	cout << "Кэш (МБ): "; getline(cin, line); fout << line << '\n';
	cout << "Кол-во потоков: "; getline(cin, line); fout << line << '\n';
	cout << "Тактовая частота (МГц): "; getline(cin, line); fout << line << '\n';
	cout << "Тип памяти: "; getline(cin, line); fout << line << '\n';
	cout << "Цена (Руб.): "; getline(cin, line); fout << line << '\n';
	fout << "*********************************\n" << id;

	fout.close();
}

void Processor::Info() {
	cout << "Модель: " << this->GetModel() << endl;
	cout << "Сокет: " << this->Soket << endl;
	cout << "Ядро: " << this->Core << endl;
	cout << "Кол-во ядер: " << this->Core_Num << endl;
	cout << "КЭШ: " << this->Cache << " МБ" << endl;
	cout << "Кол-во потоков: " << this->Flows_Num << endl;
	cout << "Тактовая частота процессора: " << this->Freq << " МГц" << endl;
	cout << "Тим памяти: " << this->MemType << endl;
	cout << "Цена: " << this->GetCost() << " Руб." << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////    
//          ВЕНТИЛЯТОРЫ        //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void Fan::Get(int id) {
	string line;
	ifstream fin = Items::EDIT("Fans", id);
	//...и записываем в объект Processor данные процессора с текущим ID
	for (int i = 0; i < 5; i++) {
		getline(fin, line);
		switch (i) {
		case 0:
			this->SetModel(line);
			break;
		case 1:
			this->Power = Str2Int(line);
			break;
		case 2:
			this->VPower = line;
			break;
		case 3:
			this->Speed = Str2Int(line);
			break;
		case 4:
			this->SetCost(Str2Int(line));
			break;
		}
	}
	fin.close();
}

void Fan::Add() {
	string line;
	ofstream fout;
	fout.open("Data Base\\Fans.txt", ios_base::app);
	int id = GETID("Fans");
	fout << "\n\n#" << id << '\n';
	getline(cin, line);
	cout << "Модель: "; getline(cin, line); fout << line << '\n';
	cout << "Мощность (Вт): "; getline(cin, line); fout << line << '\n';
	cout << "Разъём для подкл-я вентиляторов: "; getline(cin, line); fout << line << '\n';
	cout << "Максимальная скорость вращения (об/мин): "; getline(cin, line); fout << line << '\n';
	cout << "Цена (Руб.): "; getline(cin, line); fout << line << '\n';
	fout << "*********************************\n" << id;

	fout.close();
}

void Fan::Info() {
	cout << "Модель: " << this->GetModel() << endl;
	cout << "Мощность: " << this->Power << "Вт" << endl;
	cout << "Разъём для подкл-я вентиляторов: " << this->VPower << endl;
	cout << "Максимальная скорость вращения: " << this->Speed << " об/мин" << endl;
	cout << "Цена: " << this->GetCost() << " Руб." << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////    
//          ОПЕРАТИВНАЯ        //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void RAM::Get(int id) {
	string line;
	ifstream fin = Items::EDIT("Mem", id);
	//...и записываем в объект Processor данные процессора с текущим ID
	for (int i = 0; i < 6; i++) {
		getline(fin, line);
		switch (i) {
		case 0:
			this->SetModel(line);
			break;
		case 1:
			this->MemType = line;
			break;
		case 2:
			this->FormFactor = line;
			break;
		case 3:
			this->Capacity = Str2Int(line);
			break;
		case 4:
			this->Freq = Str2Int(line);
			break;
		case 5:
			this->SetCost(Str2Int(line));
			break;
		}
	}
	fin.close();
}

void RAM::Add() {
	string line;
	ofstream fout;
	fout.open("Data Base\\Mem.txt", ios_base::app);
	int id = GETID("Mem");
	fout << "\n\n#" << id << '\n';
	getline(cin, line);
	cout << "Модель: "; getline(cin, line); fout << line << '\n';
	cout << "Тип памяти: "; getline(cin, line); fout << line << '\n';
	cout << "Форм-фактор: "; getline(cin, line); fout << line << '\n';
	cout << "Объём памяти (ГБ): "; getline(cin, line); fout << line << '\n';
	cout << "Частота памяти (МГц): "; getline(cin, line); fout << line << '\n';
	cout << "Цена (Руб.): "; getline(cin, line); fout << line << '\n';
	fout << "*********************************\n" << id;

	fout.close();
}

void RAM::Info() {
	cout << "Модель: " << this->GetModel() << endl;
	cout << "Тип памяти: " << this->MemType << endl;
	cout << "Форм-фактор: " << this->FormFactor<< endl;
	cout << "Объём памяти: " << this->Capacity << " ГБ" << endl;
	cout << "Частота памяти: " << this->Freq << " МГц" << endl;
	cout << "Цена: " << this->GetCost() << " Руб." << endl;
}


/////////////////////////////////////////////////////////////////////////////////////////////////
//         ЖЁСТКИЙ ДИСК        //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void HDD::Get(int id) {
	string line;
	ifstream fin = Items::EDIT("HardDiskDrives", id);
	//...и записываем в объект Processor данные процессора с текущим ID
	for (int i = 0; i < 7; i++) {
		getline(fin, line);
		switch (i) {
		case 0:
			this->SetModel(line);
			break;
		case 1:
			this->Capacity = Str2Int(line);
			break;
		case 2:
			this->RSpeed = Str2Int(line);
			break;
		case 3:
			this->DSpeed = Str2Int(line);
			break;
		case 4:
			this->Cache = Str2Int(line);
			break;
		case 5:
			this->Interface = line;
			break;
		case 6:
			this->SetCost(Str2Int(line));
			break;
		}
	}
	fin.close();
}

void HDD::Add() {
	string line;
	ofstream fout;
	fout.open("Data Base\\HardDiskDrives.txt", ios_base::app);
	int id = GETID("HardDiskDrives");

	fout << "\n\n#" << id << '\n';
	getline(cin, line);
	cout << "Модель: "; getline(cin, line); fout << line << '\n';
	cout << "Объём памяти (ГБ): "; getline(cin, line); fout << line << '\n';
	cout << "Скорость вращения шпинделя (об/мин): "; getline(cin, line); fout << line << '\n';
	cout << "Максимальная скорость передачи данных (Мбайт/с): "; getline(cin, line); fout << line << '\n';
	cout << "Кэш (МБ): "; getline(cin, line); fout << line << '\n';
	cout << "Интерфейс: "; getline(cin, line); fout << line << '\n';
	cout << "Цена (Руб.): "; getline(cin, line); fout << line << '\n';
	fout << "*********************************\n" << id;

	fout.close();
}

void HDD::Info() {
	cout << "Модель: " << this->GetModel() << endl;
	cout << "Объём памяти: " << this->Capacity << " ГБ" << endl;
	cout << "Скорость вращения шпинделя: " << this->RSpeed << " об/мин" << endl;
	cout << "Максимальная скорость передачи данных: " << this->DSpeed << " Мбайт/с" << endl;
	cout << "Кэш: " << this->Cache << " МБ" << endl;
	cout << "Интерфейс: " << this->Interface << endl;
	cout << "Цена: " << this->GetCost() << " Руб." << endl;
}

void SSD::Get(int id) {
	string line;
	ifstream fin = Items::EDIT("SSD", id);
	//...и записываем в объект Processor данные процессора с текущим ID
	for (int i = 0; i < 6; i++) {
		getline(fin, line);
		switch (i) {
		case 0:
			this->SetModel(line);
			break;
		case 1:
			this->Capacity = Str2Int(line);
			break;
		case 2:
			this->TypeChipMem = line;
			break;
		case 3:
			this->Speed = Str2Int(line);
			break;
		case 4:
			this->Interface = line;
			break;
		case 5:
			this->SetCost(Str2Int(line));
			break;
		}
	}
	fin.close();
}

void SSD::Add() {
	string line;
	ofstream fout;
	fout.open("Data Base\\SSD.txt", ios_base::app);
	int id = GETID("SSD");

	fout << "\n\n#" << id << '\n';
	getline(cin, line);
	cout << "Модель: "; getline(cin, line); fout << line << '\n';
	cout << "Объём памяти (ГБ): "; getline(cin, line); fout << line << '\n';
	cout << "Тип памяти: "; getline(cin, line); fout << line << '\n';
	cout << "Максимальная скорость передачи данных (Мбайт/с): "; getline(cin, line); fout << line << '\n';
	cout << "Интерфейс: "; getline(cin, line); fout << line << '\n';
	cout << "Цена (Руб.): "; getline(cin, line); fout << line << '\n';
	fout << "*********************************\n" << id;

	fout.close();
}

void SSD::Info() {
	cout << "Модель: " << this->GetModel() << endl;
	cout << "Объём памяти: " << this->Capacity << " ГБ" << endl;
	cout << "Тип памяти: " << this->TypeChipMem << " ГБ" << endl;
	cout << "Максимальная скорость передачи данных: " << this->Speed << " Мбайт/с" << endl;
	cout << "Интерфейс: " << this->Interface << endl;
	cout << "Цена: " << this->GetCost() << " Руб." << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//         ВИДЕОКАРТА          //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void VCard::Get(int id) {
	string line;
	ifstream fin = Items::EDIT("VideoCards", id);
	//...и записываем в объект Processor данные процессора с текущим ID
	for (int i = 0; i < 10; i++) {
		getline(fin, line);
		switch (i) {
		case 0:
			this->SetModel(line);
			break;
		case 1:
			this->GPU = line;
			break;
		case 2:
			this->GPUFreq = Str2Int(line);
			break;
		case 3:
			this->Capacity = Str2Int(line);
			break;
		case 4:
			this->MemType = line;
			break;
		case 5:
			this->MemFreq = Str2Int(line);
			break;
		case 6:
			this->Pitanie = Str2Int(line);
			break;
		case 7:
			this->PConsuming = Str2Int(line);
			break;
		case 8:
			this->PB = Str2Int(line);
			break;
		case 9:
			this->SetCost(Str2Int(line));
			break;
		}
	}
	fin.close();
}

void VCard::Add() {
	string line;
	ofstream fout;
	fout.open("Data Base\\VideoCards.txt", ios_base::app);
	int id = GETID("VideoCards");

	fout << "\n\n#" << id << '\n';
	getline(cin, line);
	cout << "Модель: "; getline(cin, line); fout << line << '\n';
	cout << "Графический процессор: "; getline(cin, line); fout << line << '\n';
	cout << "Частота графического процессора (МГц): "; getline(cin, line); fout << line << '\n';
	cout << "Объём видеопамяти (ГБ): "; getline(cin, line); fout << line << '\n';
	cout << "Тип памяти: "; getline(cin, line); fout << line << '\n';
	cout << "Частота памяти (МГц): "; getline(cin, line); fout << line << '\n';
	cout << "Питание (pin): "; getline(cin, line); fout << line << '\n';
	cout << "Потребление энергии (Вт): "; getline(cin, line); fout << line << '\n';
	cout << "Рекомендуемый блок питания (Вт): "; getline(cin, line); fout << line << '\n';
	cout << "Цена (Руб.): "; getline(cin, line); fout << line << '\n';
	fout << "*********************************\n" << id;

	fout.close();
}

void VCard::Info() {
	cout << "Модель: " << this->GetModel() << endl;
	cout << "Графический процессор: " << this->GPU << endl;
	cout << "Частота графического процессора: " << this->GPUFreq << " МГц" << endl;
	cout << "Объём видеопамяти: " << this->Capacity << "ГБ" << endl;
	cout << "Тип памяти: " << this->MemType << endl;
	cout << "Частота памяти: " << this->MemFreq << " МГц" << endl;
	cout << "Питание: " << this->Pitanie << " pin"<< endl;
	cout << "Потребление энергии: " << this->PConsuming << " Вт" << endl;
	cout << "Рекомендуемый блок питания: " << this->PB << " Вт" << endl;
	cout << "Цена: " << this->GetCost() << " Руб." << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//           ПРИНТЕР           //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void Printer::Get(int id) {
	string line;
	ifstream fin = Items::EDIT("Printers", id);
	//...и записываем в объект Processor данные процессора с текущим ID
	for (int i = 0; i < 4; i++) {
		getline(fin, line);
		switch (i) {
		case 0:
			this->SetModel(line);
			break;
		case 1:
			this->PColor = line;
			break;
		case 2:
			this->Copy = line;
			break;
		case 3:
			this->SetCost(Str2Int(line));
			break;
		}
	}
	fin.close();
}

void Printer::Add() {
	string line;
	ofstream fout;
	fout.open("Data Base\\Printers.txt", ios_base::app);
	int id = GETID("Printers");

	fout << "\n\n#" << id << '\n';
	getline(cin, line);
	cout << "Модель: "; getline(cin, line); fout << line << '\n';
	cout << "Цвет печати (RB | Multicolor): "; getline(cin, line); fout << line << '\n';
	cout << "Ксерокопирование (Yes | No): "; getline(cin, line); fout << line << '\n';
	cout << "Цена (Руб.): "; getline(cin, line); fout << line << '\n';
	fout << "*********************************\n" << id;

	fout.close();
}

void Printer::Info() {
	cout << "Модель: " << this->GetModel() << endl;
	cout << "Цвет печати: " << this->PColor << endl;
	cout << "Ксерокопирование: " << this->Copy << endl;
	cout << "Цена: " << this->GetCost() << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//           КОРПУС           ///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void Box::Get(int id) {
	string line;
	ifstream fin = Items::EDIT("Boxes", id);
	//...и записываем в объект Processor данные процессора с текущим ID
	for (int i = 0; i < 8; i++) {
		getline(fin, line);
		switch (i) {
		case 0:
			this->SetModel(line);
			break;
		case 1:
			this->MBFF.fst = line;
			break;
		case 2:
			this->MBFF.sec = line;
			break;
		case 3:
			this->MBFF.third = line;
			break;
		case 4:
			this->MBFF.fourth = line;
			break;
		case 5:
			this->MBFF.fifth = line;
			break;
		case 6:
			this->PBFF = line;
			break;
		case 7:
			this->SetCost(Str2Int(line));
			break;
		}
	}
	fin.close();
}

void Box::Add() {
	string line;
	ofstream fout;
	fout.open("Data Base\\Boxes.txt", ios_base::app);
	int id = GETID("Boxes");

	fout << "\n\n#" << id << '\n';
	getline(cin, line);
	cout << "Модель: "; getline(cin, line); fout << line << '\n';
	cout << "Форм-фактор совместимых плат (Необходимо ввести 5 названий): \n          Первое: "; getline(cin, line); fout << line << '\n';
	cout << "          Второе: "; getline(cin, line); fout << line << '\n';
	cout << "          Третье: "; getline(cin, line); fout << line << '\n';
	cout << "          Четвёртое: "; getline(cin, line); fout << line << '\n';
	cout << "          Пятое: "; getline(cin, line); fout << line << '\n';
	cout << "Форм-фактор совместимых блоков питания: "; getline(cin, line); fout << line << '\n';
	cout << "Цена (Руб.): "; getline(cin, line); fout << line << '\n';
	fout << "*********************************\n" << id;

	fout.close();
}

void Box::Info() {
	cout << "Модель: " << this->GetModel() << endl;
	cout << "Форм-фактор совместимых плат: " << this->MBFF.fst << ", " << this->MBFF.sec << ", " << this->MBFF.third << ", " << this->MBFF.fourth << ", " << this->MBFF.fifth << endl;
	cout << "Форм-фактор совместимых блоков питания: " << this->PBFF << endl;
	cout << "Цена: " << this->GetCost() << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//   МЕТОДЫ ПРЕОБРАЗОВАНИЯ     //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

int Str2Int(string obj) {
	int receiver = 0;
	stack <char> buffer;
	int IntBuf = 0;
	int Step = 0;
	int Result = 0;
	int length = obj.length();

	for (int i = 0; i < length; i++) {
		buffer.push(obj[i]);
	}

	while (!buffer.empty()) {
		IntBuf = (int(buffer.top()) - 48);
		buffer.pop();
		Result += IntBuf * pow(10, Step);
		Step++;
	}

	return Result;
}

string Int2Str(int obj) {
	stack <char> buffer;
	string receiver;
	int ost;
	if (obj != 0) {
		while (obj != 0) {
			ost = obj % 10;
			obj /= 10;
			buffer.push(char(ost) + 48);
		}
	}
	else {
		buffer.push(char(0) + 48);
	}
	while (!buffer.empty()) {
		receiver += buffer.top();
		buffer.pop();
	}
	return receiver;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//      ЗНАНИЯ И ПРАВИЛА      ///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void FACT::Set(string n) {
	int schk = 0;
	//считывающая строка
	string line = " ";
	//создание объекта файла для чтения
	ifstream fin;

	fin.open("Data Base\\Facts.txt");

	//Ищем нужный ID и...
	while (line != n) {
		while (line[0] != 'N') {
			getline(fin, line);
		}
		getline(fin, line);
	}
	name = line;
	while (line != "**************************") {
		getline(fin, line);
		switch (line[0]) {
		case '?':
			getline(fin, line);
			q = line;
			break;
		case 'i':
			getline(fin, line);
			i = line;
			break;
		case '-':
			getline(fin, line);
			list.push_back(line);
			break;
		}
	}
	fin.close();
}

void RULE::Get(int id) {
	string line = " ";
	ifstream fin;
	string id_line = "#";

	id_line += Int2Str(id);
	fin.open("Data Base\\Rules.txt");

	while (line != (id_line)) {
		getline(fin, line);
	}
	for (int i = 0; i < 4; i++) {
		getline(fin, line);
		switch (i) {
		case 1:
			this->from = line;
			break;
		case 3:
			this->to = line;
			break;
		}
	}
	fin.close();
	this->Info();
}

void RULE::Set(string name) {
	//считывающая строка
	string line = "+";
	//создание объекта файла для чтения
	ifstream fin;
	bool flag = true;

	fin.open("Data Base\\Rules.txt");

	//Ищем нужный ID и...
	while (line != name && flag) {
		while (line != "from") {
			getline(fin, line);
			if (fin.eof()) {
				flag = false;
				break;
			}
		}
		getline(fin, line);
	}
	if (flag) {
		from = line;
		getline(fin, line);
		if (line == "to") {
			getline(fin, line);
			to = line;
		}
		else {
			cout << "Ошибка чтения правила!" << endl;
		}
	}
	else {
		cout << "ERROR: Правило не найдено\n";
	}
	fin.close();
}

void RULE::Info() {
	if (from.size() > 0) {
		cout << "Правило: Если выбрано \"" << from << "\", то переход в \"" << to << "\"\n";
	}
	else {
		cout << "ERROR: Правило не найдено\n";
	}
}

void FACT::Info() {
	printf("%12s", "Название: "); cout << name << endl;
	printf("%12s", "Вопрос: "); cout << q << endl;
	printf("%12s", "Пояснение: "); cout << i << endl;
	printf("%12s", "Варианты: "); cout << endl;
	cout << "[ ";
	for (int i = 0; i < list.size(); i++) {
		cout << i << "." << list[i] << " ";
	}
	cout << "]\n";
}

void FACT::Get(int id) {
	string line = " ";
	ifstream fin;
	string id_line = "#";

	id_line += Int2Str(id);
	fin.open("Data Base\\Facts.txt");

	while (line != (id_line)) {
		getline(fin, line);
	}
	int i = 0;
	while (line != "**************************") {
		getline(fin, line);

		switch (i) {
		case 1:
			this->name = line;
			break;
		case 3:
			this->q = line;
			break;
		case 5:
			this->i = line;
			break;
		case 7:
			this->list.push_back(line);
			break;
		case 9:
			this->list.push_back(line);
			break;
		case 11:
			this->list.push_back(line);
			break;
		case 13:
			this->list.push_back(line);
			break;
		case 15:
			this->list.push_back(line);
			break;
		}
		i++;
	}
	fin.close();
	this->Info();
	this->list.clear();
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//           СПИСКИ           ///////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

vector <MBoard> GetMBList(MBoard setup) {
	MBoard mb;
	string line = " ";
	ifstream fin;
	int id = 0;
	fin.open("Data Base\\Motherboards.txt");
	vector <MBoard> list;
	while (!fin.eof()) {
		getline(fin, line);
	}
	fin.close();
	int maxID = Str2Int(line);
	while (id <= maxID) {
		mb.Get(id);
		bool fact1 = (mb.MemType == setup.MemType);
		bool fact2 = (mb.MemSlots == setup.MemSlots);
		bool fact3 = (mb.PCI_Ex16 == setup.PCI_Ex16);
		int mCost = mb.GetCost(); int sCost = setup.GetCost();
		bool COST = ((mCost > sCost-1000)&&(mCost < sCost));
		if (fact1 && fact2 && fact3 && COST) {
			list.push_back(mb);
		}
		id++;
	}
	return list;
}

vector <EBlock> GetEBList(EBlock setup) {
	EBlock eb;
	string line = " ";
	ifstream fin;
	int id = 0;
	fin.open("Data Base\\EnergyBlocks.txt");
	vector <EBlock> list;
	while (!fin.eof()) {
		getline(fin, line);
	}
	fin.close();
	int maxID = Str2Int(line);
	while (id <= maxID) {
		eb.Get(id);
		bool fact1 = (eb.Power >= setup.Power && eb.Power <= setup.Power+100);
		if (fact1) {
			list.push_back(eb);
		}
		id++;
	}
	return list;
}

vector <Processor> GetProcList(Processor setup) {
	Processor obj;
	string line = " ";
	ifstream fin;
	int id = 0;
	fin.open("Data Base\\Processors.txt");
	vector <Processor> list;
	while (!fin.eof()) {
		getline(fin, line);
	}
	fin.close();
	int maxID = Str2Int(line);
	while (id <= maxID) {
		obj.Get(id);
		bool fact1 = (obj.Core_Num >= setup.Core_Num);
		bool fact2 = (obj.Cache >= setup.Cache);
		bool fact3 = (obj.Flows_Num >= setup.Flows_Num);
		bool fact4 = (obj.Soket == temp.mb.Soket);
		bool fact5 = (obj.MemType == temp.mb.MemType);
		int mCost = obj.GetCost(); int sCost = setup.GetCost();
		bool COST = (mCost < sCost);
		if (fact1 && fact2 && fact3 && fact4 && COST) {
			list.push_back(obj);
		}
		id++;
	}
	return list;
}

vector <Fan> GetFanList(Fan setup) {
	Fan obj;
	string line = " ";
	ifstream fin;
	int id = 0;
	fin.open("Data Base\\Fans.txt");
	vector <Fan> list;
	while (!fin.eof()) {
		getline(fin, line);
	}
	fin.close();
	int maxID = Str2Int(line);
	while (id <= maxID) {
		obj.Get(id);
		int mCost = obj.GetCost(); int sCost = setup.GetCost();
		bool COST = ((mCost >= sCost - 1000) && (mCost <= sCost));
		if (COST) {
			list.push_back(obj);
		}
		id++;
	}
	return list;
}

vector <RAM> GetRAMList(RAM setup) {
	RAM obj;
	string line = " ";
	ifstream fin;
	int id = 0;
	fin.open("Data Base\\Mem.txt");
	vector <RAM> list;
	while (!fin.eof()) {
		getline(fin, line);
	}
	fin.close();
	int maxID = Str2Int(line);
	while (id <= maxID) {
		obj.Get(id);
		bool fact1 = (obj.Capacity >= setup.Capacity);
		bool fact2 = (obj.Freq >= setup.Freq);
		bool fact3 = (obj.FormFactor == temp.mb.MemFF);
		bool fact4 = (obj.MemType == temp.mb.MemType);
		int mCost = obj.GetCost(); int sCost = setup.GetCost();
		bool COST = (mCost <= sCost);
		if (fact1 && fact2 && fact3 && fact4 && COST) {
			list.push_back(obj);
		}
		id++;
	}
	return list;
}

vector <HDD> GetHDDList(HDD setup) {
	HDD obj;
	string line = " ";
	ifstream fin;
	int id = 0;
	fin.open("Data Base\\HardDiskDrives.txt");
	vector <HDD> list;
	while (!fin.eof()) {
		getline(fin, line);
	}
	fin.close();
	int maxID = Str2Int(line);
	while (id <= maxID) {
		obj.Get(id);
		bool fact1 = (obj.Capacity >= setup.Capacity);
		int mCost = obj.GetCost(); int sCost = setup.GetCost();
		bool COST = (mCost < sCost);
		if (fact1 && COST) {
			list.push_back(obj);
		}
		id++;
	}
	return list;
}

vector <SSD> GetSSDList(SSD setup) {
	SSD obj;
	string line = " ";
	ifstream fin;
	int id = 0;
	fin.open("Data Base\\SSD.txt");
	vector <SSD> list;
	while (!fin.eof()) {
		getline(fin, line);
	}
	fin.close();
	int maxID = Str2Int(line);
	while (id <= maxID) {
		obj.Get(id);
		bool fact1 = (obj.Capacity == setup.Capacity);
		bool fact2 = (obj.TypeChipMem == setup.TypeChipMem);
		int mCost = obj.GetCost(); int sCost = setup.GetCost();
		bool COST = (mCost < sCost);
		if (fact1 && fact2 && COST) {
			list.push_back(obj);
		}
		id++;
	}
	return list;
}

vector <VCard> GetVCardList(VCard setup) {
	VCard obj;
	string line = " ";
	ifstream fin;
	int id = 0;
	fin.open("Data Base\\VideoCards.txt");
	vector <VCard> list;
	while (!fin.eof()) {
		getline(fin, line);
	}
	fin.close();
	int maxID = Str2Int(line);
	while (id <= maxID) {
		obj.Get(id);
		bool fact1 = (obj.Capacity >= setup.Capacity);
		bool fact2 = (obj.GPUFreq >= setup.GPUFreq-200);
		bool fact3 = (obj.PB <= temp.eb.Power);
		bool fact4 = false;
		switch(obj.Pitanie) {
		case 6:
			if (temp.eb.VCPower.size() > 1) {
				if (temp.eb.VCPower[2] == '6') {
					fact4 = true;
				}
				else {
					fact4 = false;
				}
			}
			break;
		case 8:
			if (temp.eb.VCPower.size() > 2) {
				if (temp.eb.VCPower[2] == '6' && temp.eb.VCPower[4] == '2' ) {
					fact4 = true;
				}
				else {
					fact4 = false;
				}
			}
			break;
		case 0:
			fact4 = true;
			break;
		}
		
		int mCost = obj.GetCost(); int sCost = setup.GetCost();
		bool COST = (mCost < sCost);
		if (fact1 && fact2 && fact3 && fact4 && COST) {
			list.push_back(obj);
		}
		id++;
	}
	return list;
}

vector <Printer> GetPRList(Printer setup) {
	Printer mb;
	string line = " ";
	ifstream fin;
	int id = 0;
	fin.open("Data Base\\Printers.txt");
	vector <Printer> list;
	while (!fin.eof()) {
		getline(fin, line);
	}
	fin.close();
	int maxID = Str2Int(line);
	while (id <= maxID) {
		mb.Get(id);
		bool fact1 = (mb.PColor == setup.PColor);
		bool fact2 = (mb.Copy == setup.Copy);
		if (fact1 && fact2) {
			list.push_back(mb);
		}
		id++;
	}
	return list;
}

vector <Box> GetBOXList(Box setup) {
	Box mb;
	string line = " ";
	ifstream fin;
	int id = 0;
	fin.open("Data Base\\Boxes.txt");
	vector <Box> list;
	while (!fin.eof()) {
		getline(fin, line);
	}
	fin.close();
	int maxID = Str2Int(line);
	while (id <= maxID) {
		mb.Get(id);
		bool fact1 = false;
		bool fact2 = (mb.PBFF == temp.eb.FormFactor);
		if (mb.MBFF.fst == temp.mb.FormFactor) {
			fact1 = true;
		}
		else if (mb.MBFF.sec == temp.mb.FormFactor) {
			fact1 = true;
		}
		else if (mb.MBFF.third == temp.mb.FormFactor) {
			fact1 = true;
		}
		else if (mb.MBFF.fourth == temp.mb.FormFactor) {
			fact1 = true;
		}
		else if (mb.MBFF.fifth == temp.mb.FormFactor) {
			fact1 = true;
		}
		int mCost = mb.GetCost(); int sCost = setup.GetCost();
		bool COST = ((mCost > sCost - 1500) && (mCost < sCost));
		if (fact1 && COST) {
			list.push_back(mb);
		}
		id++;
	}
	return list;
}