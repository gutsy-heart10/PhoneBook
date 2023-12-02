#include<iostream>
#include<string.h>
using namespace std;


class Phonebook {
private:
	char* fullName;
	char homeNumb[30]{};
	char workNumb[30]{};
	char mobileNumb[30]{};
	char additionalInformation[30]{};
public:
	Phonebook() {}
	Phonebook(const char* fullname, const char* homenumb, const char* worknumb, const char* mobilenumb, const char* additionalInfo) {
		fullName = new char[strlen(fullname) + 1];
		strcpy_s(this->fullName, strlen(fullname) + 1, fullname);

		strcpy_s(homeNumb, 30, homenumb);
		strcpy_s(workNumb, 30, worknumb);
		strcpy_s(mobileNumb, 30, mobilenumb);
		strcpy_s(additionalInformation, 30, additionalInfo);
	}

	void showSubs(int index) {
		cout << "------------------------------" << endl;
		cout << "Subscriber " << ++index << endl;
		cout << "Full Name: " << fullName << endl;
		cout << "Home number: " << homeNumb << endl;
		cout << "Work number: " << workNumb << endl;
		cout << "Mobile number: " << mobileNumb << endl;
		cout << "Additional information: " << additionalInformation << endl;
		cout << "------------------------------" << endl;
	}
	void setFullName(const char* name) {
		delete[] fullName;
		fullName = new char[strlen(name) + 1];
		strcpy_s(fullName, strlen(name) + 1, name);
	}
	char* getFullName() {
		return fullName;
	}
	void setHomeNumber(const char* home) {
		strcpy_s(homeNumb, 30, home);
	}
	void setWorkNumber(const char* work) {
		strcpy_s(workNumb, 30, work);
	}
	void setMobileNumber(const char* mobile) {
		strcpy_s(mobileNumb, 30, mobile);
	}
	void setAdditionalInfo(const char* info) {
		strcpy_s(additionalInformation, 30, info);
	}
};

class Subscribers {
private:
	Phonebook* subscribers;
	int size;
	int capacity;
public:

	Subscribers(int capacity = 10) {
		subscribers = new Phonebook[capacity];
		this->capacity = capacity;
		size = 0;
	}
	~Subscribers()
	{
		delete[] subscribers;
	}
	void addSubscriber(const Phonebook& subscriber) {
		if (size < capacity) {
			subscribers[size++] = subscriber;
		}
		else {
			int newCapacity = capacity * 2;
			Phonebook* newSubscriber = new Phonebook[newCapacity];
			for (int i = 0; i < size; i++)
			{
				newSubscriber[i] = subscribers[i];
			}
			delete[] subscribers;
			subscribers = newSubscriber;
			capacity = newCapacity;
			subscribers[size++] = subscriber;
		}
	}
	void deleteSubscriber(int index) {
		if (index >= 0 && index < size) {
			Phonebook* newSubscribers = new Phonebook[capacity - 1];
			for (int i = 0; i < index; i++) {
				newSubscribers[i] = subscribers[i];
			}
			for (int i = 1; i < size; i++) {
				newSubscribers[i - 1] = subscribers[i];
			}
			delete[] subscribers;
			subscribers = newSubscribers;
			size--;
			if (size < 0) {
				size = 0;
			}
		}
	}

	void searchSubscriber(char* fullName) {
		for (int i = 0; i < size; i++)
		{
			if (_strcmpi(subscribers[i].getFullName(), fullName) == 0) {
				subscribers[i].showSubs(i);
			}
		}
	}
	void showAllSubsribers() {
		for (int i = 0; i < size; i++)
		{
			subscribers[i].showSubs(i);
			cout << '\n';
		}
	}
};