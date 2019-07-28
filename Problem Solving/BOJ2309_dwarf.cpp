#include<iostream>
#include<algorithm>
using namespace std;
int arr[9];
int main()
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	int one, two;
	for (int a = 0; a < 9; a++)
	{
		for (int b = a + 1; b < 9; b++)
		{
			if (sum - arr[a] - arr[b] == 100)
			{
				one = arr[a];
				two = arr[b];
				break;
			}
		}
	}

	sort(arr, arr + 9);

	for (int i = 0; i < 9; i++)
	{
		if (arr[i] != one && arr[i] != two)
		{
			cout << arr[i] << "\n";
		}
	}

}