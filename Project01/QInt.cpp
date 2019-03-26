#include "QInt.h"

//Hàm chia chuỗi số cho 2, trả về số dư, thay đổi chuỗi thành kết quả phép chia
string DivineTo2(string &number)
{
	string ans = ""; //chuỗi sau khi chia 2
	int pos = 0; //vị trí xét
	string SoDu; //số dư sau khi chia 2
	int temp = number[pos] - '0';
	if ((temp == 1 || temp == 0) && number.size() == 1)
	{
		number = ans;
		SoDu = temp + '0';
		return SoDu;
	}
	while (temp < 2)
	{
		temp = temp * 10 + (number[++pos] - '0');
	}
	while (number.size() > pos)
	{
		ans += (temp / 2) + '0';
		SoDu = (temp % 2) + '0';
		temp = (temp % 2) * 10 + (number[++pos] - '0');
	}
	number = ans;
	return SoDu;
}

//Hàm chuyển chuỗi nhị phân sang chuỗi thập phân
string BinToInt(string a)
{
	string b;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] == '1')
		{
			b = Plus(b, Exp2(a.size() - i - 1));
	
		}
	}
	return b;
}

//Hàm chuyển chuỗi thập phân sang chuỗi nhị phân
string IntToBin(string a)
{
	string b;
	while (a != "")
	{
		b = DivineTo2(a) + b;
	}
	return b;
}

//Hàm xóa số 0 ở đầu chuỗi số bất kì
void DeleteZero(string &a)
{
	int pos = 0;
	while (a[pos] == '0')
	{
		pos++;
	}
	string b;
	for (int i = pos; i < a.size(); i++)
	{
		b.push_back(a[i]);
	}
	a = b;
}

//Hàm lưu QInt từ chuỗi thập phân lớn
QInt ScanQIntFromInt(string a)
{
	QInt x;
	for (size_t i = 0; i < 4; i++)
	{
		x.data[i] = 0;
	}
	a = IntToBin(a);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] == '1')
		{
			int k = (128 - a.size() + i);
			x.data[k / 32] = x.data[k / 32] | (1 << (32 - 1 - (k % 32)));
		}
	}
	return x;
}

////Hàm nhập QInt từ bàn phím
//void ScanQInt(QInt &x)
//{
//	for (size_t i = 0; i < 4; i++)
//	{
//		x.data[i] = 0;
//	}
//	string a, c;
//	cout << "Nhap vao chuoi so: ";
//	cin >> a;
//	DeleteZero(a);
//	c = a;
//	string b = IntToBin(a);
//	for (size_t i = 0; i < b.size(); i++)
//	{
//		if (b[i] == '1')
//		{
//			int k = (128 - b.size() + i);
//			x.data[k / 32] = x.data[k / 32] | (1 << (32 - 1 - (k % 32)));
//		}
//	}
//	cout << "So ban dau: " << c << endl;
//	cout << "So nhi phan: " << b << endl;
//	cout << "So luu trong QInt: ";
//	for (size_t i = 0; i < 4; i++)
//	{
//		cout << x.data[i] << " ";
//	}
//	cout << endl;
//}

//Hàm tính 2 mũ n kiểu chuỗi, trả về chuỗi kết quả
string Exp2(int n)
{
	string ans = "1";
	for (int i = 0; i < n; i++)
	{
		ans = Plus(ans, ans);
	}
	return ans;
}

//Hàm chuyển QInt lại chuỗi thập phân
string PrintQInt(QInt x)
{
	string a;
	char temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			temp = ((x.data[i] >> 32 - 1 - j) & 1) + '0';
			a.push_back(temp);
		}
	}
	DeleteZero(a);
	string b = BinToInt(a);
	return b;
}

//Hàm chuyển đổi thập phân sang nhị phân
string DecToBin(QInt x)
{
	string Bit;
	int i, j, temp;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 32; j++)
		{
			if (((x.data[i] >> 32 - 1 - j) & 1) != 0)
			{
				i += 3;
				break;
			}
		}
	}
	for (int k = i - 4; k < 4; k++)
	{
		for (int l = j; l < 32; l++)
		{
			temp = (x.data[k] >> 32 - 1 - l) & 1;
			Bit += temp + '0';
		}
		j = 0;
	}
	return Bit;
}

//Hàm chuyển nhị phân sang thập phân
QInt BinToDec(string bit)
{
	QInt x;
	for (size_t i = 0; i < 4; i++)
	{
		x.data[i] = 0;
	}
	int l = bit.length();
	for (int i = 0; i < l; i++)
	{
		if (bit[i] == '1')
		{
			int k = (128 - l + i);
			x.data[k / 32] = x.data[k / 32] | (1 << (32 - 1 - (k % 32)));
		}
	}
	return x;
}

