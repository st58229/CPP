#include "api.h"

std::string NullValue::serialize() const
{
	return "null";
}

///////////////////////////////////////////////////////////////////////////////

BoolValue::BoolValue()
{

}

BoolValue::BoolValue(bool value)
{
	this->value = value;
}

bool BoolValue::get() const
{
	return this->value;
}

std::string BoolValue::serialize() const
{
	return value ? "true" : "false";
}

///////////////////////////////////////////////////////////////////////////////

NumberValue::NumberValue()
{

}

NumberValue::NumberValue(double value)
{
	this->value = value;
}

double NumberValue::get() const
{
	return value;
}

std::string NumberValue::serialize() const
{
	return std::to_string(value);
}

///////////////////////////////////////////////////////////////////////////////

StringValue::StringValue()
{

}

StringValue::StringValue(std::string value)
{
	this->value = value;
	escapeChar();
}

std::string StringValue::get() const
{
	return this->value;
}

void StringValue::escapeChar()
{
	std::string newValue;

	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '\\' || value[i] == '\"')
		{
			newValue.push_back('\\');
		}

		newValue.push_back(value[i]);		
	}

	value = newValue;
}

std::string StringValue::serialize() const
{	
	return '"'+value+'"';
}

///////////////////////////////////////////////////////////////////////////////

KeyValuePair::KeyValuePair()
{
	
}

KeyValuePair::KeyValuePair(std::string key, Value* value)
{
	_value = value;
	_key = key;
}

std::string KeyValuePair::getKey() const
{
	return _key;
}

Value* KeyValuePair::getValue() const
{
	return _value;
}

///////////////////////////////////////////////////////////////////////////////

ArrayValue::ArrayValue()
{
	
}

ArrayValue::~ArrayValue()
{

}

void ArrayValue::append(Value* element)
{
	this->arrayValues.append(element);
}

Value* ArrayValue::get(int index)
{
	return arrayValues.getElementAt(index);
}

int ArrayValue::getSize()
{
	return arrayValues.getSize();
}

void ArrayValue::remove(int index)
{
	arrayValues.remove(index);
}

std::string ArrayValue::serialize() const
{
	std::string serial;

	serial.append("[");
	for (int i = 0; i < arrayValues.getSize(); i++)
	{		
		serial.append(arrayValues.getElementAt(i)->serialize());
		
		if (i < arrayValues.getSize() - 1) serial.append(",");
	}
	serial.append("]");

	return serial;
}

///////////////////////////////////////////////////////////////////////////////

ObjectValue::ObjectValue()
{

}

ObjectValue::~ObjectValue()
{
	
}

void ObjectValue::append(const KeyValuePair& pair)
{
	objectValues.append(pair);
}

 const KeyValuePair ObjectValue::get(int index)
{
	return objectValues.getElementAt(index);
}

 int ObjectValue::getSize()
 {
	 return objectValues.getSize();
 }

 void ObjectValue::remove(int index)
 {
	 objectValues.remove(index);
 }

std::string ObjectValue::serialize() const
{
	std::string serial;

	serial.append("{");
	for (int i = 0; i < objectValues.getSize(); i++)
	{
		serial.push_back('"');
		serial.append(objectValues.getElementAt(i).getKey());
		serial.push_back('"');
		serial.push_back(':');
		serial.append(objectValues.getElementAt(i).getValue()->serialize());
		if (i < objectValues.getSize() - 1) serial.append(",");
	}
	serial.append("}");

	return serial;
}

///////////////////////////////////////////////////////////////////////////////

Value* deserializeIndex(const std::string& string, int& position);


void filtrWhiteSpaces(const std::string string, int& position)
{
	char chr = string.at(position);

	// While chr == bílý znak, posouvej se na pozici, kde už není bílý znak
	while (chr == ' ' || chr == '\t' || chr == '\n')
	{
		position++;
		chr = string.at(position);
		if (chr == '}' || chr == ']')
		{			
			break;
		}

		if (position >= string.length())
		{
			break;
		}
	}
}

std::string findJsonType(char chr)
{
	return nullptr;
}

