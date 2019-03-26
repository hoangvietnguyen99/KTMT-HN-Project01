#include "Function.h"

//Xử lý bài 1
void Function1(string IPFile, string OPFile)
{
	ifstream Input(IPFile, ios::in);
	ofstream Output(OPFile, ios::out, ios::trunc);
	if (Input.fail() || Output.fail())
	{
		cout << "Open/Create files error!!";
		exit(0);
	}
	while (!Input.eof())
	{
		string a;
		getline(Input, a);
		//Đếm khoảng trắng
		string temp;
		int j = 0;
		for (size_t i = 0; i < a.size(); i++)
		{
			if (a[i] == ' ')
			{
				temp += (i + '0');
			}
		}
		if (temp.size() == 2)
		{
			string ts1, ts2, ts3;
			ts1 = a.substr(0, temp[0] - '0');
			ts2 = a.substr(temp[0] - '0' + 1, temp[1] - temp[0] - 1);
			ts3 = a.substr(temp[1] - '0' + 1, temp[2] - temp[1] - 1);
			Output << ChuyenDoi1(ts1, ts2, ts3) << '\n';
		}
		else if (temp.size() == 3)
		{
			string ts1, ts2, ts3, ts4;
			ts1 = a.substr(0, temp[0] - '0');
			ts2 = a.substr(temp[0] - '0' + 1, temp[1] - temp[0] - 1);
			ts3 = a.substr(temp[1] - '0' + 1, temp[2] - temp[1] - 1);
			ts4 = a.substr(temp[2] - '0' + 1, temp[3] - temp[2] - 1);
			Output << ts1 << " " << ts2 << " " << ts3 << " " << ts4 << '\n';
		}
	}
}

//Hàm xử lý chuyển đổi
string ChuyenDoi1(string a, string b, string c)
{
	if (a == "2") //TH input nhị phân
	{
		if (b == "10")
		{
			if (c.size() == 128 && c[0] == '1') //TH số âm
			return PrintQInt(BinToDec(c),1);
			else return PrintQInt(BinToDec(c));
		}
		else
		{
			return BinToHex(c);
		}
	}
	else if (a == "10")
	{
		if (b == "2")
		{
			return DecToBin(ScanQInt(c));
		}
		else
		{
			return DecToHex(ScanQInt(c));
		}
	}
}