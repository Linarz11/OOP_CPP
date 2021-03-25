#include <iostream>
using namespace std;

#define tab "\t"
//#define CONSTRUCTORS
#define ASSIGNMENT_CHECK
//#define DISTANCE
//#define OPERATOR_EXAMPLES
//Создание структуры:

using std::cin;
using std::cout;
using std::endl;
class Point
{
	//Структура Point описывает точки на плоскости
	double x; //Координата по X
	double y; // Координата по Y
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
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
	/*Point()
	{
		x = y = int();
		cout << "Default_Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Single-argument_Constructor: \t\t" << this << endl;
	}

	Point(double x, double y)
	{
		//Конструктор с параметрами создает точку на плоскости
		this->x = x;
		this->y = y;
		cout << "Constructor: \t\t" << this << endl;
	}
*/
	Point(double x = 0, double y = 0)
	{
		//Этот конструктор может быть вызван: - без параметров; - с одним параметром; - с двумя параметрами
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;

	}
	Point(const Point& other)
	{
		// other - это другой объект, копию которого мы создаем.
		this->x = other.x;
		this->y = other.y;
		cout << "Copy_Constructor: \t" << this << endl;

	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// Operators
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy_Assignment: \t\t" << this << endl;
		return *this;
	}
	//	Methods
	void print()
	{
		cout << "X= " << x << "\tY= " << y << endl;
	}

	double distance(const Point& other)const
	{
		double x_distance = (other.x - this->x);
		double y_distance = (other.y - this->y);
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance); //sqrt - квадратный корень
		return distance;
	}
};

double distance(const Point& A, const Point& B)
{
	
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance); //sqrt - квадратный корень
	return distance;
}

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

#ifdef CONSTRUCTORS
	Point A;//Default constructor
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B = 5;// Single-argument constructor
	B.print();

	Point C(8); // Single - argument constructoor
	C.print();

	Point D{ 12 };
	D.print();

	Point E(5, 3);
	E.print();

	Point F = E; // При таком создании вызовется Copy_Constructor

	Point G; //Default_Constructor
	G = D; // Copy_Assignment - оператор присвоить (operator=)
	G.print();
#endif // CONSTRUCTORS

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	Point A, B, C;
	A = B = C = Point();

#endif // ASSIGNMENT_CHECK

#ifdef DISTANCE
	Point A(2, 3);
	Point B(4, 5);

#ifdef OPERATOR_EXAMPLES
	cout << A + B << endl; // Неявный вызов оператора +
	cout << A.operator+(B) << endl; //Явный вызов оператора +, перегруженного в классе
	cout << operator +(A, B) << endl; //Явный вызов оператора +, перегруженного за классом  
#endif // OPERATOR_EXAMPLES


	A.print();
	B.print();
	cout << "Расстояние равно: " << A.distance(B) << endl;
	cout << "Растояние через функцию равно: " << distance(A, B) << endl;
#endif // DISTANCE



}