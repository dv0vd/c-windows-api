#include "SystemMetrics.h"
#include "Windows.h"
#include <tchar.h>
SYSTEM_METRICS_H_API void SystemMetrics()
{
	INT metric = GetSystemMetrics(SM_CLEANBOOT);
	_tprintf(TEXT("SM_CLEANBOOT - возвращает значение, определяющее режим загрузки:     %d\n"), metric);
	metric = GetSystemMetrics(SM_CXICON);
	_tprintf(TEXT("SM_CXICON - возвращает заданную по умолчанию ширину иконки:     %d\n"), metric);
	metric = GetSystemMetrics(SM_CYICON);
	_tprintf(TEXT("SM_CYICON - возвращает заданную по умолчанию высоту иконки :     %d\n"), metric);
	metric = GetSystemMetrics(SM_CXSMSIZE);
	_tprintf(TEXT("SM_CXSMSIZE - возвращает ширину маленькой надписи кнопки:     %d\n"), metric);
	metric = GetSystemMetrics(SM_CYSMSIZE);
	_tprintf(TEXT("SM_CYSMSIZE - возвращает высоту маленькой надписи кнопки:     %d\n"), metric);
}
