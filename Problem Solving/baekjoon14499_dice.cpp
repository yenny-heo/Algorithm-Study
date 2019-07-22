#include<iostream>
using namespace std;
int map[21][21];
int dice[7];
int main()
{
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	for (; K > 0; K--)
	{
		int move;
		cin >> move;
		if (move == 1 && y + 1 < M)//µ¿
		{
			y++;
			int d1 = dice[1];
			int d3 = dice[3];
			int d4 = dice[4];
			int d6 = dice[6];
			dice[1] = d4;
			dice[3] = d1;
			dice[4] = d6;
			dice[6] = d3;
			cout << dice[1] << "\n";
			if (map[x][y] == 0)
				map[x][y] = dice[6];
			else
			{
				dice[6] = map[x][y];
				map[x][y] = 0;
			}

		}
		else if (move == 2 && y - 1 >= 0)//¼­
		{
			y--;
			int d1 = dice[1];
			int d3 = dice[3];
			int d4 = dice[4];
			int d6 = dice[6];
			dice[1] = d3;
			dice[3] = d6;
			dice[4] = d1;
			dice[6] = d4;
			cout << dice[1] << "\n";
			if (map[x][y] == 0)
				map[x][y] = dice[6];
			else
			{
				dice[6] = map[x][y];
				map[x][y] = 0;
			}

		}
		else if (move == 3 && x - 1 >= 0)//ºÏ
		{
			x--;
			int d1 = dice[1];
			int d2 = dice[2];
			int d5 = dice[5];
			int d6 = dice[6];
			dice[1] = d5;
			dice[2] = d1;
			dice[5] = d6;
			dice[6] = d2;
			cout << dice[1] << "\n";
			if (map[x][y] == 0)
				map[x][y] = dice[6];
			else
			{
				dice[6] = map[x][y];
				map[x][y] = 0;
			}

		}
		else if (move == 4 && x + 1 < N)//³²
		{
			x++;
			int d1 = dice[1];
			int d2 = dice[2];
			int d5 = dice[5];
			int d6 = dice[6];
			dice[1] = d2;
			dice[2] = d6;
			dice[5] = d1;
			dice[6] = d5;
			cout << dice[1] << "\n";
			if (map[x][y] == 0)
				map[x][y] = dice[6];
			else
			{
				dice[6] = map[x][y];
				map[x][y] = 0;
			}

		}
	}

}