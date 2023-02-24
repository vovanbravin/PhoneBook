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
			std::cout << "\t\t����:\n"
				<< "\t�������� ���� - 1\n"
				<< "\t�������� ������������ - 2\n"
				<< "\t������� ������������ - 3\n"
				<< "\t����� - 4\n";
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
		std::cout << "���� ������ ��������� - 0,���������� - 1\n";
		std::cin >> out;
	} while (out == 1);

	return 0;
}


void ShowAll(std::vector<User>& mas)
{
	std::cout << "��� ��� ��� ������� �����: \n";
	if (mas.size() == 0)
	{
		std::cout << "������!������������ �� ���������!\n";
		return;
	}
	for (auto x : mas)
	{
		std::cout << "���: " << x.GetName()<<"\n";
		std::cout << "�������� �������: " << x.GetHouseNum() << "\n";
		std::cout << "������� �������: " << x.GetWorkNum() << "\n";
		std::cout << "��������� �������: " << x.GetPhoneNum() << "\n";
		std::cout << "���.�����.: " << x.GetAddInfo() << "\n";
	}
}

void PlusUser(std::vector<User>& mas)
{
	User a;
	int out;
	do {
		a.InitUser();
		mas.push_back(a);
		std::cout << "���� ������ �������� ��� - 1,����� - 0\n";
		std::cin >> out;
	} while (out);
}

void DeletUser(std::vector<User>& mas) 
{
	ShowAll(mas);

	if (mas.size() == 0)return;
	int index;
	std::cout << "������ ������� ������������ ������ �������: ";
	std::cin >> index;
	mas.erase(mas.cbegin() + index-1);

}

void Search(std::vector<User>& mas)
{
	std::cin.get();
	std::string name;
	std::cout << "������� ���: ";
	getline(std::cin, name);
	std::vector<User>mas_1;

	for (auto x : mas) if (x.GetName() == name) mas_1.push_back(x);
	if (mas_1.size() == 0)
	{
		std::cout << "������������ �� ������!\n";
		mas_1.clear();
		return;
	}
	else
	{
		ShowAll(mas_1);
		mas_1.clear();
	}

}
