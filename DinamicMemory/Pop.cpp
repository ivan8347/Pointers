void Pop_back(int*& arr, int& n)
{
	int* buffer = new int[n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
}
void Pop_front(int*& arr, int& n)
{

	int* buffer = new int[n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
}