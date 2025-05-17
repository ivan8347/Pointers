#pragma once
#include"stdafx.h"
template<typename T>T* Push_back(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;

	arr[n] = value;
	n++;
	return arr;
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
