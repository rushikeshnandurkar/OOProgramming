//============================================================================

//	Rushikesh Nandurkar	[SI035]
//============================================================================
// Name        : Inheritance_assignment.cpp

// Description : Inheritance Assignment in C++, Ansi-style
//============================================================================

/*
Problem :
	Design a base class with name, DoB, blood group & another base class
	consisting of a data members such as height and weight. Design one
	more base class consisting of insurance policy no and contact address.
	The derived class contains the data members tele. no. & driving lic.no.
	Write a menu driven program to carry out foll. things.
	1. Build mastertable
	2. Display
	3. Insert new entry
	4. Delete Entry
	5. Search for a record
	6. Edit or modify.
*/
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include <iostream>
#include<string.h>
using namespace std;

class A
{
	int dob,mob,yob;
public:
	char name[10];
	char bg[5];
	void read();
	void write();
	int get_dob();
	int get_mob();
	int get_yob();
	int bloodgroup(char []);
};

class B
{
	float height;
	int weight;
public:
	void read();
	void write();
	float get_height();
	int get_weight();
};

class C
{
	long ins_no;
public:
	char addr[20];
	void read();
	void write();
	long get_ins();
};


class derived:private A,private B,private C
{
	long long tel,dl_no;
public:
	void accept();
	void display(int);
};
//----------------------------------------------------------------
void A::read()
{
	int flag;
	do
	{
		cout<<"Name (not more than 10 char) :";
		cin>>name;
		cout<<"***  Enter DoB ***\nDate :";
		cin>>dob;
		cout<<"Month :";
		cin>>mob;
		cout<<"Year :";
		cin>>yob;
		//Validation of DOB starts.
		if(yob<1950||yob>2017)
		{
			cout<<"Invalid Year\n";
			flag=1;
		}
		else
		{
		int leap;
		if(yob%4==0)
		{
			if(yob%100==0)
			{
				if(yob%400==0)
					leap=1;
				else
					leap=0;
			}
			else
				leap=1;
		}
		else
			leap=0;
		if(mob==1||mob==3||mob==5||mob==7||mob==8||mob==10||mob==12)
		{
			if(dob>31||dob<1)
			{
				flag=1;
				cout<<"Invalid Date. Repeat\n";
			}
			else
				flag=0;
		}
		else if(mob==4||mob==6||mob==9||mob==11)
		{
			if(dob>30||dob<1)
			{
				flag=1;
				cout<<"Invalid Date. Repeat\n";
			}
			else
				flag=0;
		}
		else if(mob==2)
		{
			if(leap==1)
			{
				if(dob>29||dob<1)
				{
					flag=1;
					cout<<"Invalid Date. Repeat\n";
				}
				else
					flag=0;
			}
			else
			{
				if(dob>28||dob<1)
				{
					flag=1;
					cout<<"Invalid Date. Repeat\n";
				}
				else
					flag=0;
			}
		}
		else
		{
			flag=1;
			cout<<"Invalid month.\n";
		}
		}
	}while(flag==1);
	//Validation of DOB ends here.
	do
	{
		cout<<"Blood Group :";
		cin>>bg;
		flag=bloodgroup(bg);
		if(flag==1)
			cout<<"Enter a valid blood group.\n";
	}while(flag==1);
}

void B::read()
{
	int flag;
	do
	{
		cout<<"Height in cm :";
		cin>>height;
		if(height>200||height<100)//......validation of height
		{
			cout<<"Ohh.. One cannot be that high. Plesae Re-enter.\n";
			flag=1;
		}
		else flag=0;
	}while(flag==1);
	do
	{
		cout<<"weight in kg :";
		cin>>weight;
		if(weight>150||weight<15)//....validation for weeight
		{
			cout<<"plesae Re-enter the value.\n";
			flag=1;
		}
		else flag=0;
	}while(flag==1);
}

void C::read()
{
	cout<<"Insurance Policy No. :";
	cin>>ins_no;
	cout<<"Address :";
	cin>>addr;
}

void derived::accept()
{
	int flag;
	A::read();
	B::read();
	C::read();
	do
	{
		cout<<"Mobile No ";
		cin>>tel;
		cout<<"Driving License No.(12 digits) :";
		cin>>dl_no;
		if(tel<1000000000||tel>9999999999||dl_no<100000000000||dl_no>999999999999)//...........validation for tel.no & DL no
		{
			cout<<"Please Re-enter both inputs again!\n";
			flag=1;
		}
		else flag=0;
	}while(flag==1);
}
//----------------------------------------------------------------
int A::get_dob()
{
	return dob;
}
int A::get_mob()
{
	return mob;
}
int A::get_yob()
{
	return yob;
}

float B::get_height()
{
	return height;
}
int B::get_weight()
{
	return weight;
}

