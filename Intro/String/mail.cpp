#include "String.h"





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
