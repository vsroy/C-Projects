//Program to implement the merge sort algorithm
#include<iostream>
using namespace std;

void PrintElements(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
}

void MergeElements(int *arr, int left, int mid, int right)
{
	int elementsA = mid - left + 1;
	int elementsB = right - mid;

	int *leftArray = new int[elementsA];
	int *rightArray = new int[elementsB];

	for (int i = 0; i < elementsA; i++)
	{leftArray[i] = arr[left + i];}

	for (int i = 0; i < elementsB; i++)
	{rightArray[i] = arr[mid + 1 + i];}

	int leftCounter = 0; int rightCounter = 0; int mainCounter = 0;

	while ((leftCounter < elementsA) && (rightCounter < elementsB))
	{
		if (leftArray[leftCounter] < rightArray[rightCounter])
		{
			arr[mainCounter] = leftArray[leftCounter];
			leftCounter++;
		}
		else
		{
			arr[mainCounter] = rightArray[rightCounter];
			rightCounter++;
		}
		mainCounter++;
	}

	while (leftCounter < elementsA)
	{
		arr[mainCounter] = leftArray[leftCounter];
		leftCounter++; mainCounter++;
	}

	while (rightCounter < elementsB)
	{
		arr[mainCounter] = rightArray[leftCounter];
		leftCounter++; mainCounter++;
	}
}

void Merge(int *arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		Merge(arr, left, mid);
		Merge(arr, mid + 1, right);
		MergeElements(arr, left, mid, right);
	}
}

int main()
{
	int arr[] = {4,56,8,1,32,10,55,87,115,541};
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]);
	cout << "\n\nArray size = " << right;
	cout << "\nElements before merge = ";
	PrintElements(arr, right);
	Merge(arr, 0, right-1);
	cout << "\nElements after merge = ";
	PrintElements(arr, right);
	return 0;


}