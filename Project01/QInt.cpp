#include "QInt.h"

//Hàm chia chuỗi thập phân cho 2, trả về số dư, thay đổi chuỗi thành kết quả phép chia
string DivineTo2(string &number)
{
	char sign = number[0];
	if (sign == '-')
	{
		number.erase(0, 1);
	}
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
	if (number != "0" && number != "" && sign == '-')
	{
		number = '-' + number;
	}
	return SoDu;
}

//Hàm chia chuỗi thập phân cho 16, trả về số dư, thay đổi chuỗi thành chuỗi kết quả
string DivineTo16(string &number)
{
	char sign = number[0];
	if (sign == '-')
	{
		number.erase(0, 1);
	}
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
	if (number != "0" && number != "" && sign == '-')
	{
		number = '-' + number;
	}
	return SoDu;
}

//Hàm chuyển chuỗi thập phân sang chuỗi nhị phân
string DecToBin(string a)
{
	string b;
	while (a != "")
	{
		b = DivineTo2(a) + b;
	}
	return b;
}

//Hàm xóa số 0 ở đầu chuỗi số nhị phân hoặc thập phân
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
QInt DecToQInt(string a)
{
	QInt x;
	for (size_t i = 0; i < 4; i++)
	{
		x.data[i] = 0;
	}
	bool sign = (a[0] == '-');
	if (sign)
	{
		a.erase(0, 1);
	}
	a = DecToBin(a);
	if (sign) //Xử lý số âm
	{
		for (size_t i = a.size(); i < 128; i++) //Thêm số 0 để a đủ 128 bits
		{
			a = '0' + a;
		}
		a = ChuyenBu2(a); //Chuyển sang dạng bù 2
	}
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

//Hàm tính 16 mũ n kiểu chuỗi, trả về chuỗi kết quả
string Exp16(int n)
{
	string ans = "1";
	for (int i = 0; i < n; i++)
	{
		ans = Multi(ans, "16");
	}
	return ans;
}

//Hàm chuyển chuỗi nhị phân sang chuỗi thập phân
string BinToDec(string a)
{
	string b;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != '0')
		{
			b = Plus(b, Exp2(a.size() - i - 1));
		}
	}
	return b;
}

//Hàm chuyển chuỗi thập lục phân sang chuỗi thập phân
string HexToDec(string a)
{
	string b;
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] == 'A')
		{
			string x = "10";
			b = Plus(b, Multi(x, Exp16(a.size() - i - 1)));
		}
		else if (a[i] == 'B')
		{
			string x = "11";
			b = Plus(b, Multi(x, Exp16(a.size() - i - 1)));
		}
		else if (a[i] == 'C')
		{
			string x = "12";
			b = Plus(b, Multi(x, Exp16(a.size() - i - 1)));
		}
		else if (a[i] == 'D')
		{
			string x = "13";
			b = Plus(b, Multi(x, Exp16(a.size() - i - 1)));
		}
		else if (a[i] == 'E')
		{
			string x = "14";
			b = Plus(b, Multi(x, Exp16(a.size() - i - 1)));
		}
		else if (a[i] == 'F')
		{
			string x = "15";
			b = Plus(b, Multi(x, Exp16(a.size() - i - 1)));
		}
		else if (a[i] != '0')
		{
			string temp = MultiABit(Exp16(a.size() - i - 1), a[i]);
			b = Plus(b, temp);
		}
	}
	return b;
}

//Hàm chuyển QInt lại chuỗi thập phân
string QIntToDec(QInt x)
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
	bool sign = (a.size() == 128 && a[0] == '1');
	if (sign) //Chuyển bù 2
	{
		a = ChuyenBu2(a);
	}
	a = BinToDec(a);
	if (sign) //Thêm dấu trừ
	{
		a = '-' + a;
	}
	return a;
}

//Hàm chuyển đổi QInt sang nhị phân
string QIntToBin(QInt x)
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

//Hàm chuyển nhị phân sang QInt
QInt BinToQInt(string bit)
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

//Hàm chuyển chuỗi thập phân sang chuỗi thập lục phân
string DecToHex(string a)
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

//Hàm chuyển QInt sang thập lục phân
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
	string b = BinToDec(a);
	a = DecToHex(b);
	return a;
}

//Hàm chuyển nhị phân sang thập lục phân
string BinToHex(string bit)
{
	return QIntToHex(BinToQInt(bit));
}

