#pragma once
template<typename T>void Pop_front(T*& arr, int& n)
{

	T* buffer = new T[n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
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
