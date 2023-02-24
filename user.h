#pragma once
#include <iostream>
#include <string>
#include <vector>
class User
{
	std::string Name;
	std::string HouseNum;
	std::string WorkNum;
	std::string PhoneNum;
	std::string AddInfo;

public:
	User()
	{
		Name = "NoName";
		HouseNum = "-";
		WorkNum = "-";
		PhoneNum = "-";
		AddInfo = "-";
	}
	~User()
	{
		HouseNum.clear();
		WorkNum.clear();
		PhoneNum.clear();
		AddInfo.clear();
	}
	inline std::string GetName() { return Name; };
	inline std::string GetHouseNum() { return HouseNum; };
	inline std::string GetWorkNum() { return WorkNum; };
	inline std::string GetPhoneNum() { return PhoneNum; };
	inline std::string GetAddInfo() { return AddInfo; };

	inline void SetName(std::string Name) { this->Name = Name; };
	inline void SetHouse(std::string HouseNum) { this->HouseNum = HouseNum; };
	inline void SetWork(std::string WorkNum) { this->WorkNum = WorkNum; };
	inline void SetPhone(std::string PhoneNum) { this->PhoneNum = PhoneNum; };
	inline void SetAddInfo(std::string AddInfo) { this->AddInfo = AddInfo; };

	void InitUser();
};

