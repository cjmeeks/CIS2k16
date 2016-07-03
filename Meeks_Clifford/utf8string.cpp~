
#include "utf8string.hpp"
#include "ksu_utf8.h"
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;

//defaut just initialize
utf8string::utf8string()
{
	word = "";
	len = 0;
	byte = 0;
}
//constructor
utf8string::utf8string(std::string s)
{
	word = s;
	len = ksu_charlen((unsigned char*)s.c_str());
	byte = sizeof(s);
}


//copy constructor
utf8string::utf8string(const utf8string &old)
{
	
}

utf8string::~utf8string()
{

}

utf8string &utf8string::operator=(const utf8string& s)
{
	word = s.word;
	len = s.len;
	byte = s.byte;
	return *this;
}
std::ostream& operator<<(std::ostream& os, const utf8string obj)
{
	os << obj.word << obj.len << obj.byte;
	return os;
}

utf8string utf8string::operator+(utf8string u)
{
	return word + u.word;
}

utf8string utf8string::reverse()
{
	std::string temp;
	for(int i = len; i > -1; i++)
	{
		temp += word[i];
	}
	return temp;
}

size_t utf8string::length(){
	return len;
}

size_t utf8string::byte_length(){
	return byte;
}
//compare
/*bool utf8string::operator==(const utf8string &str){
	return !(*this == str);
}*/
