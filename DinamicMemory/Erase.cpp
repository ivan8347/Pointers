void Erase(int*& arr, int& n, const int value)
{
	int* buffer = new int[n];
	for (int i = 0; i < value; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = value; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}