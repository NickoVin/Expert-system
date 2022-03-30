//������ �������� �������
#include "Header.h"
#include "ES_DataBase.h"

extern SBORKA temp;
extern SBORKA production;
extern SBORKA empt;

//����� ��� ������� ���� ������������
void Instructions(string value) {
	//if ������ switch �.� switch �� ������������ ������

	//����� �������
	if (value == "���������_������") {
		temp.box.SetCost(2000);
	}
	else if (value == "�������_������") {
		temp.box.SetCost(5000);
	}
	else if (value == "medium_capacity") {
		temp.hdd.Capacity = 1024;
		temp.hdd.SetCost(3500);
	}
	else if (value == "hight_capacity") {
		temp.hdd.Capacity = 2048;
		temp.hdd.SetCost(5000);
	}

	//������� �����
	else if (value == "�������_���������_�������") {
		Office(temp);
		Dialog("������");
		Dialog("���������");
		Constructor();
	}
	else if (value == "�������_���������_�_��") {
		temp.prnt.PColor = "RB";
		Dialog("����������");
	}
	else if (value == "�������_���������_�_��") {
		temp.prnt.PColor = "Multicolor";
		Dialog("����������");
	}
	else if (value == "�������_���������_����������") {
		temp.prnt.Copy = "Yes";
		Instructions("�������_���������_�������");
	}

	//�������� �����
	else if (value == "��������_���������_�������") {
		Internet(temp);
		Dialog("������");
		Dialog("���������");
		Constructor();
	}

	//����������� �����
	else if (value == "�����������_���������_�������") {
		Graphic(temp);
		Dialog("������");
		Dialog("������");
		Dialog("���������");
		Constructor();
	}

	//����������� �����
	else if (value == "�����������_���������_�������") {
		Program(temp);
		Dialog("������");
		Dialog("������");
		Dialog("���������");
		Constructor();
	}

	//������� �����
	else if (value == "�������_���������_�������") {
		Game(temp);
		Dialog("������");
		Dialog("���������");
		Constructor();
	}

	//������� �� ������������� �������
	else {
		Dialog(value);
	}
}

