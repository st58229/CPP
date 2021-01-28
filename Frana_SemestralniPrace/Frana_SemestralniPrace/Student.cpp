#include "Student.h"

Student::Student()
{

}


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
	delete subjects_st;	
}

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
void Student::updatePredmety(ArrayValue* subjects)
{
	delete subjects_st;
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
	ArrayValue* av = new ArrayValue{};

	for (int i = 0; i < subjects_st->getSize(); i++)
	{
		av->append(new StringValue{ dynamic_cast<StringValue*>(subjects_st->get(i))->get() });
	}
	ov->append(KeyValuePair{ "subjects", av});
	ov->append(KeyValuePair{ "study", new BoolValue{study_st}});
	ov->append(KeyValuePair{ "year", new NumberValue{year_st}});
	return ov;
}

void Student::createStudent(ObjectValue* value)
{
	name_st = dynamic_cast<StringValue*>(value->get(0).getValue())->get();
	surname_st = dynamic_cast<StringValue*>(value->get(1).getValue())->get();
	id_st = dynamic_cast<NumberValue*>(value->get(2).getValue())->get();
	sex_st = dynamic_cast<StringValue*>(value->get(3).getValue())->get();
	birth_st = dynamic_cast<StringValue*>(value->get(4).getValue())->get();
	ArrayValue* oldArray = dynamic_cast<ArrayValue*>(value->get(5).getValue());
	subjects_st = new ArrayValue();
	int size = oldArray->getSize();
	for (int i = 0; i < size; i++) {
		subjects_st->append(new StringValue{ dynamic_cast<StringValue*>(oldArray->get(i))->get() });
	}	
	study_st = dynamic_cast<BoolValue*>(value->get(6).getValue())->get();
	year_st = dynamic_cast<NumberValue*>(value->get(7).getValue())->get();

}

