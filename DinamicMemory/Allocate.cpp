void Allocate(int** arr, const int rows, const int cols)
{
	//int** arr = new int* [rows];//1. ������� ������ ����������
	for (int i = 0; i < rows; i++)//2 �������� ������ ��� ������ �������
	
	{
		arr[i] = new int[cols];
	}

}
