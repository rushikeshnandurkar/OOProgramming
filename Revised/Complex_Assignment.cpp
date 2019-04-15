//============================================================================

//	Rushikesh nandurkar [SI035]

//============================================================================
// Name        : Complex_Assignment.cpp
// Author      : Rishikesh
// Version     :
// Copyright   : Your copyright notice
// Description : Complex Number assignment in C++
//============================================================================

#include<iostream>
using namespace std;

class complex
{
	float real,img;
public:
	friend istream & operator>>(istream &,complex &);//................overloading extraction operator
	friend ostream & operator<<(ostream &,complex &);//................overloading insertion operator
	complex operator+(complex);//......................................operator overloading for addition
	complex operator-(complex);//......................................operator overloading for subtraction
	complex operator*(complex);//......................................operator overloading for multiplication
	complex operator/(complex);//......................................operator overloading for division
};
//------------------------------------------------


istream & operator>>(istream &in,complex &c)//........definition of extraction operator
{
	cout<<"Enter first complex number. \nReal Part.: ";
	in>>c.real;
	cout<<"Img Part : ";
	in>>c.img;
	return in;
}

ostream & operator<<(ostream &out,complex &c)//......definition of insertion operator
{
	out<<c.real;
	cout<<"+";
	out<<c.img;
	cout<<"i\n";
	return out;
}

complex complex::operator+(complex c2)
{
	complex temp;
	temp.real=real+c2.real;
	temp.img=img+c2.img;
	return temp;
}
complex complex::operator-(complex c2)
{
	complex temp;
	temp.real=real-c2.real;
	temp.img=img-c2.img;
	return temp;
}

complex complex::operator*(complex c2)
{
	complex temp;
	temp.real=(real*c2.real)-(img*c2.img);
	temp.img=(real*c2.img)+(img*c2.real);
	return temp;
}
complex complex::operator/(complex c2)
{
	complex temp;
	temp.real=((real*c2.real)+(img+c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
	temp.img=((img*c2.real)-(real*c2.img))/((c2.real*c2.real)+(c2.img*c2.img));
	return temp;
}

//--------------------------------------------------

int main()
{
	complex c1,c2;
	cin>>c1>>c2;
	cout<<c1<<c2;

	complex c3;
	c3=c1+c2;
	cout<<"The addition  of two complex numbers is : "<<c3;

	complex c4;
	c4=c1-c2;
	cout<<"The subtraction  of two complex numbers is : "<<c4;

	complex c5;
	c5=c1*c2;
	cout<<"The multiplication  of two complex numbers is : "<<c5;

	complex c6;
	c6=c1/c2;
	cout<<"The division  of two complex numbers is : "<<c6;
	return 0;
}
