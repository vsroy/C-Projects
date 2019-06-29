#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

void ArrayReducedForm(int* arr,  int size)
{
	//Create a temp array
	int* temp = new int[size];

	//Copy the elements to the temporary array from the original array
	memcpy(temp, arr, size*sizeof(int));

	//Sort the array using in built algorithm
	sort(temp, temp+size);

	//Use an unordered map to store numbers and their indexes in sorted order
	unordered_map<int, int> u_map;

	//Traverse the elements in the temporary array and add them to the map
	for (int i = 0; i < size; i++)
		u_map[temp[i]] = i;

	//One by one, copy the elements from the unordered map to the original array by their sorted index
	for (int i = 0; i < size; i++)
	{
		int temp = arr[i];
		arr[i] = u_map[temp];
	}
}

void PrintArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}

int main()
{
	int arr[] = { 10, 20, 15, 12, 11, 50 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given Array is \n";
	PrintArray(arr, n);

	ArrayReducedForm(arr, n);

	cout << "\n\nConverted Array is \n";
	PrintArray(arr, n);

	return 0;
}