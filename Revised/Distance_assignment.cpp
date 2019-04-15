//============================================================================

//	Rushikesh Nandurkar [SI035]

//============================================================================
// Name of project	: Distance_assignment.cpp

// Description 		: Distance Assignment in C++.
//				Concept used:   1.Friend function
//						2.Operator overloading
//============================================================================
#include<iostream>
using namespace std;

class feet;

class metric
{
    int mtr,cm;
    public:
    void getdata();
    void display();
    friend metric operator+(metric,feet);
    friend feet operator+(feet,metric);
    friend metric operator-(metric,feet);
    friend feet operator-(feet,metric);
};

class feet
{
    int ft,inch;
public:
    void getdata();
    void display();
    friend metric operator+(metric,feet);//.......Operator overloading
    friend feet operator+(feet,metric);//.......Operator overloading
    friend metric operator-(metric,feet);//.......Operator overloading
    friend feet operator-(feet,metric);//.......Operator overloading
};
//-----------------------------------------------------------------------------
void metric::getdata()
{
    cout<<"Enter distance in metric form.\n";
    cin>>mtr>>cm;
}

void feet::getdata()
{
    cout<<"Enter distance in feet-inch form.\n";
    cin>>ft>>inch;
}
//-------------------------------------------------------------------------------------
void metric::display()
{
    cout<<mtr<<"m "<<cm<<"cm\n";
}

void feet::display()
{
    cout<<ft<<"ft "<<inch<<"inches\n";
}
//-----------------------------------------------------------------------------
metric operator+(metric m1,feet f1)
{
    metric temp;
    float tot_in_mtr;
    tot_in_mtr=m1.mtr+(m1.cm/100.0)+(f1.ft*0.3048)+(f1.inch*0.0254);//......Type casting (divided by 100.0)
    cout<<tot_in_mtr<<endl;
    temp.mtr=tot_in_mtr;//...........Type casting from float to int;
    float var;
    var=tot_in_mtr-temp.mtr;
    temp.cm=var*100;//.........Type casting;
    return temp;
}

feet operator+(feet f1,metric m1)
{
    feet temp;
    float tot_in_ft;
    tot_in_ft=f1.ft+(f1.inch*0.0833)+(m1.mtr*3.28)+(m1.cm*0.0328);
    cout<<tot_in_ft<<endl;
    temp.ft=tot_in_ft;//........Type casting
    float var;
    var=tot_in_ft-temp.ft;
    temp.inch=var*12;//..........Type casating
    return temp;
}
//------------------------------------------------------------------------------
metric operator-(metric m1,feet f1)
{
    metric temp;
    float tot_in_mtr;
    tot_in_mtr=m1.mtr+(m1.cm/100.0)-((f1.ft*0.3048)+(f1.inch*0.0254));//.....Type casting (divided by 100.0)
    cout<<tot_in_mtr<<endl;
    temp.mtr=tot_in_mtr;//.......Type casting;
    float var;
    var=tot_in_mtr-temp.mtr;
    temp.cm=var*100;//.........Type casting;
    if(temp.mtr<0)
    {
    	temp.mtr=-temp.mtr;
    	temp.cm=-temp.cm;
    	cout<<"Second distance is greater than first distance.\n";
    }
    else
    	cout<<"First distance is greater than second distance.\n";
    return temp;
}

feet operator-(feet f1,metric m1)
{
    feet temp;
    float tot_in_ft;
    tot_in_ft=f1.ft+(f1.inch*0.0833)-((m1.mtr*3.28)+(m1.cm*0.0328));
    cout<<tot_in_ft<<endl;
    temp.ft=tot_in_ft;//........Type casting;
    float var;
    var=tot_in_ft-temp.ft;
    temp.inch=var*12;//.......Type casting;
    if(temp.ft<0)
    {
    	temp.ft=-temp.ft;
    	temp.inch=-temp.inch;
    	cout<<"First distance is greater than second distance.\n";
    }
    else
    	cout<<"Second distance is greater than first distance.\n";
    return temp;
}
//-----------------------------------------------------------------------
int main()
{
    int k;
    metric m1;
    m1.getdata();
    feet f1;
    f1.getdata();
    do
    {
        cout<<"Select an option.\n1. Sum in metric form.\n2. Subtraction in metric form\n";
        cout<<"3. Sum in Feet and inches form.\n4. Subtraction in feet n inches form.\n";
        cin>>k;
        switch(k)
        {
        case 1:
            {
                metric m2;
                m2=m1+f1;//.......Operator overloading
                cout<<"Sum is : ";
                m2.display();
                break;
            }
        case 2:
            {
                metric m2;
                m2=m1-f1;//.......Operator overloading
                cout<<"Difference is : ";
                m2.display();
                break;
            }
        case 3:
            {
                feet f2;
                f2=f1+m1;//.......Operator overloading
                cout<<"Sum is : ";
                f2.display();
                break;
            }
        case 4:
            {
                feet f2;
                f2=f1-m1;//.......Operator overloading
                cout<<"Difference is : ";
                f2.display();
                break;
            }
        }
        cout<<"Wish to go again in menu?\n1.YES\n2.NO\n";
        cin>>k;
    }while(k==1);
    return 0;
}
