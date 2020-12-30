#ifndef API_H
#define API_H
#include <string>
#include "platform.h"

// - šablona s parametrem datového typu uložených hodnot
// - není povoleno užití STL kontejnerù ani jiných knihoven pro ukládání dat
// - realizace musí využívat dynamicky alokované pole, spojový seznam nebo jinou vhodnou Vámi implementovanou ADS 
template<typename T>
class DynamicArray {
private:
	T* field;
	int size;
	int items;
	void increase();
	bool isNotFull() const;
	const int startSize = 5;

public:
	DynamicArray();
	~DynamicArray();

	// - pøidá element na konec pole
	void append(const T& element);

	// - výjimky pøi neplatném nebo nekorektním indexu
	const T& getElementAt(int index) const;

	// - vrací velikost (poèet prvkù) v poli
	int getSize() const;

	void remove(int index);

	T& operator[](int index);
	T operator[](int index) const;
};

template <typename T>
bool DynamicArray<T>::isNotFull() const
{
	if (items < size)
	{
		return true;
	}
	return false;
}

template <typename T>
void DynamicArray<T>::increase()
{	
	int newSize = size + (size/2); //Navýšení o 50% kapacity
	T* newField = new T[newSize];

	for (int i = 0; i < size; i++) {
		newField[i] = field[i];
	}

	delete[] field;
	field = newField;
	size = newSize;
}

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	field = new T[startSize];
	size = startSize;
	items = 0;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] field;
}

template<typename T>
inline void DynamicArray<T>::append(const T& element)
{
	if (!isNotFull())
	{
		increase();

	}		
	
	field[items] = element;
	items++;	
}

template<typename T>
inline const T& DynamicArray<T>::getElementAt(int index) const
{
	if (index >= items || index < 0)
	{
		throw std::exception();
	}
	return field[index];
}

template<typename T>
inline int DynamicArray<T>::getSize() const
{
	return items;
}

template <typename T>
void DynamicArray<T>::remove(int index)
{
	if (index > items - 1)
	{
		throw std::exception();
	}
	else if (index == items - 1)
	{
		items--;
	}
	else
	{
		for (size_t i = index; i < items; i++)	field[i] = field[i + 1];
		items--;
	}
}

template <typename T>
T& DynamicArray<T>::operator[](int index)
{
	if (index >= items)
	{
		throw std::exception();
	}
	return field[index];
}

template <typename T>
T DynamicArray<T>::operator[](int index) const
{
	if (index > items - 1)
	{
		throw std::exception();
	}
	return field[index];
}

///////////////////////////////////////////////////////////////////////////////

// JSON hodnota - reprezentuje abstraktního pøedka pro základní datové typy v JSON (string, number, object, array, bool, null)
class DLL_SPEC Value
{
public:
	// serializuje hodnotu do podoby JSON reprezentace
	virtual std::string serialize() const = 0;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON null
class DLL_SPEC NullValue :
	public Value
{
public:
	virtual std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON bool
class DLL_SPEC BoolValue :
	public Value
{
private:
	bool value;
public:
	BoolValue();
	BoolValue(bool value);

	// - vrací bool hodnotu
	bool get() const;

	virtual std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON èíslo
class DLL_SPEC NumberValue :
	public Value
{
private:
	double value;
public:
	NumberValue();
	NumberValue(double value);

	// - vrací èíselnou hodnotu 
	double get() const;

	virtual std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON øetìzec (string)
class DLL_SPEC StringValue :
	public Value
{
private:
	std::string value;
public:
	StringValue();
	StringValue(std::string value);

	void escapeChar();
	// - vrací øetìzcovou hodnotu
	std::string get() const;

	virtual std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - definuje pár klíè (øetìzec) a hodnota (JSON hodnota) pro reprezentaci hodnot JSON objektu
class DLL_SPEC KeyValuePair {
private:
	std::string _key;
	Value* _value;

public:
	KeyValuePair();
	KeyValuePair(std::string key, Value* value);

	// - vrátí klíè
	std::string getKey() const;
	// - vrátí hodnotu
	Value* getValue() const;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON pole
class DLL_SPEC ArrayValue :
	public Value
{
public:
	ArrayValue();
	~ArrayValue();

	// - pøidá element na konec pole
	void append(Value* element);

	virtual std::string serialize() const override;

	Value* get(int index);
	int getSize();
	void remove(int index);

private:
	DynamicArray<Value*> arrayValues;	
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON objekt
class DLL_SPEC ObjectValue :
	public Value
{
public:

	ObjectValue();
	~ObjectValue();

	// - pøidá klíè-element do objektu
	void append(const KeyValuePair& pair);

	virtual std::string serialize() const override;

	const KeyValuePair get(int index);
	int getSize();
	void remove(int index);

private:
	DynamicArray<KeyValuePair> objectValues;
};

///////////////////////////////////////////////////////////////////////////////

// - tøída pro práci s JSON
class DLL_SPEC JSON
{

private:
	
	//static Value* deserializeIndex(const std::string& string, int& position);

public:
	// - provede deserializaci øetìzce na vytvoøené objekty
	// - pøeètu znak a rozhodnu se
	// -- '{' - zaèínám èíst objekt
	// -------- ètu znaky, pak musí být dvojteèka, potom volám rekurzivnì deserialize(); následuje èárka nebo '}', podle situace se ètení opakuje
	// -- '[' - zaèínám èíst pole
	// -------- volám rekurzivnì deserialize(); následuje èárka nebo ']', podle situace se ètení opakuje
	// -- '"' - zaèínám èíst øetìzec - pozor na escapované uvozovky
	// -- [-0123456789] - zaèínám èíst èíslo - naètu všechny èíslice (pozor na možnou desetinnou teèku)
	// -- 'n' - 'null'
	// -- 't' - 'true'
	// -- 'f' - 'false'
	// -- cokoliv jiného - vyvolávám výjimku
	// - není pøípustné vracet nullptr
	// - deserializace musí být rozumnì implementována - není pøípustné zde napsat jednu extrémnì dlouhou metodu
	static Value* deserialize(const std::string& string);
	
	// - provede serializaci do JSON øetìzce
	static std::string serialize(const Value* value);
};

#endif 
///////////////////////////////////////////////////////////////////////////////