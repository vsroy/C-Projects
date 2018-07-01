//Implementting a greedy algorithm to find the miniumun number of coins
#include<iostream>
#include<vector>
using namespace std;

void PrintDenominations(int *denomination_Array, int totalSum, int size)
{
	vector<int> deno_Vector;
	for (int i = size - 1; i >= 0; i--)
	{
		while (totalSum >= denomination_Array[i])
		{
			totalSum = totalSum - denomination_Array[i];
			deno_Vector.push_back(denomination_Array[i]);
		}
	}
	cout << "The total number of denominations required are " << deno_Vector.size() << endl;
	cout << "Denominations are ";
	for (int i = 0; i < deno_Vector.size(); i++)
		cout << deno_Vector[i] << " ";
}

int main()
{
	int denomination_Array[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
	int size = sizeof(denomination_Array) / sizeof(denomination_Array[0]);
	PrintDenominations(denomination_Array, 93, size);
	return 0;
}
