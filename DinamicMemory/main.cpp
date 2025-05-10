#include"stdafx.h"
#include"constants.h"
#include"FILLRand.h"
#include"Print.h"
#include"Push.h"
#include"Pop.h"
#include"Erase.h"
#include"Insert.h"
using namespace std;
#define DYNAMIC_MEMORY_1

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	/*cout << arr << endl;
	cout << *arr << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr + i << "\t";
	}
	cout << endl;*/
	int value;
	int index;
	cout << "������� ����������� �������� � ����� �������: "; cin >> value;
	//1.������ �������� ������
	arr = Push_back(arr, n, value);
	//#ifdef DEBUG
//	//2.�������� �� ���������� ��������� � �����
//for (int i = 0; i < n; i++)
//{
//	buffer [i] = arr[i];
//}
// 	   //3.������� �������� ������
//   delete[] arr;
//  //4.��������� ������ � ��������� "arr" ���������� ������ �������
//arr =  buffer;
////5.������ ����� ����� � ������� ���������� ������� 
//arr[n] = value;
////6.��� � ������ ��������� ������� ���-�� ��������� ������������� �� ����
//n++;  
//#endif // DEBUG
	Print(arr, n);

	cout << "������� ����������� �������� � ������ �������: "; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);

	cout << "������� ������ ������������ �������� �������: "; cin >> index;
	cout << "������� �������� ������������ �������� �������: "; cin >> value;
	arr = Insert(arr, n, value, index);
	Print(arr, n);

	cout << "�������� ���������� �������� �������: " << endl;
	Pop_back(arr, n);
	Print(arr, n);

	cout << "�������� �������� �������� �������: " << endl;
	Pop_front(arr, n);
	Print(arr, n);

	cout << "��������  �������� �������: "; cin >> value;
	Erase(arr, n, value);
	Print(arr, n);

	delete[] arr;

#endif // DYNAMIC_MEMORY_1
}





