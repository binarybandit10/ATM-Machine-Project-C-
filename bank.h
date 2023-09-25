#pragma once
#ifndef BANK_H
#define BANK_H

#include <chrono>
#include <thread>
#include<iostream>
#include<conio.h>
#include<fstream>
#include <windows.h>

using namespace std;

class Bank
{
private:
	string pin;
	float balance = 0.0;
	string id, name, fname, address, phone;
public:
	void menu();
	void bank_management();
	void atm_management();
	void new_user();
	void deposit();
	void withdraw();
	void transfer();
	void search();
	void edit();
	void dele();
	void show_record();
	void user_balance();
	void withdraw_atm();
	void account_details();



	char getch() {

		return '*';
	}

};
void showLoadingAnimation(int seconds) 
{
	system("cls");
	int numDots = 0;
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
	while (seconds > 0) {
		cout << "\t\t\t\t\t\t\t\033[1;33mLoading";
		for (int i = 0; i < numDots; ++i) {
			cout << ".";
		}
		cout << "\t\t\t\t\t\t\t\033[0m\r";
		cout.flush();

		this_thread::sleep_for(chrono::milliseconds(100));

		++numDots;
		if (numDots > 5) {
			numDots = 0;
			--seconds;
		}
	}
	cout << "\t\t\t\t\t\t\t\033[1;32mLoading complete!\033[0m" << endl;
	system("cls");

}

void Bank::menu()
{

	string pin, id;
	int choice;
	bool exitMenu = false;

	while (!exitMenu)
	{
		system("cls");

		cout << "\n\n\t\t\t\t\t*********Control Panel*********";
		cout << "\n\n\t\t\t\t\t 1. Bank Management";
		cout << "\n\t\t\t\t\t 2. ATM Management";
		cout << "\n\t\t\t\t\t 3. Exit";
		cout << "\n\n\t\t\t\t\t Enter Your Choice :";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			showLoadingAnimation(1);
			cout << "\n\n\t\t\t\t********Login Account********";
			cout << "\n\n\t\t\t\t\t User ID : ";
			cin >> id;
			cout << "\n\n\t\t\t\t\t Pin Code: ";
			cin >> pin;
			showLoadingAnimation(1);

			if (id == "usman" && pin == "233505")
			{
				bank_management();
			}
			else
			{
				cout << "\n\n\t\t\t\t\t You Entered Incorrect E-mail or Pin.......";
			}

			break;

		case 2:
			showLoadingAnimation(1);

			atm_management();
			break;

		case 3:
			showLoadingAnimation(1);

			exitMenu = true;
			break;

		default:
			cout << "\t\t\t\t\tInvalid value...... Please Enter Valid Value... ";
			break;
		}
	}
}

void Bank::bank_management()
{
	while (true) {
		system("cls");
		int choice;
		cout << "\n\n\t\t\t\t\tATM Management System";
		cout << "\n\n\t\t\t\t\t 1. New User";
		cout << "\n\t\t\t\t\t 2. Edit User Info";
		cout << "\n\t\t\t\t\t 3. Search User Info";
		cout << "\n\t\t\t\t\t 4. Delete User Account";
		cout << "\n\t\t\t\t\t 5. Show All Records";

		cout << "\n\t\t\t\t\t 6. Go Back";
		cout << "\n\n\t\t\t\t\t Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			showLoadingAnimation(1);

			new_user();
			break;
		case 2:
			showLoadingAnimation(1);

			edit();
			break;
		case 3:
			showLoadingAnimation(1);

			search();
			break;
		case 4:
			showLoadingAnimation(1);

			dele();
			break;
		case 5:
			showLoadingAnimation(1);

			show_record();
			break;

		case 6:
			showLoadingAnimation(1);

			menu();
			return;  // exit the function and go back to the previous menu
		default:
			cout << "\n\n\t\t\t\t\tInvalid Value...Please Enter Try Again";
		}
	}
}


