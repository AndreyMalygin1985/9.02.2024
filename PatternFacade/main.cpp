#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class Firma {
private:
	string name;
	bool builderLicense;
	bool enviromentalLicense;
	bool cityLicense;
public:
	Firma() {
		builderLicense = false;
		name = "";
	}
	Firma(string fName, bool bLicense, bool eLicense, bool cLicense) {
		builderLicense = false;
		name = fName;
		bLicense = bLicense;
		eLicense = eLicense;
		cLicense = cLicense;
	}
	virtual ~Firma() {}

	string GetName() {
		return name;
	}
	void SetName(string fName) {
		name = fName;
	}

	bool SetbuilderLicense() {
		return builderLicense;
	}

	bool GetCityLicense(bool ) {
		return cityLicense;
	}


};

class EnviromentalService {
public:
	EnviromentalService() {}
	virtual ~EnviromentalService() {}

	bool HasEnviromentalAccess(Firma* pFirma) {
		return pFirma->GetEnviromentalLicense() ? true : false;
	}
};

class CityService {
public:
	CityService() {}
	virtual ~CityService() {}

	bool HasCityAccess(Firma* pFirma) {
		return pFirma->GetCityLicense() ? true : false;
	}
};

class BuilderService {
public:
	BuilderService() {}
	virtual ~BuilderService() {}

	bool HasBuilderAccess(Firma* pFirma) {
		return pFirma->GetBuilderLicense() ? true : false;
	}
};

class Facade {
public:
	EnviromentalService eService;
	CityService cService;
	BuilderService bService;

	Facade() {}
	virtual ~Facade() {}

	bool IsAllowed(Firma* pFirma) {
		if (cService.HasCityAccess(pFirma) && eService.HasEnviromentalAccess(pFirma) && bService.HasBuilderAccess(pFirma))
		{
			return true;
		}return false;
	}
};

int main()
{
	SetConsoleOutputCP(1251);

	Facade facade;

	Firma* myFavoriteFirma = new Firma("LTD РОГА И КОПЫТА", true, true, false);
	bool allowed = facade.IsAllowed(myFavoriteFirma);

	cout << myFavoriteFirma->GetName() << ((allowed) ? " Будет строить!" : " Фигвам строить");

	return 777;
}