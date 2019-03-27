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

//Hàm chia chuỗi thập phân cho 2, trả về số dư, thay đổi chuỗi thành kết quả phép chia
string DivineTo2(string &number);

//Hàm chia chuỗi thập phân cho 16, trả về số dư, thay đổi chuỗi
string DivineTo16(string &number);

//Hàm chuyển chuỗi thập phân sang chuỗi nhị phân
string DecToBin(string a);

//Hàm xóa số 0 ở đầu chuỗi số nhị phân hoặc thập phân
void DeleteZero(string &a);

//Hàm lưu QInt từ chuỗi thập phân lớn
QInt DecToQInt(string a);

//Hàm tính 2 mũ n kiểu chuỗi, trả về chuỗi kết quả
string Exp2(int n);

//Hàm tính 16 mũ n kiểu chuỗi, trả về chuỗi kết quả
string Exp16(int n);

//Hàm chuyển chuỗi nhị phân sang chuỗi thập phân
string BinToDec(string a);

//Hàm chuyển chuỗi thập lục phân sang chuỗi thập phân
string HexToDec(string a);

//Hàm chuyển QInt sang chuỗi thập phân
string QIntToDec(QInt x);

//Hàm chuyển đổi QInt sang nhị phân
string QIntToBin(QInt x);

//Hàm chuyển nhị phân sang QInt
QInt BinToQInt(string bit);

//Hàm chuyển chuỗi thập phân sang chuỗi thập lục phân
string DecToHex(string a);

//Hàm chuyển QInt sang thập lục phân
string QIntToHex(QInt x);

//Hàm chuyển nhị phân sang thập lục phân
string BinToHex(string bit);

//Các operator toán tử cho QInt
//+
QInt operator+(QInt a, QInt b);
//-
QInt operator-(QInt a, QInt b);
//*
QInt operator*(QInt a, QInt b);

//Hàm cộng hai chuỗi số thập phân, trả về chuỗi thập phân tổng
string Plus(string a, string b);

//Hàm cộng 2 chuỗi nhị phân, trả về chuỗi nhị phân tổng
string BinPlus(string a, string b);

//Hàm chuyển nhị phân âm bù 2 về ban đầu
string ChuyenBu2(string a);

//Hàm trừ 2 chuỗi nhị phân, trả về chuỗi nhị phân thương
string BinSubtract(string a, string b);

//Hàm nhân chuỗi nhị phân với 1 bit, trả về chuỗi nhị phân kết quả
string MultiABit(string a, char bit);

//Hàm nhân 2 chuỗi thập phân trả về chuỗi thập phân tích
string Multi(string a, string b);

//Hàm nhân 2 chuỗi nhị phân trả về chuỗi nhị phân tích
string BinMulti(string a, string b);

//Hàm xử lý nhân hai dãy nhị phân, trả về chuỗi kết quả
string XuLyBinMulti(string a, string b);

//Hàm chia 2 chuỗi nhị phân trả về chuỗi nhị phân thương
string BinDivine(string a, string b);

//Các toán tử so sánh và gán
//<
bool operator<(QInt x, QInt y);

//>
bool operator>(QInt x, QInt y);

//==
bool operator==(QInt x, QInt y);

//<=
bool operator<=(QInt x, QInt y);

//>=
bool operator>=(QInt x, QInt y);

//= //Không cài đặt được vì chỉ được khai báo hàm thành viên trong class
//QInt operator=(QInt x, QInt y);

//Toán tử AND
QInt operator& (QInt a, QInt b);

//Toán tử OR
QInt operator|(QInt a, QInt b);

//Toán tử XOR
QInt operator^(QInt a, QInt b);

//Toán tử NOT
QInt operator~(QInt a);

//Hàm chuyển chuỗi số sang số
int StrToInt(string a);

//Phép dịch trái số học
QInt operator<<(QInt a, int pos);

//Phép dịch phải số học
QInt operator>>(QInt a, int pos);

//Hàm xoay trái
QInt RoL(QInt a);

//Hàm xoay phải
QInt RoR(QInt a);

#endif