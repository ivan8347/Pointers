#include<iostream>
using namespace std;
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_back(int arr[],  int& n, const int value);
void Pop_back(int*& arr,  int& n);
void Pop_front(int*& arr,  int& n);
int* Push_front(int arr[], int& n, const int value);
void Erase(int*& arr, int& n, const int value);
int* Push(int arr[], int& n, const int value, const int tab);


void main()
{
	setlocale(LC_ALL, "");
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
	int tab;
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
	
	cout << "”даление последнего элемента массива: " << endl;
    Pop_back(arr, n);
	Print(arr, n);

	cout << "”даление нулевого элемента массива: " << endl;
	Pop_front(arr, n);
	Print(arr, n);

	cout << "¬ведите добавленное значение в начале массива: "; cin >> value;
	 arr = Push_front(arr, n, value);
	Print(arr, n);

	cout << "”даление  элемента массива: "; cin >> value; 
	Erase(arr, n, value);
	Print(arr, n);

	cout << "¬ведите индекс добавленного элемента массива: "; cin >> value;
	cout << "¬ведите значение добавленного элемента массива: "; cin >> tab;
	arr = Push(arr, n, value, tab);
	Print(arr, n);


	delete[] arr;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
int* Push_back(int arr[],  int& n, const int value)
{
	int* buffer = new int[n + 1];
	
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr =  buffer;
	 
	arr[n] = value;
	n++;
	return arr;
}
void Pop_back(int*& arr, int& n)
{
	int* buffer = new int[n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
void Pop_front(int*& arr, int& n)
{
	
	int* buffer = new int[n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
void Erase(int*& arr, int& n, const int value)
{	
	int* buffer = new int[n];
	for (int i = 0; i < value; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = value; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
int* Push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr [i];
	}
	delete[] arr;
	arr = buffer;
    arr [0] = value;
	n++;
	return arr;



}
int* Push(int arr[], int& n, const int value, const int tab)
{
	int* buffer = new int[n];
	for (int i = 0; i < value; i++)
	{
		buffer[i] = arr [i];
	}
	buffer[value] = tab;
	for (int i = value; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	//arr[n] = arr [value];

	n++;
	return arr;



}