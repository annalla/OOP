#pragma warning(disable:4996)
#include"MyString.h"
#include<cstring>
#include<string>
int main()
{
	MyString s;
	getline(std::cin,s,'d');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//// let's replace the first needle:
	//str.replace(str.find(str2), str2.length(), "preposition");
	//std::cout << str << '\n';
	
	//MyString base = "this is a test string.";
	//MyString str2 = "n example";
	//MyString str3 = "sample phrase";
	//MyString str4 = "useful.";

	//// replace signatures used in the same order as described above:

	//// Using positions:                 0123456789*123456789*12345
	//MyString str = base;           // "this is a test string."
	//str.replace(9, 5, str2);      
	//cout << str << endl;// "this is an example string." (1)
	//str.replace(19, 6, str3, 7, 6);  
	//cout << str << endl;// "this is an example phrase." (2)
	//str.replace(8, 10, "just a");    
	//cout << str << endl;// "this is just a phrase."     (3)
	//str.replace(8, 6, "a shorty", 7);  
	//cout << str << endl;// "this is a short phrase."    (4)
	//str.replace(22, 1, 3, '!');  
	//cout << str << endl;// "this is a short phrase!!!"  (5)

	// used in the same order as described above:
	//str.insert(6, str2);                 // to be (the )question
	//str.insert(6, str3, 3, 4);             // to be (not )the question
	//str.insert(10, "that is cool", 8);    // to be not (that is )the question
	//str.insert(10, "to be ");            // to be not (to be )that is the question
	//str.insert(15, 1, ':');
	//std::cout << str << '\n';
	//MyString name("John");
	//MyString family("Smith");
	//name += " K. ";         // c-string
	//name += family;         // string
	//name += '\n';           // character
	/*MyString str("I like to code in C");
	std::cout << str << '\n';
	char c = 'c';
	str = c;
	std::cout << str << '\n';
	unsigned sz = str.size();
	str.resize(14);
	std::cout << str << '\n';
	str.resize(sz + 2, '+');*/
	/*std::cout << str << '\n';
*/
	//MyString str;
	//MyString str2 = "Writing ";
	//MyString str3 = "print 10 and then 5 more";

	//// used in the same order as described above:
	//str.append(str2);                       // "Writing "
	//str.append(str3, 6, 3);                   // "10 "
	//str.append("dots are cool", 5);          // "dots "
	//str.append("here: ");                   // "here: "
	//str.append(10u, '.');                    // ".........."
	//

	/*std::cout << str << '\n';*/
	//MyString str;
	//std::ifstream file("test.txt", std::ios::in);
	//if (file) {
	//	while (!file.eof()) str.push_back(file.get());
	//}
	//std::cout << str << '\n';
	system("pause");
	return 0;
	
	return 0;
}
