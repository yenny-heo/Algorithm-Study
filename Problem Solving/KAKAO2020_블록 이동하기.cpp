#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <cstdlib>

using namespace std;
queue<pair<pair<int,int>,pair<int,int>>> pos;
queue<pair<int,int>> time_dir;

bool visit[100][100][4];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int rotate_x[4] = {-1, -1, 1, 1};
int rotate_y[4] = {1, -1, -1, 1};

int check_hori_x[4] = {-1, -1, 1, 1};
int check_hori_y[4] = {0, 0, 0, 0};

int check_vert_x[4] = {0, 0, 0, 0};
int check_vert_y[4] = {1, -1, -1, 1};


int direction(pair<int, int> r1, pair<int, int> r2){
    int r1_x = r1.first;
    int r1_y = r1.second;
    
    int r2_x = r2.first;
    int r2_y = r2.second;
    
    if(r1_x - r2_x == 1) return 0;
    else if(r1_x - r2_x == -1) return 2;
    else if(r1_y - r2_y == -1) return 1;
    else if(r1_y - r2_y == 1) return 3;
    return -1;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int N = board.size();
    //초기 로봇 위치
    pair<int,int> r1 = {0, 0};
    pair<int,int> r2 = {0, 1};
    int dir = direction(r1, r2);
    pos.push({r1, r2});
    time_dir.push({0, dir});
    visit[r1.first][r1.second][dir] = 1;
    
    while(!time_dir.empty()){
        int r1_x = pos.front().first.first;
        int r1_y = pos.front().first.second;
        int r2_x = pos.front().second.first;
        int r2_y = pos.front().second.second;
        int t = time_dir.front().first;
        int d = time_dir.front().second;
        pos.pop();
        time_dir.pop();
        if((r1_x == N-1 && r1_y == N-1) || (r2_x == N-1 && r2_y == N-1)){
            answer = t;
            break;
        }
        //상하좌우 이동
        for(int i=0; i<4; i++){
            int r1_nx = r1_x + dx[i];
            int r1_ny = r1_y + dy[i];
            int r2_nx = r2_x + dx[i];
            int r2_ny = r2_y + dy[i];
            pair<int, int> r1_n = {r1_nx, r1_ny};
            pair<int, int> r2_n = {r2_nx, r2_ny};
            int nd = direction(r1_n, r2_n);
            if(r1_nx >= 0 && r1_nx < N && r1_ny >= 0 && r1_ny < N
               && r2_nx >= 0 && r2_nx < N && r2_ny >= 0 && r2_ny < N
               && board[r1_nx][r1_ny] == 0 && board[r2_nx][r2_ny] == 0
               && visit[r1_nx][r1_ny][nd] == 0){
                pos.push({r1_n, r2_n});
                time_dir.push({t+1, nd});
                visit[r1_nx][r1_ny][nd] = 1;
            }
        }
        //회전
        //로봇 1번 위치 회전
        for(int i=0; i<4; i++){
            int r1_rnx = r1_x + rotate_x[i];
            int r1_rny = r1_y + rotate_y[i];
            
             //올바른 회전인지 검증
            int a = abs(r1_rnx - r2_x) + abs(r1_rny - r2_y);
            if(abs(a) > 1) continue;

            int check_x, check_y;
            if(d == 1 || d == 3) {//가로 => 세로
                check_x = r1_x + check_hori_x[i];
                check_y = r1_y + check_hori_y[i];
            }else{// 세로 => 가로
                check_x = r1_x + check_vert_x[i];
                check_y = r1_y + check_vert_y[i];
            }
            
            //방향 계산
            int nd = direction({r1_rnx, r1_rny}, {r2_x, r2_y});
            
            if(r1_rnx >= 0 && r1_rnx < N && r1_rny >= 0 && r1_rny < N
               && board[r1_rnx][r1_rny] == 0 && board[check_x][check_y] == 0
               && visit[r1_rnx][r1_rny][nd] == 0){
                pos.push({{r1_rnx, r1_rny}, {r2_x, r2_y}});
                time_dir.push({t+1, nd});
                visit[r1_rnx][r1_rny][nd] = 1;
            }
        }
        //로봇 2번 위치 회전
        for(int i=0; i<4; i++){
            int r2_rnx = r2_x + rotate_x[i];
            int r2_rny = r2_y + rotate_y[i];
            
            //올바른 회전인지 검증
            int a = abs(r1_x - r2_rnx) + abs(r1_y - r2_rny);
            if(abs(a) > 1) continue;

            int check_x, check_y;
            if(d == 1 || d == 3) {//가로 => 세로
                check_x = r2_x + check_hori_x[i];
                check_y = r2_y + check_hori_y[i];
            }else{// 세로 => 가로
                check_x = r2_x + check_vert_x[i];
                check_y = r2_y + check_vert_y[i];
            }

            //방향 계산
            int nd = direction({r1_x, r1_y}, {r2_rnx, r2_rny});
            
            if(r2_rnx >= 0 && r2_rnx < N && r2_rny >= 0 && r2_rny < N
               && board[r2_rnx][r2_rny] == 0 && board[check_x][check_y] == 0
               && visit[r1_x][r1_y][nd] == 0){
                pos.push({{r1_x, r1_y}, {r2_rnx, r2_rny}});
                time_dir.push({t+1, nd});
                visit[r1_x][r1_y][nd] = 1;
            }
        }
        
    }
    
    return answer;
}
