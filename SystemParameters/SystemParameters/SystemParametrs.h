#pragma once

#if !defined(SYSTEM_PARAMETERS)
#define SYSTEM_PARAMETERS

#ifdef SYSTEM_PARAMETERS_EXPORTS
#define SYSTEM_PARAMETERS_API __declspec(dllexport)
#else
#define SYSTEM_PARAMETERS_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
	SYSTEM_PARAMETERS_API void SystemParameters();
#ifdef __cplusplus
}
#endif

#endif
