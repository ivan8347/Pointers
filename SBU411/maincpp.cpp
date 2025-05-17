#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n---------------------------------------\n"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, const int value, int index);

int* pop_back(int arr[], int& n);

int** push_row_back(int** arr, int& rows, const int cols);


//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
	/*
	----------------------------------
	+, -, ++, --;
	----------------------------------
	*/

	int value;
	cout << "������� ����������� ��������: "; cin >> value;

	arr = push_back(arr, n, value);

	//7) �������� ���������, ��������� ���������:
	Print(arr, n);


	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	Print(arr = pop_back(arr, n), n);
	Print(arr = pop_back(arr, n), n);
	Print(arr = pop_back(arr, n), n);
	Print(arr = pop_back(arr, n), n);
	Print(arr = pop_back(arr, n), n);
	Print(arr, n);
	Print(arr, n);
	Print(arr, n);
	Print(arr, n);
	Print(arr, n);
	Print(arr, n);
	Print(arr, n);
	Print(arr, n);

	delete[] arr;
	//Memory leak  
#endif // DYNAMIC_MEMORY_1

	int rows;
	int cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;

	//1) ������� ������ ����������:
	int** arr = new int* [rows];

	//2) �������� ������ ��� ������ ���������� ������������� �������:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	//int   - 'int';
	//int*  - ��������� �� 'int';
	//int** - ��������� �� ��������� �� 'int';

	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	//1) ������� ������� ������:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	//2) ������� ������ ����������:
	delete[] arr;

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		//Index operator, Subscript operator;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n)
{
	cout << arr << ":\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << delimiter << endl;
	cout << endl;
}

int* push_back(int arr[], int& n, const int value)
{

	//1) ������� �������� ������ ������� �������:
	int* buffer = new int[n + 1];

	//2) �������� ��� ���������� ��������� ������� � ��������:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) ������� �������� ������:
	delete[] arr;

	//4) ��������� ����� � ��������� 'arr' ������� ������ �������:
	arr = buffer;

	//5) ������ ����� ����� ����� � ����� ������� ���������� �������, 
	//	 � ������� ����� ��������� ����������� ��������:
	arr[n] = value;

	//6) ����� ���� ��� � ������ ��������� �������, 
	//	 ���������� ��� ��������� ������������� �� 1:
	n++;

	return arr;
}

int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	buffer[0] = value;
	n++;
	return buffer;
}
int* insert(int arr[], int& n, const int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
		buffer[i] = arr[i];
	for (int i = index; i < n; i++)
		buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) ������� �������� ������ ���������� ������� �������:
	int** buffer = new int* [rows + 1];

	//2) �������� ������ ����� � �������� ������ ����������:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}

	//3) ������� �������� ������ ����������:
	delete[] arr;

	//4) ������� ����������� ������, � ���������� �� ����� � ������ ����������:
	buffer[rows] = new int[cols] {};

	//5) ��� ���������� � ������ ������, ���������� ��� ����� ������������� �� 1:
	rows++;

	//6) ���������� ����� ������ �� ����� ������:
	return buffer;
}