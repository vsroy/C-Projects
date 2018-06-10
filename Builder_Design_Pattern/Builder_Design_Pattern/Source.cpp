//The builder design pattern is used to build the components of an object step by step
#include <iostream>
#include <string>
using namespace std;

class Plane  //The end product
{
	string _plane;
	string _body;
	string _engine;

public:
	Plane(string planeType) : _plane(planeType){}
	void setEngine(string type)
	{_engine = type;}

	void setBody(string type)
	{
		_body = type;
	}

	string getEngine()
	{
		return _engine;
	}

	string getBody()
	{
		return _body;
	}

	void showPlaneDetails()
	{
		cout << "Plane = " << _plane << endl;
		cout << "Engine = " << _engine << endl;
		cout << "Body = " << _body << endl;
	}
};

//The plane builder abstract class. All subsequent classes will inherit these methods
class PlaneBuilder
{
protected:
	Plane* _plane;
public:
	virtual void getPartsDone() = 0;
	virtual void buildBody() = 0;
	virtual void buildEngine() = 0;
	Plane* getPlane()
	{
		return _plane;
	}
};

class PropellorBuilder : public PlaneBuilder
{
public:
	void getPartsDone()
	{
		_plane = new Plane("propeller plane");
	}

	void buildBody()
	{
		_plane->setBody("Propellor body");
	}

	void buildEngine()
	{
		_plane->setEngine("Propellor Engine");
	}
};

class JetBuilder : public PlaneBuilder
{
public:
	void getPartsDone()
	{
		_plane = new Plane("Jet plane");
	}

	void buildBody()
	{
		_plane->setBody("Jet body");
	}

	void buildEngine()
	{
		_plane->setEngine("Jet Engine");
	}
};

//Defines the steps and then tells the builder to build in given order
class Director
{
public:
	Plane* createPlane(PlaneBuilder* builder)
	{
		builder->getPartsDone();
		builder->buildBody();
		builder->buildEngine();
		return builder->getPlane();
	}
};

int main()
{
	Director dir;
	JetBuilder jb;
	PropellorBuilder pb;

	Plane *jet = dir.createPlane(&jb);
	Plane *propellor = dir.createPlane(&pb);

	delete jet;
	delete propellor;

	jet->showPlaneDetails();
	propellor->showPlaneDetails();

	return 0;
}