#pragma once
#include"stdafx.h"
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

template<typename T>T** Push_row_back(T** arr, int& rows, const int cols)
{
	//1 создаем буферный массив указателей нужного размера
	T** buffer = new T * [rows + 1];
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
template<typename T>T** Push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}

template<typename T>T** Push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [rows + 1];
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
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}

template<typename T>T** Insert_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T * [rows + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
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
		T* buffer = new T[cols + 1];
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		buffer[index] = 0;
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}

template<typename T>T** Pop_row_back(T**& arr, int& rows, const int cols)
{
	T** buffer = new T * [--rows];

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

template<typename T>T** Pop_row_front(T**& arr, int& rows, const int cols)
{
	T** buffer = new T * [--rows];

	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;

}
template<typename T>void Pop_col_front(T**& arr, const int rows, int& cols)
{

	cols--;

	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols];

		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete[]arr[i];
		arr[i] = buffer;
	}

}

template<typename T>T** Erase_row(T**& arr, int& rows, const int cols, const int index)
{
	T** buffer = new T * [--rows];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}

	for (int i = index; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr;
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
		for (int j = index; j < cols; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
}

