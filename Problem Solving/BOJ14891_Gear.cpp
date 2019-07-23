#include<iostream>
#include<math.h>
using namespace std;
char gear[5][8];
int visit[4];
int main()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> gear[i][j];
		}
	}
	int K;
	cin >> K;
	int top[5] = { 0,0,0,0,0 };
	for (; K > 0; K--)
	{
		int n, d;//n: 톱니바퀴 번호, d: 방향
		int rotate[5];
		for (int i = 1; i < 5; i++)
		{
			rotate[i] = 0;
		}
		cin >> n >> d;
		rotate[n] = d;
	

		//오른쪽으로
		int curGear = n;
		int curDir = d;
		bool flag = 1;
		while (curGear + 1 <= 4 && flag == 1)
		{
			flag = 0;
			int curRight = (top[curGear] + 2) % 8;
			int nextLeft = (top[curGear + 1] + 6) % 8;
			if (gear[curGear][curRight] != gear[curGear + 1][nextLeft])
			{
				flag = 1;
				rotate[curGear + 1] = -curDir;
			}
			curGear++;
			curDir = -curDir;
		}

		//왼쪽으로
		curGear = n;
		curDir = d;
		flag = 1;
		while (curGear - 1 >= 1 && flag == 1)
		{
			flag = 0;
			int curLeft = (top[curGear] + 6) % 8;
			int nextRight = (top[curGear - 1] + 2) % 8;
			if (gear[curGear][curLeft] != gear[curGear - 1][nextRight])
			{
				flag = 1;
				rotate[curGear - 1] = -curDir;
			}
			curGear--;
			curDir = -curDir;
		}

		for (int i = 1; i < 5; i++)
		{
			if (rotate[i] == 1)//시계방향으로 회전
			{
				top[i] = (top[i] + 7) % 8;
			}
			else if (rotate[i] == -1)//반시계
			{
				top[i] = (top[i] + 1) % 8;
			}
		}

	}
	int score = 0;
	for (int i = 1; i < 5; i++)
	{
		if (gear[i][top[i]] == '1')
		{
			score += pow(2, i - 1);
		}
	}
	cout << score << "\n";
}
