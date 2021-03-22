#include <iostream>
using namespace std;

//Создание структуры:
class Point
{
	//Структура Point описывает точки на плоскости
	double x; //Координата по X
	double y; // Координата по Y
public:
	double get_x()
	{
		return x;
	}
	double get_y()
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//Constructors
	Point()
	{
		x = y = 0;
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Constructor: \t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//	Methods
	void print()
	{
		cout << "X= " << x << "\tY= " << y << endl;
	}

};

// Создавая структуру или класс, мы создаем новый тип данных, 
// а объявляя объекты этого класса или структры мы создаем переменные нашего типа.
// Классы и структуры еще называют пользовательскими типами данных.

// КЛАСС - ЭТО ТИП ДАННЫХ.
// СТРУКТУРА - ЭТО ТОЖЕ ТИП ДАННЫХ.
// ОБЪЕКТ - САМАЯ ОБЫЧНАЯ ПЕРЕМЕННАЯ. 
//#define INTRO
void main()
{
	setlocale(LC_ALL, "Rus");
#ifdef INTRO
	int a; // Объявление перпеменной 'a', типа int 
	Point A; // Объявление объекта 'A' структуры 'Point' 
			 //Объявление переменной 'A' типа Point
	A.set_x(2);;
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* pA = &A; // СОздаем указатель на объект
	cout << pA->get_x() << "\t" << pA->get_y() << endl;
#endif // INTRO

	Point A;
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B = 5;
	B.print();
}