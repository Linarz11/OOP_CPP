#pragma once
#include "Student.h"


class Graduate : public Student
{
	string topic; // ���� ���������� �������
public:
	const string& get_topic() const;
	void set_topic(const string& topic);

	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_GET_PARAMETERS, const string& topic);
	~Graduate();

	void info() const;
};