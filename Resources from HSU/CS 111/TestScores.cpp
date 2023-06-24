//---------------------------------------------------------------------
//Joshua P. Barnard
//CS 111 Fall 2013
//Due: 12/05/13
//Test Scores
//---------------------------------------------------------------------


#include<iostream>

using namespace std;

//********************************************************************************
//This function receives input values from the main program and outputs an average
//for all the values it receives.
//********************************************************************************

float
averagefunction(int array[], int count)
{
	int i;
	float total, average;
	
	i = 0;
	
	while(i != count)
	{
		total = total + array[i];
		
		i++;
		
	}
	
	average = total / count;
	
	return average;
	
}


//****************************************************************************
// The main function receives a series of integers and sends them to the array
// until it receives a -1.  Upon each input, it stores the greatest and lowest 
// integers.  When a -1 is entered, the program tells the user the total number
// of scores entered, the highest and lowest scores, the average, and all 
// scores that were entered above the mean.
//****************************************************************************


int
main()
{

float answer;
int count, score, greatest, lowest, i, array[25];

count = 1;
i = 0;

cout << "Please enter a test score: ";
cin >> score;

greatest = score;
lowest = score;

while(score != -1)
{
	
	array[i] = score;
	
	if(array[i] > greatest)
		greatest = array[i];
	
	if(array[i] < lowest)
		lowest = array[i];
		
	i++;
	
	cout << "\nPlease enter a test score: ";
	cin >> score;
	
}

count = i;

cout << "\n-----------------------------------------\nHighest Score:  " << greatest << '\n';

cout << "Lowest Score:  " << lowest << '\n';

cout << "Total Number of Scores:  " << count << '\n';

answer = averagefunction(array, count);

cout << "The Average:  " << answer << '\n';

cout << "All Scores Greater Than The Mean Are:" << '\n';

i = 0;

while(i <= count - 1)
{
	
	if(array[i] > answer)
	
	cout << array[i] << ", ";
	
	i++;
	
}

}
