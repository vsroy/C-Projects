#include<iostream>
#include<list>
using namespace std;

class Hash
{
	list<int> *hashList;
	int hashSize;
public:
	Hash(int hashSize) : hashSize(hashSize)
	{
		hashList = new list<int>[hashSize];
	}
	~Hash()
	{
		delete [] hashList;
	}
	void InsertItem(int val);
	void DeleteItem(int val);
	int hashFunction(int val);
	void DisplayHash();
};

int Hash::hashFunction(int val)
{
	return (val % hashSize);
}

void Hash::InsertItem(int val)
{
	int index = hashFunction(val);
	hashList[index].push_back(val);
}

void Hash::DeleteItem(int val)
{
	int index = hashFunction(val);
	hashList[index].remove(val);
}

void Hash::DisplayHash()
{
	for (int i = 0; i < hashSize; i++)
	{
		list<int>& tempList = hashList[i];
		cout << i << "----";
		for (auto j : tempList)
		{
			cout << "--->" << j;
		}
		cout << endl;
	}
}

int main()
{
	int a[] = { 15, 11, 27, 8, 12 };
	int n = sizeof(a) / sizeof(a[0]);

	Hash hashObj(7);

	for (int i = 0; i < n; i++)
		hashObj.InsertItem(a[i]);

	hashObj.DeleteItem(12);

	hashObj.DisplayHash();

	return 0;

}