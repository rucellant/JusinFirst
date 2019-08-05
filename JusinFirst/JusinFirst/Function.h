#pragma once

template<typename T>
void SAFE_RELEASE(T& ptr)
{
	if (ptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}