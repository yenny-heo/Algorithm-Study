#include<iostream>
using namespace std;
int arr[3] = { 1, 2, 3 };
int result;
void add(int n, int m, int cnt)
{
	for (int i = 0; i < 3; i++)
	{
		if (n == m + arr[i]) result++;
		if (cnt + 1 < n) add(n, m + arr[i], cnt + 1);
	}
}
int main()
{
	int T;
	cin >> T;
	for (; T > 0; T--)
	{
		int n;
		cin >> n;
		result = 0;
		add(n, 0, 0);
		cout << result << "\n";
	}
}