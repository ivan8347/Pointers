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
int** Push_col_back(int** arr,  const int rows ,int &cols);

int* Push_front(int arr[], int& n, const int value);
int** Push_row_front(int** arr, int& rows, const int cols);
int** Push_col_front(int** arr, const int rows, int& cols);

int* Insert(int arr[], int& n, const int value, const int index);
int** Insert_row(int** arr, int& rows, const int cols, const int index);
int** Insert_col(int** arr, const int rows, int& cols,const int index);

void Pop_back(int*& arr, int& n);
int** Pop_row_back(int**& arr, int& rows,const int cols);
void Pop_col_back(int**& arr,  const int rows ,int& cols);

void Pop_front(int*& arr,  int& n);
int** Pop_row_front(int**& arr, int& rows,const int cols);
void Pop_col_front(int**& arr, const int rows,int& cols);

void Erase(int*& arr, int& n, const int value);
int** Erase_row(int**& arr, int& rows, const int cols, const int index);
void Erase_col(int**& arr, const int rows, int& cols, const int index);

void Clear(int** arr, const int rows, const int cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2


void main()

{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
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
	cout << "Введите добавленное значение в конце массива: "; cin >> value;
	//1.создаём буферный массив
	arr = Push_back(arr, n, value);
	//#ifdef DEBUG
//	//2.копируем всё содержимое исходного в буфер
//for (int i = 0; i < n; i++)
//{
//	buffer [i] = arr[i];
//}
// 	   //3.удаляем исходный массив
//   delete[] arr;
//  //4.подменяем адресс в указателе "arr" указателем нового массива
//arr =  buffer;
////5.только после этого в массиве появляется элимент 
//arr[n] = value;
////6.как в массив добавился элимент кол-во элементов увеличивается на один
//n++;  
//#endif // DEBUG
	Print(arr, n);

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
	//1 создаем буферный массив указателей нужного размера
	int** buffer = new int* [rows + 1];
	//2 копируем адресса строк в буфер
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;//удаляем исходный массив
	buffer[rows] = new int[cols] {};//создаем добавляемую строку и записывает адрес в массив указателей
	rows++;//при добавлении в массив строки количество увеличивается
	return buffer;//возвращает новый массив на место вызова
}
int** Push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
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
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[]arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** Push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
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
	for (int i = index; i < rows; i++)
	{
		buffer[i+1] = arr[i];
	}
	buffer[index] = new int[cols] {};
	delete[] arr;

	rows++;
	return buffer;
}
int** Insert_col(int** arr, const int rows, int& cols, const int index)
{
	
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols+1];
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
int** Pop_row_back(int**& arr, int& rows, const int cols)
{
	int** buffer = new int*[--rows];

	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr[rows];
	delete[] arr;
	return buffer;
	
}
void Pop_col_back(int**& arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
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
int** Pop_row_front(int**& arr, int& rows, const int cols)
{
	int** buffer = new int* [--rows];

	for (int i = 0; i < rows; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
	
}
void Pop_col_front(int**& arr, const int rows, int& cols)
{
	
	cols--;

	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];

		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j+1];
		delete[]arr[i];
		arr[i] = buffer;
	}
	
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
int** Erase_row(int**& arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [--rows];
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
void Erase_col(int**& arr, const int rows, int& cols, const int index)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols];
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