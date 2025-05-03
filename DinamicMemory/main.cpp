#include<iostream>
using namespace std;
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "¬ведите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "¬ведите добавленное значение: "; cin >> value;
	//буферный массив нужного размера
	int* buffer = new int[n = 1];
	//копируем всЄ содержимое исходного в буфер
	for (int i = 0; i < n; i++)
	{
		buffer [i] = arr[i];
	}
	delete[] arr;
	arr[n] = buffer;
	//только после этго в массиве по€вл€етс€ элимент 
	arr[n] = value;
	//как в массив добавилс€ элимент кол-во элементов увеличиваетс€ на один
	n++;
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