void Bank::atm_management()
{
	while (true) {
		system("cls");
		int choice;
		cout << "\n\n\t\t\t\t\tATM Management System";
		cout << "\n\n\t\t\t\t\t 1. User Login & Check Balance";
		cout << "\n\t\t\t\t\t 2. Withdraw Amount";
		cout << "\n\t\t\t\t\t 3. Account Detailes";
		cout << "\n\t\t\t\t\t 4. Money transfer";
		cout << "\n\t\t\t\t\t 5. Go Back";
		cout << "\n\n\t\t\t\t\t Enter Your Choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			showLoadingAnimation(1);

			user_balance();
			break;
		case 2:
			showLoadingAnimation(1);

			withdraw_atm();
			break;
		case 3:
			showLoadingAnimation(1);

			account_details();
			break;
		case 4:
			showLoadingAnimation(1);

			transfer();
		case 5:
			showLoadingAnimation(1);

			return; // exit the function and return to the previous menu
		default:
			cout << "\n\n \t\t\t\t\tInvalid Value...Please Enter Try Again";
		}
		getch(); // wait for a key to be pressed before clearing the screen
	}
}

void Bank::new_user()
{
	system("cls");
	fstream file;
	string p;
	float b = 0.0;
	string n, f, a, ph, i;
	bool userExists = false;

	cout << "\n\n\t\t\t\t\tAdd New User";
	cout << "\n\n\t\t\t\t\t User ID: ";
	cin >> id;

	cout << "\n\n\t\t\t\t\tName : ";
	cin >> name;

	cout << "\n\n\t\t\t\t\t Father Name:";
	cin >> fname;

	cout << "\n\n\t\t\t\t\tAddress : ";
	cin >> address;

	cout << "\n\n\t\t\t\t\t Pin Code (5 digit): ";
	cin >> pin;

	cout << "\n\n\t\t\t\t\t Phone Number: ";
	cin >> phone;

	cout << "\n\n\t\t\t\t\tCurrent Balance: ";
	cin >> balance;

	file.open("bank.txt", ios::in);
	if (!file)
	{
		file.open("bank.txt", ios::app | ios::out);
		file << "  " << id << "  " << name << "  " << fname << "  " << address << "  " << pin << "  " << phone << "  " << balance << "\n";
		file.close();
	}
	else
	{
		file << i << n << f << a << p << ph << b;
		while (file >> i >> n >> f >> a >> p >> ph >> b)
		{
			if (i == id)
			{
				userExists = true;
				cout << "\n\n \t\t\t\t\tUser ID Already Exist...";
				break;
			}
		}
		file.close();

		if (!userExists)
		{
			file.open("bank.txt", ios::app | ios::out);
			file << "  " << id << "  " << name << "  " << fname << "  " << address << "  " << pin << "  " << phone << "  " << balance << "\n";
			file.close();
			showLoadingAnimation(1);

			cout << " \n\t\t\t\t\tNew User Created Successfully " << endl;
		}
	}

	cin.ignore();
	cin.get();
}

