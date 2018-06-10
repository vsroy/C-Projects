//Factory method design patterns delegates the object creation process to the library based on the options provided
#include<iostream>
using namespace std;

class Fruit
{
public:
	static Fruit* eatFrut(int option);
	virtual void DisplayColor() = 0;
};

class Orange : public Fruit
{
public:
	void DisplayColor()
	{
		cout << "Orange";
	}
};

class Apple : public Fruit
{
public:
	void DisplayColor()
	{
		cout << "Red";
	}
};

class Banana : public Fruit
{
public:
	void DisplayColor()
	{
		cout << "Banana";
	}
};


Fruit* Fruit::eatFrut(int option)
{
	switch (option)
	{
	case(1) :
		return new Orange;

	case(2) :
		return new Apple;

	case(3) :
		return new Banana;

	default:
		break;
	}
}



int main()
{
	int choice;
	cout << "Enter your choice ";
	cin >> choice;

	Fruit::eatFrut(choice)->DisplayColor();

	return 0;
}

