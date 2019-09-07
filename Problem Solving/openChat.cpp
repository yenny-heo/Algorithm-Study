#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	map<string, string> m;

	for (int i = 0; i < record.size(); i++)
	{
		string parse = record[i];
		char rec[3][11];
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 11; k++)
			{
				rec[j][k] = '\0';
			}
		}//배열 초기화
		int curX = 0, curY = 0;
		for (int j = 0; parse[j] != '\0'; j++)
		{
			if (parse[j] == ' ')
			{
				curX++;
				curY = 0;
			}
			else
			{
				rec[curX][curY] = parse[j];
				curY++;
			}

		}
		if (rec[0][0] == 'E')
		{
			m[rec[1]] = rec[2];

		}
		else if (rec[0][0] == 'C')
		{
			m[rec[1]] = rec[2];
		}
	}
	int num = 0;
	for (int i = 0; i < record.size(); i++)
	{
		string parse = record[i];
		char rec[3][11];
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 11; k++)
			{
				rec[j][k] = '\0';
			}
		}//배열 초기화
		int curX = 0, curY = 0;
		for (int j = 0; parse[j] != '\0'; j++)
		{
			if (parse[j] == ' ')
			{
				curX++;
				curY = 0;
			}
			else
			{
				rec[curX][curY] = parse[j];
				curY++;
			}
		}
		string a;
		if (rec[0][0] == 'E')
		{
			a = m[rec[1]];
			a += "님이 들어왔습니다.";
			answer.push_back(a);
			num++;

		}
		else if (rec[0][0] == 'L')
		{
			a = m[rec[1]];
			a += "님이 나갔습니다.";
			answer.push_back(a);
			num++;
		}
	}
	return answer;
}