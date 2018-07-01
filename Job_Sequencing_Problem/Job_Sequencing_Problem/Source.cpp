//Program to solve the Job sequencing problem using Greedy Principle
#include<iostream>
#include<algorithm>
using namespace std;

struct Job
{
	char jobID;
	int profit;
	int deadline;
};

bool comparision(Job job1, Job job2)
{
	return (job2.deadline > job1.deadline);
}

void PrintJobSequence(Job *jobs, int size)
{

	int *jobSequence = new int[size];
	bool *slots = new bool[size];
	sort(jobs, jobs + size, comparision);

	for (int i = 0; i < size; i++)
		slots[i] = true;

	for (int i = 0; i < size; i++)
	{
		for (int j = min(jobs[i].deadline, size) - 1; j >= 0; j--)
		{
			if (slots[j] == false)
			{
				jobSequence[i] = j;
				break;
			}
		}
	}

	cout << "\nThe correct job sequence is ";
	for (int i = 0; i < size; i++)
		if (slots[i] == false)
			cout << jobs[i].jobID << " ";
}

int main()
{
	Job jobs[] = {
		{ 'a', 2, 100 },
		{ 'b', 1, 19 },
		{ 'c', 2, 27 },
		{ 'd', 1, 25 },
		{ 'e', 3, 15 }
	};

	int size = sizeof(jobs) / sizeof(jobs[0]);
	PrintJobSequence(jobs, size);
	return 0;
}