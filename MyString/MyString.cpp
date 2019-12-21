#include "MyString.h"


MyString::MyString()
{
	_len = 0;
	_max = 15;
	_str = NULL;
}
MyString::MyString(const MyString&a)
{
	_len = a._len;
	_max = a._max;
	_str = new char[a._max];
	for (int i = 0; i < _len; i++)
		_str[i] = a._str[i];
	_str[_len] = 0;
}
MyString::MyString(const char* s)
{
	size_t n = strlen(s);
	_len = n;
	_max = 16 * (_len / 16 + 1) - 1;
	_str = new char[_max];
	for (int i = 0; i < _len; i++)
		_str[i] = s[i];
	_str[_len] = 0;
}
MyString::MyString(const char* s, size_t n)
{
	_len = n;
	_max = 16 * (_len / 16 + 1) - 1;
	_str = new char[_max];
	for (int i = 0; i < _len; i++)
		_str[i] =s[i];
	_str[_len] = 0;
}
MyString::MyString(const MyString& str, size_t pos, size_t len)
{
	if (len == npos)
	{
		_len = str._len-pos;
		_max = 16 * (_len / 16 + 1) - 1;
		_str = new char[_max];
		for (int i = 0, j = pos; i < _len; i++, j++)
			_str[i] = str._str[j];
		_str[_len] = 0;
	}
	else
	{
		_len = len;
		_max = 16 * (_len / 16 + 1) - 1;
		_str = new char[_max];
		for (int i = 0, j = pos; i < _len; i++, j++)
			_str[i] = str._str[j];
		_str[_len] = 0;
	}

}
MyString::MyString(size_t n, char c)
{
	_len = n;
	_max = 16 * (_len / 16 + 1) - 1;
	_str = new char[_max];
	for (int i = 0; i < _len; i++)
		_str[i] = c;
}
MyString::MyString(char* first, char* last)
{
	_len = last-first;
	_max = 16 * (_len / 16 + 1) - 1;
	_str = new char[_max];
	for (int i = 0; i < _len; i++,first++)
		_str[i] = *first;
	
}

MyString::~MyString()
{
	if (_str != NULL)
		delete[]_str;
	_str = NULL;
}



MyString& MyString::operator=(const MyString &a)
{
	if (this != &a)
	{
		if (_str != NULL)
			delete[]_str;
		_len = a._len;
		_max = 16 * (_len / 16 + 1) - 1;
		_str = new char[_max];
		for (int i = 0; i < _len; i++)
			_str[i] = a._str[i];
		_str[_len] = 0;
	}
	return *this;
}
MyString& MyString::operator= (const char* s)
{
	size_t n = strlen(s);
	if (_str != NULL)
		delete[]_str;
	_len = n;
	_max = 16 * (_len / 16 + 1) - 1;
	_str = new char[_max];
	for (int i = 0; i < _len; i++)
		_str[i] = s[i];
	_str[_len] = 0;
	return *this;
}
MyString& MyString::operator= (char c)
{
	if (_str != NULL)
		delete[]_str;
	_len = 1;
	_max = 16 * (_len / 16 + 1) - 1;
	_str = new char[_max];
	_str[0] = c;
	_str[1] = 0;
	return *this;
}

char* MyString::begin()
{
	return &_str[0];
}
const char* MyString::begin() const
{
	return &_str[0];
}
char* MyString::end()
{
	return &_str[_len];
}
const char* MyString::end() const
{
	return &_str[_len];
}

size_t MyString::size() const
{
	return _len;
}
size_t MyString::length() const
{
	return _len;
}
size_t MyString::max_size() const
{
	return 2147483647;
}

void MyString ::resize(size_t n)
{
	if (_str == NULL)
	{
		_len = n;
		_max = 16 * (_len / 16 + 1) - 1;
		_str = new char[_max];
		for (size_t i = 0; i < n; i++)
			_str[i] = 0;
		return;
	}
	if (n <= _len)
	{
		for (size_t i = n; i < _len; i++)
			_str[i] = 0;
		_len = n;
		return;
	}
	if(n>_max)
	{
		char *s;
		s = new char[16 * (n / 16 + 1) - 1];
		if (_len < n)
		{
			for (size_t i = 0; i < _len; i++)
				s[i] = _str[i];
			for (size_t i = _len; i < n; i++)
				s[i] = 0;
		}
		delete[] _str;
		_len = n;
		_max = 16 * (_len / 16 + 1) - 1;
		_str = s;
	}
	else
	{
		_len = n;
		for (size_t i = n; i < _len; i++)
			_str[i] = 0;
	}
	
}
void MyString::resize(size_t n, char c)
{
	if (_str == NULL)
	{
		_len = n;
		_max = 16 * (_len / 16 + 1) - 1;
		_str = new char[_max];
		for (size_t i = 0; i < _len; i++)
			_str[i] = c;
		return;
	}
	if (n <= _len)
	{
		for (size_t i = n; i < _len; i++)
			_str[i] = 0;
		_len = n;
		return;
	}
	if (n > _max)
	{
		char *s;
		s = new char[16 * (n / 16 + 1) - 1];
		if (_len < n)
		{

			for (size_t i = 0; i < _len; i++)
				s[i] = _str[i];
			for (size_t i = _len; i < n; i++)
				s[i] = c;
		}
		delete[] _str;
		_len = n;
		_max = 16 * (_len / 16 + 1) - 1;
		_str = s;
	}
	else
	{
		_len = n;
		for (size_t i = n; i < _len; i++)
			_str[i] = c;
	}
}

