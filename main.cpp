#include <iostream>

int main()
{
	__int8 C = 16;
	__int16 A = 234;
	__int16 B = 129;
	__int32 D;
	__int32 E;

	_asm{
		movsx       eax, word ptr[A]
		movsx       ecx, word ptr[B]
		imul        eax, ecx
		movsx       ecx, byte ptr[C]
		cdq
		idiv        ecx
		mov         dword ptr[D], eax
	}
	
	std::cout << D << std::endl;

	_asm{
		movsx       eax, word ptr[A]
		movsx       ecx, word ptr[B]
		sub         eax, ecx
		movsx       edx, word ptr[B]
		movsx       ecx, byte ptr[C]
		sub         edx, ecx
		imul        eax, edx
		mov         dword ptr[E], eax
	}
	std::cout << E << std::endl;

}
