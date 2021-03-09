#ifndef MY_EXCEPTION
#define MY_EXCEPTION
#include "pch.h"
class MyException
{
public:
	MyException(string error, string fileName) : error_(error), fileName_(fileName) {}
	~MyException() {}

	string getError()
	{
		cerr << endl << fileName_ << " " << error_ << endl;
		return "";
	}

private:
	string error_;
	string fileName_;
};

#endif
