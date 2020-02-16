#include <iostream>
#include <queue>
#include <utility>

using namespace std;
char map[11][11];
bool visit[11][11][11][11];
queue <pair<pair<int, int>, int>> q1;
queue <pair<pair<int, int>, int>> q2;

pair<pair<int, int>, int> moveRed(int i, int rcx, int rcy, int rm, int ord) {

	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	int j = 1;
	int result, rnx, rny;
	bool flag = 0;

	while (1) {
		rnx = rcx + (dx[i] * j);
		rny = rcy + (dy[i] * j);

		if (map[rnx][rny] == 'O') {//탈출 조건
			flag = 1;
			result = rm + 1;
			break;

		}

		else if (map[rnx][rny] != '.') {//벽 or 공 충돌

			rnx = rcx + (dx[i] * (j - 1));
			rny = rcy + (dy[i] * (j - 1));
			if (ord == 0) {
				map[rnx][rny] = 'R';
			}
			else if (map[rnx][rny] == 'B') {
				rnx = rcx + (dx[i] * (j - 2));
				rny = rcy + (dy[i] * (j - 2));
			}

			map[rnx][rny] = 'R';
			break;
		}
		j++;
	}

	if (flag == 1) return { {result, -1}, -1 };

	return { {rnx,rny},rm + 1 };
}



pair<pair<int, int>, int> moveBlue(int i, int bcx, int bcy, int bm, int ord) {
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };
	int j = 1;
	int bnx, bny;
	bool flag = 0;

	while (1) {
		bnx = bcx + (dx[i] * j);
		bny = bcy + (dy[i] * j);

		if (map[bnx][bny] == 'O') {//탈출 조건
			flag = 1;
			break;
		}

		else if (map[bnx][bny] != '.') {//벽 or 공 충돌


			bnx = bcx + (dx[i] * (j - 1));
			bny = bcy + (dy[i] * (j - 1));
			if (ord == 0) {
				map[bnx][bny] = 'B';

			}
			else if (map[bnx][bny] == 'R') {
				bnx = bcx + (dx[i] * (j - 2));
				bny = bcy + (dy[i] * (j - 2));
			}

			map[bnx][bny] = 'B';
			break;

		}

		j++;

	}

	if (flag == 1) return { {-1, -1}, -1 };
	return { {bnx,bny},bm + 1 };

}



int main() {

	int N, M;
	cin >> N >> M;
	int rx, ry, bx, by;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'R') {
				rx = i;
				ry = j;
				map[i][j] = '.';
			}

			else if (map[i][j] == 'B') {
				bx = i;
				by = j;
				map[i][j] = '.';
			}
		}
	}

	visit[rx][ry][bx][by] = 1;
	q1.push({ {rx, ry}, 0 });
	q2.push({ {bx, by}, 0 });



	bool flag = 0;

	int result = 0;

	while (!q1.empty()) {

		int rcx = q1.front().first.first;
		int rcy = q1.front().first.second;
		int rm = q1.front().second;

		int bcx = q2.front().first.first;
		int bcy = q2.front().first.second;
		int bm = q2.front().second;

		q1.pop();
		q2.pop();

		for (int i = 0; i < 4; i++) {

			int rnx, rny, bnx, bny;
			pair<pair<int, int>, int> red, blue;

			//빨간 공을 먼저 움직이는 경우

			if ((rcx < bcx && i == 0) || (rcx > bcx && i == 1)
				|| (rcy < bcy && i == 2) || (rcy > bcy && i == 3)) {
				red = moveRed(i, rcx, rcy, rm, 0);
				blue = moveBlue(i, bcx, bcy, bm, 1);
			}

			//파란 공을 먼저 움직이는 경우

			else {

				blue = moveBlue(i, bcx, bcy, bm, 0);
				red = moveRed(i, rcx, rcy, rm, 1);

			}
			rnx = red.first.first;
			rny = red.first.second;
			bnx = blue.first.first;
			bny = blue.first.second;


			if (blue.second != -1) {//파란 공이 구멍에 빠지지 않은 경우

				if (red.second == -1) {//빨간 공이 구멍에 빠진 경우

					flag = 1;
					result = red.first.first;
					break;
				}


				if (visit[rnx][rny][bnx][bny] == 0) {//방문 체크

					visit[rnx][rny][bnx][bny] = 1;
					q1.push({ {rnx, rny}, red.second });
					q2.push({ {bnx, bny}, blue.second });
				}

			}
			map[rnx][rny] = '.';
			map[bnx][bny] = '.';

		}

		if (flag == 1) break;

	}



	if (flag == 1 && result <= 10) cout << result << "\n";

	else cout << -1 << "\n";

}