//============================================================================
//		Rushikesh Nandurkar	[SI035]
//============================================================================
// Name        : weather_report_assignment.cpp

// Description : Weather Report Assignment in C++;
//============================================================================

#include <iostream>

using namespace std;

class weather_report
{
    int *month=NULL;
    float *hightemp=NULL;
    float *lowtemp=NULL;
    float *amount_rain=NULL;
    float *amount_snow=NULL;
public:
     void assignment(int,int);
     void getdata(int);
    void display();
    friend void average(weather_report [],int);
    int allocate(int,int);
    friend int validation1(int);//...........validation of only year
    friend int validate(int,int,int);//..........validation of month and date
    void display(int);
};
//----------------------------------------------------------------------------------
void weather_report::assignment(int month_no,int flag)//..........function to initialize all the values to zero
{
    int no_days;
    no_days=allocate(month_no,flag);
    month=new int[no_days+1];
    hightemp=new float[no_days+1];
    lowtemp=new float[no_days+1];
    amount_rain=new float[no_days+1];
    amount_snow=new float[no_days+1];
    int *month1=month;
    float *hightemp1=hightemp;
    float *lowtemp1=lowtemp;
    float *amount_rain1=amount_rain;
    float *amount_snow1=amount_snow;
    for(int i=0;i<no_days;i++)
    {
        *month1=i+1;
        *hightemp1=0;
        *lowtemp1=0;
        *amount_rain1=0;
        *amount_snow1=0;
        month1++;hightemp1++;lowtemp1++;amount_rain1++;amount_snow1++;
    }
        *month1='\0';
        *hightemp1='\0';
        *lowtemp1='\0';
        *amount_rain1='\0';
        *amount_snow1='\0';
}

int weather_report::allocate(int month_no,int flag)//........function to allocate the memory of all pointer data members dynamically
{
    int temp;
    if(month_no==1||month_no==3||month_no==5||month_no==7||month_no==8||month_no==10||month_no==12)
    {
        temp=31;
    }
    else if(month_no==4||month_no==6||month_no==9||month_no==11)
    {
        temp=30;
    }
    else if(month_no==2)
    {
        if(flag==1)
            temp=29;
        else
            temp=28;
    }
    return temp;
}
//---------------------------------------------------------------------------------------
void weather_report::display()//....display function with no parameter
{
    int *month1=month;
    float *hightemp1=hightemp;
    float *lowtemp1=lowtemp;
    float *amount_rain1=amount_rain;
    float *amount_snow1=amount_snow;
    while(*month1!='\0')
    {
        cout<<*month1<<"\t\t"<<*hightemp1<<"\t\t"<<*lowtemp1<<"\t\t"<<*amount_rain1<<"\t\t"<<*amount_snow1<<endl;
        month1++;hightemp1++;lowtemp1++;amount_rain1++;amount_snow1++;
    }
}

void weather_report::display(int x)//.......display function with a parameter
{
    int *month1=month;
    float *hightemp1=hightemp;
    float *lowtemp1=lowtemp;
    float *amount_rain1=amount_rain;
    float *amount_snow1=amount_snow;
    x--;
    for(int i=0;i<x;i++)
    {
        month1++;hightemp1++;lowtemp1++;amount_rain1++;amount_snow1++;
    }
    cout<<"Date \t Max Temp \t Min temp \t Rainfall \t Snowfall \n";
    cout<<*month1<<"\t\t"<<*hightemp1<<"\t\t"<<*lowtemp1<<"\t\t"<<*amount_rain1<<"\t\t"<<*amount_snow1<<endl;
}

