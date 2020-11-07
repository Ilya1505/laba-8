// C++.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <Conio.h>
#include<Windows.h>
#include <iostream>
#include <string>
using namespace std;
const int LEN = 20;
class engine// двигатель
{
private:
	string name;// марка двигателя
	double weight;// вес
	int power;// мощность (л.с.)
	int probeg;// пробег
	int resurs;// ресурс двигателя
public:
	engine(string init_name, double weight, int power, int probeg, int resurs)// конструктор с параметрами
	{
		this->name = init_name;
		this->weight = weight;
		this->power = power;
		this->probeg = probeg;
		this->resurs = resurs;
	}
	engine()// конструктор без параметров
	{
		name = "no_name";
		weight = 10;
		power = 100;
		probeg = 0;
		resurs = 300;
	}

	engine operator +(const engine & other)// перегрузка оператора +
	{
		engine temp;
		temp.weight = weight + other.weight;
		temp.power = power + other.power;
		temp.probeg = probeg + other.probeg;
		temp.resurs = resurs + other.resurs;
		temp.name = name;
		return temp;
	}

	engine & operator ++()// перегрузка оператора ++, префиксная форма, возврат по ссылке
	{
		weight++;
		power++;
		probeg++;
		resurs++;
		return *this;
	}

	engine operator ++(int value)// перегрузка оператора ++, постфиксная форма
	{
		engine temp = *this;
		weight++;
		power++;
		probeg++;
		resurs++;
		return temp;
	}
	// сеттеры и геттеры
	void SetName(string name)
	{
		this->name = name;
	}
	void SetWeight(double weight)
	{
		this->weight = weight;
	}
	void SetPower(int power)
	{
		this->power = power;
	}
	void SetProbeg(int probeg)
	{
		this->probeg = probeg;
	}
	void SetResurs(int resurs)
	{
		this->resurs = resurs;
	}
	string GetName()
	{
		return name;
	}
	double GetwWight()
	{
		return weight;
	}
	int GetPower()
	{
		return power;
	}
	int GetProbeg()
	{
		return probeg;
	}
	int GetResurs()
	{
		return resurs;
	}
	void Remont()// ремонт двигателя
	{
		probeg = 0;
	}
	void Read()// ввод данных
	{
		fflush(stdin);
		cout << endl << "Марка двигателя: ";
		getline(cin, name);
		cout << "Вес двигателя: ";
		cin >> weight;
		cout << "Мощность двигателя: ";
		cin >> power;
		cout << "Пробег двигателя: ";
		cin >> probeg;
		cout << "Ресурс двигателя: ";
		cin >> resurs;
	}
	void Print()// вывод данных
	{
		cout << "Марка двигателя: " << name << endl;
		cout << "Мощность двигателя: " << power << endl;
		cout << "Пробег двигателя: " << probeg << endl;
		cout << "Ресурс двигателя: " << resurs << endl;
		cout << "Масса двигателя: ";
		printf("%.4lf\n", weight);
	}
	~engine()// деструктор
	{

	}
};
class cars// класс авто
{
private:
	static int count;
	string name;// марка авто
	string color;// цвет авто
	int year;// год выпуска
	double price;// цена
	engine dvs;// двигатель
public:
	cars(string name, string color, int year, double price, engine dvs)// конструктор с параметрами
	{
		this->name = name;
		this->color = color;
		this->year = year;
		this->price = price;
		this->dvs = dvs;//установка двигателя
	}
	cars()// конструктор без параметров
	{
		name = "no_name";
		color = "no_color";
		year = 2000;
		price = 0;
	}
	void init(string name, string color, int year, double price, engine dvs)// функция инициализация
	{
		this->name = name;
		this->color = color;
		this->year = year;
		this->price = price;
		this->dvs = dvs;//установка двигателя
	}
	// сеттеры и геттеры
	void SetName(string name)
	{
		this->name = name;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	void SetYear(int year)
	{
		this->year = year;
	}
	void SetPrice(double price)
	{
		this->price = price;
	}
	string GetName()
	{
		return name;
	}
	string GetColor()
	{
		return color;
	}
	int GetYear()
	{
		return year;
	}
	double GetPrice()
	{
		return price;
	}
	void OutputCars()// функкция вывода данных
	{
		cout << endl << "Марка машины: " << name << endl;
		cout << "Цвет машины: " << color << endl;
		cout << "Год выпуска: " << year << endl;
		cout << "Цена машины: ";
		printf("%.4lf\n", price);
		dvs.Print();
	}
	void PutCars()// функция ввода данных
	{
		fflush(stdin);
		cout << endl << " Ввод данных" << endl;
		cout << "Марка машины: ";
		getline(cin, name);
		fflush(stdin);
		cout << "Цвет машины: ";
		getline(cin, color);
		cout << "Год выпуска машины: ";
		cin >> year;
		cout << "Цена: ";
		cin >> price;
		dvs.Read();
	}
	void Modern(double NewWeight, int NewPower, int NewResurs)// модернизация
	{
		dvs.SetWeight(NewWeight);
		dvs.SetPower(NewPower);
		dvs.SetResurs(NewResurs);
		dvs.Remont();
	}
	friend void Drive(cars *avto);// тест-драйв, дружественная функция для класса car
	~cars()
	{
	}
};

void Drive(cars *avto)// возврат значений через указатель
{
	int probeg;
	probeg = avto->dvs.GetProbeg() + 10;
	avto->dvs.SetProbeg(probeg);
}
int cars::count = 0;
int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);// подключение русскоязычного ввода/вывода
	SetConsoleOutputCP(1251);
	system("color F0");
	// Работа со статическими переменными
	printf("Статическая переменная\n");
	printf("Инициализация:");
	engine a("св-01", 10, 100, 0, 400);
	engine b("св-02", 10, 100, 0, 500);
	engine c = a + b;// перегрузка оператора +
	++c;// перегрузка оператора ++ префикс
	engine dvs = c++;// перегрузка оператора ++ постфикс 
	cars avto("no_name", "no_color", 2020, 1000, dvs);
	avto.OutputCars();
	avto.PutCars();
	printf("\nДанные после ввода:");
	avto.OutputCars();
	Drive(&avto);
	printf("\nПосле тест-драйва:");
	avto.OutputCars();
	avto.Modern(100, 200, 500);
	printf("\nПосле модернизации:");
	avto.OutputCars();
	//Работа с динамическими переменными
	printf("\nДинамическая переменная\n");
	printf("Инициализация:\n");
	cars* avto1 = new cars("no_name", "no_color", 2020, 100, dvs);
	avto1->OutputCars();
	avto1->PutCars();
	printf("\nДанные после ввода:\n");
	avto1->OutputCars();
	Drive(avto1);
	printf("После тест-драйва:\n");
	avto1->OutputCars();
	avto1->Modern(100, 200, 500);
	printf("После модернизации:\n");
	avto1->OutputCars();
	delete avto1;
	//Работа с динамическим массивом через new
	int n;
	printf("\nДинамический массив с помощью new\n");
	printf("\nВведите размерность массива: ");
	scanf("%d", &n);
	cars* avtoArray = new cars[n];
	printf("\nИнициализация:\n");
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->init("no_name", "no_color", 2020, 1000, dvs);
	}
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->OutputCars();
	}
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->PutCars();
	}
	printf("\nДанные после ввода:\n");
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->OutputCars();
	}
	printf("Тест-Драйв\n");
	for (int i = 0; i < n; i++)
	{
		Drive(avtoArray + i);
	}
	printf("После тест-драйва:\n");
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->OutputCars();
	}
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->Modern(100, 200, 500);
	}
	printf("После модернизации:\n");
	for (int i = 0; i < n; i++)
	{
		(avtoArray + i)->OutputCars();
	}
	delete[] avtoArray;
	getch();
	return 0;
}

