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
	cout << "¬ведите размер массива: "; cin >> n;
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
	cout << "¬ведите добавленное значение в конце массива: "; cin >> value;
	//1.создаЄм буферный массив
	arr = Push_back(arr, n, value);
	//#ifdef DEBUG
//	//2.копируем всЄ содержимое исходного в буфер
//for (int i = 0; i < n; i++)
//{
//	buffer [i] = arr[i];
//}
// 	   //3.удал€ем исходный массив
//   delete[] arr;
//  //4.подмен€ем адресс в указателе "arr" указателем нового массива
//arr =  buffer;
////5.только после этого в массиве по€вл€етс€ элимент 
//arr[n] = value;
////6.как в массив добавилс€ элимент кол-во элементов увеличиваетс€ на один
//n++;  
//#endif // DEBUG
	Print(arr, n);

	cout << "¬ведите добавленное значение в начале массива: "; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);

	cout << "¬ведите индекс добавленного элемента массива: "; cin >> index;
	cout << "¬ведите значение добавленного элемента массива: "; cin >> value;
	arr = Insert(arr, n, value, index);
	Print(arr, n);

	cout << "”даление последнего элемента массива: " << endl;
	Pop_back(arr, n);
	Print(arr, n);

	cout << "”даление нулевого элемента массива: " << endl;
	Pop_front(arr, n);
	Print(arr, n);

	cout << "”даление  элемента массива: "; cin >> value;
	Erase(arr, n, value);
	Print(arr, n);

	delete[] arr;

#endif // DYNAMIC_MEMORY_1
}





