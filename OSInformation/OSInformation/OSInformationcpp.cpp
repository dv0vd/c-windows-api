#include"Windows.h"
#include "OSInformation.h"
#include <stdio.h>
#include <tchar.h>
#include <VersionHelpers.h>
#include <ShlObj.h>
#pragma warning(disable : 4996)
OSINFORMATION_API void ShowDirectories(const long csidl[], unsigned long nCount, const LPCTSTR names[])
{  
	TCHAR szBuffer[MAX_PATH + 1];
	for (unsigned long i = 0; i < nCount; ++i)
	{
		HRESULT hr = SHGetFolderPath(NULL, csidl[i], NULL, SHGFP_TYPE_CURRENT, szBuffer);
		if (S_OK == hr)
			_tprintf(TEXT("%s:      %s\n"), names[i], szBuffer);
	}
}
OSINFORMATION_API void ShowOSVersion() 
{
	OSVERSIONINFO info;
	info.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	BOOL res = GetVersionEx((OSVERSIONINFO*)&info);
	if (res != FALSE)
	{
		_tprintf(TEXT("Название ОС:      "));
		switch (info.dwMajorVersion)
		{
		case 5:
			switch (info.dwMinorVersion)
			{
			case 1:
				_tprintf(TEXT("Windows XP\n"));
				break;
			case 2:
				_tprintf(TEXT("Windows Server 2003\n"));
				break;
			} // switch
			break;
		case 6:
			switch (info.dwMinorVersion)
			{
			case 0:
				_tprintf(TEXT("Windows Vista\n"));
				break;
			case 1:
				_tprintf(TEXT("Windows 7\n"));
				break;
			case 2:
				_tprintf(TEXT("Windows 8\n"));
				break;
			case 3:
				_tprintf(TEXT("Windows 8.1\n"));
				break;
			} // switch
			break;
		case 10:
			switch (info.dwMinorVersion)
			{
			case 0:
				_tprintf(TEXT("Windows 10\n"));
				break;
			} // switch
			break;
		} // switch
		_tprintf(TEXT("Идентификатор ОС:      %u\n"), info.dwMajorVersion);
		_tprintf(TEXT("Идентификатор версии:      %u\n"), info.dwMinorVersion);
		_tprintf(TEXT("Идентификатор сборки:      %u\n"), info.dwBuildNumber);
		_tprintf(TEXT("Платформа:      %u\n"), info.dwPlatformId);
	}
}
OSINFORMATION_API void ShowDateTime()
{
	INT cchDate = GetDateFormatEx(LOCALE_NAME_SYSTEM_DEFAULT, NULL, NULL, TEXT("yyyy'-'MM'-'dd"), NULL, 0, NULL);
	if (cchDate != 0)
	{
		PTCHAR buffer = new TCHAR[cchDate];
		cchDate = GetDateFormatEx(LOCALE_NAME_SYSTEM_DEFAULT, NULL, NULL, TEXT("yyyy'-'MM'-'dd"), buffer, cchDate, NULL);
		if (cchDate != 0)
		{
			_tprintf(TEXT("Текущая дата:      %s\n"), buffer);
		}
	}
	INT cchTime = GetTimeFormatEx(LOCALE_NAME_INVARIANT, NULL, NULL, TEXT("hh':'mm':'ss tt"), NULL, 0);
	if (cchTime != 0)
	{
		PTCHAR buffer = new TCHAR[cchTime];
		cchTime = GetTimeFormatEx(LOCALE_NAME_INVARIANT, NULL, NULL, TEXT("hh':'mm':'ss tt"), buffer, cchTime);
		if (cchTime != 0)
		{
			_tprintf(TEXT("Текущее время:      %s\n"), buffer);
		}
	}
}
