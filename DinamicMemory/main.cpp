#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void Allocate(int** arr, const int rows, const int cols);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* Push_back(int arr[],  int& n, const int value);
int** Push_row_back(int** arr,  int &rows,const int cols);
int** Push_col_back(int** arr, const int rows ,int &cols);

int* Push_front(int arr[], int& n, const int value);
int** Push_row_front(int** arr, int& rows, const int cols);
int** Push_col_front(int** arr, const int rows, int& cols);

int* Insert(int arr[], int& n, const int value, const int index);
int** Insert_row(int** arr, int& rows, const int cols, const int index);

void Pop_front(int*& arr,  int& n);
void Erase(int*& arr, int& n, const int value);

void Clear(int** arr, const int rows, const int cols);

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
	int index;
	int rows;
	int cols;
	
	cout << "������� ���������� ����� : "; cin >> rows;
	cout << "������� ���������� ��������� ������ : "; cin >> cols;
	////1. ������� ������ ����������
	////2 �������� ������ ��� ������ �������
	////for (int i = 0; i < rows; i++)
	////{
	////	arr[i] = new int [cols];
	////}

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
	
	//cout << "���������� ������� � ����� ������� :" << endl;
	//arr = Push_col_back(arr, rows, cols);
	//Print(arr, rows, cols);

	//arr = Push_col_front(arr, rows, cols);
	//Print(arr, rows, cols);

	










	////3.������� �������
	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] arr[i];
	//}
	////4. ������� ������ ����������
	//delete[]arr;

	Clear(arr, rows, cols);
	
}

void Allocate(int** arr, const int rows, const int cols)
{
	//int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;;
		} 
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		} cout << endl;
	}
	cout << "\n";
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
int** Push_row_back(int** arr, int& rows, const int cols)
{
	//1 ������� �������� ������ ���������� ������� �������
	int** buffer = new int* [rows + 1];
	//2 �������� ������� ����� � �����
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;//������� �������� ������
	buffer[rows] = new int[cols] {};//������� ����������� ������ � ���������� ����� � ������ ����������
	rows++;//��� ���������� � ������ ������ ���������� �������������
	return buffer;//���������� ����� ������ �� ����� ������
}
int** Push_col_back(int** arr, const int rows, int& cols)
{
	int** buffer = new int* [cols + 1];
	for (int j = 0; j < rows; j++)
	{


		for (int i = 0; i < cols; i++)
		{
			buffer[i] = arr[i];
		}
	}
	delete[]arr;

	buffer[cols] = new int[rows] {};
	cols++;

	return buffer;

}

int* Push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int** Push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** Push_col_front(int** arr, const int rows, int& cols)
{
	int** buffer = new int* [cols + 1];

	for (int i = 0; i < cols; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[]arr;
	buffer[0] = new int[rows] {};
	cols++;
	return buffer;
}

int* Insert(int arr[], int& n, const int value, const int index)
{
	int* buffer = new int[n+1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr [i];
	}
	buffer[index] = value;
	for (int i = index; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return buffer;
}
int** Insert_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = new int[cols] {};
	for (int i = index; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;

	rows++;
	return buffer;
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




void Clear(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;
}