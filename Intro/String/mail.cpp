#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define delimeter "\n-----------------------------\n"
/////////////////////////////////////////////////////////CLASS DECLARATION - Объявление класса///////////////////////////


class String;
String operator+(const String& left, const String& right);

class String
{
	char* str; //Указатель на строку в динамической памяти
	int size; //Размер строки
public:
	const char* get_str()const;
	char* get_str();
	int get_size() const;
	//   Constructors

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();
	//Operators
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(String& other);

	const char& operator[](int i)const;
	char& operator[](int i);

	//			Methods

	void print() const;
};

/////////////CLASS DECLARATION END////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////
/////////////CLASS DEFINITION - Определение класса////////////////////////////////////////////////////////////
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
int String::get_size() const
{
	return size;
}
//   Constructors

 String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << (size == 80 ? "DEfault" : "Size") << "_Constructor:\t" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)//Делегирование конструктора с одним параметром типа int
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	strcpy(this->str, str);	//String copy
	cout << "Constructor:\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	/*this->size = other.size;
	this->str = new char[size] {};

	strcpy(this->str, other.str);*/

	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	/*this->size = other.size;
	this->str = other.str;*/
	other.str = nullptr;
	cout << "MoveConstructor: \t" << this << endl;
}

String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}

//Operators
String& String::operator=(const String& other)
{
	// 0)ПРоверить не является ли другой объект ЭТИМ объектом:
	if (this == &other)return *this;

	delete[] this->str; // 1) В первую очередь удаляем старое значение объекта,
	// и только после этого присваиваем ему новое значение
	this->size = other.size;
	this->str = new char[size] {};
	strcpy(this->str, other.str);
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}

String& String::operator+=(String& other)
{
	return *this = *this + other;



	/*char* result = new char[this->size + other.size];
	strcpy(result, this->str);
	strcat(result, other.str);
	delete[] str;
	this->str = result;
	return *this;*/
}


const char& String::operator[](int i)const
{
	return this->str[i];
}
char& String::operator[](int i)
{
	return this->str[i];
}

//			Methods

void  String::print() const
{
	cout << "str:\t" << str << endl;
	cout << "size:\t" << size << endl;

}

String  operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	/*for (int i = 0; i < left.get_size(); i++)
	{
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		//result.get_str()[i+left.get_size()-1] = right.get_str()[i];
		result [i + left.get_size() - 1] = right[i];
	}*/
	strcpy(result.get_str(), left.get_str());//strcpy - выполняет копирование строки left в строку result
	strcat(result.get_str(), right.get_str());//выполняет конкатенацию строки right в строку result
		return result;
}






ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

/////////////CLASS DEFINITION END- Определение класса////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define OPERATOR_PLUS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTOR_CHECK
	String str;
	str.print();

	//String str2 = 5;	//
	String str2(5);
	str2.print();

	cout << typeid("Hello").name() << endl;
	String str3 = "Hello";
	str3.print();
	cout << str3 << endl;

	String str4 = str3;//Copy Constructor
	cout << "Str4: - " << str3 << endl;

	String str5;
	str5 = str4;
	cout << "Str 5 - " << str5 << endl;
#endif // CONSTRUCTOR_CHECK

#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;


#endif // ASSIGNMENT_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello, ";
	String str2 = "World!";
	cout << delimeter << endl;
	String str3;
	str3 = str1 + str2;// Оператор + будет выполнять конкатенацию (слияние) строк
	cout << delimeter << endl;

	cout << str3 << endl;

	//cout << delimeter;
	//str1 += str2;
	//cout << str1 << endl;  
#endif // OPERATOR_PLUS_CHECK

	String str1;//Default Constructor
	str1.print();
	String str2 = "Hello"; //Single Argument constructor
	str2.print();

	String str3("World"); //Single Argument Constructor
	str3.print();

	String str4(int a, int b); //Объявление функции str4, которая ничего не принимает,
									//и возвращает значение типа String
									//String str4; не вызывает конструктор по умолчанию

	String str5{}; //Явно вызывается конструктор по умолчанию
	str5.print();
	String str6{ 7 };
	str6.print();

	String str7{ "Привет" };
	str7.print();
	String str8 = str7;
	str8.print();
	cout << delimeter << endl;
	cout << str2 + str3 << endl;
	cout << delimeter << endl;

}