Value* createJsonObject(const std::string& string, int& pos)
{
	pos++;																					// { (Posun o znak)					
	ObjectValue* ov = new ObjectValue{};	

	while (string[pos] != '}')
	{
		filtrWhiteSpaces(string, pos);
		if (string[pos] == '}')
		{
			break;
		}
		StringValue* key = dynamic_cast<StringValue*>(deserializeIndex(string, pos));		// Key (název)
		filtrWhiteSpaces(string, pos);
		pos ++;																			// : (Posun o znak)
		filtrWhiteSpaces(string, pos);
		Value* val = deserializeIndex(string, pos);											// Value (hodnota)		
		filtrWhiteSpaces(string, pos);

		ov->append(KeyValuePair{ key->get(), val });	// Uložení do objektu

		if (string[pos] != ',')
			{			
				break;
			}													// Konec
		else pos++;																			// , (pokraèování)
	}

	if (pos < string.length())
	{
		pos++;
	}

	return ov;
}

Value* createJsonArray(const std::string& string, int& position)
{
	position++;																					// [ (Posun o znak)					
	ArrayValue* av = new ArrayValue{};


	while (string[position] != ']')
	{
		filtrWhiteSpaces(string, position);
		if (string[position] == ']')
		{
			break;
		}
		Value* val = deserializeIndex(string, position);											// Value (hodnota)		
		filtrWhiteSpaces(string, position);

		av->append( val );	// Uložení do objektu							

		if (string[position] != ',')
		{			
			break;
		}													// Konec
		else position++;																			// , (pokraèování)
	}
	
	if (position < string.length())
	{
		position++;
	}

	return av;
}

Value* readJsonData(const std::string& string, int& position)
{
	std::string val;	

	position++; // Skok kvùli "
	while (string[position] != '"') 
	{
		if (string[position] == '\\')
		{
			position++;
		}
		val.push_back(string[position]);
		position++;
	}
	position++; // Skok o jedno kvùli "

	return new StringValue{ val };
}

Value* readJsonNumber(const std::string& string, int& position)
{
	std::string val;	
	
	while (isdigit(string[position]) || string[position] == '-' || string[position] == '.')
	{
		val.push_back(string[position]);
		position++;
	}	

	return new NumberValue{ std::stof(val) };
}

Value* readJsonNull(const std::string& string, int& position)
{
	std::string check;
	for (int i = 0; i < 4; i++)
	{
		check.push_back(string[position + i]);
	}
	if (check._Equal("null"))
	{
		position += 4;
	}
	else
	{
		std::exception();
	}
	
	return new NullValue;
}

Value* readJsonTrue(const std::string& string, int& position)
{
	std::string check;
	for (int i = 0; i < 4; i++)
	{
		check.push_back(string[position + i]);
	}
	if (check._Equal("true"))
	{
		position += 4;
	}
	else
	{
		std::exception();
	}
	return new BoolValue(true);
}

Value* readJsonFalse(const std::string& string, int& position)
{
	std::string check;
	for (int i = 0; i < 5; i++)
	{
		check.push_back(string[position + i]);
	}
	if (check._Equal("false"))
	{
		position += 5;
	}
	else
	{
		std::exception();
	}
	return new BoolValue(false);
}

Value* deserializeIndex(const std::string& string, int& position)
{	
	filtrWhiteSpaces(string, position);

	Value* ret;
	char chr = string.at(position);

	if (chr == '{')
	{
		filtrWhiteSpaces(string, position);
		ret = createJsonObject(string, position);
	}
	else if (chr == '[')
	{
		filtrWhiteSpaces(string, position);
		ret = createJsonArray(string, position);
	}
	else if (chr == '"')
	{
		filtrWhiteSpaces(string, position);
		ret = readJsonData(string, position);
	}
	else if (chr == '-' || isdigit(chr))
	{
		filtrWhiteSpaces(string, position);
		ret = readJsonNumber(string, position);
	}
	else if (chr == 'n')
	{
		filtrWhiteSpaces(string, position);
		ret = readJsonNull(string, position);
	}
	else if (chr == 't')
	{
		filtrWhiteSpaces(string, position);
		ret = readJsonTrue(string, position);
	}
	else if (chr == 'f')
	{
		filtrWhiteSpaces(string, position);
		ret = readJsonFalse(string, position);
	}
	else throw std::exception(); //TODO

	return ret;
}


Value* JSON::deserialize(const std::string& string)
{
	int pointer = 0;
	//string = filtrWhiteSpaces(string);
	return deserializeIndex(string, pointer);
}



std::string JSON::serialize(const Value* value)
{	
	return value->serialize();
}