//Các operator toán tử
//+
QInt operator+(QInt a, QInt b)
{
	return BinToQInt(BinPlus(QIntToBin(a), QIntToBin(b)));
}

//-
QInt operator-(QInt a, QInt b)
{
	return DecToQInt(BinSubtract(QIntToDec(a), QIntToDec(b)));
}

//*
QInt operator*(QInt a, QInt b)
{
	return BinToQInt(XuLyBinMulti(QIntToBin(a), QIntToBin(b)));
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
	if (a.size() < 128) //Chuyển số dương sang số âm bù 2
	{
		for (size_t i = a.size(); i < 128; i++) //Thêm đủ 128bit
		{
			a = '0' + a;
		}
		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = (a[i] == '1') ? '0' : '1';
		}
		a = BinPlus(a, "1");
	}
	else //Chuyển số âm bù 2 thành số dương
	{
		for (size_t i = 0; i < a.size(); i++)
		{
			a[i] = (a[i] == '1') ? '0' : '1';
		}
		a = BinPlus(a, "1");
		DeleteZero(a);
	}
	return a;
}

//Hàm trừ 2 chuỗi nhị phân, trả về chuỗi nhị phân thương
string BinSubtract(string a, string b)
{
	if (a.size() < 128 || (a.size() == 128 && a[0] == '0'))
	{
		return BinPlus(a, ChuyenBu2(b));
	}
	else
	{
		return BinPlus(ChuyenBu2(a), ChuyenBu2(b));
	}
}

//Hàm nhân chuỗi nhị phân với 1 bit, trả về chuỗi nhị phân kết quả
string MultiABit(string a, char bit)
{
	string ans;
	int temp = bit - '0';
	for (size_t i = 0; i < a.size(); i++)
	{
		ans += ((a[i] - '0')*temp) + '0';
	}
	return ans;
}

//Hàm nhân 2 chuỗi thập phân trả về chuỗi thập phân tích
string Multi(string a, string b)
{
	string ans;
	int temp = 0;
	string c;
	for (size_t i = 0; i < b.size(); i++)
	{
		c = MultiABit(a, b[b.size() - 1 - i]);
		for (size_t j = 0; j < temp; j++)
		{
			c += '0';
		}
		ans = Plus(ans, c);
		temp++;
	}
	DeleteZero(ans);
	return ans;
}

//Hàm nhân 2 chuỗi nhị phân trả về chuỗi nhị phân tích
string BinMulti(string a, string b)
{
	string ans;
	int temp = 0;
	string c;
	for (size_t i = 0; i < b.size(); i++)
	{
		c = MultiABit(a, b[b.size() - 1 - i]);
		for (size_t j = 0; j < temp; j++)
		{
			c += '0';
		}
		ans = BinPlus(ans, c);
		temp++;
	}
	DeleteZero(ans);
	return ans;
}

//Hàm xử lý nhân hai dãy nhị phân, trả về chuỗi kết quả
string XuLyBinMulti(string a, string b)
{
	if (a.size() == 128 && a[0] == '1')
	{
		if (b.size() == 128 && b[0] == '1')
		{
			return BinMulti(ChuyenBu2(a), ChuyenBu2(b));
		}
		else
		{
			return ChuyenBu2(BinMulti(ChuyenBu2(a), b));
		}
	}
	else
	{
		if (b.size() == 128 && b[0] == '1')
		{
			return ChuyenBu2(BinMulti(a, ChuyenBu2(b)));
		}
		else
		{
			return BinMulti(a, b);
		}
	}
}

//Hàm chia 2 chuỗi nhị phân trả về chuỗi nhị phân thương
string BinDivine(string a, string b)
{
	return a;
}

//Các toán tử so sánh và gán
//<
bool operator<(QInt x, QInt y)
{
	string a = QIntToBin(x);
	string b = QIntToBin(y);
	string c = BinSubtract(a, b);
	if (c.size() == 128 && c[0] == '1')
	{
		for (size_t i = 1; i < c.size(); i++)
		{
			if (c[i] == '1')
			{
				return true;
			}
		}
		return false;
	}
	else
	{
		return false;
	}
}

//>
bool operator>(QInt x, QInt y)
{
	return !(x < y);
}

//==
bool operator==(QInt x, QInt y)
{
	string a = QIntToBin(x);
	string b = QIntToBin(y);
	return (a == b);
}

