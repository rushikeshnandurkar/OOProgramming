//============================================================================
//		Rushikesh Nandurkar  [SI035]
//============================================================================
// Name        : StringOperations_.cpp

// Description : StringOperations assignment in C++
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

class stringop
{
	int len;
	char *str=NULL;
public:
	stringop(){len=0;}//...........default constructor
	stringop(char *);//...........parameterized constructor
	int length(char *);//......to find out the length
	void allocate(stringop,stringop);//......to allocate memories dynamically
	void allocate(stringop);//.....to allocate memory dynamically
	void display();
	stringop operator+(stringop);//.........operator overloading
	stringop operator-();//........operator overloading
	void copy(stringop);
	friend int palindrome(stringop);
	int operator==(stringop);
	void occur(char);//......to check occurrence of a single character
	int substring(char *);//.......to check occurrence of a substring

};

stringop::stringop(char *s)
{
	len=length(s);
	str=new char[len+1];
	strcpy(str,s);
}

int stringop::length(char *s)
{
	int i=0;
	while(*s!='\0')
	{
		i++;
		s++;
	}
	return i;
}
void stringop::display()
{
	cout<<"The string is : "<<str<<"\n And the length is : "<<len<<endl;
}

void stringop::allocate(stringop s1,stringop s2)
{
	len=s1.len+s2.len;
	str=new char[len+1];
}

void stringop::allocate(stringop s1)
{
	len=s1.len;
	str=new char[len+1];
}

stringop stringop::operator+(stringop s2)
{
	stringop temp;
	temp.len=len+s2.len;
	temp.str=new char[temp.len+1];
	char *ptr;
	ptr=temp.str;
	while(*str!='\0')
	{
		*ptr=*str;
		ptr++;str++;
	}

	while(*s2.str!='\0')
	{
		*ptr=*s2.str;
		ptr++;s2.str++;
	}
	*ptr='\0';
	return temp;
}

stringop stringop::operator-()
{
    stringop temp;
    temp.len=len;
    temp.str=new char[temp.len+1];
    char *ptr;
    ptr=temp.str;
    while(*str!='\0')
    {
        str++;
    }
    str--;
    int i=0;
    while(i<len)
    {
        *ptr=*str;
        ptr++;str--;
        i++;
    }
    *ptr='\0';
    return temp;
}

int palindrome(stringop s1)
{
	int flag;
	char *ptr=s1.str;
	while(*s1.str!='\0')
		s1.str++;
	s1.str--;
	while(*ptr!='\0')
	{
		if(*ptr==*s1.str)
		flag=1;
		else
		{
			flag=0;
			break;
		}
		ptr++;s1.str--;
	}
	return flag;
}

void stringop::copy(stringop s1)
{
	len=s1.len;
	str=new char[len+1];
	char *ptr=str;
	while(*s1.str!='\0')
	{
		*ptr=*s1.str;
		ptr++;s1.str++;
	}
	*ptr='\0';
}

int stringop::operator==(stringop s2)
		{
			int flag;
			while(*str!='\0'||*s2.str!='\0')
			{
				if(*str==*s2.str)
					flag=1;
				else
				{
					flag=0;
					break;
				}
				str++;s2.str++;
			}
			return flag;
		}

void stringop::occur(char c)
{
	int i=0;
	while(*str!='\0')
	{
		if(*str==c)
			i++;
		str++;
	}
	cout<<"The character "<<c<<" is occured "<<i<<" times in entered string.\n";
}

int stringop::substring(char *s)
{
	int len_s=0;
	int occ=0;
	char *ptr1=s;
	while(*ptr1!='\0')
	{
		len_s++;
		ptr1++;
	}
	int i=0;
	len_s--;
	int j=len-len_s;
	len_s++;
	int k=0;
	while(k<j)
	{
		i=0;
		char *ptr1=s;
		char *ptr=str;
		while(*ptr1!='\0')
		{
			if(*ptr==*ptr1)
			{
				ptr++;
				ptr1++;
				i++;
			}
			else
				break;
		}
		if(i==len_s)
			occ++;
		str++;
		k++;
	}
	return occ;
}

int main()
{
	char str1[10];
	int flag;
	do
	{
		cout<<"Select the option. \n1.Concat \n2.Reverse\n3.Palindrome\n";
		cout<<"4.Copy\n5.Compare\n6.Occurence\n7.Substring\n";
		cin>>flag;
		switch(flag)
		{
		case 1:
		{
			cout<<"Enter first string : ";
			cin>>str1;
			stringop s1(str1);
			cout<<"Enter second string : ";
			cin>>str1;
			stringop s2(str1);
			stringop s3;
			s3.allocate(s1,s2);
			s3=s1+s2;
			s3.display();
			break;
		}
		case 2:
            {
                cout<<"Enter the string to be reversed. \n";
                cin>>str1;
                stringop s1(str1);
                stringop s2;
                s2.allocate(s1);
                s2=-s1;
                s2.display();
                break;
            }
       case 3:
            {
            	cout<<"Enter the string you want to check if palindrome.\n";
            	cin>>str1;
            	stringop s1(str1);
            	flag=palindrome(s1);
            	if(flag==1)
            	cout<<"Entered string is palindrome. \n";
            	else
            	cout<<"Entered string is not a palindrome.\n";
            	break;
            }
        case 4:
        	{
        		cout<<"Enter string which is going to be copied.\n";
        		cin>>str1;
        		stringop s1(str1);
        		stringop s2;
        		s2.allocate(s1);
        		s2.copy(s1);
        		s2.display();
        		break;
        	}
        case 5:
        {
        	cout<<"Enter the first string.\n";
        	cin>>str1;
        	stringop s1(str1);
        	cout<<"Enter the second string.\n";
        	cin>>str1;
        	stringop s2(str1);
        	flag=s1==s2;
        	if(flag==1)
        		cout<<"Strings are equal.\n";
        	else
        		cout<<"Strings are not equal.\n";
        	break;
        }
        case 6:
        {
        	char c;
        	cout<<"Enter the string.\n";
        	cin>>str1;
        	cout<<"Enter the character whose occurence is needed to be checked.\n";
        	cin>>c;
        	stringop s1(str1);
        	s1.occur(c);
        	break;
        }
        case 7:
        {
        	cout<<"Enter the parent string.\n";
        	cin>>str1;
        	stringop s1(str1);
        	cout<<"Enter the substring to check the occurence of.\n";
        	cin>>str1;
        	flag=s1.substring(str1);
        	cout<<"The given substing is occured "<<flag<<" times on your string.\n";
        	break;
        }
		}
		cout<<"Do you wish to enter previous menu again? \n1. Yes	2. No. \n";
		cin>>flag;
	}while(flag==1);
	cout<<flag<<" means The End Of the Process.\n";
return 0;
}
