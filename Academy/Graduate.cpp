#include "Graduate.h"


const string& Graduate::get_topic() const
{
	return this->topic;
}
void Graduate::set_topic(const string& topic)
{
	this->topic = topic;
}

Graduate::Graduate
(
	HUMAN_TAKE_PARAMETERS, STUDENT_GET_PARAMETERS, const string& topic)
	:Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS), topic(topic)
{
	cout << "GConstructor:\t" << this << endl;
}
Graduate::~Graduate()
{
	cout << "GDestructor:\t" << this << endl;
}

void Graduate::info() const
{
	Student::info();
	cout << "Тема дипломного проекта: " << topic << endl;
}