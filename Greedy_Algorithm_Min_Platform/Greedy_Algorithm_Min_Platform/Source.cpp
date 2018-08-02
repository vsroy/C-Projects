//A Greedy Algorithm to find the minimum number of platforms
#include<iostream>
#include<algorithm>
using namespace std;

void FindMinPlatForm(int *arr, int *dep, int size)
{
	sort(arr, arr + size);
	sort(dep, dep + size);
	
	int platforms = 1; int result = 1;
	int arrivalCounter = 1;  int departureCounter = 0;
	while ((arrivalCounter < size) && (departureCounter < size))
	{
		if (arr[arrivalCounter] <= dep[departureCounter])
		{
			platforms++;
			arrivalCounter++;
			if (platforms > result)
				result = platforms;
		}
		else
		{
			platforms--;
			departureCounter++;
		}
	}
	cout << "Minimum number of platforms needed are = " << result;
}

int main()
{
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	FindMinPlatForm(arr, dep, n);
	return 0;
}