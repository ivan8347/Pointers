#include"stdafx.h"
#include"constants.h"
#include"Allocate.h"
#include"FillRand.h"
#include"Print.h"
#include"Push_back.h"
#include"Push_front.h"
#include"Insert.h"
#include"Pop_back.h"
#include"Pop_front.h"
#include"Erase.h"
#include"Clear.h"
using namespace std;

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
//#define DEBUG
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	double* arr = new double[n];
	FillRand(arr, n);
	Print(arr, n);
	
	double value;
	int index;
	cout << "������� ����������� �������� � ����� �������: "; cin >> value;
	
	arr = Push_back(arr, n, value);
	Print(arr, n);

#ifdef DEBUG	
	//1.������ �������� ������
	int* buffer = new int [n]
    for (int i = 0; i < n; i++)//2.�������� �� ���������� ��������� � �����
{
	buffer [i] = arr[i];
}
 	   
   delete[] arr;//3.������� �������� ������
  
arr =  buffer;//4.��������� ������ � ��������� "arr" ���������� ������ �������
//5.������ ����� ����� � ������� ���������� ������� 
arr[n] = value;
//6.��� � ������ ��������� ������� ���-�� ��������� ������������� �� ����
n++;  
#endif // DEBUG

	cout << "�������� ���������� �������� �������: " << endl;
	Pop_back(arr, n);
	Print(arr, n);

	cout << "�������� �������� �������� �������: " << endl;
	Pop_front(arr, n);
	Print(arr, n);

	cout << "������� ����������� �������� � ������ �������: "; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);

	cout << "��������  �������� �������: "; cin >> value;
	Erase(arr, n, value);
	Print(arr, n);

	cout << "������� ������ ������������ �������� �������: "; cin >> index;
	cout << "������� �������� ������������ �������� �������: "; cin >> value;
	arr = Insert(arr, n, value, index);
	Print(arr, n);
	delete[] arr;

#endif // DYNAMIC_MEMORY_1
#ifdef DYNAMIC_MEMORY_2
	int index;
	int rows;
	int cols;

	cout << "������� ���������� ����� : "; cin >> rows;
	cout << "������� ���������� ��������� ������ : "; cin >> cols;
	//1. ������� ������ ����������
	//2 �������� ������ ��� ������ �������
	//for (int i = 0; i < rows; i++)
	//{
	//	arr[i] = new int [cols];
	//}

	int** arr = new int* [rows];
	Allocate(arr, rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "���������� ������ � ����� ������� :" << endl;
	arr = Push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "���������� ������ � ������ ������� :" << endl;
	arr = Push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "������� ������ ����������� ������ �������: "; cin >> index;
	arr = Insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "���������� ������� � ����� ������� :" << endl;
	arr = Push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "���������� ������� � ������ ������� :" << endl;
	arr = Push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "������� ������ ������������ ������� �������: "; cin >> index;
	arr = Insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "�������� ��������� ������ �������: " << endl;
	arr = Pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "�������� ���������� ������� �������: " << endl;
	Pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "�������� ��������� ������ �������: " << endl;
	arr = Pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "�������� ���������� ������� �������: " << endl;
	Pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "������� ������ ��������� ������ �������: "; cin >> index;
	arr = Erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "������� ������ ���������� ������� �������: "; cin >> index;
	Erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	////3.������� �������
	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] arr[i];
	//}
	////4. ������� ������ ����������
	//delete[]arr;

	Clear(arr, rows, cols);

#endif // DYNAMIC_MEMORY_2
}











