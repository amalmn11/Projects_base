#pragma once
class Shape
{
private:
	static int compt;
	int id_shape;
public:
	Shape();
	virtual void Draw()=0 ;
};