void MyString::shrink_to_fit()
{
	if (_len < _max)
	{
		char *s = new char[_len];
		_max = _len;
		for (size_t i = 0; i < _len; i++)
			s[i] = _str[i];
		delete[]_str;
		_str = s;
	}
}
size_t MyString::capacity() const
{
	return _max;
}
void MyString::reserve(size_t n )
{
	if (n > _max)
	{
		_max = 16 * (n / 16 + 1) - 1;
		char *s = new char[_max];
		for (size_t i = 0; i < _len; i++)
			s[i] = _str[i];
		s[_len] = 0;
		delete[]_str;
		_str = s;
	}
		
	return;
}

void MyString::clear()
{
	char*s = _str;
	_len = 0;
	_max = 15;
	_str = NULL;
	if (s != NULL) return;
	else
		delete[] s;
	
}
bool  MyString::empty() const
{
	if (_len == 0)
		return true;
	else
		return false;
}

char& MyString::operator[] (size_t pos)
{
	if (pos >= _len)
	{
		cout << "String index out of bound!";
		exit(0);
	}
	return _str[pos];
}
const char& MyString::operator[] (size_t pos) const
{
	if (pos >= _len)
	{
		cout << "String index out of bound!";
		exit(0);
	}
	return _str[pos];
}

char& MyString::at(size_t pos)
{
	if (pos >= _len)
	{
		cout << "String index out of bound!";
		exit(0);
	}
	return _str[pos];
}
const char& MyString::at(size_t pos) const
{
	if (pos >= _len)
	{
		cout << "String index out of bound!";
		exit(0);
	}
	return _str[pos];
}

char& MyString::back()
{
	if(_len!=0)
	 return _str[_len-1];
	else
	{
		cout << "String is empty";
		exit(0);
	}

}
const char& MyString::back() const
{
	if (_len != 0)
		return _str[_len - 1];
	else
	{
		cout << "String is empty\n";
		exit(0);
	}
}

char& MyString::front()
{
	if (_len != 0)
		return _str[0];
	else
	{
		cout << "String is empty\n";
		exit(0);
	}
}
const char& MyString::front() const
{
	if (_len != 0)
		return _str[0];
	else
	{
		cout << "String is empty\n";
		exit(0);
	}
}

MyString& MyString::operator+= (const MyString& str)
{
	MyString a(*this);
	size_t n = _len;
	resize(_len+str._len);
	for (size_t i = 0; i < a._len; i++)
		_str[i] = a._str[i];
	for (size_t j=0,i=n; i < _len; i++,j++)
	{
		_str[i] = str._str[j];
	}
	return *this;
}
MyString& MyString::operator+= (const char* s)
{
	MyString a(*this);
	size_t n = _len;
	resize(_len+strlen(s));
	for (size_t i = 0; i < a._len; i++)
		_str[i] = a._str[i];
	for (size_t j = 0, i=n; i < _len; i++, j++)
	{
		_str[i] =(char) s[j];
	}
	return *this;
}
MyString& MyString::operator+= (char c)
{
	MyString a(*this);
	size_t i = _len;
	resize(_len+1);
	for (size_t i = 0; i < a._len; i++)
		_str[i] = a._str[i];
	_str[i] = c;
	return *this;
}

MyString& MyString::append(const MyString& str)
{
	MyString a(*this);
	size_t n = _len;
	resize(_len+str._len);
	for (size_t i = 0; i < a._len; i++)
		_str[i] = a._str[i];
	for (size_t j = 0, i=n; i < _len; i++, j++)
	{
		_str[i] = str._str[j];
	}
	return *this;
}
MyString& MyString::append(const MyString& str, size_t subpos, size_t sublen)
{
	MyString a(*this);
	size_t n = _len;
	resize(_len+sublen);
	for (size_t i = 0; i < a._len; i++)
		_str[i] = a._str[i];
	for (size_t j = subpos, i=n; i < _len; i++, j++)
	{
		_str[i] = str._str[j];
	}
	return *this;
}
MyString& MyString::append(const char* s)
{
	MyString a(*this);
	size_t n = _len;
	resize(_len+strlen(s));
	for (size_t i = 0; i < a._len; i++)
		_str[i] = a._str[i];
	for (size_t j = 0, i=n; i < _len; i++, j++)
	{
		_str[i] = (char)s[j];
	}
	return *this;
}
MyString& MyString::append(const char* s, size_t n)
{
	MyString a(*this);
	size_t len = _len;
	resize(_len+n);
	for (size_t i = 0; i < a._len; i++)
		_str[i] = a._str[i];
	for (size_t j = 0, i=len; i < _len; i++, j++)
	{
		_str[i] = (char)s[j];
	}
	return *this;
}
MyString& MyString::append(size_t n, char c)
{
	MyString a(*this);
	size_t len = _len;
	resize(_len+n);
	for (size_t i = 0; i < a._len; i++)
		_str[i] = a._str[i];
	for (size_t  i=len; i < _len; i++)
	{
		_str[i] = c;
	}
	return *this;
}
MyString& MyString::append(char* first, char* last)
{
	MyString a(*this);
	size_t len = _len;
	resize(_len + (last-first));
	for (size_t i = 0; i < a._len; i++)
		_str[i] = a._str[i];
	for (size_t j = 0, i = len; i < _len; i++, j++,first++)
	{
		_str[i] = *first;
	}
	return *this;
}