void Bank::deposit()
{
	fstream file, file1;
	string t_id;
	float dep;
	int found = 0;

	system("cls");
	cout << "\n\n\t\t\t\t\tDeposit Amount Option";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		cout << "\n\n\t\t\t\t\t File Opening Error...";
	}
	else
	{
		cout << "\n\n\t\t\t\t\t User 1 ";
		cin >> t_id;
		file.open("bank 1.txt", ios::app | ios::out);
		file >> id >> name >> fname >> address >> pin >> phone >> balance;
		while (file.eof())
		{

			if (t_id == id)
			{
				system("cls");
				cout << "\n\n \t\t\t\t\tAmount For Deposit: ";
				cin >> dep;
				balance += dep;
				file1 << " " << id << " " << name << "1 " << fname << "  " << address << "  " << pin << "  " << phone << "  " << balance << "\n";
				found++;

				cout << "\n\n\t\t\t\t\tYour Amount " << dep << " Sucessfully Deposit...";

			}
			else
			{
				file1 << " " << id << " " << name << " " << fname << "  " << address << "  " << pin << "  " << phone << "  " << balance << "\n";


			}
			file >> id >> name >> fname >> address >> pin >> phone >> balance;

		}

		file.close();
		file1.close();
		remove("bank.txt");
		rename("bank1.txt", "bank.txt");
		if (found == 0);
		cout << "\n\n \t\t\t\t\tUser ID Can't Found...";

	}

}
void Bank::withdraw()
{
	fstream file, file1;
	string t_id;
	float wdraw;
	int found = 0;

	system("cls");
	cout << "\n\n\t\t\t\t\tWithdraw Amount Option";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		cout << "\n\n\t\t\t\t\t File Opening Error...";
	}
	else
	{
		cout << "\n\n\t\t\t\t\t User 1 ";
		cin >> t_id;
		file.open("bank 1.txt", ios::app | ios::out);
		file >> id >> name >> fname >> address >> pin >> phone >> balance;
		while (file.eof())
		{

			if (t_id == id)
			{
				system("cls");
				cout << "\n\n \t\t\t\t\tAmount For Withdraw : ";
				cin >> wdraw;
				if (wdraw <= balance) {
					balance -= wdraw;
					file1 << " " << id << " " << name << " " << fname << "  " << address << "  " << pin << "  " << phone << "  " << balance << "\n";

					cout << "\n\n\t\t\t\t\tYour Amount " << wdraw << " Sucessfully Deposit...";
				}
				else
				{
					file1 << " " << id << " " << name << " " << fname << "  " << address << "  " << pin << "  " << phone << "  " << balance << "\n";
					cout << "\n\n\t\t\t\t\tYour Current Balance is Less...";


				}
				found++;

			}
			else
			{
				file1 << " " << id << " " << name << " " << fname << "  " << address << "  " << pin << "  " << phone << "  " << balance << "\n";


			}
			file >> id >> name >> fname >> address >> pin >> phone >> balance;

		}

		file.close();
		file1.close();
		remove("bank.txt");
		rename("bank1.txt", "bank.txt");
		if (found == 0);
		cout << "\n\n \t\t\t\t\tUser ID Can't Found...";

	}
	cin.ignore();
	cin.get();

}
void Bank::transfer()
{
	fstream file, file1;
	system("cls");
	string s_id, r_id;
	int found = 0;
	float amount;
	cout << "\n\n\t\t\t\t\tPayment Transfer Option";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		cout << "\n\n\t\t\t\t\t File Opening Error...";
	}
	else
	{
		cout << "\n\n\t\t\t\t\t Sender User ID For Transaction :";
		cin >> s_id;
		cout << "\n\n\t\t\t\t\t Receiver User ID For Transaction : ";
		cin >> r_id;
		cout << "\n\n\n \t\t\t\t\tEnter Amount to Transfer ";
		cin >> amount;

		file >> id >> name >> fname >> address >> pin >> phone >> balance;
		while (!file.eof())
		{
			if (s_id == id && amount <= balance)
				found++;
			else if (r_id == id)
				found++;
			file >> id >> name >> fname >> address >> pin >> phone >> balance;
		}
		file.close();

		if (found == 2)
		{
			file.open("bank.txt", ios::in);
			file1.open("bank1.txt", ios::app | ios::out);
			file >> id >> name >> fname >> address >> pin >> phone >> balance;
			while (!file.eof())
			{
				if (s_id == id)
				{
					balance -= amount;
					file1 << " " << id << " " << name << " " << fname << " " << address << "  " << pin << "  " << phone << "  " << balance << "\n";
				}
				else if (r_id == id)
				{

					balance += amount;
					file1 << " " << id << " " << name << " " << fname << " " << address << "  " << pin << "  " << phone << "  " << balance << "\n";
				}
				else
				{
					file1 << " " << id << " " << name << " " << fname << " " << address << "  " << pin << "  " << phone << "  " << balance << "\n";

				}
				file >> id >> name >> fname >> address >> pin >> phone >> balance;



			}
			file.close();
			file1.close();
			remove("bank.txt");
			rename("bank1.txt", "bank.txt");


		}
		else
		{
			cout << "\n\n\t\t\t\t\tBoth Transction User ID's & Balance Invalid.";
		}

	}

	cin.ignore();
	cin.get();


}

