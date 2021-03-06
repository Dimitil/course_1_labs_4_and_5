
/*************************************************************
	������������ ������� �5. �������.
	����������, �����������, �����.
	�������� ����������. ����������� ��������.
	
*************************************************************/
#include <iostream>
#include <tchar.h>
//#include <cstdio>
//#include <cstdarg>
#include "other.h"


#define	  stop __asm nop

int _tmain()
{

	/////////////////////////////////////////////////////////////////////////////
	// ������� 1. ������.
	// 1.1. �������� ������ �� ��� double. ����������� ������ �������� ��������

	{
		double d = 10.0;

		double& rd = d;

		rd = 20.0;
	}


	// 1.2. ����������������  ��������� �������. 
	//��� ������� �������, ����� linker �� ������� ������ ��� �������� exe-�����?
	// ���������: ref - ��� ������� �� ��������� � ������� ����� ������!
	//���������, ��� ���� �������� ��� ������� ������, � ��� �� ����������.

	// �� ��������� ������� main �������� � ������������ �����, include ���,
	//���������� ��� ���������� 
	//extern int& ref;
	ref++;

	// 1.3. ���������������� ��������� ������. 
	//��� ������� �������, ����� ���������� �� ������� ������ 
	// �������� �����
	const int& ref1 = 1;


	// 1.4. ����� ���������:
	char c = 'A';
	char* pc = &c;


	//�������� ������ �� ���������.

	char*& rpc = pc;

	//����������� ������ ��������

	//�) �������� �� ������
	*rpc = 'B';
	//�) ��� �����
	rpc++;


	// 1.5. �������� � ���������� �������, ����������� ������� �����, ����������� � �������� ���������.
	//  �������� ������ ���� �������. �������� ������� � ��������� ���� �����������
   //��������� (!!!):
   // ���������� ������� ������� �������� � ������������ ���� (.h),
   // � ����������� �������- � ���� ���������� (.cpp)
   // � ������� ����������� ����� other.cpp � other.h. 
   //��� ����� ����� ������������ ��� ����������  ����� �������.
	{
		int x = 10;
		int res1 = square(x);
		int res2 = square(5);
		stop
	}


	////////////////////////////////////////////////////////////////////////////	

		//������� 2. ������� ��� �������� ���������� 
		//�) �� ��������, �) �� ������, �) �� ���������


		//�� �������� - � ������� ���������� ��������� ����� � ��� ���� ���������� ��������.
		//�o ������ � �� ��������� - ���������� ����� ����������. �� ������������ ������ ���������, �� ��������� ������ ������� ��������


		// 2.1. �������� � ���������� ��� �������, ������� ����������� ��������
		//� ������� ��������� �������� �� 1 
		// �) - IncByValue(),

		// �) - IncByPointer()

		//�) - IncByReference() . 

		//��������� ������������ � ������� ���������.
		//




	int val = 1;//�������� ���� ���������� ������ ���� ��������� � �������
				//������ �� ������� �� �������

	int test = IncByValue(val);

	IncByPointer(&val);

	IncByReference(val);

	stop


		// 2.2 �������� ���������� c ������� ��������� � �� ������.
		//�������� ������� (�������) Swap(), ������� ������ ��������
		//���������� nX � nY �������.

		// �)������� ������ ��������� ��� ��������� �� int  � �������� ����� �����������
		//   ������ ������ �������� ���������� � ���������� (!) ���������

		// �)������� ������ ��������� ��� ������ �� int � �������� ����� ��������
		//   ������ ������ �������� ���������� � ���������� (!) ���������
		//��������� ������������ � ������� ������������ ���� ���������.

		int	nX = 1;
	int nY = -1;
	Swap(&nX, &nY);  //�������� ������� �������� nX � nY � ������� ���������� �� nX � nY
	Swap(nX, nY);  //� ������ ������� � ������� ������ �� nX � nY
	stop

		////////////////////////////////////////////////////////////////////////////

		//������� 3. ������� � �������� ����������.
		// 3.1. �������� ������� ������ ��������� �� ���������� ���������� �������

		//��������:
	//	int ar[N] = {������ ���������������};//��������� - ��� � ��� ������ ���� ����� �������� N
		//PrintArray(ar, ... ����� ����, ����������� �������� ��� �����-������ ������);
		const int N = 5;

	int ar[N] = { 5,1,7,3,2 };
	int ar1[] = { 5,1,7,3,2,11 };
	std::cout << "\n\nZadanie #3\n";
	PrintArray(ar, N);
	PrintArray(ar1, sizeof(ar1)/sizeof(ar[0]));

	// 3.2. �������� ������� ������ ������������ �������� �� ���������� ���������� �������

	//��������:
	//int ar[N] = {������ ���������������};//��������� - ��� � ��� ������ ���� ����� �������� N
	//int res = Min(ar, ... ����� ����, ����������� �������� ��� �����-������ ������);


	int res = Min(ar, N);


	// 3.3. �������� ������� ��������� ���� ����� - MyStrCmp():
	//������� ������ ��������� ��� ��������� �� ������������ ������ 
	//(�������� �� ������ ������� �����������, ��� ������� �� ����� ����� �������������� 
	//���������� �����)

	//������� ������ ���������� ������������� ��������, ����
	//������ ������ ����������������� ������ ������, 0 - ����
	//��� ����� � ������������� ��������, ���� ������ ������
	//������ ������.
	//���������: ��� ������������������ ������� ������������ ���� �������� (!!!), � �� ����� �����
	// ���� ���  ������� ������ ������ > ���������������� ���� ������� ������ ������, 
	// �� ������ ������ > ������ 
	//���������, ��� ��������� ����� ������ �������� ������� ����.


	//�������� ��� ������ ��� ���������:

	char str1[] = { "Bcdae" };
	char str2[] = { "Abcda" };



	//�������� ������� ���������

	//�������� ��������� ��������� � ������� cout:
	std::cout << "\n\nZadanie #3.3";
	std::cout << '\n' << MyStrCmp(str1, str2);



	stop

		////////////////////////////////////////////////////////////////////////////
			//������� 4. ������� ������ �� ��������

				// 4.1. �������� � �������� �������, ������� ��������� � �������� ��������� 
				//���������� ����� - nN - ������, 
				//� ����������  ��������� �� ���������� ������, ���������� �������� ��������� ������. 
				//���������: 
				//-��� ����, ����� ������ ������� �������� ���������, ����� ����� � ��� ��������� ������,
				//��������� �� ������� ��������� �������.
				//����� ����, ���� �� ������� ������������� ������ ��� ������������ �������� ������.
	{
		std::cout << "\n\nZadanie #4";
		std::cout << '\n';
	std::cout << NameOfMonth(3);

	stop
	}

		// 4.2. �������� � �������� �������, ������� �� ��������� ������������� ����������
		// (����, �����, ���)
		//��������� ��������������� ������ 
		//��������, 12, 11, 2020 => "12.11.2020" 
		//  ���  1, 1, 2020 => "1.1.2020"   (� ����� "01.01.2020")

		// ��������� � 
		// 1) ��� �������� ������ ����� � ��������� ������������� ����� ������������ ������� 
		// ����������� ���������� _itoa(), 
		// ������������ ���� <cstdlib>� ������ MSDN).
		// char* _itoa( int value, char * buffer,  int radix );

		// 2) ��� ������������ �������������� ������ ��� ������ ����� ����������� ������� ����������� 		
		// ���������� strcpy() � strcat
		//������������ ���� <cstring>� ������ MSDN).
		// char * strcpy( char * dest, const char * source); 
		// - ��������  �� ������ source, ������� ����������� ������� ������, � ������ dest
		// char * strcat( char * dest, const char * source);  
		//- ����������� �����. ����� ������ source  ����������� � ����� ������ dest. 
		// ������� ������ ����� ������ dest ���������� ������ �������� ������ source
		// � ����� dest ����������� ������ ����� ������ ('\0').

		// 3) !!! ������ �����, ��� ������������� ���� �������, �� �������� ��������� �����������:
		//Severity	Code	Description	Project	File	Line	Suppression State
		//Error	C4996	strcpy': This function or variable may be unsafe.Consider using strcpy_s
		//instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
		//��� ����, ����� ��� ��������� �� ����������, ����� ����� #include �������� 
		//  #define _CRT_SECURE_NO_WARNINGS


		//� ������� �������� ����������, ����������� � ����� �������.
	{
		char data[11];

		std::cout << "\n\nZadanie #4.2";
		std::cout << '\n' << DataStr(20, 4, 2020, data);

		stop
	}

	////////////////////////////////////////////////////////////////////////////
		//������� 5. ����������� ������.
		//�������� �������, ������� ������� ����� ������������ �������� � �������,
		// ����� �������, ����� �� ����� ����� ���� ������������ ����� �� ����� 
		// ���������: *MyMin(���������) = 0;
	{
		const int N = 5;
		int ar[N] = {1,5,-1,2,5};
	*MyMin(ar, N) = 0;

	std::cout << "\n\nZadanie #5";
	std::cout << std::endl;
	for (int i = 0; i < N; i++)	std::cout << ar[i]<<' ';	
	std::cout << std::endl;
	}
	

////////////////////////////////////////////////////////////////////////////
	//������� 6 (*).
	//��� ���������� ������ �� N ���������
	//��������: �������� ��������� ����� ���� ������ � ��������� 0, 1, 2 �., 30, 31.  
	//�������� ��� ������� :
	//������� - ��������� ����� �������� ����������� � ������� ������ ����� ���, 
	//� ����� � ��������(��� ���� ��� ���������� ����� ������������ ������ ���� int) = >
	//int   f1(���������);
	//������� �  ������� ���������(��������: 0 ����������� � ������� ������ ����� ���)

	//� ������� �������� ����������, ����������� � ����� �������.

	{//������� 1	
		const int N = 5;
		int ar[N] = { 1,2,3,1,2 };

		std::cout << "\n\nZadanie #6\nFunc#1.1\n";
		std::cout << Even_Func(0, ar, N);		//���������� -1 ���� ������� ���, 1 ���� ������ ��� � 0 ���� �������
		std::cout << "\n\nZadanie #6\nFunc#1.2\n";
		print_Even_Func(4, ar, N);
	}

	std::cout << "\n\n";


	{	//������� 2 (
	const int N = 5;
	int ar[] = { 1,2,3,3,31,7, 7, 7 };  

	std::cout << "\n\nZadanie #6\nFunc#2.1\n";
	
	//std::cout <<std::hex<< not_Even_Func(ar, N);

	std::cout << "\n\nZadanie #6\nFunc#2.2\n";
	
	print_not_Even_Func(ar, sizeof(ar)/sizeof(ar[0]));


	}

	return 0;

}//main
