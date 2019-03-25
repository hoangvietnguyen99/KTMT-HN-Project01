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
string ConvertIntToBin(string& a);

//Hàm xóa số 0 ở đầu chuỗi số
void DeleteZero(string &a);

//Hàm nhập QInt từ bàn phím
void ScanQInt(QInt &x);

//Hàm cộng hai chuỗi số, trả về chuỗi tổng
string Plus(string a, string b);

//Hàm tính 2 mũ n kiểu chuỗi, trả về chuỗi kết quả
string Exp2(int n);

//Hàm chuyển chuỗi nhị phân sang chuỗi thập phân
string ConvertBinToInt(const string& a);

//Hàm xuất
void PrintQInt(QInt x);

//Hàm chuyển đổi thập phân sang nhị phân
bool* DecToBin(QInt x);

//Hàm tính độ dài dãy bit
int BitLength(bool* bit);

//Hàm chuyển nhị phân sang thập phân
QInt BinToDec(bool* bit);

//Hàm chia chuỗi cho 16, trả về số dư, thay đổi chuỗi
string DivineTo16(string &number);

//Hàm chuyển chuỗi thập phân sang chuỗi thập lục phân
string ConvertIntToHex(string& a);

//Hàm chuyển thập phân sang thập lục phân
string DecToHex(QInt x);

//Hàm chuyển nhị phân sang thập lục phân
string BinToHex(bool* bit);

//Các operator toán tử
// +
QInt operator+(QInt a, QInt b);

//Đây là dòng test
#endif