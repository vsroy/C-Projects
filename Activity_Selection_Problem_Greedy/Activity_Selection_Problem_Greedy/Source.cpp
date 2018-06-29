//Program to solve the activity selection problem using the greedy method
#include<iostream>
using namespace std;

void SolveActivityProblem(int *startTime, int *endTime, int size)
{
	int i = 0;
	cout << i;
	for (int j = 1; j < size; j++)
	{
		if (startTime[j] >= endTime[i])
		{
			cout << " " << j;
			i = j;
		}
	}
}


int main()
{
	int start[] = { 1, 3, 0, 5, 8, 5 };
	int end[] = {  2, 4, 6, 7, 9, 9  };
	int size = sizeof(start) / sizeof(int);
	SolveActivityProblem(start, end, size);
	return 0;
}