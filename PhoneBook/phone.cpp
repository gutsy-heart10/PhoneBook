#include<iostream>
#include"Phonebook.h"
using namespace std;


int main() {
	Subscribers subs(10);
	Phonebook someone{ "Empty","XXX-XXX","XXX-XX","XXX-XX","Something" };
	subs.addSubscriber(someone);
	Phonebook Murad;
	Murad.setFullName("Murad Nurmammadli");
	Murad.setHomeNumber("012-555-44-77");
	Murad.setWorkNumber("055-444-55-77");
	Murad.setMobileNumber("051-555-44-77");
	Murad.setAdditionalInfo("Student of Step IT");
	subs.addSubscriber(Murad);
	int choice{};
	while (true)
	{
		system("cls");
		cout << "<<Choose the option>>" << endl;
		cout << "1.Adding information." << endl;
		cout << "2.Deleting information." << endl;
		cout << "3.Search subscribers." << endl;
		cout << "4.Show subscribers." << endl;
		cout << "5.Exit." << endl;
		cin >> choice;
		system("cls");
		if (choice == 1) {
			char fullName[30]{}, homeNumb[30]{}, workNumb[30]{}, mobileNumb[30], additionalInformation[30]{};
			cout << "Enter the full name of subscriber: ";
			cin >> fullName;
			cout << "Enter the home number of subscriber: ";
			cin>>homeNumb, 
			cout << "Enter the work number of subscriber: ";
			cin>>workNumb;
			cout << "Enter the mobile number of subscriber :";
			cin>>mobileNumb;
			cout << "Enter the additional information about subscriber :";
			cin>>additionalInformation;
			Phonebook addSubscribers{ fullName,homeNumb,workNumb,mobileNumb,additionalInformation };
			subs.addSubscriber(addSubscribers);
			cout << "Subscriber is added!" << endl;
			system("pause");
		}
		else if (choice == 2) {
			int index{};
			subs.showAllSubsribers();
			cout << "Choose the subscriber: ";
			cin >> index;
			subs.deleteSubscriber(index);
			cout << "Subscriber is deleted!" << endl;
			system("pause");
			
		}
		else if (choice == 3) {
			char name[30]{};
			cout << "Enter the name of subscriber: ";
			cin >> name;
			subs.searchSubscriber(name);
			system("pause");
			
		}
		else if (choice == 4) {
			subs.showAllSubsribers();
			system("pause");
			
		}
		else if (choice == 5) {
			cout << "GoodBye!" << endl;
			return 0;
		}
		else {
			cout << "Invalid option" << endl;
			break;
		}
	}
}