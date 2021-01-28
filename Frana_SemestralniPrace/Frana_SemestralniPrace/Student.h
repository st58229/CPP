#pragma once

#include <api.h>

class Student
{
private:	
	std::string name_st;
	std::string surname_st;
	double id_st;
	std::string sex_st;
	std::string birth_st;
	ArrayValue* subjects_st;
	bool study_st;
	double year_st;

	

public:
	Student();
	Student(std::string name, std::string surname, double id, std::string sex, std::string birth, ArrayValue* subjects, bool study, double year);
	~Student();

	void setJmeno(std::string string);
	void setPrijmeni(std::string string);
	void setID(int id);
	void setPohlavi(std::string string);
	void setdatumNarozeni(std::string string);
	void setPredmety(ArrayValue* subjects);
	void setStuduje(bool studuje);
	void setRocnik(int rocnik);

	Value* deserialize(const std::string& string);
	std::string serialize(const Value* value);
	Value* toValue();
	void createStudent(ObjectValue* value);

	std::string showAll(); //Vypíše detaily o studentovi

	void updatePredmety(ArrayValue* subjects);
};

