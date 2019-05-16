#include <iostream>
using namespace std;
void sum(int, int);

void out()
{
	cout << "don't have 1" << endl;
}
void out2()
{
	cout << "have 1" << endl;
}

void fmore()
{
	cout << "'a>b' \na*a:" << endl;
}

void fless()
{
	cout << "'a<b' \nb*b:" << endl;
}

void feql()
{
	cout << "'a=b' \nb*b:" << endl;
}
int  main()
{
	short a, b;
	cin >> a;
	cin >> b;

	_asm
	{
		mov ax, a
		mov bx, b
		start : cmp ax, bx
				je end_start
				jg c1
				jl c2
				c1 :
		sub ax, bx
			jmp start
			c2 :
		sub bx, ax
			jmp start
			end_start :
		mov a, ax
	}
	cout << "NOD(" << a << "," << b << ") " << a << endl;

	short c, d, e;
	cin >> c;
	cin >> d;
	cin >> e;

	_asm
	{
		mov ax, c
		mov bx, d
		start2 : cmp ax, bx
				 je end_start2
				 jg c3
				 jl c4
			c3 :
				sub ax, bx
				jmp start2
			c4 :
				sub bx, ax
				jmp start2
			end_start2 :
				mov c, ax
			mov ax, c
			mov bx, e
			start3 : cmp ax, bx
				je end_start3
				jg c5
				jl c6
			c5 :
				sub ax, bx
				jmp start3
			c6 :
				sub bx, ax
				jmp start3
			end_start3 :
				mov c, ax
	}

	cout << "NOD(" << c << "," << d << "," << e << ") " << c << endl;
	

	cout << "Number: " << endl;
	short el = 0;
	cin >> el;
	_asm
	{
		mov cx, 0
		mov ax, el
		mov bx, 128
		Mystart: cmp cx, 5
				je lop1
				jl lop2
				jg end_Mystart
			lop1 :
				and ax, bx
				cmp ax, 0
					je lop3
					jg lop4
					jl lop4
			lop3 :
				call out
				jmp end_Mystart
			lop4 :
				call out2
				jmp end_Mystart
			lop2 :
				shr bx, 1
				inc cx
				jmp Mystart
			end_Mystart :
	}
	/*char* a = new char[6]{ 'h','e','l','l','o' };
	char* b;

	_asm
	{
		mov eax, dword ptr[a]
		mov dword ptr[b], eax
		mov eax, 1
		shl eax, 2
		mov ecx, dword ptr[b]
		mov byte ptr[ecx + eax], '$'
	}
	cout << endl << b << endl;
	*/

	float aa, bb;
	cout << "Write a, b" << endl;
	cin >> aa;
	cin >> bb;
	_asm
	{
		FINIT
		FLD aa
		FLD bb
		FUCOMI st, st(1)
			ja c11
			jb c22
			je c33
		c22 :
		call fmore
			FSTP bb
			FMUL aa
			loop END
			c11 :
		call fless
			FMUL bb
			loop END
			c33 :
		call feql
			FMUL bb
			loop END
			END :
		FST aa
	}
	cout << aa << endl;
	getchar();
	return 0;
}
void sum(int a, int b)
{
	printf("%d\n", a + b);
}
