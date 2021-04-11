#include <iostream>
using namespace std;

#define tab "\t"
//#define CONSTRUCTORS
//#define ASSIGNMENT_CHECK
//#define DISTANCE
//#define OPERATOR_EXAMPLES
#define OPERATORS_OVERLOADS
//#define ARITHMETICAL_OPERATORS
#define COMPOUND_ASSIGNMENTS

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
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "Operator+=\t\t " << this << endl;
		return *this;
	}
	//		Increment/Decrement
	Point& operator++() //Prefix increment
	{
		this->x++;
		this->y++;
		cout << "Prefix Increment++" << this << endl;
		return *this;
	}
	Point operator++(int)//Postfix increment
	{
		Point old = *this; //Copy_constructor
		this->x++;
		this->y++;
		cout << "Postfix_Increment:\t\t " << this << endl;
		return old;
	}


	/*Point operator+(const Point& other)const
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "operator+" << endl;
		return result;
	}*/
	/*Point operator-(const Point& other)const
	{
		Point result(this->x - other.x, this->y - other.y);

		cout << "operator-" << endl;
		return result;
	}*/

	//Point operator*(const Point& other)
	//{
	//	return Point(this->x * other.x, this->y * other.y);
	//}
	//Point operator/(const Point& other)
	//{
	//	return Point(this->x / other.x, this->y / other.y);
	//}




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

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	cout << "Global+" << endl;
	return result;
}

Point operator-(const Point& left, const Point& right)
{
	Point result(
		left.get_x() - right.get_x(),
		left.get_y() - right.get_y()
	);
	cout << "Global-" << endl;
	return result;
}

Point operator*(const Point& left, const Point& right)
{
	return Point(left.get_x() * right.get_x(), left.get_y() * right.get_y());
}

Point operator/(const Point& left, const Point& right)
{
	return Point(left.get_x() / right.get_x(), left.get_y() / right.get_y());
}



ostream& operator<<(ostream& os/* output stream*/, const Point& obj)
{
	return os << "X = " << obj.get_x() << tab << "Y = " << obj.get_y();
}


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

#ifdef OPERATORS_OVERLOADS


	int a = 2;
	int b = 3;
	int c = a + b;
	a += b;


#ifdef ARITHMETICAL_OPERATORS
	Point A(2, 3);
	Point B(4, 5);
	Point C = A + B;
	C.print();
	Point D = A - B;//Неявный вызов оператора
	D.print();
	(A * B).print();
	//Point E = A.operator/(B);// Явный вызов оператора. Мы его явно вызываем как обычный метод
	Point E = operator/(A, B);//Тоже явный вызов глобального оператора
	E.print();
#endif // ARITHMETICAL_OPERATORS

#ifdef COMPOUND_ASSIGNMENTS
	Point A(2, 3);
	Point B(4, 5);
	A += B;
	A.print();
	/*++A;
	A.print();
	A++;
	A.print();*/

	cout << A++ << endl;
	cout << A << endl;
	cout << ++A << endl;
	cout << A << endl;
	++A++;
#endif // COMPOUND_ASSIGNMENTS


#endif // OPERATORS_OVERLOADS



}