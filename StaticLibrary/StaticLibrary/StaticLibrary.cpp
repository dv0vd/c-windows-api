#include <Windows.h>
#include <stdio.h>
#include <tchar.h> 
#include <LMCons.h>
#define SECURITY_WIN32
#include <Security.h>
#include "StaticLibrary.h"
#pragma comment(lib, "SECUR32.lib")
BOOL ShowLocalComputerName() {
	TCHAR szBuffer[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD cch = _countof(szBuffer);
	BOOL bRet = GetComputerName(szBuffer, &cch);
	if (FALSE != bRet)
		_tprintf(TEXT("Имя локального компьютера: %s\n"), szBuffer);
	return bRet;
}
BOOL ShowDomainComputerName() {
	LPTSTR lpszBuffer = NULL;
	DWORD cch = 0;
	GetComputerNameEx(ComputerNamePhysicalDnsHostname, NULL, &cch);
	lpszBuffer = new TCHAR[cch];
	BOOL bRet = GetComputerNameEx(ComputerNamePhysicalDnsHostname, lpszBuffer, &cch);
	if (FALSE != bRet)
		_tprintf(TEXT("Доменное имя, назначенное локальному компьютеру: %s\n"), lpszBuffer);
	delete[]lpszBuffer;
	return bRet;
}
BOOL ShowUserName() {
	DWORD cch = 0;
	BOOL bRet = GetUserName(NULL, &cch);
	PTCHAR szBuffer = new TCHAR[cch];
	bRet = GetUserName(szBuffer, &cch);
	if (FALSE != bRet)
	{
		_tprintf(TEXT("Имя пользователя в текущем сеансе: %s\n"), szBuffer);
	}
	delete[] szBuffer;
	return bRet;
}
BOOL ShowFullUserName() {
	DWORD cch = 0;
	BOOL bRet = GetUserNameEx(NameSamCompatible, NULL, &cch);
	PTCHAR szBuffer = new TCHAR[cch];
	bRet = GetUserNameEx(NameSamCompatible, szBuffer, &cch);
	if (FALSE != bRet)
	{
		_tprintf(TEXT("Полное имя пользователя в текущем сеансе: %s\n"), szBuffer);
	}
	delete[] szBuffer;
	return bRet;
}