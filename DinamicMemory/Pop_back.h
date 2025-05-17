#pragma once
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
