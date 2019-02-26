#pragma once
#include <Windows.h>
interface IX : IUnknown
{
	virtual void __stdcall Fx() = 0;
};