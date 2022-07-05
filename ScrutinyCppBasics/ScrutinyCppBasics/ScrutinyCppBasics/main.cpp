#include <iostream>
#include <vector>
////////////////////////////////////////////////////////////////////////////////////////////////////
/*
*		A namespace - is an declarative area within various indentifiers (names of types, 
* functions, variables etc.) are defined. [ = Пространство имен — это декларативная область, в 
* рамках которой определяются различные идентификаторы (имена типов, функций, переменных, и т.д.).]
*    1.1 Доступ за пределами пространства имен к идентификатору можно получить с помощью: 1) полного 
* имени для каждого идентификатора, например 'std::vector<std::string> vec;'; 2) с помощью 
* объявления для одного идентификатора (using std::string) или директивы using для всех идентификаторов 
* в пространстве имен (using namespace std;). Код в файлах заголовков всегда должен содержать полное 
имя в пространстве имен.
*/

// Declaring namespace.
namespace space1 {

	//   [1.1] An identifier can be accessed outside of the namespace by: 1) the fully qualified name for 
	//each identifier like: 'std::vector<std::string> vec;';
	std::string str1;
	
	// 2) with using declaration for single indentifier like:
	using std::string;
	string str2; // (You can use it withon namespase...!!!)


	using namespace std;

	vector<string> vec_s;

	class A {
		A() {
			//   1.1 'SIZE' accessible in class 'A' and so on (structs)
		}
	};

	A::A()
	{
	}

	A::~A()
	{
	}
}

int main() {

	return 0;
}