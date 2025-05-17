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
	cout << "Введите размер массива: "; cin >> n;
	double* arr = new double[n];
	FillRand(arr, n);
	Print(arr, n);
	
	double value;
	int index;
	cout << "Введите добавленное значение в конце массива: "; cin >> value;
	
	arr = Push_back(arr, n, value);
	Print(arr, n);

#ifdef DEBUG	
	//1.создаём буферный массив
	int* buffer = new int [n]
    for (int i = 0; i < n; i++)//2.копируем всё содержимое исходного в буфер
{
	buffer [i] = arr[i];
}
 	   
   delete[] arr;//3.удаляем исходный массив
  
arr =  buffer;//4.подменяем адресс в указателе "arr" указателем нового массива
//5.только после этого в массиве появляется элимент 
arr[n] = value;
//6.как в массив добавился элимент кол-во элементов увеличивается на один
n++;  
#endif // DEBUG

	cout << "Удаление последнего элемента массива: " << endl;
	Pop_back(arr, n);
	Print(arr, n);

	cout << "Удаление нулевого элемента массива: " << endl;
	Pop_front(arr, n);
	Print(arr, n);

	cout << "Введите добавленное значение в начале массива: "; cin >> value;
	arr = Push_front(arr, n, value);
	Print(arr, n);

	cout << "Удаление  элемента массива: "; cin >> value;
	Erase(arr, n, value);
	Print(arr, n);

	cout << "Введите индекс добавленного элемента массива: "; cin >> index;
	cout << "Введите значение добавленного элемента массива: "; cin >> value;
	arr = Insert(arr, n, value, index);
	Print(arr, n);
	delete[] arr;

#endif // DYNAMIC_MEMORY_1
#ifdef DYNAMIC_MEMORY_2
	int index;
	int rows;
	int cols;

	cout << "Введите количество строк : "; cin >> rows;
	cout << "Введите количество элементов строки : "; cin >> cols;
	//1. Создаем массив указателей
	//2 выделяем память под строки массива
	//for (int i = 0; i < rows; i++)
	//{
	//	arr[i] = new int [cols];
	//}

	int** arr = new int* [rows];
	Allocate(arr, rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << "Добавление строки в конце массива :" << endl;
	arr = Push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавление строки в начале массива :" << endl;
	arr = Push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс добавленной строки массива: "; cin >> index;
	arr = Insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Добавление столбца в конце массива :" << endl;
	arr = Push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавление столбца в начале массива :" << endl;
	arr = Push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс добавленного столбца массива: "; cin >> index;
	arr = Insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Удаление последней строки массива: " << endl;
	arr = Pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление последнего столбца массива: " << endl;
	Pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление начальной строки массива: " << endl;
	arr = Pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаление начального столбца массива: " << endl;
	Pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемой строки массива: "; cin >> index;
	arr = Erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемого столбца массива: "; cin >> index;
	Erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);
	////3.удаляем стороки
	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] arr[i];
	//}
	////4. удаляем массив указателей
	//delete[]arr;

	Clear(arr, rows, cols);

#endif // DYNAMIC_MEMORY_2
}











