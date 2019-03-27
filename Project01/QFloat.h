#ifndef __QFLOAT_H__
#define __QFLOAT_H__

#include "QInt.h"

struct QFloat
{
	unsigned data[4];
};

//Chuyển đổi chuỗi thập phân thực ra chuỗi nhị phân
string FloatIntToFloatBin(string a);

#endif