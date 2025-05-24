void Allocate(int** arr, const int rows, const int cols)
{
	//int** arr = new int* [rows];//1. Создаем массив указателей
	for (int i = 0; i < rows; i++)//2 выделяем память под строки массива
	
	{
		arr[i] = new int[cols];
	}

}
