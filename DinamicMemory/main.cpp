#include<iostream>
using namespace std;
void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	//�������� ������ ������� �������
	int* buffer = new int[n = 1];
	//�������� �� ���������� ��������� � �����
	for (int i = 0; i < n; i++)
	{
		buffer [i] = arr[i];
	}
	delete[] arr;
	arr[n] = buffer;
	//������ ����� ���� � ������� ���������� ������� 
	arr[n] = value;
	//��� � ������ ��������� ������� ���-�� ��������� ������������� �� ����
	n++;
	Print(arr, n);

	delete[] arr;



}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}