long C::get_ins()
{
	return ins_no;
}
//----------------------------------------------------------------
void derived::display(int x)
{
	cout<<x+1<<"\t"<<name<<"\t"<<get_dob()<<"/"<<get_mob()<<"/"<<get_yob()<<"\t"<<bg<<"\t\t"<<get_height()<<"\t"<<get_weight()<<"\t";
	cout<<get_ins()<<"\t\t"<<addr<<"\t"<<tel<<"\t"<<dl_no<<endl;
}
//----------------------------------------------------------------
//fuhnction for validation of blood group
int A::bloodgroup(char bg[])
{
	int flag;
	char bg1[5]="A+";
	char bg2[5]="A-";
	char bg3[5]="B+";
	char bg4[5]="B-";
	char bg5[5]="AB+";
	char bg6[5]="AB-";
	char bg7[5]="O+";
	char bg8[5]="O-";
	if(strcmp(bg,bg1)==0)
		flag=0;
	else if(strcmp(bg,bg2)==0)
		flag=0;
	else if(strcmp(bg,bg3)==0)
		flag=0;
	else if(strcmp(bg,bg4)==0)
		flag=0;
	else if(strcmp(bg,bg5)==0)
		flag=0;
	else if(strcmp(bg,bg6)==0)
		flag=0;
	else if(strcmp(bg,bg7)==0)
		flag=0;
	else if(strcmp(bg,bg8)==0)
		flag=0;
	else flag=1;
	return flag;
}
//----------------------------------------------------------------
int main()
{
	int no_records,choice,flag;
	derived d[10];
	int i;
	do
	{
		do
		{
			cout<<"********Select one.********\n1. Build mastertable\n2. Display\n";
			cout<<"3. Insert new entry\n4. Delete Entry\n";
			cout<<"5. Search for a record\n6. Edit or modify. ";
			cin>>choice;
			if(choice>6||choice<1)//.....validation
			{
				cout<<"## WRONG ##\nEnter a valid number between 1-6\n";
				flag=1;
			}
			else
			{
				flag=0;
				break;
			}
		}while(flag==1);
		switch(choice)
		{
		case 1:
		{
			do
			{
				cout<<"How many records do you want to create?\n";
				cin>>no_records;
				if(no_records>10||no_records<1)//...........validation
				{
					cout<<"## WRONG ##Enter a valid number between 1-10\n";
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			}while(flag==1);
			for(i=0;i<no_records;i++)
			{
				cout<<"Fill the record no. "<<i+1<<endl;
				d[i].derived::accept();
			}
			break;
		}
		//------------------------------------------------------------------
		case 2:
		{
			cout<<"Mastertable : \n";
			cout<<"Sr.No.\tName\t\tDOB\t\tBlood Grp\tHeight\tWeight\tInsurance Pol.No.\tAddress\tContact No.\tDriving Lic. No.\n";
			for(i=0;i<no_records;i++)
			{
				d[i].display(i);
			}
			break;
		}
		//------------------------------------------------------------------
		case 3:
		{
			int j,k,n;
			do
			{
				cout<<"How much entries do you want to insert newly?\n";
				cin>>j;
				if((no_records+j)>10)//........validation
				{
					cout<<"Please Enter a valid number between 0 and "<<10-no_records<<endl;
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			}while(flag==1);
			for(i=0;i<j;i++)
			{
				no_records++;
					do
					{
						cout<<"Enter at which place you wish to add a record?\n";
						cin>>k;
						if(k>no_records||k<1)//......validation
						{
							cout<<"## WRONG ##\nEnter a valid number between 1 and "<<no_records<<endl;
							flag=1;
						}
						else
						{
							flag=0;
							break;
						}
					}while(flag==1);
				if(k<no_records)
				{
					for(n=no_records-1;n>=k;n--)
					{
						d[n]=d[n-1];
					}
					cout<<"Enter inputs for the entry no. "<<k<<endl;
					d[k-1].accept();
				}
				else
				{
					cout<<"Enter inputs for the entry no. "<<k<<endl;
					d[k-1].accept();
				}
			}
			break;
		}
		//-------------------------------------------------------------------
		case 4:
		{
			int j;
			do
			{
				cout<<"Which record do you wish to delete?\n";
				cin>>j;
				if(j>no_records||j<0)//.........validation
				{
					cout<<"Please enter a valid number between 1 to "<<no_records<<endl;
					flag=1;
				}
				else flag=0;
			}while(flag==1);
			j--;
			for(i=0;i<no_records;i++)
			{
				d[i]=d[i+1];
			}
			no_records--;
			cout<<"Successfully Deleted \n";
			break;
		}
		//---------------------------------------------------------------------
		case 5:
		{
			 do
			 {
				cout<<"Enter the ID no you are searching for.\n";
				cin>>i;
				if(i>no_records||i<1)//.........validation
				{
					cout<<"## WRONG ##\nEnter a valid number between 1 and "<<no_records<<endl;
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			 }while(flag==1);
			i--;
			cout<<"Sr.No.\tName\tDOB\t\tBlood Grp\tHeight\tWeight\tInsurance Pol.No.\tAddress\t\tContact No.\tDriving Lic. No.\n";
			d[i].display(i);
			break;
		}
		//------------------------------------------------------------------------------
		case 6:
		{
			do
			{
				cout<<"Enter the number of records you wish to modify.\n";
				cin>>i;
				if(i>no_records||i<1)//............validation
				{
					cout<<"## WRONG ##\nEnter a valid number between 1 and "<<no_records<<endl;
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
				}while(flag==1);
			i--;
			d[i].accept();
			break;
		}
		}
		cout<<"Do you wish to go to the previous menu again?\n******1.YES\t2.NO******\n";
		cin>>choice;
	}while(choice==1);
	return 0;
}
