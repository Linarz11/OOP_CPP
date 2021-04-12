#include <iostream>

using namespace std;

//#define MY_WORK
//#define CONSTRUCTORS_CHECK
//#define COMPOUND_ASSIGNMENTS_CHECK
//#define TYPE_CONVERSIONS
#define COMPARISON_OPERATORS

#define tab "\t"
#//define ARITHMETICAL_OPERATORS_CHECK
#define DEBUG

class Fraction;//CLass declaration - объявление класса
Fraction operator+(Fraction left, Fraction right);//ПРототип оператора +
Fraction operator-(Fraction left, Fraction right);//ПРототип оператора +
Fraction operator*(Fraction left, Fraction right);//ПРототип оператора +
Fraction operator/(Fraction left, Fraction right);//ПРототип оператора +
class Fraction
{
#ifdef MY_WORK
	int a;
	int b;
public:
	int get_a()const
	{
		return a;
	}
	int get_b()const
	{
		return b;
	}
	void set_a(int a)
	{
		this->a = a;
	}
	void set_b(int b)
	{
		this->b = b;
	}

	Fraction(int a, int b)
	{

		this->a = a;
		this->b = b;
		cout << "Constructor: \t\t" << this << endl;
	}

	Fraction(const Fraction& other)
	{
		this->a = other.a;
		this->b = other.b;
		cout << "Copy_Constructor: \t" << this << endl;

	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}


	void print()
	{
		cout << a << "/" << b << endl;
	}


	int to_proper(const Fraction& other)
	{
		int c;
		if (this->a > this->b)
		{
			c = a / b;
			a = a - c * b;
		}
	}
#endif // MY_WORK
	bool minus;
	int integer; // Цела часть
	int numerator; //Числитель
	int denominator;//Знаменатель
public:
	bool get_minus()const
	{
		return minus;
	}
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;

	}void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	void set_minus(bool minus)
	{
		this->minus = minus;
	}
	Fraction& set_minus_to_number()
	{
		if (minus)
		{
			integer = -integer;
			numerator = -numerator;
			minus = false;
		}
	return *this;
	}
Fraction& get_minus_from_number()
	{
		if (integer < 0)
		{
			integer = -integer;
			minus = true;
		}
		if (numerator < 0)
		{
			numerator = -numerator;
			minus = true;
		}
		return *this;

	}
	//Constructors


	Fraction()
	{
		this->minus = false;
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
#ifdef DEBUG
		cout << "Default COnstructor0:\t" << this << endl;

#endif // DEBUG
	}

	explicit Fraction(int integer)
	{
		this->minus = false;
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		if (integer < 0)
		{
			minus = true;
			this->integer = -integer;
		}
#ifdef DEBUG
		cout << "One ARG Constructor1:\t" << this << endl;

#endif // DEBUG
	}

	Fraction(double decimal)
	{
		decimal += 1e-10;
		minus = false;
		if (decimal < 0)
		{
			minus = true;
			decimal = -decimal;
		}
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();
		cout << "Constructor double: \t" << this << endl;

	}

	Fraction(int numerator, int denominator)
	{
		this->minus = false;
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		if (numerator < 0)
		{
			minus = true;
			this->numerator = -numerator;
		}

#ifdef DEBUG
		cout << "COnstructor2:\t" << this << endl;

#endif // DEBUG
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->minus = false;
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
		if (integer < 0)
		{
			minus = true;
			this->integer = -integer;
		}

		if (numerator < 0)
		{
			minus = true;
			this->numerator = -numerator;
		}
#ifdef DEBUG
		cout << "Constructor3:\t" << this << endl;

#endif // DEBUG
	}
	~Fraction()
	{
#ifdef DEBUG
		cout << "Destructor:\t" << this << endl;

#endif // DEBUG
	}
		Fraction& operator=(const Fraction & other)
		{
		this->minus = other.minus;
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
#ifdef DEBUG
		cout << "Copy_Assignment:\t" << this << endl;
#endif // DEBUG
		return *this;
		}
	
	Fraction& operator+=(const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator-=(const Fraction& other)
	{
		return *this = *this - other;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}
				//INcrement\DEcrement
	Fraction& operator++()
	{
		
		this->integer++;
		return *this;
	}

	Fraction operator++(int)
	{
		Fraction old = *this;
		 this->integer++;
		 return old;
	}

	Fraction operator--()
	{
		this->integer--;
		return *this;
	}
	
	Fraction operator--(int)
	{
		Fraction old = *this;
		this->integer--;
		return old;
	}

	//                TYPE CAST OPERATORS
	explicit operator int() const
	{
		return minus ? -integer : integer;
	}

	explicit operator double() const
	{
		
		return minus ? -(integer+((double)numerator / denominator)) : (integer+(double)numerator / denominator);
	
	}
	//Methods
	Fraction& to_proper()
	{
		/*if(integer>=0) integer += numerator / denominator;
		else integer -=numerator / denominator;*/
		integer += numerator / denominator;
		get_minus_from_number();
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		get_minus_from_number();
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& reduce()
	{
		if (numerator == 0)return *this;
		int more, less, rest;
		// Выяясняем кто больше, числитель или знаменатель:
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		//Находим наибольший общий делитель: 
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
			int GCD = more;//Greatest Common Divisor
		//Собственно сокращаем дробь
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}


};
Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	left.set_minus_to_number();
	right.set_minus_to_number();
	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper().get_minus_from_number().reduce();
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_proper().set_minus_to_number();
	right.to_proper().set_minus_to_number();

	return Fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper().set_minus_to_number();
	right.to_improper().set_minus_to_number();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().get_minus_from_number().reduce();
}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	 Fraction result
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	);
	 result.to_proper();
	 if (left.get_minus() || right.get_minus())result.set_minus(true);
	 if (left.get_minus() && right.get_minus())result.set_minus(false);
	 return result;
}

