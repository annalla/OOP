#pragma once
#include<iostream>
#include<cstdio>
//#include<iterator>
#include<fstream>
using namespace std;
class MyString
{
private:
	char* _str;
	size_t _len;
	size_t _max;
public:
	static const size_t npos = -1;

	//Constructor
	MyString();//default constructor
	MyString(const MyString&a);// copy constructor
	// parameter constructer
	MyString(const char* s);//Copies the null-terminated character sequence pointed by s
	MyString(const char* s, size_t n);//Copies the first n characters from the array of characters pointed by s.
	MyString(const MyString& str, size_t pos, size_t len = npos);//Copies the portion of str that begins at the character position pos and spans len characters 
	MyString(size_t n, char c); //Fills the string with n consecutive copies of character c
	MyString(char* first, char* last);//Copies the sequence of characters in the range [first,last), in the same order.
	
	//Destructor
	~MyString();

	char* begin();
	const char* begin() const;
	char* end();
	const char* end() const;

	size_t size() const;
	size_t length() const;
	size_t max_size() const;

	void resize(size_t n);
	void resize(size_t n, char c);

	size_t capacity() const;
	void shrink_to_fit();
	void reserve(size_t n = 0);

	void clear();
	bool empty() const;

	char& operator[] (size_t pos);
	const char& operator[] (size_t pos) const;

	char& at(size_t pos);
	const char& at(size_t pos) const;

	char& back();
	const char& back() const;

	char& front();
	const char& front() const;

	MyString& operator=(const MyString &a);
	MyString& operator= (const char* s);
	MyString& operator= (char c);

	MyString& operator+= (const MyString& str);
	MyString& operator+= (const char* s);
	MyString& operator+= (char c);

	MyString& append(const MyString& str);
	MyString& append(const MyString& str, size_t subpos, size_t sublen);
	MyString& append(const char* s);
	MyString& append(const char* s, size_t n);
	MyString& append(size_t n, char c);
	MyString& append(char* first, char* last);

	void push_back(char c);

	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str, size_t subpos, size_t sublen);
	MyString& assign(const char* s);
	MyString& assign(const char* s, size_t n);
	MyString& assign(size_t n, char c);
	MyString& assign(char* first, char* last);
	MyString& insert(size_t pos, const MyString& str);
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);
	MyString& insert(size_t pos, const char* s);
	MyString& insert(size_t pos, const char* s, size_t n);
	MyString& insert(size_t pos, size_t n, char c);
	void insert(char* p, size_t n, char c);
	char* insert(char* p, char c);
	void insert(char* p, char* first, char* last);

	MyString& erase(size_t pos = 0, size_t len = npos);
	char* erase(char* p);
	char* erase(char* first, char* last);

	MyString& replace(size_t pos, size_t len, const MyString& str);
	MyString& replace(size_t pos, size_t len, const MyString& str,size_t subpos, size_t sublen);
	MyString& replace(size_t pos, size_t len, const char* s);
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& replace(size_t pos, size_t len, size_t n, char c);
	MyString& replace(char* i1, char* i2, size_t n, char c);
	MyString& replace(char* i1, char* i2, char* first, char* last);
	MyString& replace(char* i1, char* i2, const MyString& str);
	MyString& replace(char* i1, char* i2, const char* s, size_t n);
	MyString& replace(char* i1, char* i2, const char* s);

	void swap(MyString& str);

	void pop_back();

	const char* c_str() const;
	const char* data() const;

	size_t copy(char* s, size_t len, size_t pos = 0) const;

	size_t find(const MyString& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;

	size_t rfind(const MyString& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = npos) const;

	size_t find_first_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;

	size_t find_last_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;

	size_t find_first_not_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;

	size_t find_last_not_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;

	MyString substr(size_t pos = 0, size_t len = npos) const;

	int compare(const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str,size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;

	friend MyString operator+ (const MyString& lhs, const MyString& rhs);
	friend MyString operator+ (const MyString& lhs, const char*   rhs);
	friend MyString operator+ (const char*   lhs, const MyString& rhs);
	friend MyString operator+ (const MyString& lhs, char          rhs);
	friend MyString operator+ (char          lhs, const MyString& rhs);

	friend bool operator== (const MyString& lhs, const MyString& rhs);
	friend bool operator== (const char*   lhs, const MyString& rhs);
	friend bool operator== (const MyString& lhs, const char*   rhs);

	friend bool operator!= (const MyString& lhs, const MyString& rhs);
	friend bool operator!= (const char*   lhs, const MyString& rhs);
	friend bool operator!= (const MyString& lhs, const char*   rhs);

	friend bool operator<  (const MyString& lhs, const MyString& rhs);
	friend bool operator<  (const char*   lhs, const MyString& rhs);
	friend bool operator<  (const MyString& lhs, const char*   rhs);

	friend bool operator<= (const MyString& lhs, const MyString& rhs);
	friend bool operator<= (const char*   lhs, const MyString& rhs);
	friend bool operator<= (const MyString& lhs, const char*   rhs);

	friend bool operator>  (const MyString& lhs, const MyString& rhs);
	friend bool operator>  (const char*   lhs, const MyString& rhs);
	friend bool operator>  (const MyString& lhs, const char*   rhs);

	friend bool operator>= (const MyString& lhs, const MyString& rhs);
	friend bool operator>= (const char*   lhs, const MyString& rhs);
	friend bool operator>= (const MyString& lhs, const char*   rhs);

	friend void swap(MyString& x, MyString& y);
	friend istream& operator>> (istream& is, MyString& str);
	friend ostream& operator<<(ostream&out,const MyString&a);
	friend istream& getline(istream& is, MyString& str, char delim);
	friend istream& getline(istream& is, MyString& str);
};

