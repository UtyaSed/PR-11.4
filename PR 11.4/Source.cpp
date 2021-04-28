#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Busines
{
	char name[100];
	char shop[100];
	double price;
	double kilk;
	char vumiruvanya[20];
};

void Create(char* fname);
void Print(char* fname);
void FiltrShop(char* fname);
void FiltrTovar(char* fname);
void SortTovar(char* fname);
void SortShop(char* fname);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char fname[61];
	char ch;

	do
	{
		cout << endl;
		cout << "������� ����:	" << endl;
		cout << "[1] - �������� �� ���������� ������;" << endl;
		cout << "[2] - �������� �� ���� ������;" << endl;
		cout << "[3] - Գ���������� �� ���������;" << endl;
		cout << "[4] - Գ���������� �� �������;" << endl;
		cout << "[5] - ����������� �� �������;" << endl;
		cout << "[6] - ���������� �� ���������;" << endl << endl;

		cout << "[0] - ���������� ������." << endl << endl;
		cout << "��� ����: "; cin >> ch;
		switch (ch)
		{
		case '0':
			break;
		case '1':
			cin.get();
			cin.sync();
			cout << endl;
			cout << "������ ����� �����: "; cin.getline(fname, sizeof(fname));
			Create(fname);
			break;
		case '2':
			cin.get();
			cin.sync();
			cout << endl;
			cout << "������ ����� �����: "; cin.getline(fname, sizeof(fname));
			Print(fname);
			break;
		case '3':
			cin.get(); 
			cin.sync();
			cout << endl;
			cout << "������ ����� �����: "; cin.getline(fname, sizeof(fname));
			FiltrShop(fname);
			break;
		case '4':
			cin.get();
			cin.sync();
			cout << endl;
			cout << "������ ����� �����: "; cin.getline(fname, sizeof(fname));
			FiltrTovar(fname);
			break;
		case '5':
			cin.get();
			cin.sync();
			cout << "������ ����� �����: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			SortTovar(fname);
			cout << "���� �����������!" << endl;
			Print(fname);
			break;
		case '6':
			cin.get();
			cin.sync();
			cout << "������ ����� �����: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			SortShop(fname);
			cout << "���� �����������!" << endl;
			Print(fname);
			break;
		default:
			cout << "������� �����! ";
		}
	} while (ch != '0');
	return 0;
}

