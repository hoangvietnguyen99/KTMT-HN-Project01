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
			Output << TinhToan1(ts1,ts2,ts3,ts4) << '\n';
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
			{
				return QIntToDec(BinToQInt(c));
			}
			else return QIntToDec(BinToQInt(c));
		}
		if (b == "16")
		{
			return BinToHex(c);
		}
		if (b == "~")
		{
			return QIntToBin(~BinToQInt(c));
		}
		if (b == "RoL")
		{
			return QIntToBin(RoL(BinToQInt(c)));
		}
		if (b == "RoR")
		{
			return QIntToBin(RoR(BinToQInt(c)));
		}
	}
	else if (a == "10")
	{
		if (b == "2")
		{
			if (c[0] == '-')
			{
				return QIntToBin(DecToQInt(c));
			}
			else return QIntToBin(DecToQInt(c));
		}
		if (b == "16")
		{
			if (c[0] == '-')
			{
				return QIntToHex(DecToQInt(c));
			}
			return QIntToHex(DecToQInt(c));
		}
		if (b == "~")
		{
			return QIntToDec(~DecToQInt(c));
		}
		if (b == "RoL")
		{
			return QIntToDec(RoL(DecToQInt(c)));
		}
		if (b == "RoR")
		{
			return QIntToDec(RoR(DecToQInt(c)));
		}
	}
	else
	{
		if (b == "2")
		{
			return DecToBin(HexToDec(c));
		}
		if (b == "10")
		{
			return HexToDec(c);
		}
		if (b == "~")
		{
			return QIntToHex(~DecToQInt(HexToDec(c)));
		}
		if (b == "RoL")
		{
			return QIntToHex(RoL(DecToQInt(HexToDec(c))));
		}
		if (b == "RoR")
		{
			return QIntToHex(RoR(DecToQInt(HexToDec(c))));
		}
	}
}

//Hàm tính toán bài 1
string TinhToan1(string a, string b, string c, string d)
{
	if (a == "2")
	{
		if (c == "+")
		{
			return BinPlus(b, d);
		}
		if (c == "-")
		{
			return BinSubtract(b, d);
		}
		if (c == "*")
		{
			return XuLyBinMulti(b, d);
		}
		if (c == "&")
		{
			return QIntToBin((BinToQInt(b) & BinToQInt(d)));
		}
		if (c == "|")
		{
			return QIntToBin((BinToQInt(b) | BinToQInt(d)));
		}
		if (c == "^")
		{
			return QIntToBin((BinToQInt(b) ^ BinToQInt(d)));
		}
		if (c == "<<")
		{
			return QIntToBin(BinToQInt(b) << StrToInt(d));
		}
		if (c == ">>")
		{
			return QIntToBin(BinToQInt(b) >> StrToInt(d));
		}
		if (c == "<")
		{
			QInt x = BinToQInt(b);
			QInt y = BinToQInt(d);
			return (x < y) ? "True" : "False";
		}
		if (c == ">")
		{
			QInt x = BinToQInt(b);
			QInt y = BinToQInt(d);
			return (x > y) ? "True" : "False";
		}
		if (c == "==")
		{
			QInt x = BinToQInt(b);
			QInt y = BinToQInt(d);
			return (x == y) ? "True" : "False";
		}
		if (c == "<=")
		{
			QInt x = BinToQInt(b);
			QInt y = BinToQInt(d);
			return (x <= y) ? "True" : "False";
		}
		if (c == ">=")
		{
			QInt x = BinToQInt(b);
			QInt y = BinToQInt(d);
			return (x >= y) ? "True" : "False";
		}
	}
	else if (a == "10")
	{
		QInt x, y;
		x = DecToQInt(b);
		y = DecToQInt(d);
		if (c == "+")
		{
			return QIntToDec(x + y);
		}
		if (c == "-")
		{
			return QIntToDec(x - y);
		}
		if (c == "*")
		{
			return QIntToDec(x*y);
		}
		if (c == "&")
		{
			return QIntToDec((DecToQInt(b) & DecToQInt(d)));
		}
		if (c == "|")
		{
			return QIntToDec((DecToQInt(b) | DecToQInt(d)));
		}
		if (c == "^")
		{
			return QIntToDec((DecToQInt(b) ^ DecToQInt(d)));
		}
		if (c == "<<")
		{
			return QIntToDec(DecToQInt(b) << StrToInt(d));
		}
		if (c == ">>")
		{
			return QIntToDec(DecToQInt(b) >> StrToInt(d));
		}
		if (c == "<")
		{
			QInt x = DecToQInt(b);
			QInt y = DecToQInt(d);
			return (x < y) ? "True" : "False";
		}
		if (c == ">")
		{
			QInt x = DecToQInt(b);
			QInt y = DecToQInt(d);
			return (x > y) ? "True" : "False";
		}
		if (c == "==")
		{
			QInt x = DecToQInt(b);
			QInt y = DecToQInt(d);
			return (x == y) ? "True" : "False";
		}
		if (c == "<=")
		{
			QInt x = DecToQInt(b);
			QInt y = DecToQInt(d);
			return (x <= y) ? "True" : "False";
		}
		if (c == ">=")
		{
			QInt x = DecToQInt(b);
			QInt y = DecToQInt(d);
			return (x >= y) ? "True" : "False";
		}
	}
	else if (a == "16")
	{
		string x, y;
		x = HexToDec(b);
		y = HexToDec(d);
		x = DecToBin(x);
		y = DecToBin(y);
		if (c == "+")
		{
			return BinToHex(BinPlus(x, y));
		}
		if (c == "-")
		{
			return BinToHex(BinSubtract(x, y));
		}
		if (c == "*")
		{
			return BinToHex(BinMulti(x, y));
		}
		if (c == "&")
		{
			return QIntToHex(DecToQInt(HexToDec(b)) & DecToQInt(HexToDec(d)));
		}
		if (c == "|")
		{
			return QIntToHex(DecToQInt(HexToDec(b)) | DecToQInt(HexToDec(d)));
		}
		if (c == "^")
		{
			return QIntToHex(DecToQInt(HexToDec(b)) ^ DecToQInt(HexToDec(d)));
		}
		if (c == "<<")
		{
			return QIntToHex(DecToQInt(HexToDec(b)) << StrToInt(d));
		}
		if (c == ">>")
		{
			return QIntToHex(DecToQInt(HexToDec(b)) >> StrToInt(d));
		}
		if (c == "<")
		{
			QInt x = DecToQInt(HexToDec(b));
			QInt y = DecToQInt(HexToDec(d));
			return (x < y) ? "True" : "False";
		}
		if (c == ">")
		{
			QInt x = DecToQInt(HexToDec(b));
			QInt y = DecToQInt(HexToDec(d));
			return (x > y) ? "True" : "False";
		}
		if (c == "==")
		{
			QInt x = DecToQInt(HexToDec(b));
			QInt y = DecToQInt(HexToDec(d));
			return (x == y) ? "True" : "False";
		}
		if (c == "<=")
		{
			QInt x = DecToQInt(HexToDec(b));
			QInt y = DecToQInt(HexToDec(d));
			return (x <= y) ? "True" : "False";
		}
		if (c == ">=")
		{
			QInt x = DecToQInt(HexToDec(b));
			QInt y = DecToQInt(HexToDec(d));
			return (x >= y) ? "True" : "False";
		}
	}
}