bool operator==(Fraction left, Fraction right)
{
	left.to_improper().reduce();
	right.to_improper().reduce();
	/*if (left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_numerator())
	{
		return true;
	}
	else return false;*/
	return 	left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return!(left == right);
}

bool operator >(const Fraction& left, const Fraction& right)
{
	return((double)left > (double)right);
}

bool operator <(const Fraction& left, const Fraction& right)
{
	return((double)left < (double)right);
}



bool operator >=(const Fraction& left, const Fraction& right)
{
	//return((double)left >= (double)right);
	return left > right || left == right;

}

bool operator <=(const Fraction& left, const Fraction& right)
{
	//return((double)left <= (double)right);
	return !(left > right);
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_minus())os << "(-";
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_integer() && obj.get_numerator())os << "(";
	if (obj.get_numerator())os << obj.get_numerator() << "/" << obj.get_denominator();
	if (obj.get_integer() && obj.get_numerator())os << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)os << 0;
	if (obj.get_minus())os << ")";

	return os;

}


//#define INCREMENTS_CHECK

void main()
{
	setlocale(LC_ALL, "");
	/*Fraction A(2, 3, 4);
	Fraction B(5, 6, 7);

	cout << A << endl;
	cout << B << endl;*/

	/*Fraction A(2, 3);
	A.print();*/
#ifdef CONSTRUCTORS_CHECK
	Fraction A;//Default constructor
	cout << A << endl;
	Fraction B = -5;//Single-argument constructor
	cout << B << endl;
	Fraction C(-1, 2);
	cout << C << endl;
	Fraction D(-2, 3, 4);
	cout << D << endl;


#endif // CONSTRUCTORS_CHECK

	/*double a = 2.7;
	double b = 3.5;
	cout << a * b << endl;*/
	
#ifdef ARITHMETICAL_OPERATORS_CHECK
	cout << A << tab << B << endl;
	cout << A << " + " << B << " = " << A + B << endl;
	cout << B << " - " << B << " = " << B - B << endl;
	cout << B << " - " << A << " = " << B - A << endl;
	cout << A << " - " << B << " = " << A - B << endl;

	cout << A << " * " << B << " = " << A * B << endl;
	cout << A << " / " << B << " = " << A / B << endl;

#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPOUND_ASSIGNMENTS_CHECK
	A += B;
	cout << A << endl;
	A -= B;
	cout << A << endl;
	A *= B;
	cout << A << endl;
	A /= B;
	cout << A << endl;
#endif // COMPOUND_ASSIGNMENTS_CHECK

	//++A;
	//cout << "++A= "<<A << endl;
	//--A;
	//cout << "--A= " << A << endl;
	//A++;
	//cout << "A++ = " << A << endl;
	//A--;
	//cout << "A-- = " << A << endl;
	//cout << A << endl;
#ifdef INCREMENT_CHECK
	Fraction reduce(840, 3600);
	cout << reduce << endl;
	cout << reduce.reduce() << endl;
	cout << Fraction(29, 37).reduce() << endl;

	for (double i = 0.3; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (Fraction i(1, 2); i.get_integer() < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif // INCREMENT_CHECK

		
	/*int  a = 2;
	double b = 2;
	int c = b;
	double d = 2.5;
	int e = d;*/


		//Fraction A = (Fraction)5;// from int to Fraction (From less to more) Это преобразование выполняет конструктор с одним параметром.
		//Fraction A(5);//Если конструктор Explicit, то его можно вызвать только так.
		//cout << "Fraction A =" << A << endl;
		/*cout << sizeof(int) << endl;
		cout << sizeof(Fraction) << endl;*/
		
		//Type cast operator
		//int a;

		//a = (int)A;//From more to less,possible loss of data (operator int)
		//cout <<"Int a = " << a << endl;

		//Fraction B(-3, 4, 5);
		//cout << B << endl;
		//double b = (double)B;
		//cout << b << endl;
		//int c = (int)B;
		//cout << c << endl;
		
		/*Fraction  C= 2.3;
		cout <<C << endl;
		cout <<(double)C << endl;*/

#ifdef COMPARISON_OPERATORS

		Fraction A(5, 11);
		Fraction B(5, 2);
		/*if (A == B)
		{
			cout << "Fractions equal" << endl;

		}
		else
		{
			cout << "Fractions different" << endl;

		}*/
		//cout << "Fractions " << (A == B ? "equal" : "different") << endl;
		cout << "Равно\t"<<(A == B) << endl;
		cout << "Не равно\t" <<(A != B) << endl;
		cout << "БОльше\t" <<(A > B) << endl;
		cout << "Меньше\t" <<(A < B) << endl;
		cout << "Больше или равно\t" <<(A >= B) << endl;
		cout << "Меньше или равно\t" <<(A <= B) << endl;
#endif // COMPARISON_OPERATORS


}