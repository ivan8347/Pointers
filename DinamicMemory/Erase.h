#pragma once
template<typename T>void Erase(T*& arr, int& n, const int index)
{
	T* buffer = new T[n];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
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