void Bank::search()
{
	system("cls");
	fstream file;
	string t_id;
	int found = 0;
	cout << "\n\n\t\t\t\t\tSearch User Record";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		cout << "\n\n \t\t\t\t\tFile Opening Error...";
	}
	else
	{
		cout << "\n\n\t\t\t\t\t User ID: ";
		cin >> t_id;
		file >> id >> name >> fname >> address >> pin >> phone >> balance;
		while (!file.eof())
		{
			if (t_id == id)
			{

				cout << "\n\n\t\t\t\t\tSearch User Record";
				cout << "\n\n\n\t\t\t\t\t User ID: " << id << " \n\n\n\t\t\t\t\tName: " << name << "\n\n\n\t\t\t\t\tFather's Name: " << fname;
				cout << "\n\n\n\t\t\t\t\t  Address: " << address << " \n\n\n\t\t\t\t\tPIN :" << pin << "\n\n\n\t\t\t\t\tBalance: " << balance << endl;
				found++;
			}
			file >> id >> name >> fname >> address >> pin >> phone >> balance;
		}
		file.close();
		if (found == 0)
			cout << "\n\n\t\t\t\t\t User ID Can't Found...";
	}
	cout << "\n\t\t\t\t\tPress any Key to Continue....";
	cin.ignore();
	cin.get();
}
void Bank::edit()
{
	system("cls");

	fstream file, file1;
	string t_id;
	int p;
	float b;
	string n, f, a, ph, i;
	int found = 0;
	cout << "\n\n\t\t\t\t\tEdit User Record";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		cout << "\n\n\t\t\t\t\t File Opening Error.";
	}
	else
	{
		cout << "\n\n\t\t\t\t\t User ID: ";
		cin >> t_id;
		cout << "\n\n\t\t\t\t\t please Confirm User ID: ";
		cin >> t_id;
		file1.open("bank1.txt", ios::app | ios::out);
		file >> id >> name >> fname >> address >> pin >> phone >> balance;
		while (!file.eof())
		{
			if (t_id == id)
			{
				cout << "\n\n\t\t\t\t\tAdd New User";

				cout << "\n\n\t\t\t\t\tName : ";
				cin >> n;
				cout << "\n\n \t\t\t\t\tFather Name:";
				cin >> f;
				cout << "\n\n\t\t\t\t\tAddress : ";
				cin >> a;
				cout << "\n\n\t\t\t\t\t Pin Code (5 digit): ";
				cin >> p;
				cout << "\n\n\t\t\t\t\t Phone Number: ";
				cin >> ph;
				file1 << " " << id << " " << n << " " << f << " " << a << "  " << p << "  " << p << "  " << balance << "\n";
				found++;
				cout << "\n\n\n\n\t\t\t\t\t Receord has been succcessfully update ";

			}
			else
			{
				file1 << " " << id << " " << name << " " << fname << " " << address << "  " << pin << "  " << phone << "  " << balance << "\n";
			}
			file >> id >> name >> fname >> address >> pin >> phone >> balance;
		}
		file.close();
		file1.close();
		remove("bank.txt");
		rename("bank1.txt", "bank.txt");

		if (found == 0)
			cout << "\n\n\t\t\t\t\t User ID Can't Found..." << endl;
	}
	cout << "\t\t\t\t\tPress any Key" << endl;
	cin.ignore();
	cin.get();


}
void Bank::dele()
{
	system("cls");

	fstream file, file1;
	string t_id;

	int found = 0;
	cout << "\n\n\t\t\t\t\tEdit User Record";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		cout << "\n\n \t\t\t\t\tFile Opening Error.";
	}
	else
	{
		cout << "\n\n\t\t\t\t\t User ID: ";
		cin >> t_id;
		cout << "\n\n\t\t\t\t\t User ID: ";
		cin >> t_id;
		file1.open("bank1.txt", ios::app | ios::out);
		file >> id >> name >> fname >> address >> pin >> phone >> balance;
		while (!file.eof())
		{
			if (t_id == id)
			{

				cout << "\n\n\n\n\t\t\t\t\t Receord has been deleted succcessfully update";
				found++;
			}
			else
			{
				file1 << " " << id << " " << name << " " << fname << " " << address << "  " << pin << "  " << phone << "  " << balance << "\n";
			}
			file >> id >> name >> fname >> address >> pin >> phone >> balance;
		}
		file.close();
		file1.close();
		remove("bank.txt");
		rename("bank1.txt", "bank.txt");

		if (found == 0)
			cout << "\n\n\t\t\t\t\t User ID Can't Found...";
	}
	cout << "\n\t\t\t\t\tPress any Key to Continue....";
	cin.ignore();
	cin.get();
}
void Bank::show_record()
{

	system("cls");
	fstream file;
	int found = 0;
	cout << "\n\n\t\t\t\t\tShow All User's Records";
	file.open("bank.txt", ios::in); if (!file)
	{
		cout << "\n\n\t\t\t\t\t File Opening Error...";
	}
	else
	{

		file >> id >> name >> fname >> address >> pin >> phone >> balance;
		while (!file.eof())
		{


			cout << "\n\n\n\t\t\t\t\t User ID: " << id;
			cout << "\n \t\t\t\t\tName : " << name;
			cout << "\n \t\t\t\t\tFather Name: " << fname;
			cout << "\n \t\t\t\t\tAddress: " << address;
			cout << "\n\t\t\t\t\t Pin: " << pin;

			cout << "\n \t\t\t\t\tPhone No. : " << phone;
			cout << "\n \t\t\t\t\tCurrent Balance: " << balance;
			cout << "\n\n\t\t\t\t\t======+++++++++++++++++++++++";

			file >> id >> name >> fname >> address >> pin >> phone >> balance;

			found++;
		}
		file.close();
		if (found == 0)
			cout << "\n\n \t\t\t\t\tData Base is Empty...";


	}

	cout << "\n\t\t\t\t\tPress any Key to Continue....";
	cin.ignore();
	cin.get();
}
void Bank::user_balance()
{
	system("cls");
	fstream file;
	string t_pin, t_id;
	char ch;
	int found = 0;

	cout << "\n\n\t\t\t\t\tUser Login & Check Balance";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		cout << "\n\n \t\t\t\t\tFile Opening Error...";
	}
	else
	{
		cout << "\n\n\t\t\t\t\t User ID: ";
		cin >> t_id;

		cout << "\n\n\t\t\t\tPin Code : ";
		ch = _getch(); // Use _getch() instead of getch()
		while (ch != 13) // 13 is the ASCII value of Enter key
		{
			t_pin.push_back(ch); // Append the character to t_pin
			cout << "*";
			ch = _getch(); // Read the next character
		}

		file >> id >> name >> fname >> address >> pin >> phone >> balance;
		while (!file.eof())
		{
			if (t_id == id && t_pin == pin)
			{
				cout << "\n\n\t\t\t\t\tYour Current Balance is: " << balance;
				found++;
			}
			file >> id >> name >> fname >> address >> pin >> phone >> balance;
		}

		if (found == 0)
		{
			cout << "\n\n\t\t\t\t\tUser ID, Pin & Password Invalid...";
		}

		file.close();
	}

	cin.ignore();
	cin.get();
}