void Create(char* fname)
{
	ofstream fout(fname, ios::binary); 
	char ch;
	string s;
	Busines busines;
	do
	{
		cout << "����� ������: "; cin >> busines.name;
		cout << "�������: "; cin >> busines.shop;
		cout << "ֳ��(UAH): "; cin >> busines.price;
		cout << "ʳ������: "; cin >> busines.kilk;
		cout << "������� ����������: "; cin >> busines.vumiruvanya;
		if (!fout.write((char*)&busines, sizeof(Busines)))
		{
			cerr << "������� ������ � ����." << endl;
		}
		cout << "����������? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
	fout.close();
}

void Print(char* fname)
{
	ifstream fin(fname, ios::binary);
	if (fin.fail())
	{
		cout << "������� �������� ����� '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Busines busines;
	cout << "========================================================================="
		<< endl;
	cout << "|  �  |  �����  |  �������  |  ֳ��  |  ʳ������  |  ��. ����������  |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	int i = 0;
	while (fin.read((char*)&busines, sizeof(Busines)))
	{
		cout << " | " << setw(2) << right << i + 1 << "  "; i++;
		cout << " |   " << setw(6) << left << busines.name
			<< " |   " << setw(6) << left << busines.shop << "  "
			<< " |   " << setw(5) << left << busines.price
			<< setw(4) << " |     " << setw(6) << left << busines.kilk << "  "
			<< setw(6) << " |       " << setw(12) << left << busines.vumiruvanya << " |";
		cout << endl;
	}
	cout << "========================================================================= "
		<< endl;
	cout << endl;
	cout << endl;
	fin.close();
}

void FiltrShop(char* fname)
{
	ifstream fin(fname, ios::binary);
	if (fin.fail())
	{
		cout << "������� �������� ����� '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Busines busines;
	string store;
	int k = 0;
	cout << "���� �����, ������ ����� ��������: "; cin.sync(); getline(cin, store);
	cout << endl;
	cout << "========================================================================="
		<< endl;
	cout << "|  �  |  �����  |  �������  |  ֳ��  |  ʳ������  |  ��. ����������  |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	int i = 0;
	while (fin.read((char*)&busines, sizeof(Busines)))
	{
		if (busines.shop == store) {
			cout << " | " << setw(2) << right << i + 1 << "  "; i++;
			cout << " |   " << setw(6) << left << busines.name
				<< " |   " << setw(6) << left << busines.shop << "  "
				<< " |   " << setw(5) << left << busines.price
				<< setw(4) << " |     " << setw(6) << left << busines.kilk << "  "
				<< setw(6) << " |       " << setw(12) << left << busines.vumiruvanya << " |";
			cout << endl;
			k = 1;
		}
	}
	if (k == 0) {
		cout << "����� ������� �� ���� ��������. ���� �����, �������� ����������� �����." << endl;
	}
	cout << "========================================================================= "
		<< endl;
	cout << endl;
	cout << endl;
	fin.close();
}

void FiltrTovar(char* fname)
{
	ifstream fin(fname, ios::binary);
	if (fin.fail())
	{
		cout << "������� �������� ����� '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Busines busines;
	string store;
	int k = 0;
	cout << "���� �����, ������ ����� ������: "; cin.sync(); getline(cin, store);
	cout << endl;
	cout << "========================================================================="
		<< endl;
	cout << "|  �  |  �����  |  �������  |  ֳ��  |  ʳ������  |  ��. ����������  |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	int i = 0;
	while (fin.read((char*)&busines, sizeof(Busines)))
	{
		if (busines.name == store) {
			cout << " | " << setw(2) << right << i + 1 << "  "; i++;
			cout << " |   " << setw(6) << left << busines.name
				<< " |   " << setw(6) << left << busines.shop << "  "
				<< " |   " << setw(5) << left << busines.price
				<< setw(4) << " |     " << setw(6) << left << busines.kilk << "  "
				<< setw(6) << " |       " << setw(12) << left << busines.vumiruvanya << " |";
			cout << endl;
			k = 1;
		}
	}
	if (k == 0) {
		cout << "����� ����� �� ���� ��������. ���� �����, �������� ����������� �����." << endl;
	}
	cout << "========================================================================= "
		<< endl;
	cout << endl;
	cout << endl;
	fin.close();
}

void SortTovar(char* fname) {
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "������� �������� ����� '" << fname << "'" << endl;
		f.close();
		return;
	}
	f.seekg(0, ios::end);
	int size = f.tellg();
	size = size / sizeof(Busines);
	f.seekg(0, ios::beg);
	Busines* busines = new Busines[size];
	Busines temp;
	f.read((char*)busines, size * sizeof(Busines));
	f.close();
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			string nameOne = busines[j].name;
			string nameTwo = busines[j - 1].name;
			if ((nameOne < nameTwo))
			{
				temp = busines[j];
				busines[j] = busines[j - 1];
				busines[j - 1] = temp;
			}
		}
	}
	f.close();
	ofstream file(fname, ios::binary);
	file.write((char*)busines, size * sizeof(Busines));
	file.close();
}

void SortShop(char* fname) {
	ifstream f(fname, ios::binary);
	if (!f)
	{
		cerr << "������� �������� ����� '" << fname << "'" << endl;
		f.close();
		return;
	}
	f.seekg(0, ios::end);
	int size = f.tellg();
	size = size / sizeof(Busines);
	f.seekg(0, ios::beg);
	Busines* busines = new Busines[size];
	Busines temp;
	f.read((char*)busines, size * sizeof(Busines));
	f.close();
	for (int i = 0; i < size - 1; i++) {
		for (int j = size - 1; j > i; j--) {
			string shopOne = busines[j].shop;
			string shopTwo = busines[j - 1].shop;
			if ((shopOne < shopTwo))
			{
				temp = busines[j];
				busines[j] = busines[j - 1];
				busines[j - 1] = temp;
			}
		}
	}
	f.close();
	ofstream file(fname, ios::binary);
	file.write((char*)busines, size * sizeof(Busines));
	file.close();
}