//<=
bool operator<=(QInt x, QInt y)
{
	string a = QIntToBin(x);
	string b = QIntToBin(y);
	string c = BinSubtract(a, b);
	if (c.size() == 128 && c[0] == '1')
	{
		for (size_t i = 1; i < c.size(); i++)
		{
			if (c[i] == '1')
			{
				return true;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

//>=
bool operator>=(QInt x, QInt y)
{
	return !(x <= y);
}

//Toán tử AND
QInt operator& (QInt a, QInt b)
{
	QInt x;
	for (size_t i = 0; i < 4; i++)
	{
		x.data[i] = 0;
	}
	int temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			temp = ((a.data[i] >> 32 - 1 - j) & 1) & ((b.data[i] >> 32 - 1 - j) & 1);
			if (temp)
			{
				x.data[i] = x.data[i] | (1 << (32 - 1 - j));
			}
		}
	}
	return x;
}

//Toán tử OR
QInt operator|(QInt a, QInt b)
{
	QInt x;
	for (size_t i = 0; i < 4; i++)
	{
		x.data[i] = 0;
	}
	int temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			temp = ((a.data[i] >> 32 - 1 - j) & 1) | ((b.data[i] >> 32 - 1 - j) & 1);
			if (temp)
			{
				x.data[i] = x.data[i] | (1 << (32 - 1 - j));
			}
		}
	}
	return x;
}

//Toán tử XOR
QInt operator^(QInt a, QInt b)
{
	QInt x;
	for (size_t i = 0; i < 4; i++)
	{
		x.data[i] = 0;
	}
	int temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			temp = ((a.data[i] >> 32 - 1 - j) & 1) ^ ((b.data[i] >> 32 - 1 - j) & 1);
			if (temp)
			{
				x.data[i] = x.data[i] | (1 << (32 - 1 - j));
			}
		}
	}
	return x;
}

//Toán tử NOT
QInt operator~(QInt a)
{
	QInt x;
	for (size_t i = 0; i < 4; i++)
	{
		x.data[i] = 0;
	}
	int temp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			temp = (a.data[i] >> 32 - 1 - j) & 1;
			if (!temp)
			{
				x.data[i] = (x.data[i] | (1 << (32 - 1 - j)));
			}
		}
	}
	return x;
}

//Hàm chuyển chuỗi số sang số
int StrToInt(string a)
{
	int x = 0, k = 1;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		x += (a[i] - '0') * k;
		k *= 10;
	}
	return x;
}

//Phép dịch trái số học
QInt operator<<(QInt a, int pos)
{
	QInt x;
	for (size_t i = 0; i < 4; i++)
	{
		x.data[i] = 0;
	}
	string b;
	int repeat = 0;
	for (int i = pos / 32; i < 4; i++)
	{
		for (int j = pos % 32 - repeat; j < 32; j++)
		{
			int temp = (a.data[i] >> 32 - 1 - j) & 1;
			b += temp + '0';
		}
		repeat = pos % 32;
	}
	for (size_t i = b.size(); i < 128; i++)
	{
		b += '0';
	}
	DeleteZero(b);
	return BinToQInt(b);
}

//Phép dịch phải số học
QInt operator>>(QInt a, int pos)
{
	QInt x;
	for (size_t i = 0; i < 4; i++)
	{
		x.data[i] = 0;
	}
	string b;
	int repeat = 0;
	for (int i = 0; i < 4 - pos / 32; i++)
	{
		if ((i + 1) == 4 - pos / 32) repeat = pos % 32;
		for (int j = 0; j < 32 - repeat; j++)
		{
			int temp = (a.data[i] >> 32 - 1 - j) & 1;
			b += temp + '0';
		}
	}
	for (size_t i = b.size(); i < 128; i++)
	{
		if ((a.data[0] >> 31) & 1)
			b = '1' + b;
		else
			b = '0' + b;
	}
	return BinToQInt(b);
}

//Hàm xoay trái
QInt RoL(QInt a)
{
	QInt x = a << 1;
	int temp = (a.data[0] >> 31) & 1;
	if (temp)
		x.data[3] = (x.data[3] | (1 << 0));
	return x;
}

//Hàm xoay phải
QInt RoR(QInt a)
{
	QInt x = a >> 1;
	int temp = (a.data[3] >> 0) & 1;
	if (temp)
		x.data[0] = (x.data[0] | (1 << 31));
	return x;
}