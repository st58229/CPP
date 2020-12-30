#include "Student.h"

Student::Student()
{

}

//Student::Student(StringValue jme, StringValue prijm, NumberValue idcko, StringValue pohlav, StringValue datumNar, ArrayValue predmety_pole, BoolValue stud, NumberValue roc)
//{
//	jmeno = jme;
//	prijmeni = prijm;
//	id = idcko;
//	pohlavi = pohlav;
//	datumNarozeni = datumNar;
//	predmety = predmety_pole;
//	studuje = stud;
//	rocnik = roc;
//}

Student::Student(std::string name, std::string surname, double id, std::string sex, std::string birth, ArrayValue* subjects, bool study, double year)
{
	name_st = name;
	surname_st = surname;
	id_st = id;
	sex_st = sex;
	birth_st = birth;
	subjects_st = subjects; 
	study_st = study;
	year_st = year;
}

Student::~Student()
{
	
}

//StringValue Student::getJmeno()
//{
//	return jmeno;
//}
//StringValue Student::getPrijmeni()
//{
//	return prijmeni;
//}
//NumberValue Student::getID()
//{
//	return id;
//}
//StringValue Student::getPohlavi()
//{
//	return pohlavi;
//}
//StringValue Student::getdatumNarozeni()
//{
//	return datumNarozeni;
//}
//ArrayValue	Student::getPredmety()
//{
//	return ArrayValue();
//}
//BoolValue   Student::getStuduje()
//{
//	return studuje;
//}
//NumberValue Student::getRocnik()
//{
//	return rocnik;
//}

void Student::setJmeno(std::string string)
{
	name_st = string;
}
void Student::setPrijmeni(std::string string)
{
	surname_st = string;
}
void Student::setID(int id)
{
	id_st = id;
}
void Student::setPohlavi(std::string string)
{
	sex_st = string;
}
void Student::setdatumNarozeni(std::string string)
{
	birth_st = string;
}
void Student::setPredmety(ArrayValue* subjects)
{
	subjects_st = subjects;

}
void Student::setStuduje(bool study)
{
	study_st = study;
}
void Student::setRocnik(int year)
{
	year_st = year;
}

Value* Student::deserialize(const std::string& string)
{
	return JSON::deserialize(string);
}
std::string Student::serialize(const Value* value)
{
	return value->serialize();
}

std::string Student::showAll()
{
	return nullptr;
}

Value* Student::toValue()
{
	ObjectValue* ov = new ObjectValue{};
	ov->append(KeyValuePair{ "name", new StringValue{name_st}});
	ov->append(KeyValuePair{ "surname", new StringValue{surname_st} });
	ov->append(KeyValuePair{ "id", new NumberValue{id_st}});
	ov->append(KeyValuePair{ "sex", new StringValue{sex_st}});
	ov->append(KeyValuePair{ "birth", new StringValue{birth_st}});
	ov->append(KeyValuePair{ "subjects", subjects_st});
	ov->append(KeyValuePair{ "study", new BoolValue{study_st}});
	ov->append(KeyValuePair{ "year", new NumberValue{year_st}});
	return ov;
}

void Student::createStudent(ObjectValue* value)
{
	name_st = dynamic_cast<StringValue*>( value->get(0).getValue() )->get();
	surname_st = dynamic_cast<StringValue*>(value->get(1).getValue())->get();
	id_st = dynamic_cast<NumberValue*>(value->get(2).getValue())->get();
	sex_st = dynamic_cast<StringValue*>(value->get(3).getValue())->get();
	birth_st = dynamic_cast<StringValue*>(value->get(4).getValue())->get();
	subjects_st = dynamic_cast<ArrayValue*>(value->get(5).getValue());
	study_st = dynamic_cast<BoolValue*>(value->get(6).getValue())->get();
	year_st = dynamic_cast<NumberValue*>(value->get(7).getValue())->get();
}