//Hàm chia chuỗi cho 16, trả về số dư, thay đổi chuỗi thành chuỗi kết quả
string DivineTo16(string &number)
{
	string ans = ""; //chuỗi sau khi chia 16
	int pos = 0; //vị trí xét
	string SoDu; //số dư sau khi chia 16
	int temp = number[pos] - '0';
	if (number.size() < 3)
	{

		if (number.size() == 1) //Xử lý TH chuỗi có 1 chữ số
		{
			number = ans;
			SoDu = (temp + '0');
			return SoDu;
		}
		else //Xử lý TH chuỗi có 2 chữ số
		{
			temp = temp * 10 + (number[++pos] - '0');
			if (temp < 16) //và bé hơn 16
			{
				number = ans;
				SoDu = (temp / 10 + '0');
				SoDu += (temp % 10 + '0');
				return SoDu;
			}
		}
	}
	while (temp < 16)
	{
		temp = temp * 10 + (number[++pos] - '0');
	}
	while (number.size() > pos)
	{
		ans += (temp / 16) + '0';
		if (temp % 16 < 10) //Xử lý TH Số Dư có 1 chữ số
		{
			SoDu = (temp % 16) + '0';
		}
		else //Xử lý TH Số Dư có 2 chữ số
		{
			SoDu = (temp % 16 / 10) + '0';
			SoDu += (temp % 16 % 10) + '0';
		}
		temp = (temp % 16) * 10 + (number[++pos] - '0');
	}
	number = ans;
	return SoDu;
}

//Hàm chuyển chuỗi thập phân sang chuỗi thập lục phân
string IntToHex(string& a)
{
	string b;
	while (a != "")
	{
		string temp = DivineTo16(a);
		if (temp.size() == 1)
		{
			b = temp[0] + b;
		}
		else
		{
			switch (temp[1])
			{
			case '0':
				b = 'A' + b;
				break;
			case '1':
				b = 'B' + b;
				break;
			case '2':
				b = 'C' + b;
				break;
			case '3':
				b = 'D' + b;
				break;
			case '4':
				b = 'E' + b;
				break;
			case '5':
				b = 'F' + b;
				break;
			}
		}
	}
	return b;
}

//Hàm chuyển thập phân sang thập lục phân
string DecToHex(QInt x)
{
	string a;
	char temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			temp = ((x.data[i] >> 32 - 1 - j) & 1) + '0';
			a.push_back(temp);
		}
	}
	DeleteZero(a);
	string b = BinToInt(a);
	a = IntToHex(b);
	return a;
}

//Hàm chuyển nhị phân sang thập lục phân
string BinToHex(string bit)
{
	return DecToHex(BinToDec(bit));
}

//Các operator toán tử
//+
QInt operator+(QInt a, QInt b)
{
	return ScanQIntFromInt(Plus(PrintQInt(a), PrintQInt(b)));
}

//Hàm cộng hai chuỗi số thập phân, trả về chuỗi thập phân tổng
string Plus(string a, string b)
{
	string ans;
	int gaps = a.size() - b.size();
	if (gaps < 0)
	{
		gaps = abs(gaps);
		a.insert(0, gaps, '0');
	}
	else if (gaps > 0)
	{
		b.insert(0, gaps, '0');
	}
	int A, B, Ans, temp = 0;
	char c;
	for (size_t i = a.size(); i > 0; i--)
	{
		A = a[i - 1] - '0';
		B = b[i - 1] - '0';
		Ans = A + B + temp;
		temp = Ans / 10;
		c = Ans % 10 + '0';
		ans = c + ans;
	}
	if (temp > 0)
	{
		c = temp + '0';
		ans = c + ans;
	}
	return ans;
}

//Hàm cộng 2 chuỗi nhị phân, trả về chuỗi nhị phân tổng
string BinPlus(string a, string b)
{
	string ans;
	int gaps = a.size() - b.size();
	if (gaps < 0)
	{
		gaps = abs(gaps);
		a.insert(0, gaps, '0');
	}
	else if (gaps > 0)
	{
		b.insert(0, gaps, '0');
	}
	int A, B, Ans, temp = 0;
	char c;
	for (size_t i = a.size(); i > 0; i--)
	{
		A = a[i - 1] - '0';
		B = b[i - 1] - '0';
		Ans = A + B + temp;
		temp = Ans / 2;
		c = Ans % 2 + '0';
		ans = c + ans;
	}
	if (temp > 0)
	{
		c = temp + '0';
		ans = c + ans;
	}
	return ans;
}

//Hàm chuyển nhị phân âm bù 2 về ban đầu
string ChuyenBu2(string a)
{
	for (size_t i = 0; i < a.size(); i++)
	{
		a[i] = (a[i] == '1') ? '0' : '1';
	}
	a = BinPlus(a, "1");
	return a;
}