void weather_report::getdata(int x)
{
    int *month1=month;
    float *hightemp1=hightemp;
    float *lowtemp1=lowtemp;
    float *amount_rain1=amount_rain;
    float *amount_snow1=amount_snow;
    x--;
    for(int i=0;i<x;i++)
    {
        month1++;hightemp1++;lowtemp1++;amount_rain1++;amount_snow1++;
    }
    *month1=x+1;
    cout<<"Enter High temp, low temp, rainfall and snowfall \n";
    cin>>*hightemp1>>*lowtemp1>>*amount_rain1>>*amount_snow1;
}
//---------------------------------------------------------------------------
void average(weather_report w[12],int leap)//..........friend function to find out the avg values for year
{
	float high,low,rain,snow;
	high=low=rain=snow=0;
	for(int i=0;i<12;i++)
	{
		int *month1=w[i].month;
	    float *hightemp1=w[i].hightemp;
	    float *lowtemp1=w[i].lowtemp;
	    float *amount_rain1=w[i].amount_rain;
	    float *amount_snow1=w[i].amount_snow;
		while(*month1!='\0')
		{
			high=high+*hightemp1;
			low=low+*lowtemp1;
			rain=rain+*amount_rain1;
			snow=snow+*amount_snow1;
			hightemp1++;
			lowtemp1++;
			amount_rain1++;
			amount_snow1++;
			month1++;
		}
	}
	if(leap==1)
	{
		high=high/366;
		low=low/366;
		rain=rain/366;
		snow=snow/366;
	}
	else
	{
		high=high/365;
		low=low/365;
		rain=rain/365;
		snow=snow/365;
	}
    cout<<"Avg Max Temp \t Avg Min temp \t Avg Rainfall \t Avg Snowfall \n";
    cout<<high<<"\t\t"<<low<<"\t\t"<<rain<<"\t\t"<<snow<<endl;
}
//--------------------------------VALIDATIONS---------------------------------------------------
int validation1(int x)
{
    int flag;
    if(x<1950||x>2150)
    {
        cout<<"You have entered an incorrect value for year. \n Re-enter\n";
        flag=5;
    }
    else if(x%4==0)
        {
            if(x%100==0)
            {
                if(x%400==0)
                {
                    flag=1;
                }
                else
                    flag=0;
            }
            else
                flag=1;
        }
        else
            flag=0;
    return flag;
}

int validate(int month_no,int day_no,int leap)
{
    int flag;
    if(month_no==1||month_no==3||month_no==5||month_no==7||month_no==8||month_no==10||month_no==12)
    {
        if(day_no>0&&day_no<32)
            flag=1;
        else
            flag=0;
    }
    else if(month_no==4||month_no==6||month_no==9||month_no==11)
    {
        if(day_no>0&&day_no<31)
            flag=1;
        else
            flag=0;
    }
    else if(month_no==2)
    {
        if(leap==1)
        {
            if(day_no>0&&day_no<30)
            flag=1;
            else
                flag=0;
        }
        else
        {
            if(day_no>0&&day_no<29)
            flag=1;
            else
                flag=0;
        }
    }
    else
        flag=0;
    return flag;
}
//---------------------------------------------------------------------------
int main()
{
    weather_report w[12];
    int year,flag,leap,day,month_1;
    cout<<"Enter the year you want to make database for. \n";
    cin>>year;
    leap=validation1(year);
    for(int i=0;i<12;i++)
    {
        if(leap==5)
        {
            i--;
            cin>>year;
            leap=validation1(year);
            break;
        }
        else
        {
            int k=i+1;
            w[i].assignment(k,leap);
        }
    }
    cout<<"The program has initialized all the record as zero. \n";
    for(int i=0;i<12;i++)
    {
        int k=i+1;
        cout<<"Month : "<<k<<endl;
        cout<<"Date\tMax.Temp\tMin.Temp\tRainfall\tSnowfall\n";
        w[i].display();
    }
    //-----------------------------------------------------------------------------------------
    int k;
    do
    {
        cout<<" 1. Display \n 2. Modify \n 3.Average \n Enter the number of menu you want to select. : ";
        cin>>k;
        switch(k)
        {
        case 1:
        {
            cout<<"Enter the date you want to display. \n";
            cin>>day>>month_1;
            flag=validate(month_1,day,leap);
            if(flag==0)
               {
                   do
                    {
                        cout<<"Enter correct values.\n";
                        cout<<"Enter the date you want to display. \n";
                        cin>>day>>month_1;
                        flag=validate(month_1,day,leap);

                    }while(flag==0);
               }

            w[month_1-1].display(day);
            break;
        }

        case 2:
        {
            cout<<"Enter the date you want to modify \n";
            cin>>day>>month_1;
            flag=validate(month_1,day,leap);
            if(flag==0)
               {
                   do
                    {
                        cout<<"Enter correct values.\n";
                        cout<<"Enter the date you want to modify. \n";
                        cin>>day>>month_1;
                        flag=validate(month_1,day,leap);

                    }while(flag==0);
               }
            w[month_1-1].getdata(day);
            cout<<"After Modification, the database is as follows. : \n";
             for(int i=0;i<12;i++)
                {
                    int k=i+1;
                    cout<<"Month : "<<k<<endl;
                    cout<<"Date\tMax.Temp\tMin.Temp\tRainfall\tSnowfall\n";
                    w[i].display();
                }
            break;
        }
        case 3:
        {
        	average(w,leap);
            break;
        }

        }
        cout<<"Do you wish to go to the previous menu again? \n 1. Yes 2. No \n";
        cin>>k;
    }while(k==1);
    return 0;
}
