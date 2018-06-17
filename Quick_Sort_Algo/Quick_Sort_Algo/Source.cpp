//Program to impmement quick sort algorithm
#include<iostream>
using  namespace std;

void PrintElements(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void SwapElements(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int quickSort(int *arr, int low, int high)
{
	int pivot = arr[high];
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			SwapElements(&arr[i], &arr[j]);
			i++;
		}
	}
	SwapElements(&arr[i], &arr[high]);
	return i;
}

void partition(int *arr, int low, int high)
{
	if (low < high)
	{
		int pivot = quickSort(arr, low, high);	
		partition(arr, low, pivot - 1);
		partition(arr, pivot + 1, high);
	}
}

int main()
{
	int arr[] = { 10, 7, 8, 9, 1, 5 };
	cout << "\nElements before partition = "; PrintElements(arr, 6);
	partition(arr, 0,5);
	cout << "\nElements after partition = "; PrintElements(arr, 6);
	return 0;
}