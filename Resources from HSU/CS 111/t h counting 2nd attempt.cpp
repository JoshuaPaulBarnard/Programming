//--------------------------------------
//Joshua P. Barnard
//CS 111 HW
//Due: 10/24/13
//t and h counting
//----------------------------------------

#include <iostream>
using namespace std;

int main ()
{
	
	char text;
	int count1=0;
	int count2=0;

//Input Text to be evaluated-------------------

	cout<<"Please Enter Text:  ";
	cin>>text;
	
	
	while (text != '.')
	{
//Test
		
		if(text == 't')
		{
			cin>>text;
			
				if(text == 'h')
				{
				count2++;
				}
		
		
			else
			{
			count1++;
			}
		}
	
		else
		{
		cin>>text;
		}
	}
	
	
	cout<<"The total number of t's is:  "<<count1<<endl;
	cout<<"The total number of th's is:  "<<count2;
	
	return 0;
}
