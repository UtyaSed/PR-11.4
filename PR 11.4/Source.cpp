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
		cout << "Головне меню:	" << endl;
		cout << "[1] - Введення та збереження данних;" << endl;
		cout << "[2] - Загрузка та вивід данних;" << endl;
		cout << "[3] - Фільтрування по магазинам;" << endl;
		cout << "[4] - Фільтрування по товарам;" << endl;
		cout << "[5] - Сортуванням по товарам;" << endl;
		cout << "[6] - Сортування по магазинам;" << endl << endl;

		cout << "[0] - Завершення роботи." << endl << endl;
		cout << "Ваш вибір: "; cin >> ch;
		switch (ch)
		{
		case '0':
			break;
		case '1':
			cin.get();
			cin.sync();
			cout << endl;
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			Create(fname);
			break;
		case '2':
			cin.get();
			cin.sync();
			cout << endl;
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			Print(fname);
			break;
		case '3':
			cin.get(); 
			cin.sync();
			cout << endl;
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			FiltrShop(fname);
			break;
		case '4':
			cin.get();
			cin.sync();
			cout << endl;
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			FiltrTovar(fname);
			break;
		case '5':
			cin.get();
			cin.sync();
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			SortTovar(fname);
			cout << "Файл відсортовано!" << endl;
			Print(fname);
			break;
		case '6':
			cin.get();
			cin.sync();
			cout << "Введіть назву файлу: "; cin.getline(fname, sizeof(fname));
			cout << endl;
			SortShop(fname);
			cout << "Файл відсортовано!" << endl;
			Print(fname);
			break;
		default:
			cout << "Помилка вводу! ";
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
		cout << "Назва товару: "; cin >> busines.name;
		cout << "Магазин: "; cin >> busines.shop;
		cout << "Ціна(UAH): "; cin >> busines.price;
		cout << "Кількість: "; cin >> busines.kilk;
		cout << "Одиниці вимірювання: "; cin >> busines.vumiruvanya;
		if (!fout.write((char*)&busines, sizeof(Busines)))
		{
			cerr << "Помилка запису у файл." << endl;
		}
		cout << "Продовжити? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
	fout.close();
}

void Print(char* fname)
{
	ifstream fin(fname, ios::binary);
	if (fin.fail())
	{
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Busines busines;
	cout << "========================================================================="
		<< endl;
	cout << "|  №  |  Товар  |  Магазин  |  Ціна  |  Кількість  |  Од. вимірювання  |"
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
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Busines busines;
	string store;
	int k = 0;
	cout << "Будь ласка, введіть назву магазину: "; cin.sync(); getline(cin, store);
	cout << endl;
	cout << "========================================================================="
		<< endl;
	cout << "|  №  |  Товар  |  Магазин  |  Ціна  |  Кількість  |  Од. вимірювання  |"
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
		cout << "Даний магазин не було знайдено. Будь ласка, перевірте правильність вводу." << endl;
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
		cout << "Помилка відкриття файлу '" << fname << "'!" << endl;
		return;
	}
	cout << endl;
	Busines busines;
	string store;
	int k = 0;
	cout << "Будь ласка, введіть назву товару: "; cin.sync(); getline(cin, store);
	cout << endl;
	cout << "========================================================================="
		<< endl;
	cout << "|  №  |  Товар  |  Магазин  |  Ціна  |  Кількість  |  Од. вимірювання  |"
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
		cout << "Даний товар не було знайдено. Будь ласка, перевірте правильність вводу." << endl;
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
		cerr << "Помилка відкриття файлу '" << fname << "'" << endl;
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
		cerr << "Помилка відкриття файлу '" << fname << "'" << endl;
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
