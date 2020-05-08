//Прототипы используемых в данном задании функций:
#pragma once

extern int& ref;

const char* const Months[] = {"NONE" ,"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

int square(const int& x);

int IncByValue(int a);


void IncByPointer(int* p);


void IncByReference(int& r);

void Swap(int* a, int* b);

void Swap(int& a, int& b);

void PrintArray(const int* ar, int size);

int Min(int const* ar, int size);

int MyStrCmp(const char* str1, const char* str2);

const char* NameOfMonth(int a);

char* DataStr(int dd, int mm, int yyyy, char* data);

int* MyMin(const int* ar, int size);

int Even_Func(int num, int* ar, int size);

void print_Even_Func(int num, int* ar, int size);

unsigned int not_Even_Func(const int* ar, int size);

void print_not_Even_Func(int* ar, int size);