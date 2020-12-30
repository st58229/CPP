#ifndef API_H
#define API_H
#include <string>
#include "platform.h"

// - �ablona s parametrem datov�ho typu ulo�en�ch hodnot
// - nen� povoleno u�it� STL kontejner� ani jin�ch knihoven pro ukl�d�n� dat
// - realizace mus� vyu��vat dynamicky alokovan� pole, spojov� seznam nebo jinou vhodnou V�mi implementovanou ADS 
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

	// - p�id� element na konec pole
	void append(const T& element);

	// - v�jimky p�i neplatn�m nebo nekorektn�m indexu
	const T& getElementAt(int index) const;

	// - vrac� velikost (po�et prvk�) v poli
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
	int newSize = size + (size/2); //Nav��en� o 50% kapacity
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

// JSON hodnota - reprezentuje abstraktn�ho p�edka pro z�kladn� datov� typy v JSON (string, number, object, array, bool, null)
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

	// - vrac� bool hodnotu
	bool get() const;

	virtual std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON ��slo
class DLL_SPEC NumberValue :
	public Value
{
private:
	double value;
public:
	NumberValue();
	NumberValue(double value);

	// - vrac� ��selnou hodnotu 
	double get() const;

	virtual std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - reprezentuje hodnotu typu JSON �et�zec (string)
class DLL_SPEC StringValue :
	public Value
{
private:
	std::string value;
public:
	StringValue();
	StringValue(std::string value);

	void escapeChar();
	// - vrac� �et�zcovou hodnotu
	std::string get() const;

	virtual std::string serialize() const override;
};

///////////////////////////////////////////////////////////////////////////////

// - definuje p�r kl�� (�et�zec) a hodnota (JSON hodnota) pro reprezentaci hodnot JSON objektu
class DLL_SPEC KeyValuePair {
private:
	std::string _key;
	Value* _value;

public:
	KeyValuePair();
	KeyValuePair(std::string key, Value* value);

	// - vr�t� kl��
	std::string getKey() const;
	// - vr�t� hodnotu
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

	// - p�id� element na konec pole
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

	// - p�id� kl��-element do objektu
	void append(const KeyValuePair& pair);

	virtual std::string serialize() const override;

	const KeyValuePair get(int index);
	int getSize();
	void remove(int index);

private:
	DynamicArray<KeyValuePair> objectValues;
};

///////////////////////////////////////////////////////////////////////////////

// - t��da pro pr�ci s JSON
class DLL_SPEC JSON
{

private:
	
	//static Value* deserializeIndex(const std::string& string, int& position);

public:
	// - provede deserializaci �et�zce na vytvo�en� objekty
	// - p�e�tu znak a rozhodnu se
	// -- '{' - za��n�m ��st objekt
	// -------- �tu znaky, pak mus� b�t dvojte�ka, potom vol�m rekurzivn� deserialize(); n�sleduje ��rka nebo '}', podle situace se �ten� opakuje
	// -- '[' - za��n�m ��st pole
	// -------- vol�m rekurzivn� deserialize(); n�sleduje ��rka nebo ']', podle situace se �ten� opakuje
	// -- '"' - za��n�m ��st �et�zec - pozor na escapovan� uvozovky
	// -- [-0123456789] - za��n�m ��st ��slo - na�tu v�echny ��slice (pozor na mo�nou desetinnou te�ku)
	// -- 'n' - 'null'
	// -- 't' - 'true'
	// -- 'f' - 'false'
	// -- cokoliv jin�ho - vyvol�v�m v�jimku
	// - nen� p��pustn� vracet nullptr
	// - deserializace mus� b�t rozumn� implementov�na - nen� p��pustn� zde napsat jednu extr�mn� dlouhou metodu
	static Value* deserialize(const std::string& string);
	
	// - provede serializaci do JSON �et�zce
	static std::string serialize(const Value* value);
};

#endif 
///////////////////////////////////////////////////////////////////////////////