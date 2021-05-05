#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include "Graduate.h"


void main()
{
	setlocale(LC_ALL, "");
	
#ifdef INHERITANCE_CHECK
	/*Human human("Тупенко", "Василий", 18);
human.info();*/

	Student Vasya("Тупенко", "Василий", 18, "Программирование", "PD-011", 4.5);
	Vasya.info();

	Teacher Oleg("Ковтун", "Олег", 35, "ООП С++", 11.5);
	Oleg.info();


	Graduate Tony(
		"Montana", "Antonio", 25,
		"Современные технологии продаж", "BV-011", 80,
		"Распространение колбас");
	Tony.info();
#endif // INHERITANCE_CHECK
	

	// 1. Generalization

	Human* group[] =
	{
	new Student("Батодалаев", "Даши", 16, "РПО", "PD_011", 5),
	new Student("Загидуллин", "Линар", 32, "РПО", "PD_011", 5),
	new Graduate("Шугани", "Сергей", 15, "РПО", "PD_011", 5, "Защита Персональных данных"),
	new Teacher("Эйнштейн", "Альберт", 141, "Astrophisics", 110),
	new Student("Маркин", "Даниил", 17, "РПО", "PD_011", 5),
	new Teacher("КОвтун", "ОЛег ", 35, "С++", 99)
	};
	cout << sizeof(group) << endl;
	// 2. Specialization

	cout <<delimeter;
	for (int i = 0; i < sizeof(group)/sizeof(Human*); i++)
	{
		group[i]->info();
		cout << delimeter;

	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
}