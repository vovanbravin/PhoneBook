#include "user.h"

void ShowAll(std::vector<User>&mas);

void PlusUser(std::vector<User>& mas);

void DeletUser(std::vector<User>& mas);

void Search(std::vector<User>& mas);

int main()
{
	setlocale(LC_ALL, "RUS");

	std::vector<User>mas;
	int out;
	do {
		system("cls");
		int action;
		do {
			std::cout << "\t\tМеню:\n"
				<< "\tПоказать всех - 1\n"
				<< "\tДобавить пользователя - 2\n"
				<< "\tУдалить пользователя - 3\n"
				<< "\tПоиск - 4\n";
			std::cin >> action;
		} while (action < 1 || action>4);

		enum action { showAll = 1, plusUser,deletUser,search };

		switch (action)
		{
		case showAll:
			ShowAll(mas);
			break;
		case plusUser:
			PlusUser(mas);
			break;
		case deletUser:
			DeletUser(mas);
			break;
		case search:
			Search(mas);
			break;
		default:
			break;
		}
		std::cout << "Если хотите завершить - 0,продолжить - 1\n";
		std::cin >> out;
	} while (out == 1);

	return 0;
}


void ShowAll(std::vector<User>& mas)
{
	std::cout << "Вот что нам удалось найти: \n";
	if (mas.size() == 0)
	{
		std::cout << "Ошибка!Пользователи не добавлены!\n";
		return;
	}
	for (auto x : mas)
	{
		std::cout << "ФИО: " << x.GetName()<<"\n";
		std::cout << "Домашний телефон: " << x.GetHouseNum() << "\n";
		std::cout << "Рабочий телефон: " << x.GetWorkNum() << "\n";
		std::cout << "Мобильный телефон: " << x.GetPhoneNum() << "\n";
		std::cout << "Доп.инфор.: " << x.GetAddInfo() << "\n";
	}
}

void PlusUser(std::vector<User>& mas)
{
	User a;
	int out;
	do {
		a.InitUser();
		mas.push_back(a);
		std::cout << "Если хотите добавить еще - 1,выйти - 0\n";
		std::cin >> out;
	} while (out);
}

void DeletUser(std::vector<User>& mas) 
{
	ShowAll(mas);

	if (mas.size() == 0)return;
	int index;
	std::cout << "Какого посчету пользователя хотите удалить: ";
	std::cin >> index;
	mas.erase(mas.cbegin() + index-1);

}

void Search(std::vector<User>& mas)
{
	std::cin.get();
	std::string name;
	std::cout << "Введите ФИО: ";
	getline(std::cin, name);
	std::vector<User>mas_1;

	for (auto x : mas) if (x.GetName() == name) mas_1.push_back(x);
	if (mas_1.size() == 0)
	{
		std::cout << "Пользователь не найден!\n";
		mas_1.clear();
		return;
	}
	else
	{
		ShowAll(mas_1);
		mas_1.clear();
	}

}
