#include "stdafx.h"
#include "SystemParametrs.h"
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
SYSTEM_PARAMETERS_API void SystemParameters()
{
	UINT value;
	SystemParametersInfo(SPI_GETFOCUSBORDERHEIGHT, 0, &value, 0);
	_tprintf(TEXT("SPI_GETFOCUSBORDERHEIGHT - возвращает высоту верхнего и нижнего краев прямоугольника фокуса:     %d\n"), value);
	SystemParametersInfo(SPI_GETFOCUSBORDERWIDTH, 0, &value, 0);
	_tprintf(TEXT("SPI_GETFOCUSBORDERHEIGHT - возвращает ширину верхнего и нижнего краев прямоугольника фокуса:     %d\n"), value);
}



