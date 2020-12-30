// Frana_SemestralniPrace.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <api.h>
#include "cui.h"

int main()
{
	cui evidence = cui();    	
	evidence.callChoice();

//		std::cout << "Hello World!\n";
//
		//ObjectValue* ov = new ObjectValue{};
		//ov->append(KeyValuePair{ "bool", new BoolValue{true} });
		//ov->append(KeyValuePair{ "null", new NullValue{} });
		//ov->append(KeyValuePair{ "string", new StringValue{"hello world \\ \" experiment"} });
		//ov->append(KeyValuePair{ "number", new NumberValue{3.141592} });

		//ArrayValue* av = new ArrayValue{};
		//av->append(new NumberValue{ 0 });
		//av->append(new NumberValue{ 1 });
		//av->append(new StringValue{ "two" });
		//av->append(new NumberValue{ 3 });

		//ObjectValue* four = new ObjectValue{};
		//four->append(KeyValuePair{ "four", new NumberValue{4} });
		//av->append(four);
		//av->append(new NumberValue{ 5 });

		//ov->append(KeyValuePair{ "array", av });

		//std::string out1 = ov->serialize();
		//std::cout << out1 << std::endl;

		//std::cout << std::endl;
		//std::cout << std::endl;

		//Value* val0 = JSON::deserialize(out1);
		//std::cout << val0->serialize() << std::endl;
//
//		ObjectValue* test = new ObjectValue{};
//		test->append(KeyValuePair{ "string", new StringValue{"hello world \\ \" experiment"} });
//		test->append(KeyValuePair{ "Jmeno", new StringValue{"Jan"} });
//		test->append(KeyValuePair{ "Prijmeni", new StringValue{"Novak"} });
//
//		std::cout << test->serialize();
//
//		Value* val = JSON::deserialize("{\"employee\":{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}}");
//		std::cout << val->serialize();
//
//		std::cout << std::endl;
//		std::cout << std::endl;
//		std::cout << std::endl;
//
//		std::cout << std::endl;
//		std::cout << std::endl;
//		std::cout << std::endl;
//
//		Value* val2 = JSON::deserialize("{\"glossary\":{\"title\":\"example glossary\",\"GlossDiv\":{\"title\":\"S\",\"GlossList\":{\"GlossEntry\":{\"ID\":\"SGML\",\"SortAs\":\"SGML\",\"GlossTerm\":\"Standard Generalized Markup Language\",\"Acronym\":\"SGML\",\"Abbrev\":\"ISO 8879:1986\",\"GlossDef\":{\"para\":\"A meta-markup language, used to create markup languages such as DocBook.\",\"GlossSeeAlso\":[\"GML\",\"XML\"]},\"GlossSee\":\"markup\"}}}}}");
//		std::cout << val2->serialize();
//
		/*Value* val = JSON::deserialize("{\"alpha\":{\"beta\":100,\"gamma\":200},\"delta\":[0,1,2,3,4,null]}");
		std::cout << val->serialize();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		Value* val2 = JSON::deserialize("{\"alpha\":{\"beta\":100,\"gamma\":200},\"delta\":[0,1,2,3,4,null,{\"a\":\"b\",\"c\":{},\"d\":[],\"e\":true,\"f\":false,\"g\":[{},{},{},[],[]]}]}");
		std::cout << val2->serialize();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		Value* val3 = JSON::deserialize(" { \"alpha\"	:   { \"beta\":100,    \"gamma\":200},	\"delta\": [ 0 , 1 , 2,3, 4 , null ]}");
		std::cout << val3->serialize();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		Value* val4 = JSON::deserialize("{ \"alpha\":{      \"beta\" : 100 , \"gamma\":200},\"delta\" : [ 0 , 1 , 2 ,3      ,4  ,null      , { \"a\"          :\"b\",\"c\":    { }        ,\"d\": [  ] ,\"e\":true, \"f\":false,\"g\":[{ },{ }, {}, [],[ ]]  } ] }");
		std::cout << val4->serialize();*/
}

// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
