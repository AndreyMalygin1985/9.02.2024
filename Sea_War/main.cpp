#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class Unit {
public:
	Unit() {};
	virtual ~Unit() {};

	virtual int GetPower() const = 0;
	virtual void AddUnit(Unit* p) = 0;
};

class CompositeUnit : public Unit {
public:
	vector <Unit*> fleet;
	CompositeUnit() {};
	virtual ~CompositeUnit() {
		for (size_t i = 0; i < fleet.size(); i++) {
			delete fleet[i];
		}
	};

	int GetPower()const {
		int amout = 0;
		for (size_t i = 0; i < fleet.size(); i++) {
			amout += fleet[i]->GetPower();
		}
		return amout;
	};

	void AddInit(Unit* p) {
		fleet.push_back(p);
	}
};

class MonoTubeShip : public Unit {
public:
	MonoTubeShip() {};
	virtual ~MonoTubeShip() {};

	int GetPower()const { return 1; }

	void AddUnit(Unit* p) {
		throw "This operation is not supported";
	}
};

class TewinTubeShip : public Unit {
public:
	TewinTubeShip() {};
	virtual ~TewinTubeShip() {};

	int GetPower()const { return 2; }

	void AddUnit(Unit* p) {
		throw "This operation is not supported";
	}
};

class TripleTubeShip : public Unit {
public:
	TripleTubeShip() {};
	virtual ~TripleTubeShip() {};

	int GetPower()const { return 3; }

	void AddUnit(Unit* p) {
		throw "This operation is not supported";
	}
};

class FourTubeShip : public Unit {
public:
	FourTubeShip() {};
	virtual ~FourTubeShip() {};

	int GetPower()const { return 4; }

	void AddUnit(Unit* p) {
		throw "This operation is not supported";
	}
};

CompositeUnit* CreatFleet() {
	CompositeUnit* fleet = new CompositeUnit;
	for (size_t i = 0; i < 4; i++) {
		fleet->AddUnit(new MonoTubeShip());
	}
	for (size_t i = 0; i < 3; i++) {
		fleet->AddUnit(new TewinTubeShip());
	}
	for (size_t i = 0; i < 2; i++) {
		fleet->AddUnit(new TripleTubeShip());
	}
	fleet->AddUnit(new FourTubeShip());
	return fleet;
}

int main()
{
	SetConsoleOutputCP(1251);

	CompositeUnit* fleet = CreatFleet();
	cout << "Вся мощь нашего флота" << fleet->GetPower() << endl;

	delete fleet;

	return 777;
}