void MyString::push_back(char c)
{
	MyString a(*this);
	size_t len = _len;
	this->resize(_len+1);
	for (size_t i = 0; i < a._len; i++)
		_str[i] = a._str[i];
	_str[len] = c;
}

MyString& MyString::assign(const MyString& str)
{
	*this = str;
	return *this;
}
MyString&  MyString::assign(const MyString& str, size_t subpos, size_t sublen)
{
	if (this == &str)
	{
		MyString a(*this);
		delete[] _str;
		_len = sublen;
		_max = 16 * (_len / 16 + 1) - 1;
		_str = new char[_max];
		for (size_t i = subpos, j = 0; j < _len; j++, i++)
			_str[j] = a._str[i];
		return *this;
	}
	if (_str != NULL)
	{
		delete[] _str;
	}
	_len = sublen;
	_max = 16 * (_len / 16 + 1) - 1;
	_str = new char[_max];
	for (size_t i = subpos, j = 0; j < _len; j++, i++)
		_str[j] = str._str[i];
	_str[_len] = 0;
	return *this;
	
}
MyString&  MyString::assign(const char* s)
{
	*this = s;
	return *this;
}
MyString&  MyString::assign(const char* s, size_t n)
{
	if (_str != NULL)
	{
		delete[] _str;
	}
	_len = n;
	_max = 16 * (_len / 16 + 1) - 1;
	_str = new char[_max];
	for (size_t j = 0; j < _len; j++)
		_str[j] = s[j];
	_str[_len] = 0;
	return *this;
}
MyString&  MyString::assign(size_t n, char c)
{
	if (_str != NULL)
	{
		delete[] _str;
	}
	_len = n;
	_max = 16 * (_len / 16 + 1) - 1;
	_str = new char[_max];
	for (size_t j = 0; j < _len; j++)
		_str[j] = c;
	_str[_len] = 0;
	return *this;
}
MyString& MyString::assign(char* first, char* last)
{
	if (_str != NULL)
	{
		delete[] _str;
	}
	_len = last-first;
	_max = 16 * (_len / 16 + 1) - 1;
	_str = new char[_max];
	for (size_t j = 0; j < _len; j++,first++)
		_str[j] = *first;
	_str[_len] = 0;
	return *this;
}

MyString& MyString::insert(size_t pos, const MyString& str)
{
	char*s;
	s = new char[_len - pos];
	size_t j = 0;
	for (size_t i = pos, j = 0; i < _len; i++, j++)
		s[j] = _str[i];
	resize(_len+str._len);
	size_t i = 0;
	for (j = pos,i=0; i < str._len; i++, j++)
	{
		_str[j] = str._str[i];
	}
	for (j=j, i = 0; j < _len; j++, i++)
		_str[j] = s[i];
	_str[_len] = 0;
	return *this;
}
MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen)
{
	char*s;
	s = new char[_len - pos];
	size_t j = 0;
	for (size_t i = pos, j=0; i < _len; i++, j++)
		s[j] = _str[i];
	resize(_len+sublen);
	size_t i = 0;
	for (j = pos, i = subpos; i < (subpos+sublen); i++, j++)
	{
		_str[j] = str._str[i];
	}
	for (j=j, i = 0; j < _len; j++, i++)
		_str[j] = s[i];
	_str[_len] = 0;
	return *this;
}
MyString& MyString::insert(size_t pos, const char* s)
{
	char*s1;
	s1 = new char[_len - pos];
	size_t j = 0;
	for (size_t i = pos, j=0; i < _len; i++, j++)
		s1[j] = _str[i];
	resize(_len+strlen(s));
	size_t i = 0;
	for (j = pos, i = 0; i < strlen(s); i++, j++)
	{
		_str[j] =(char) s[i];
	}
	for (j=j, i = 0; j < _len; j++, i++)
		_str[j] = s1[i];
	_str[_len] = 0;
	return *this;
}
MyString& MyString::insert(size_t pos, const char* s, size_t n)
{
	char*s1;
	s1 = new char[_len - pos];
	size_t j = 0;
	for (size_t i = pos, j=0; i < _len; i++, j++)
		s1[j] = _str[i];
	resize(_len+n);
	size_t i = 0;
	for (j = pos, i = 0; i < n; i++, j++)
	{
		_str[j] = (char)s[i];
	}
	for (j, i = 0; j < _len; j++, i++)
		_str[j] = s1[i];
	_str[_len] = 0;
	return *this;
}
MyString& MyString::insert(size_t pos, size_t n, char c)
{
	char*s1;
	s1 = new char[_len - pos];
	size_t j = 0;
	for (size_t i = pos, j=0; i < _len; i++, j++)
		s1[j] = _str[i];
	resize(_len+n);
	size_t i = 0;
	for (j = pos, i = 0; i < n; i++, j++)
	{
		_str[j] = c;
	}
	for (j, i = 0; j < _len; j++, i++)
		_str[j] = s1[i];
	_str[_len] = 0;
	return *this;
}
void MyString::insert(char* p, size_t n, char c)
{
	char*s1;
	s1 = new char[_len];
	size_t j = 0;
	for (char* i=p, j =0; i!=end(); i++, j++)
		s1[j] = *i;
	cout << j << endl;
	resize(_len + n);
	size_t i = 0;
	char*m = p;
	for (m=p, i = 0; i < n; i++)
	{
		*m = c;
		m++;
	}
	for ( size_t h = 0; m!=end(); h++)
	{
		*m = s1[h];
		m++;
	}
		
}
char* MyString::insert(char* p, char c)
{
	char*s1;
	s1 = new char[_len];
	size_t j = 0;
	for (char* i = p, j = 0; i != end(); i++, j++)
		s1[j] = *i;
	cout << j << endl;
	resize(_len + 1);
	size_t i = 0;
	char*m = p;
	*m = c;
	m++;
	for (size_t h = 0; m != end(); h++)
	{
		*m = s1[h];
		m++;
	}
	return p;
}
void MyString::insert(char* p, char* first, char* last)
{
	char*s1;
	s1 = new char[_len];
	size_t j = 0;
	for (char* i = p, j = 0; i != end(); i++, j++)
		s1[j] = *i;
	cout << j << endl;
	resize(_len + (last-first));
	char*m = p;
	for (char* i=first; i !=last; i++)
	{
		*m = *i;
		m++;
	}
	for (size_t h = 0; m != end(); h++)
	{
		*m = s1[h];
		m++;
	}
}

