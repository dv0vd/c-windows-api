#pragma once

#if !defined(SYSTEM_METRICS_H)
#define SYSTEM_METRICS_H

#ifdef SYSTEM_METRICS_H_EXPORTS
#define SYSTEM_METRICS_H_API __declspec(dllexport)
#else
#define SYSTEM_METRICS_H_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif
	SYSTEM_METRICS_H_API void SystemMetrics();
#ifdef __cplusplus
}
#endif

#endif