void Bank::withdraw_atm()
{
	fstream file, file1;
	string t_pin, t_id;
	float wdraw;
	char ch;
	int found = 0;

	system("cls");
	cout << "\n\n\t\t\t\t\tWithdraw Amount Option";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		cout << "\n\n\t\t\t\t\t File Opening Error...";
	}
	else
	{
		cout << "\n\n \t\t\t\t\tUser  ";
		cin >> t_id;

		cout << "\n\n\t\t\t\t\tPin Code : ";
		ch = _getch();
		while (ch != 13)
		{
			t_pin.push_back(ch);
			cout << "*";
			ch = _getch();
		}

		file1.open("bank1.txt", ios::app | ios::out);
		file >> id >> name >> fname >> address >> pin >> phone >> balance;
		while (!file.eof())
		{
			if (t_id == id && t_pin == pin)
			{
				system("cls");
				cout << "\n\n \t\t\t\t\tAmount For Withdraw : ";
				cin >> wdraw;
				if (wdraw <= balance)
				{
					balance -= wdraw;
					file1 << " " << id << " " << name << " " << fname << "  " << address << "  " << pin << "  " << phone << "  " << balance << "\n";
					cout << "\n\n\t\t\t\t\tYour Amount " << wdraw << " Successfully Withdrawn...";
				}
				else
				{
					file1 << " " << id << " " << name << " " << fname << "  " << address << "  " << pin << "  " << phone << "  " << balance << "\n";
					cout << "\n\n\t\t\t\t\tYour Current Balance is Insufficient...";
				}
				found++;
			}
			else
			{
				file1 << " " << id << " " << name << " " << fname << "  " << address << "  " << pin << "  " << phone << "  " << balance << "\n";
			}
			file >> id >> name >> fname >> address >> pin >> phone >> balance;
		}

		file.close();
		file1.close();
		remove("bank.txt");
		rename("bank1.txt", "bank.txt");

		if (found == 0)
		{
			cout << "\n\n\t\t\t\t\t User ID Not Found...";
		}
	}

	cin.ignore();
	cin.get();
}

