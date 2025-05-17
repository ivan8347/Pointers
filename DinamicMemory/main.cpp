#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void Allocate(int** arr, const int rows, const int cols);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* Push_back(T arr[],  int& n, const T value);
template<typename T>T** Push_row_back(T** arr,  int &rows,const int cols);
template<typename T>T** Push_col_back(T** arr,  const int rows ,int &cols);

template<typename T>T* Push_front(T arr[], int& n, const T value);
template<typename T>T** Push_row_front(T** arr, int& rows, const int cols);
template<typename T>T** Push_col_front(T** arr, const int rows, int& cols);

template<typename T>T* Insert(T arr[], int& n, const int value, const int index);
template<typename T>T** Insert_row(T** arr, int& rows, const int cols, const int index);
template<typename T>T** Insert_col(T** arr, const int rows, int& cols,const int index);

template<typename T>void Pop_back(T*& arr, int& n);
template<typename T>T** Pop_row_back(T**& arr, int& rows,const int cols);
template<typename T>void Pop_col_back(T**& arr,  const int rows ,int& cols);

template<typename T>void Pop_front(T*& arr,  int& n);
template<typename T>T** Pop_row_front(T**& arr, int& rows,const int cols);
template<typename T>void Pop_col_front(T**& arr, const int rows,int& cols);

template<typename T>void Erase(T*& arr, int& n, const int index);
template<typename T>T** Erase_row(T**& arr, int& rows, const int cols, const int index);
template<typename T>void Erase_col(T**& arr, const int rows, int& cols, const int index);

void Clear(int** arr, const int rows, const int cols);

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2


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

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T* Push_back(T arr[],  int& n, const T value)
{
	T* buffer = new T[n + 1];
	
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
template<typename T>T** Push_row_back(T** arr, int& rows, const int cols)
{
	//1 ������� �������� ������ ���������� ������� �������
	T** buffer = new T* [rows + 1];
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
template<typename T>T** Push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}

template<typename T>T* Push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
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
template<typename T>T** Push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[]arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
template<typename T>T** Push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}

template<typename T>T* Insert(T arr[], int& n, const int value, const int index)
{
	T* buffer = new T[n+1];
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
template<typename T>T** Insert_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	buffer[index] = new int[cols] {};
	delete[] arr;

	rows++;
	return buffer;
}
template<typename T>T** Insert_col(T** arr, const int rows, int& cols, const int index)
{
	
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols+1];
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[j+1] = arr[i][j];
		}
	   buffer[index] = 0;
	   delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}


template<typename T>void Pop_back(T*& arr, int& n)
{
	T* buffer = new T[n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>T** Pop_row_back(T**& arr, int& rows, const int cols)
{
	T** buffer = new T*[--rows];

	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows];
	delete[] arr;
	return buffer;
	
}
template<typename T>void Pop_col_back(T**& arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}

template<typename T>void Pop_front(T*& arr, int& n)
{
	
	T* buffer = new T[n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>T** Pop_row_front(T**& arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];

	for (int i = 0; i < rows; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
	
}
template<typename T>void Pop_col_front(T**& arr, const int rows, int& cols)
{
	
	cols--;

	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];

		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j+1];
		delete[]arr[i];
		arr[i] = buffer;
	}
	
}


template<typename T>void Erase(T*& arr, int& n, const int index)
{	
	T* buffer = new T[n];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
template<typename T>T** Erase_row(T**& arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	
	for (int i = index; i < rows; i++)
	{
		buffer[i] = arr[i+1];
	}
	//delete[] arr[rows];
	delete[] arr;

	//rows--;
	return buffer;
}
template<typename T>void Erase_col(T**& arr, const int rows, int& cols, const int index)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols ; j++)
		{
			buffer[j] = arr[i][j+1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
}


void Clear(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;
}