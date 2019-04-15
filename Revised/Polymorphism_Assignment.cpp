//===========================================================================
	//	Rushikiesh Nandurkar [SI035]
//============================================================================
// Name of the project	: Polymorphism_Assignment.cpp

// Description 			: Polymorphism Assignment in C++;
//============================================================================
/*
  	  Problem Statement:-
  	  	  Create a base class shape with two double type values and
  	  	  member functions to input the data and compute_area() for calculating
  	  	  area of figure. Derive two classes triangle and rectangle. Make
  	  	  compute_area() as a virtual function & redefine these function
  	  	  in derived class to suit their requirement.
 */
//=============================================================================

#include<iostream>
using namespace std;

class shape
{
protected:
	double a,b;
public:
	void getdata();
	virtual void compute_area()=0;//...........Pure virtual function;
};

class triangle:public shape//.............First Derived class;
{
	double area;
public:
	void compute_area();
};

class rectangle:public shape//.............Second Derived class;
{
	double area;
public:
	void compute_area();
};
//------------------------------------------------------

void shape::getdata()
{
	cout<<"Enter the value of two lengths.\n";
	cin>>a>>b;
}
void triangle::compute_area()
{
	area=0.5*a*b;
	cout<<"The area of a triangle is "<<area<<endl;
}
void rectangle::compute_area()
{
	area=a*b;
	cout<<"The area of a rectangle is "<<area<<endl;
}
//-------------------------------------------------------
int main()
{
	shape *ptr;//.........pointer of base class(shape)
	triangle t;//.........Object of derived class reiangle
	ptr=&t;//..............pointer of shape point to the object of triangle
	ptr->getdata();
	ptr->compute_area();//......compute_area() of triangle class is called
	rectangle r;//.............object of derived class rectangle
	ptr=&r;//.............pointer of shape point to the object of rectangle
	ptr->getdata();
	ptr->compute_area();//....compute_area() of rectangle class is called
	return 0;
}
