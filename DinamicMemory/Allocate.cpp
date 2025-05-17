void Allocate(int** arr, const int rows, const int cols)
{
	//int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

}
