/*************************************************************************
	> File Name: 2.string_test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年10月16日 星期三 10时44分39秒
 ************************************************************************/

#include<iostream>
using namespace std;

struct String
{
private:
    char* buffer = nullptr;

public:
    String()
        :buffer{new char[]{'\0'}}
    {
    }

    String(const_cast char* theBuffer)
        :buffer{theBuffer}
    {
    }

    String(const String& theString)
        :buffer{theString.buffer}
    {
    }

    ~String()
    {
        delete[] buffer;
    }
};

int main()
{
    String a = "This is a string!";
    String b = a;
    String c;
    c = b;
}
