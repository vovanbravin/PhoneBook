#include "user.h"

bool ProverkaHouseNum(std::string str)
{
	if (str.length() != 8) return true;
	else if(str[2] != '-' || str[5] != '-') return true;
	for (int i = 0; i < str.length(); i++)
		if ((str[i] < 48 || str[i]>57) && i != 2 && i != 5) return true;
	return false;
}

bool ProverkaWorkNum(std::string str)
{
	if (str.length() != 15)return true;
	else if (str[1] != '(' || str[5] != ')' || str[9] != '-' || str[12] != '-') return true;
	for (int i = 0; i < str.length(); i++)
		if ((str[i] < 48 || str[i]>57) && i != 1 && i != 5 && i != 9 && i != 12) return true;
	return false;
}

void User::InitUser()
{
	std::cin.get();
	std::string name, housenum, worknum, phonenum, addinfo;

	std::cout << "Введите ФИО: ";
	getline(std::cin, name);
	SetName(name);
	do {
		std::cout << "Введите домашний телефон(Образец: 62-34-32): ";
		getline(std::cin, housenum);
	} while (ProverkaHouseNum(housenum));
	SetHouse(housenum);

	do {
		std::cout << "Введите рабочий телефон(Образец: 8(911)640-13-25 ): ";
		getline(std::cin, worknum);
	} while (ProverkaWorkNum(worknum));
	SetWork(worknum);

	do {
		std::cout << "Введите мобильный телефон(Образец: 8(911)640-13-25): ";
		getline(std::cin, phonenum);
	} while (ProverkaWorkNum(phonenum));
	SetPhone(phonenum);

	std::cout << "Введите доп.инфор.: ";
	getline(std::cin, addinfo);
	SetAddInfo(addinfo);
}