void Bank::account_details()
{


	fstream file;
	string t_id, t_pass, t_pin;
	char ch;
	int found = 0;
	system("cls");
	cout << "\n\n\t\t\t\t\tCheck Details Option";
	file.open("bank.txt", ios::in);
	if (!file)
	{
		cout << "\n\n\t\t\t\t\t File Opening Error...";

	}
	else
	{


		cout << "\n\n\t\t\t\t\t User  ";
		cin >> t_id;
		cout << "\n\n\t\t\t\t\tPin Code : ";
		cin >> t_pin;
		ch = _getch();
		while (ch != 13)
		{
			t_pin.push_back(ch);
			cout << "*";
			ch = _getch();
		}

		file >> id >> name >> fname >> address >> pin >> phone >> balance;
		while (!file.eof())
		{
			if (t_id == id && t_pin == pin)
			{

				cout << "\n\n\n\t\t\t\t\t User ID: " << id;
				cout << "\n \t\t\t\t\tName : " << name;
				cout << "\n \t\t\t\t\tFather Name: " << fname;
				cout << "\n \t\t\t\t\tAddress: " << address;
				cout << "\n\t\t\t\t\t Pin: " << pin;

				cout << "\n \t\t\t\t\tPhone No. : " << phone;
				cout << "\n \t\t\t\t\tCurrent Balance: " << balance;


				found++;

			}

			file >> id >> name >> fname >> address >> pin >> phone >> balance;
		}
		file.close();

		if (found == 0);
		cout << "\n\n \t\t\t\t\tUser ID Can't Found...";


	}
	cin.ignore();
	cin.get();
}
#endif // !bank
