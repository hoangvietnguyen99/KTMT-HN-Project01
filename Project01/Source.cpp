#include "QInt.h"

void main()
{
	QInt x;
	ScanQInt(x);
	bool* a = DecToBin(x);
	cout << BinToHex(a);
}