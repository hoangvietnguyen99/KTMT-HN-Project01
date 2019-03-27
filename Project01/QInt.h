#ifndef __QINT_H__
#define __QINT_H__

#include <iostream>
#include <string>
using namespace std;

//Khai báo cấu trúc QInt
struct QInt
{
	unsigned int data[4];
};

//Hàm chia chuỗi số cho 2, trả về số dư, thay đổi chuỗi
string DivineTo2(string &number);

//Hàm chuyển chuỗi thập phân sang chuỗi nhị phân
string IntToBin(string a);

//Hàm xóa số 0 ở đầu chuỗi số
void DeleteZero(string &a);

//Hàm lưu QInt từ chuỗi thập phân lớn, mặc định là số dương
QInt ScanQInt(string a, bool sign = 0);

//Hàm tính 2 mũ n kiểu chuỗi, trả về chuỗi kết quả
string Exp2(int n);

//Hàm chuyển chuỗi nhị phân sang chuỗi thập phân
string BinToInt(string a);

//Hàm chuyển QInt lại chuỗi thập phân, mặc định là số dương
string PrintQInt(QInt x, bool sign = 0);

//Hàm chuyển đổi thập phân sang nhị phân
string DecToBin(QInt x);

//Hàm chuyển nhị phân sang thập phân
QInt BinToDec(string bit);

//Hàm chia chuỗi cho 16, trả về số dư, thay đổi chuỗi
string DivineTo16(string &number);

//Hàm chuyển chuỗi thập phân sang chuỗi thập lục phân
string IntToHex(string& a);

//Hàm chuyển thập phân sang thập lục phân
string DecToHex(QInt x);

//Hàm chuyển nhị phân sang thập lục phân
string BinToHex(string bit);

//Các operator toán tử
//+
QInt operator+(QInt a, QInt b);

//Hàm cộng hai chuỗi số thập phân, trả về chuỗi thập phân tổng
string Plus(string a, string b);

//Hàm cộng 2 chuỗi nhị phân, trả về chuỗi nhị phân tổng
string BinPlus(string a, string b);

//Hàm chuyển nhị phân âm bù 2 về ban đầu
string ChuyenBu2(string a);

//Hàm trừ 2 chuỗi nhị phân, trả về chuỗi nhị phân thương
string BinaryStringSubtract(string a, string b);

#endif