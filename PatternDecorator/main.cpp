#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class CollectionItem {
private:
	int numberOfCopies{};
public:
	CollectionItem() {};
	virtual ~CollectionItem() {};
	virtual void Show()const = 0;
	int GetNumberOfCopy() const {
		return numberOfCopies;
	}
	void SetNumberOfCopy(int value) {
		numberOfCopies = value;
	}
};

class Decorator : public CollectionItem {
protected:
	CollectionItem* item;
public:
	Decorator(CollectionItem* pItem) {
		item = pItem;
	}
	virtual ~Decorator() {}

	void Show()const {
		item->Show();
	}
};

class Book : public CollectionItem {
private:
	string autor;
	string title;
	string style;
public:
	Book(string pAutor, string pTitle, string pStyle, int pNumCopies) {
		autor = pAutor;
		title = pTitle;
		style = pStyle;
		SetNumberOfCopy(pNumCopies);
	}
	virtual ~Book() {}
	void Show()const {
		cout << "********************" << endl;
		cout << "Информация о Книге" << endl;
		cout << "Автор: " << autor << endl;
		cout << "Название: " << title << endl;
		cout << "Жанр: " << style << endl;
		cout << "Numbers of copies: " << GetNumberOfCopy() << endl;
		cout << "********************" << endl;
	}
};


class CD : public CollectionItem {
private:
	string singer;
	string title;
	string style;
	int playTame;
	int numCopies;
public:
	CD(string pSinger, string pTitle, string pStyle, int pPlayTame, int pNumCopies) {
		singer = pSinger;
		title = pTitle;
		style = pStyle;
		playTame = pPlayTame;
		numCopies = pNumCopies;
	}
	virtual ~CD() {}
	void Show()const {
		cout << "********************" << endl;
		cout << "Информация о CD" << endl;
		cout << "Исполнитель: " << singer << endl;
		cout << "Название песни: " << title << endl;
		cout << "Жанр: " << style << endl;
		cout << "Duration of CD: " << playTame << endl;
		cout << "Numbers of copies: " << GetNumberOfCopy() << endl;
		cout << "********************" << endl;
	}
};

class Borrowble : public Decorator {
private:
	vector<string> users;
public:
	Borrowble(CollectionItem* item) : Decorator(item) {}
	virtual ~Borrowble() {};

	void BorrowbleItem(string name) {
		users.push_back(name);
		item->SetNumberOfCopy(item->GetNumberOfCopy() - 1);
	}
	void ReturnItem(string name) {
		auto result = find(users.begin(), users.end(), name);
		if (result != users.end()) {
			users.erase(result);
			item->SetNumberOfCopy(item->GetNumberOfCopy() + 1);
		}
	}
	void Show() const {
		for (auto ptr = users.begin(); ptr != users.end(); ptr++) {
			cout << "Member: " << (*ptr) << endl;
		}
	}
};

int main()
{
	SetConsoleOutputCP(1251);

	Book* book = new Book("Велтисов", "Приключение Электроника", "Фантастика", 10);
	book->Show();

	CD* cd = new CD("Алла Пугачёва", "Миллион алых роз", "Классика", 100, 20);
	cd->Show();

	//Заимствуем
	Borrowble* borrowble = new Borrowble(book);
	borrowble->BorrowbleItem("Boris");
	borrowble->BorrowbleItem("Tanya");
	borrowble->Show();
	cout << endl;

	borrowble->ReturnItem("Boris");
	borrowble->BorrowbleItem("Igor");
	borrowble->Show();

	cout << endl;
	cout << endl;
	Borrowble* borrowble2 = new Borrowble(cd);
	borrowble2->BorrowbleItem("Ignat");
	borrowble2->BorrowbleItem("Denis");
	borrowble2->Show();
	cout << endl;

	borrowble2->ReturnItem("Denis");
	borrowble2->BorrowbleItem("Ignat");
	borrowble2->Show();

	delete book;
	delete cd;

	return 777;
}