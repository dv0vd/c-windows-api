#include "pch.h"
#include <iostream>
#include "StaticLibrary.h"
#include <locale.h> 
#include <tchar.h>
#include "OSInformation.h"
#include <ShlObj.h> 
#include <DelayImp.h>
#include "SystemParametrs.h"
typedef void(*SYSTEM_METRICS)();
int _tmain()
{
	_tsetlocale(LC_ALL, TEXT("Russian"));
	_tprintf(TEXT("Статистическая библиотека\n"));
	_tprintf(TEXT("---------------------------------------------------------\n"));
	ShowLocalComputerName();
	ShowDomainComputerName();
	ShowUserName();
	ShowFullUserName();
	_tprintf(TEXT("\n"));
	_tprintf(TEXT("---------------------------------------------------------\n"));
	_tprintf(TEXT("Динамическая библиотека, неявное подключение\n"));
	_tprintf(TEXT("---------------------------------------------------------\n"));
	const long csidl[] = {
		CSIDL_APPDATA,
		CSIDL_COMMON_APPDATA,
		CSIDL_COMMON_DOCUMENTS,
		CSIDL_HISTORY,
		CSIDL_INTERNET_CACHE,
		CSIDL_LOCAL_APPDATA,
		CSIDL_PERSONAL,
		CSIDL_PROGRAM_FILES,
		CSIDL_PROGRAM_FILES_COMMON,
		CSIDL_SYSTEM,
		CSIDL_WINDOWS,
	};
	LPCTSTR names[] = {
		TEXT("Каталог, в котором размещены данные приложений пользователя"),
		TEXT("Каталог, в котором размещены данные приложений всех пользователей"),
		TEXT("Каталог «Общие документы»"),
		TEXT("Каталог, в котором содержатся файлы истории Internet Explorer"),
		TEXT("Каталог, в котором размещены временные файлы Интернета"),
		TEXT("Каталог, в котором размещены данные приложений пользователя"),
		TEXT("Каталог «Мои документы»"),
		TEXT("Каталог «Program Files»"),
		TEXT("Каталог «Common Files»"),
		TEXT("Системный каталог Windows"),
		TEXT("Каталог Windows"),
	};
	ShowDirectories(csidl, _countof(csidl), names);
	_tprintf(TEXT("---------------------------------------------------------\n"));
	ShowOSVersion();
	_tprintf(TEXT("---------------------------------------------------------\n"));
	ShowDateTime();
	HMODULE hDLL = LoadLibrary(TEXT("SystemMetrics.dll"));
	if (NULL != hDLL)
	{
		SYSTEM_METRICS func = (SYSTEM_METRICS)GetProcAddress(hDLL, "SystemMetrics");
		if (NULL != func)
		{
			_tprintf(TEXT("\n"));
			_tprintf(TEXT("---------------------------------------------------------\n"));
			_tprintf(TEXT("Динамическая библиотека, явное подключение\n"));
			_tprintf(TEXT("---------------------------------------------------------\n"));
			_tprintf(TEXT("Метрики\n"));
			func();
		}
		FreeLibrary(hDLL);
		_tprintf(TEXT("\n"));
		_tprintf(TEXT("---------------------------------------------------------\n"));
		_tprintf(TEXT("Динамическая библиотека, отложенный запуск\n"));
		_tprintf(TEXT("---------------------------------------------------------\n"));
		_tprintf(TEXT("Параметры\n"));
		__try
		{
			SystemParameters();
		}
		__except (EXCEPTION_EXECUTE_HANDLER)
		{
			switch (GetLastError())
			{
			case ERROR_MOD_NOT_FOUND:
				_tprintf(TEXT("Библиотека для отложенной загрузки не найдена\n"));
				break;
			case ERROR_PROC_NOT_FOUND:
				_tprintf(TEXT("Необходимая функция в отложенно загруженной библиотеке не найдена\n"));
				break;
			}
		}
		__FUnloadDelayLoadedDLL2("SystemParametrs.dll");
	} 
}
