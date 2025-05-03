#include<iostream>
using namespace std;
void FILLRand(int arr[], const int n);
void Print(int arr[], const int n);
void main()
{
	setlocale(LC_ALL," ");
	const int n = 10;
	int arr[n];
	FILLRand(arr, n);
	Print(arr, n);
	cout << "\n";
	//считаем количество чётных и нечётных элементов
	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		// arr[i] % 2 == 0 ? even_count++ : odd_count++;
		//if (arr[i] % 2 == 0)  even_count++ ;
		//else odd_arr[k++]=arr[i];
		( arr[i] % 2 == 0 ? even_count : odd_count)++;

	}
	//выделяем память для чётных и не чётных значений
	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];
	//копируем чётные и нечётные значения в массивы
	for (int i = 0,j=0,k=0; i < n; i++)
	{
		//if (arr[i] % 2 == 0)even_arr[j++] = arr[i];
		//else odd_arr[k++] = arr[i];
		( arr[i] % 2 == 0 ? even_arr[j++] : odd_arr[k++])=arr[i];
	}
	//выводим результат
	Print(even_arr, even_count);
	Print(odd_arr, odd_count);
	//удаляем память
	delete[] odd_arr;
	delete[] even_arr;

}





void FILLRand(int arr[], const int n)
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
		cout << arr[i] << "  ";
	}cout << endl;
}
