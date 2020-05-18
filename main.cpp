#include <iostream>
#include <string>

using namespace std;

class Wallet_info {
public:                  //public св-ва
	int rur_amount = 0;
};

class Human{
protected:
	string name; //Инкапсуляция с помощью set/get
	unsigned int len;
public:
	void set_name(string name) { //setter
		this->name = name;
	}

	string get_name() const { //getter
		return name;
	}

	void human_says_name() { //Расширения поведения
	cout << "я хотел бы быть ашотом, но я -  " << get_name() << endl;
}
	virtual void say_shutka() const {
		cout << "очередной баян" << endl;
	}

	virtual void lenght(unsigned int len) {    //Позднее связывание
	this->len = len;
	cout << len;
}

	virtual void cry() {
		cout << "imcrying" << endl;
	}
};


class Baby : public Human {   //Инкапсуляция при помощи абстракций
private:
	bool horosho_kakaet;
	unsigned int weight;
public:
	Baby(bool horosho_kakaet, unsigned int weight) : Human() {
		this->horosho_kakaet = horosho_kakaet;
		this->weight = weight;
	}

	void cry() override {  //Замена поведения
		cout << "auahahahuaahahahahyauauyu ya ustal" << endl;
	}

	void shutka_ot_batya(Human* h) {
		h->say_shutka();
	}

};

int main() {
	setlocale(LC_ALL, "Russian");
	Wallet_info ledger;
	cout << ledger.rur_amount << endl;

	Human papa;
	papa.set_name("Vasyan");
	papa.human_says_name();
	papa.get_name();
	papa.cry();


	Baby small(true, 30);
	small.cry();
	small.shutka_ot_batya(&papa);

}
