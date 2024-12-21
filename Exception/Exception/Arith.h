#pragma once
class Arith
{
private:
	int a;
	int b;
public:
	Arith();
	Arith(int,int);
	int  add();
	bool is_positive();
	bool is_negative();
	int division();
};

