#pragma once
#ifndef OSINFORMATION_H
#define OSINFORMATION_H
#ifdef OSINFORMATION_EXPORTS
#define OSINFORMATION_API __declspec(dllexport)
#else
#define OSINFORMATION_API __declspec(dllimport)
#endif
#ifdef __cplusplus
extern "C" {
#endif
	OSINFORMATION_API void ShowDirectories(const long csidl[], unsigned long nCount,const LPCTSTR names[]);
	OSINFORMATION_API void ShowOSVersion();
	OSINFORMATION_API void ShowDateTime();
#ifdef __cplusplus
}
#endif
#endif