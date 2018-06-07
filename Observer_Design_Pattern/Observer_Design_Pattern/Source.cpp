//An observer design pattern acts as a broadcast channel to send information to subscribers
#include<iostream>
#include<vector>
using namespace std;

class Subject
{
	int value;
	vector<class Observer*> views;

public:
	void notify();
	int getValue()
	{
		return value;
	}
	void setValue(int x)
	{
		value = x;
		notify();
	}

	void attach(Observer *obs)
	{
		views.push_back(obs);
	}
};

class Observer
{
	Subject* model;
	int denom;

public:
	Observer(Subject* mod, int div)
	{
		model = mod;	//Registering the observer with the model
		denom = div;
		model->attach(this);
	}

	virtual void update() = 0;

protected:

	Subject* getSubject()
	{
		return model;
	}

	int getDivisor()
	{
		return denom;
	}
};

void Subject::notify()
{
	for (int i = 0; i < views.size(); i++)
	{
		views[i]->update();
	}
}

class DivObserver : public Observer
{
public:
	DivObserver(Subject* mod, int div) : Observer(mod, div){}
	void update()
	{
		int v = getSubject()->getValue();
		int d = getDivisor();
		cout << v << " div " << d << " is " << v / d << endl;
	}
};

class ModObserver : public Observer
{
public:
	ModObserver(Subject* mod, int div) : Observer(mod, div){}
	void update()
	{
		int v = getSubject()->getValue();
		int d = getDivisor();
		cout << v << " mod " << d << " is " << v % d << endl;
	}
};


int main()
{
	Subject sub;
	DivObserver div1(&sub, 4);
	DivObserver div2(&sub, 3);
	ModObserver mod1(&sub, 3);
	sub.setValue(14);
	return 0;
}