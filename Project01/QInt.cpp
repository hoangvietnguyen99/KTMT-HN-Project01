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

//Hàm xuất
void PrintQInt(QInt x)
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
	cout << "So vua nhap vao la: " << b << endl;
}

//Hàm chuyển đổi thập phân sang nhị phân
bool* DecToBin(QInt x)
{
	bool* Bit;
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

	Bit = new bool[(7 - i) * 32 + (32 - j)];
	int pos = 0;
	for (int k = i - 4; k < 4; k++)
	{
		for (int l = j; l < 32; l++)
		{
			temp = (x.data[k] >> 32 - 1 - l) & 1;
			Bit[pos] = temp;
			pos++;
		}
		j = 0;
	}
	return Bit;
}

//Hàm tính độ dài dãy bit
int BitLength(bool* bit)
{
	int length = 0, i = 0;
	while (bit[i] == 1 || bit[i] == 0)
	{
		length++;
		i++;
	}
	return length;
}

//Hàm chuyển nhị phân sang thập phân
QInt BinToDec(bool* bit)
{
	QInt x;
	for (size_t i = 0; i < 4; i++)
	{
		x.data[i] = 0;
	}
	int l = BitLength(bit);
	for (int i = 0; i < l; i++)
	{
		if (bit[i] == 1)
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
string QIntToHex(QInt x)
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
string BinToHex(bool* bit)
{
	return QIntToHex(BinToDec(bit));
}

//Các operator toán tử
//+
QInt operator+(QInt a, QInt b)
{
	return a;
}