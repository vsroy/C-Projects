//Program to randomize an array of 50 numbers
#include<iostream>
#include "time.h"
using namespace std;
#define MAX 50

void PrintArray(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

int main()
{
	int *arr = new int[MAX];
	
	//Assigning the values first
	for (int i = 1; i <= 50; i++)
		arr[i-1] = i;

	//Now randomizing the array
	srand(time(NULL));
	int temp = 0;

	cout << "Array before shuffling = ";
	PrintArray(arr, MAX);

	for (int i = 0; i < 50; i++)
	{
		int x = rand() % 50;
		int temp2 = arr[temp];
		arr[temp] = arr[x];
		arr[x] = temp2;
		temp = x;
	}

	cout << "\n\nArray after shuffling = ";
	PrintArray(arr, MAX);

	int a, b, c;
	cout << "Enter 3 numbers for the lottery : ";
	cin >> a >> b >> c;

	int random = rand() % 7;
	if ((arr[random] == a) && (arr[random + 1] == b) && (arr[random + 2] == c))
		cout << "\nYou have won the lottery\n";
	else
		printf("Better luck next time");

	return 0;
}