#define _CRT_SECURE_NO_WARNINGS
#include "other.h"
#include <iostream>
#include <cstdlib>
#include <cstring>


int x1;
int& ref=x1;

int square(const int& x)
{
	return x * x;
}

int IncByValue(int a) {
	return a += 1;
}


void IncByPointer(int* p)
{
	*p += 1;
}

void IncByReference(int& r)
{
	r++;
}

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void PrintArray(const int* ar, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << ar[i]<<' ';
	std::cout << std::endl;
}



int Min(int const* ar, int size)
{
	int min = ar[0];

	for (int i = 1; i < size; i++)
	{
		if (min > ar[i])
			min = ar[i];
	}
	return min;
}


int MyStrCmp(const char* str1, const char* str2)
{
	while (*str1 || *str2)//(*str1 || *str2)
	{


		if (*str1 < *str2 )
		{
			return -1;
		}

		if (*str1 > *str2)
		{
			return 1;
		}

		str1++;
		str2++;
	}

	
	return 0;
}


		// 4.1. —оздайте и вызовите функцию, котора€ принимает в качестве параметра 
		//пор€дковый номер - nN - мес€ца, 
		//а возвращает  указатель на символьную строку, содержащую название заданного мес€ца. 
		//ѕодсказка: 
		//-дл€ того, чтобы данна€ функци€ работала корректно, очень важно Ц как объ€влена строка,
		//указатель на которую требуетс€ вернуть.
		// роме того, было бы неплохо предусмотреть защиту при некорректном значении мес€ца.


const char* NameOfMonth(int a)
{
	if (a <= 12 && a > 0)
	{
		return Months[a];
	}

	else return Months[0];

}

char* DataStr(int dd, int mm, int yyyy, char* data) {

	char day[3];
	char month[3];
	char year[5];

	_itoa(dd, day, 10);
	_itoa(mm, month, 10);
	_itoa(yyyy, year, 10);

	strcpy(data, day);
	strcat(data, ".");
	strcat(data, month);
	strcat(data, ".");
	strcat(data, year);

	return data;
}

int* MyMin(const int* ar, int size) {
	const int* min = &ar[0];
	for (int i = 1; i < size; i++)
	{
		if (ar[i] < *min) min = &ar[i];
	}
	
	return const_cast<int*>(min);
}


//вариант 1
int Even_Func(int num, int* ar, int size)  // если четное число раз встречаетс€ в массиве - возвращает 1, нечетное -1, 0 если нет в массиве
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (ar[i] == num) count++;
	}

	if (count)
	{
		return (count & 1) ? -1 : 1;
	}

	else return count;

}

void print_Even_Func(int num, int* ar, int size)
{
	int var = Even_Func(num, ar, size);

	std::cout << '\n' << num << " meets in an array ";

	switch (var)
	{
	case -1: std::cout << "a NOT even number of times.";
		break;

	case  1:
		std::cout << "an EVEN number of times.";
		break;


	default:
		std::cout << " never.";
	}
}
//вариант 2 

unsigned int not_Even_Func(const int* ar, int size) {


	unsigned int res = 0;

	for (int i = 0; i < 32; i++)
	{

		unsigned int count = 0;
		for (int j = 0; j < size; j++)
		{
			if (i == ar[j])
				count++;
		}

		res |= (count & 1);
		if (i == 31) break; //здесь была ошибка
		res = res << 1;


	}

	return res;

}

void print_not_Even_Func(int* ar, int size)
{
	int num = not_Even_Func(ar, size);

	for (int i = 0; i < 32; i++)
	{
		std::cout << "\nnum " << 31 - i << " meets ";
		if (num & 1) std::cout << "NOT even times\n";
		else std::cout << "EVEN times or not meets\n";
		num >>= 1;
	}

}