MyString& MyString::erase(size_t pos, size_t len)
{
	if (len == npos)
	{
		_len=pos;
		_str[_len] = 0;
		return *this;
	}
	else
	{
		_len -= len;
		for (size_t i = pos, n = pos + len; i < _len; i++, n++)
			_str[i] = _str[n];
		return *this;
	}

}
char* MyString::erase(char* p)
{
	_len--;
	for (char* i = p; i!=end(); i++)
		*i = *(i+1);
	return p;
}
char* MyString::erase(char* first, char* last)
{
	_len -= (last-first);
	for (char* i = first,*j=last; i != end(); i++,j++)
		*i = *j;
	return first;
}

MyString& MyString::replace(size_t pos, size_t len, const MyString& str)
{
	char*s;
	s = new char[_len - (pos+len)];
	size_t j = 0;
	for (size_t i = pos+len, j = 0; i < _len; i++, j++)
		s[j] = _str[i];
	resize(_len + str._len-len);
	size_t i = 0;
	for (j = pos, i = 0; i < str._len; i++, j++)
	{
		_str[j] = str._str[i];
	}
	for (j = j, i = 0; j < _len; j++, i++)
		_str[j] = s[i];
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen)
{
	char*s;
	s = new char[_len - (pos+len) ];
	size_t j = 0;
	for (size_t i = pos+len, j = 0; i < _len; i++, j++)
		s[j] = _str[i];
	resize(_len + sublen-len);
	size_t i = 0;
	for (j = pos, i = subpos; i < (subpos + sublen); i++, j++)
	{
		_str[j] = str._str[i];
	}
	for (j = j, i = 0; j < _len; j++, i++)
		_str[j] = s[i];
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const char* s)
{
	char*s1;
	s1 = new char[_len - (pos+len)];
	size_t j = 0;
	for (size_t i = pos+len, j = 0; i < _len; i++, j++)
		s1[j] = _str[i];
	resize(_len + strlen(s)-len);
	size_t i = 0;
	for (j = pos, i = 0; i < strlen(s); i++, j++)
	{
		_str[j] = (char)s[i];
	}
	for (j = j, i = 0; j < _len; j++, i++)
		_str[j] = s1[i];
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const char* s, size_t n)
{
	char*s1;
	s1 = new char[_len - (pos+len)];
	size_t j = 0;
	for (size_t i = pos+len, j = 0; i < _len; i++, j++)
		s1[j] = _str[i];
	resize(_len + n-len);
	size_t i = 0;
	for (j = pos, i = 0; i < n; i++, j++)
	{
		_str[j] = (char)s[i];
	}
	for (j, i = 0; j < _len; j++, i++)
		_str[j] = s1[i];
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, size_t n, char c)
{
	char*s1;
	s1 = new char[_len - (pos+len)];
	size_t j = 0;
	for (size_t i = pos+len, j = 0; i < _len; i++, j++)
		s1[j] = _str[i];
	resize(_len + n-len);
	size_t i = 0;
	for (j = pos, i = 0; i < n; i++, j++)
	{
		_str[j] = c;
	}
	for (j, i = 0; j < _len; j++, i++)
		_str[j] = s1[i];
	return *this;
}
MyString& MyString::replace(char* i1, char* i2, size_t n, char c)
{
	char*s1;
	s1 = new char[_len];
	size_t j = 0;
	for (char* h = i2;h!=end();h++,j++)
		s1[j] = *h;
	resize(_len + n - (i2-i1));
	size_t i = 0;
	char* h = i1;
	for (i = 0; i < n; i++)
	{
		*h = c;
		h++;
	}
	for (i=0; h!=end(); h++,i++)
		*h = s1[i];
	return *this;
}
MyString& MyString::replace(char* i1, char* i2, char* first, char* last)
{
	char*s1;
	s1 = new char[_len];
	size_t j = 0;
	for (char* h = i2; h != end(); h++, j++)
		s1[j] = *h;
	resize(_len + (last-first) - (i2 - i1));
	size_t i = 0;
	char* h = i1;
	char*m = first;
	for (i = 0; i < (last - first); i++)
	{
		*h = *m;
		m++;
		h++;
	}
	for (i = 0; h != end(); h++, i++)
		*h = s1[i];
	return *this;
}
MyString& MyString::replace(char* i1, char* i2, const MyString& str)
{
	char*s1;
	s1 = new char[_len];
	size_t j = 0;
	for (char* h = i2; h != end(); h++, j++)
		s1[j] = *h;
	resize(_len + str._len - (i2 - i1));
	size_t i = 0;
	char* h = i1;
	for (i = 0; i < str._len; i++)
	{
		*h = str._str[i];
		h++;
	}
	for (i = 0; h != end(); h++, i++)
		*h = s1[i];
	return *this;
}
MyString& MyString::replace(char* i1, char* i2, const char* s, size_t n)
{
	char*s1;
	s1 = new char[_len];
	size_t j = 0;
	for (char* h = i2; h != end(); h++, j++)
		s1[j] = *h;
	resize(_len + n - (i2 - i1));
	size_t i = 0;
	char* h = i1;
	for (i = 0; i < n; i++)
	{
		*h = s[i];
		h++;
	}
	for (i = 0; h != end(); h++, i++)
		*h = s1[i];
	return *this;
}
MyString& MyString::replace(char* i1, char* i2, const char* s)
{
	char*s1;
	s1 = new char[_len];
	size_t j = 0;
	for (char* h = i2; h != end(); h++, j++)
		s1[j] = *h;
	resize(_len + strlen(s) - (i2 - i1));
	size_t i = 0;
	char* h = i1;
	for (i = 0; i < strlen(s); i++)
	{
		*h = s[i];
		h++;
	}
	for (i = 0; h != end(); h++, i++)
		*h = s1[i];
	return *this;
}

