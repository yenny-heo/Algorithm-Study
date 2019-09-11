#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	bool map1[17][17];
	bool map2[17][17];
	for (int i = 0; i < n; i++)
	{
		int num1 = arr1[i];
		int num2 = arr2[i];
		for (int j = 0; j < n; j++)
		{
			map1[i][n - j - 1] = num1 % 2;
			num1 = num1 / 2;
			map2[i][n - j - 1] = num2 % 2;
			num2 = num2 / 2;
		}
	}

	for (int i = 0; i < n; i++)
	{
		string ans = "";
		for (int j = 0; j < n; j++)
		{
			if (map1[i][j] == 1 || map2[i][j] == 1)
				ans += "#";
			else
				ans += " ";
		}
		answer.push_back(ans);
	}

	return answer;
}