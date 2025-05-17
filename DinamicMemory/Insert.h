#pragma once
template<typename T>T* Insert(T arr[], int& n, const int value, const int index)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	buffer[index] = value;
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return buffer;
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
