void Clear(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++) //3.������� �������
	{
		delete[] arr[i];
	}
	delete[]arr; //4. ������� ������ ����������
}