void Constructor() {
	int Cost = 0;
	int max = 0;
	vector <MBoard> MB = GetMBList(temp.mb); bool b1 = MB.size() > 0;
	if (b1) {
		if (MB.size() > max) { max = MB.size(); };
		Sort(MB); 
		temp.mb = MB[0];
		Cost += temp.mb.GetCost();
	}

	vector <EBlock> EB = GetEBList(temp.eb); bool b2 = EB.size() > 0;
	if (b2) {
		if (EB.size() > max) { max = EB.size(); };
		Sort(EB);
		temp.eb = EB[0];
		Cost += temp.eb.GetCost();
	}

	vector <Processor> PROC = GetProcList(temp.proc); bool b3 = PROC.size() > 0;
	if (b3) {
		if (PROC.size() > max) { max = PROC.size(); };
		Sort(PROC);
		temp.proc = PROC[0];
		Cost += temp.proc.GetCost();
	}

	vector <Fan> FN = GetFanList(temp.fan); bool b4 = FN.size() > 0;
	if (b4) { 
		if (FN.size() > max) { max = FN.size(); };
		Sort(FN);
		temp.fan = FN[0]; 
		Cost += temp.fan.GetCost();
	}

	vector <RAM> RM = GetRAMList(temp.ram); bool b5 = RM.size() > 0;
	if (b5) { 
		if (RM.size() > max) { max = RM.size(); };
		Sort(RM);
		temp.ram = RM[0]; 
		Cost += temp.ram.GetCost();
	}

	vector <HDD> HD = GetHDDList(temp.hdd); bool b6 = HD.size() > 0;
	if (b6) {
		if (HD.size() > max) { max = HD.size(); };
		Sort(HD); 
		temp.hdd = HD[0]; 
		Cost += temp.hdd.GetCost();
	}

	vector <SSD> SD = GetSSDList(temp.ssd); bool b7 = SD.size() > 0;
	if (b7) {
		if (SD.size() > max) { max = SD.size(); };
		Sort(SD); 
		temp.ssd = SD[0]; 
		Cost += temp.ssd.GetCost(); 
	}

	vector <VCard> VC = GetVCardList(temp.vc); bool b8 = VC.size() > 0;
	if (b8) { 
		if (VC.size() > max) { max = VC.size(); };
		Sort(VC);
		temp.vc = VC[0]; 
		Cost += temp.vc.GetCost();
	}

	vector <Printer> PR = GetPRList(temp.prnt); bool pr = temp.prnt.PColor.size() > 0;
	if (pr) { 
		if (PR.size() > max) { max = PR.size(); };
		Sort(PR);
		temp.prnt = PR[0]; 
		Cost += temp.prnt.GetCost();
	}

	vector <Box> BX = GetBOXList(temp.box); bool b9 = BX.size() > 0;
	if (b9) { 
		if (BX.size() > max) { max = BX.size(); };
		Sort(BX);
		temp.box = BX[0]; 
		Cost += temp.box.GetCost(); 
	}

	system("cls");
	if (Cost > temp.Budjet) {
		cout << "������: ��������� ���� ����� ������������ ��� ������ ������\n����������� ����� ��� ���� ������ = " << Cost << " ���." << "\n\n";
		cout << "          ��� ������ � ���� ������� ����� ������\n";
		_getch();
	}
	else if (!(b1 && b2 && b3 && b4 && b5 && b6 && b7 && b8 && b9)) {
		cout << "������: � ���� ������ �� ������� ���������� �������������\n\n";
		if (b1== 0) { cout << "�� ������: ����\n"; }
		if (b1== 0) { cout << "�� ������: ���� ���.\n"; }
		if (b3== 0) { cout << "�� ������: ����\n"; }
		if (b4== 0) { cout << "�� ������: �����\n"; }
		if (b5== 0) { cout << "�� ������: ����������\n"; }
		if (b6== 0) { cout << "�� ������: ������ ����\n"; }
		if (b7== 0) { cout << "�� ������: ���\n"; }
		if (b8== 0) { cout << "�� ������: ������\n"; }
		if (b9== 0) { cout << "�� ������: ������\n"; }
		cout << "\n          ��� ������ � ���� ������� ����� ������\n";
		_getch();
	}
	else {
		//�����������. ���� ��������� ������ ������ �������, ��
		//����������� ������������� �������� �, ��������������, ����������������
		for (int i = 1; i < max; i++) {
			if (EB.size() > i) {
				if (Cost + EB[i].GetCost() - temp.eb.GetCost() < temp.Budjet) {
					Cost -= temp.eb.GetCost();
					temp.eb = EB[i];
					Cost += EB[i].GetCost();
				}
			}
			if (PROC.size() > i) {
				if (Cost + PROC[i].GetCost() - temp.proc.GetCost() < temp.Budjet) {
					Cost -= temp.proc.GetCost();
					temp.proc = PROC[i];
					Cost += PROC[i].GetCost();
				}
			}
			if (FN.size() > i) {
				if (Cost + FN[i].GetCost() - temp.fan.GetCost() < temp.Budjet) {
					Cost -= temp.fan.GetCost();
					temp.fan = FN[i];
					Cost += FN[i].GetCost();
				}
			}
			if (RM.size() > i) {
				if (Cost + RM[i].GetCost() - temp.ram.GetCost() < temp.Budjet) {
					Cost -= temp.ram.GetCost();
					temp.ram = RM[i];
					Cost += RM[i].GetCost();
				}
			}
			if (HD.size() > i) {
				if (Cost + HD[i].GetCost() - temp.hdd.GetCost() < temp.Budjet) {
					Cost -= temp.hdd.GetCost();
					temp.hdd = HD[i];
					Cost += HD[i].GetCost();
				}
			}
			if (SD.size() > i) {
				if (Cost + SD[i].GetCost() - temp.ssd.GetCost() < temp.Budjet) {
					Cost -= temp.ssd.GetCost();
					temp.ssd = SD[i];
					Cost += SD[i].GetCost();
				}
			}
			if (VC.size() > i) {
				if (Cost + VC[i].GetCost() - temp.vc.GetCost() < temp.Budjet) {
					Cost -= temp.vc.GetCost();
					temp.vc = VC[i];
					Cost += VC[i].GetCost();
				}
			}
			if (PR.size() > i) {
				if (Cost + PR[i].GetCost() - temp.prnt.GetCost() < temp.Budjet) {
					Cost -= temp.prnt.GetCost();
					temp.prnt = PR[i];
					Cost += PR[i].GetCost();
				}
			}
			if (BX.size() > i) {
				if (Cost + BX[i].GetCost() - temp.box.GetCost() < temp.Budjet) {
					Cost -= temp.box.GetCost();
					temp.box = BX[i];
					Cost += BX[i].GetCost();
				}
			}
			
		}
		CompleteMes();
		system("cls");
		ConfigFst(Cost);
		temp = empt;
	}
	MB.clear(); EB.clear(); PROC.clear(); FN.clear(); RM.clear();
	SD.clear(); VC.clear();   PR.clear(); BX.clear(); HD.clear();
}

//���������� ��������� ���������
template<typename t> void Quick_Sort_Func(vector<t> &Data, int n) {
	t temp;
	int p = Data[n / 2].GetCost();

	int i = 0;
	int j = n - 1;

	do {
		while (Data[i].GetCost() < p) {i++;}
		while (Data[j].GetCost() > p) {j--;}
		if (i <= j) {
			temp = Data[i];
			Data[i] = Data[j];
			Data[j] = temp;
			i++; j--;
		}
	} while (i <= j);

	if (j > 0) Quick_Sort_Func(Data, j);
	if (n > i) Quick_Sort_Func(Data, n - i);
}

template<typename t> void Sort(t &Data) {
	int n = Data.size();
	Quick_Sort_Func(Data, n);
}