void MyString::swap(MyString& str)
{
	MyString tmp(*this);
	*this=str;
	str = tmp;
}

void  MyString::pop_back()
{
	_str[_len-1] = 0;
	_len--;
}

const char* MyString::c_str() const
{
	return _str;
}
const char* MyString::data() const
{
	return _str;
}

size_t MyString::copy(char* s, size_t len, size_t pos ) const
{
	if (pos + len > _len)
	{
		for (size_t i = pos, j = 0; i < _len; i++, j++)
			s[j] = _str[i];
		return _len - pos;
	}
	for (size_t i = pos,j=0; i < pos + len; i++,j++)
		s[j] = _str[i];
	return len;
}

size_t MyString::find(const MyString& str, size_t pos ) const
{
	bool flag = 1;
	for (size_t i = pos; i < _len; i++)
	{
		if (str._str[0] == _str[i])
		{
			size_t tmp = i;
			for (size_t j = 1; j < str._len; j++)
			{
				i++;
				if (str._str[j] != _str[i] || i>=_len)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				return tmp;
			i = tmp;
			flag = 1;
		}
			
	}
	return npos;
}
size_t MyString::find(const char* s, size_t pos) const
{
	bool flag = 1;
	for (size_t i = pos; i < _len; i++)
	{
		if (s[0] == _str[i])
		{
			size_t tmp = i;
			for (size_t j = 1; j < strlen(s); j++)
			{
				i++;
				if (s[j] != _str[i] || i >= _len)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				return tmp;
			i = tmp;
			flag = 1;
		}

	}
	return npos;
}
size_t MyString::find(const char* s, size_t pos, size_t n) const
{
	bool flag = 1;
	for (size_t i = pos; i < _len; i++)
	{
		if (s[0] == _str[i])
		{
			size_t tmp = i;
			for (size_t j = 1; j < n; j++)
			{
				i++;
				if (s[j] != _str[i] || i>=_len)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				return tmp;
			i = tmp;
			flag = 1;
		}

	}
	return npos;
}
size_t MyString::find(char c, size_t pos ) const
{
	for (size_t i = pos; i < _len; i++)
		if (_str[i] == c)
			return i;
	return npos;
}

size_t MyString::rfind(const MyString& str, size_t pos) const
{
	bool flag = 1;
	if (pos == npos)
		pos = _len-1;
	for (size_t i = pos; ; i--)
	{
		if (str._str[str._len-1] == _str[i])
		{
			size_t tmp = i;
			for (size_t j = str._len - 2; j >=0; j--)
			{
				i--;
				if (str._str[j] != _str[i] || i<0)
				{
					flag = 0;
					break;
				}
				if (j == 0)
					break;
			}
			if (flag == 1)
				return tmp-str._len+1;
			i = tmp;
			flag = 1;
		}
		if (i == 0)
			break;

	}
	return npos;
}
size_t MyString::rfind(const char* s, size_t pos) const
{
	bool flag = 1;
	if (pos == npos)
		pos = _len - 1;
	for (size_t i = pos; ; i--)
	{
		if (s[strlen(s) - 1] == _str[i])
		{
			size_t tmp = i;
			for (size_t j = strlen(s) - 2; j >= 0; j--)
			{
				i--;
				if (s[j] != _str[i] || i < 0)
				{
					flag = 0;
					break;
				}
				if (j == 0)
					break;
			}
			if (flag == 1)
				return tmp - strlen(s) + 1;
			i = tmp;
			flag = 1;
		}
		if (i == 0)
			break;

	}
	return npos;
}
size_t MyString::rfind(const char* s, size_t pos, size_t n) const
{
	bool flag = 1;
	if (pos == npos)
		pos = _len - 1;
	for (size_t i = pos; ; i--)
	{
		if (s[strlen(s) - 1] == _str[i])
		{
			size_t tmp = i;
			for (size_t j = n; j >= 0; j--)
			{
				i--;
				
				if (s[j] != _str[i] || i < 0)
				{
					flag = 0;
					break;
				}
				if (j == 0)
					break;
			}
			if (flag == 1)
				return tmp - n + 1;
			i = tmp;
			flag = 1;
		}
		if (i == 0)
			break;

	}
	return npos;
}
size_t MyString::rfind(char c, size_t pos) const
{
	if (pos == npos)
		pos = _len - 1;
	for (size_t i = pos; ; i--)
	{
		if (_str[i] == c)
			return i;
		if (i == 0)
			break;
	}
		
	return npos;
}

size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	for (size_t i = pos; i < _len; i++)
	{
		for (size_t j = 0; j < str._len; j++)
		{
			if (_str[i] == str._str[j])
				return i;
		}
	}
	return npos;
}
size_t MyString::find_first_of(const char* s, size_t pos ) const
{
	for (size_t i = pos; i < _len; i++)
	{
		for (size_t j = 0; j < strlen(s); j++)
		{
			if (_str[i] == s[j])
				return i;
		}
	}
	return npos;
}
size_t MyString::find_first_of(const char* s, size_t pos, size_t n) const
{
	for (size_t i = pos; i < _len; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (_str[i] == s[j])
				return i;
		}
	}
	return npos;
}
size_t MyString::find_first_of(char c, size_t pos ) const
{
	for (size_t i = pos; i < _len; i++)
	{
		if (_str[i] == c)
				return i;
	}
	return npos;
}

size_t MyString::find_last_of(const MyString& str, size_t pos ) const
{
	if (pos == npos)
		pos = _len - 1;
	for (size_t i = pos; ; i--)
	{
		for (size_t j = 0; j < str._len; j++)
		{
			if (_str[i] == str._str[j])
				return i;
		}
		if (i == 0)
			break;
	}
	return npos;
}
size_t MyString::find_last_of(const char* s, size_t pos ) const
{
	if (pos == npos)
		pos = _len - 1;
	for (size_t i = pos; ; i--)
	{
		for (size_t j = 0; j < strlen(s); j++)
		{
			if (_str[i] == s[j])
				return i;
		}
		if (i == 0)
			break;
	}
	return npos;
}
size_t MyString::find_last_of(const char* s, size_t pos, size_t n) const
{

	if (pos == npos)
		pos = _len - 1;
	for (size_t i = pos; ; i--)
	{
		for (size_t j = 0; j <n; j++)
		{
			if (_str[i] == s[j])
				return i;
		}
		if (i == 0)
			break;
	}
	return npos;
}
size_t MyString::find_last_of(char c, size_t pos) const
{
	if (pos == npos)
		pos = _len - 1;
	for (size_t i = pos; ; i--)
	{
		if (_str[i] == c)
			return i;
		if (i == 0)
			break;
	}
}

size_t MyString::find_first_not_of(const MyString& str, size_t pos) const
{
	bool flag = 1;
	for (size_t i = pos; i < _len; i++)
	{
		for (size_t j = 0; j < str._len; j++)
		{
			if (_str[i] == str._str[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return i;
		flag = 1;
	}
	return npos;
}
size_t MyString::find_first_not_of(const char* s, size_t pos) const
{
	bool flag = 1;
	for (size_t i = pos; i < _len; i++)
	{
		for (size_t j = 0; j < strlen(s); j++)
		{
			if (_str[i] == s[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return i;
		flag = 1;
	}
	return npos;
}
size_t MyString::find_first_not_of(const char* s, size_t pos, size_t n) const
{
	bool flag = 1;
	for (size_t i = pos; i < _len; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (_str[i] == s[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return i;
		flag = 1;
	}
	return npos;
}
size_t MyString::find_first_not_of(char c, size_t pos) const
{
	bool flag = 1;
	for (size_t i = pos; i < _len; i++)
	{
		if (_str[i] != c)
			return i;
	}
	return npos;
}

size_t MyString::find_last_not_of(const MyString& str, size_t pos) const
{
	bool flag = 1;
	if (pos == npos)
		pos = _len - 1;
	for (size_t i = pos; ; i--)
	{
		for (size_t j = 0; j < str._len; j++)
		{
			if (_str[i] == str._str[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return i;
		flag = 1;
		if (i == 0)
			break;
	}
	return npos;
}
size_t MyString::find_last_not_of(const char* s, size_t pos ) const
{
	bool flag = 1;
	if (pos == npos)
		pos = _len - 1;
	for (size_t i = pos; ; i--)
	{
		for (size_t j = 0; j < strlen(s); j++)
		{
			if (_str[i] == s[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return i;
		flag = 1;
		if (i == 0)
			break;
	}
	return npos;
}
size_t MyString::find_last_not_of(const char* s, size_t pos, size_t n) const
{
	bool flag = 1;
	if (pos == npos)
		pos = _len - 1;
	for (size_t i = pos; ; i--)
	{
		for (size_t j = 0; j < n; j++)
		{
			if (_str[i] == s[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
			return i;
		flag = 1;
		if (i == 0)
			break;
	}
	return npos;
}
size_t MyString::find_last_not_of(char c, size_t pos) const
{
	bool flag = 1;
	if (pos == npos)
		pos = _len - 1;
	for (size_t i = pos; ; i--)
	{
		if (_str[i] != c)
			return i;
	}
	return npos;
}

MyString MyString::substr(size_t pos, size_t len ) const
{
	MyString tmp(*this, pos, len);
	return tmp;
}

int MyString::compare(const MyString& str) const
{
	if (str._len == 0 && _len == 0)
		return 0;
	if (_len == 0)
		return -1;
	if (str._len == 0)
		return 1;
	for (size_t i = 0; i < _len && i<str._len; i++)
	{
		if (_str[i] > str._str[i])
			return 1;
		if (_str[i] < str._str[i])
			return -1;
	}
	if (_len == str._len)
		return 0;
	if (_len > str._len)
		return 1;
	return -1;
}
int MyString::compare(size_t pos, size_t len, const MyString& str) const
{
	if (pos > _len||pos+len>_len)
	{
		cout << "Wrong parameter!!\n";
		exit(0);
	}
	if (str._len == 0 && _len == 0)
		return 0;
	if (_len == 0)
		return -1;
	if (str._len == 0)
		return 1;
	for (size_t i = pos,j=0; i < pos+len && j < str._len; i++,j++)
	{
		if (_str[i] > str._str[j])
			return 1;
		if (_str[i] < str._str[j])
			return -1;
	}
	if (len == str._len)
		return 0;
	if (_len > str._len)
		return 1;
	return -1;
}
int MyString::compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen) const
{
	if (pos > _len || pos + len > _len|| subpos > str._len || subpos + sublen > str._len)
	{
		cout << "Wrong parameter!!\n";
		exit(0);
	}
	if (str._len == 0 && _len == 0)
		return 0;
	if (_len == 0)
		return -1;
	if (str._len == 0)
		return 1;
	for (size_t i = pos, j = subpos; i < pos + len && j < subpos+sublen; i++, j++)
	{
		if (_str[i] > str._str[j])
			return 1;
		if (_str[i] < str._str[j])
			return -1;
	}
	if (len == sublen)
		return 0;
	if (_len > str._len)
		return 1;
	return -1;
}
int MyString::compare(const char* s) const
{
	if (strlen(s) == 0 && _len == 0)
		return 0;
	if (_len == 0)
		return -1;
	if (strlen(s) == 0)
		return 1;
	for (size_t i = 0; i < _len && i < strlen(s); i++)
	{
		if (_str[i] > s[i])
			return 1;
		if (_str[i] < s[i])
			return -1;
	}
	if (_len == strlen(s))
		return 0;
	if (_len > strlen(s))
		return 1;
	return -1;
}
int MyString::compare(size_t pos, size_t len, const char* s) const
{
	if (pos > _len || pos + len > _len)
	{
		cout << "Wrong parameter!!\n";
		exit(0);
	}
	if (strlen(s) == 0 && _len == 0)
		return 0;
	if (_len == 0)
		return -1;
	if (strlen(s) == 0)
		return 1;
	for (size_t i = pos, j = 0; i < pos + len && j < strlen(s); i++, j++)
	{
		if (_str[i] > s[j])
			return 1;
		if (_str[i] < s[j])
			return -1;
	}
	if (len == strlen(s))
		return 0;
	if (_len > strlen(s))
		return 1;
	return -1;
}
int MyString::compare(size_t pos, size_t len, const char* s, size_t n) const
{
	if (pos > _len || pos + len >_len||n>strlen(s))
	{
		cout << "Wrong parameter!!\n";
		exit(0);
	}
	if (strlen(s) == 0 && _len == 0)
		return 0;
	if (_len == 0)
		return -1;
	if (strlen(s) == 0)
		return 1;
	for (size_t i = pos, j = 0; i < pos + len && j < n; i++, j++)
	{
		if (_str[i] > s[j])
			return 1;
		if (_str[i] < s[j])
			return -1;
	}
	if (len == n)
		return 0;
	if (_len > strlen(s))
		return 1;
	return -1;
}

MyString operator+ (const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}
MyString operator+ (const MyString& lhs, const char*   rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}
MyString operator+ (const char* lhs, const MyString& rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}
MyString operator+ (const MyString& lhs, char  rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}
MyString operator+ (char lhs, const MyString& rhs)
{
	MyString result;
	result += lhs;
	result += rhs;
	return result;
}

bool operator== (const MyString& lhs, const MyString& rhs)
{
	if (lhs._len != rhs._len)
		return 0;
	for (size_t i = 0; i < lhs._len; i++)
		if (lhs._str[i] != rhs._str[i])
			return 0;
	return 1;
}
bool operator== (const char*   lhs, const MyString& rhs)
{
	if (strlen(lhs) != rhs._len)
		return 0;
	for (size_t i = 0; i < rhs._len; i++)
		if (lhs[i] != rhs._str[i])
			return 0;
	return 1;
}
bool operator== (const MyString& lhs, const char*   rhs)
{
	if (strlen(rhs) != lhs._len)
		return 0;
	for (size_t i = 0; i < lhs._len; i++)
		if (lhs._str[i] != rhs[i])
			return 0;
	return 1;
}

bool operator!= (const MyString& lhs, const MyString& rhs)
{
	if (lhs == rhs)
		return 0;
	return 1;
}
bool operator!= (const char*   lhs, const MyString& rhs)
{
	if (lhs == rhs)
		return 0;
	return 1;
}
bool operator!= (const MyString& lhs, const char*   rhs)
{
	if (lhs == rhs)
		return 0;
	return 1;
}

bool operator< (const MyString& lhs, const MyString& rhs)
{
	if (lhs._len == 0 || rhs._len == 0)
		return 0;
	for (size_t i = 0; i < lhs._len && i<rhs._len; i++)
	{
		if (lhs._str[i] < rhs._str[i])
			return 1;
		if(lhs._str[i] > rhs._str[i])
			return 0;
	}
	if (lhs._len < rhs._len)
		return 1;
	return 0;
}
bool operator<  (const char*   lhs, const MyString& rhs)
{
	if (strlen(lhs) == 0 || rhs._len == 0)
		return 0;
	for (size_t i = 0; i < strlen(lhs) && i < rhs._len; i++)
	{
		if (lhs[i] < rhs._str[i])
			return 1;
		if (lhs[i] > rhs._str[i])
			return 0;
	}
	if (strlen(lhs) < rhs._len)
		return 1;
	return 0;
}
bool operator<  (const MyString& lhs, const char*   rhs)
{
	if (strlen(rhs) == 0 || lhs._len == 0)
		return 0;
	for (size_t i = 0; i < strlen(rhs) && i < lhs._len; i++)
	{
		if (lhs._str[i] < rhs[i])
			return 1;
		if (lhs._str[i] > rhs[i])
			return 0;
	}
	if (lhs._len < strlen(rhs))
		return 1;
	return 0;
}

bool operator<= (const MyString& lhs, const MyString& rhs)
{
	if (lhs > rhs)
		return 0;
	return 1;
}
bool operator<= (const char*   lhs, const MyString& rhs)
{
	if (lhs > rhs)
		return 0;
	return 1;
}
bool operator<= (const MyString& lhs, const char*   rhs)
{
	if (lhs > rhs)
		return 0;
	return 1;
}

bool operator>  (const MyString& lhs, const MyString& rhs)
{
	if (lhs._len == 0 || rhs._len == 0)
		return 0;
	for (size_t i = 0; i < lhs._len && i < rhs._len; i++)
	{
		if (lhs._str[i] > rhs._str[i])
			return 1;
		if (lhs._str[i] < rhs._str[i])
			return 0;
	}
	if (lhs._len < rhs._len)
		return 1;
	return 0;
}
bool operator>  (const char*   lhs, const MyString& rhs)
{
	if (strlen(lhs) == 0 || rhs._len == 0)
		return 0;
	for (size_t i = 0; i < strlen(lhs) && i < rhs._len; i++)
	{
		if (lhs[i] > rhs._str[i])
			return 1;
		if (lhs[i] < rhs._str[i])
			return 0;
	}
	if (strlen(lhs) > rhs._len)
		return 1;
	return 0;
}
bool operator>  (const MyString& lhs, const char*   rhs)
{
	if (strlen(rhs) == 0 || lhs._len == 0)
		return 0;
	for (size_t i = 0; i < strlen(rhs) && i < lhs._len; i++)
	{
		if (lhs._str[i] > rhs[i])
			return 1;
		if (lhs._str[i] < rhs[i])
			return 0;
	}
	if (lhs._len > strlen(rhs))
		return 1;
	return 0;
}

bool operator>= (const MyString& lhs, const MyString& rhs)
{
	if (lhs < rhs)
		return 0;
	return 1;
}
bool operator>= (const char*   lhs, const MyString& rhs)
{
	if (lhs < rhs)
		return 0;
	return 1;
}
bool operator>= (const MyString& lhs, const char*   rhs)
{
	if (lhs < rhs)
		return 0;
	return 1;
}

void swap(MyString& x, MyString& y)
{
	MyString tmp(x);
	x = y;
	y = tmp;
}
istream& operator>> (istream& is, MyString& str)
{
	char s[1030300];
	is >> s;
	if (str._str != NULL)
		delete[] str._str;
	str._len = strlen(s);
	str._max = 16 * (str._len / 16 + 1) - 1;
	str._str = new char[str._max];
	for (size_t i = 0; i < str._len; i++)
		str._str[i] = s[i];
	str._str[str._len] = 0;
	return is;
}
ostream& operator<<(ostream&out,const MyString&a)
{
	for (size_t i = 0; i < a._len; i++)
		out << a[i];
	return out;
}
istream& getline(istream& is, MyString& str, char delim)
{
	char s[1030300];
	gets_s(s);
	if (str._str != NULL)
		delete[] str._str;
	size_t n= strlen(s);
	size_t i = 0;
	for (i = 0; i < n; i++)
		if (s[i] == delim)
			break;
	str._len = i;
	str._max = 16 * (str._len / 16 + 1) - 1;
	str._str = new char[str._max];
	for (size_t i = 0; i < str._len; i++)
		str._str[i] = s[i];
	str._str[str._len] = 0;
	return is;
}
istream& getline(istream& is, MyString& str)
{
	char s[1030300];
	gets_s(s);
	if (str._str != NULL)
		delete[] str._str;
	str._len = strlen(s);
	str._max = 16 * (str._len / 16 + 1) - 1;
	str._str = new char[str._max];
	for (size_t i = 0; i < str._len; i++)
		str._str[i] = s[i];
	str._str[str._len] = 0;
	return is;
}