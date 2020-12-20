#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int map[101][101];
bool visit[101][101][4];
queue<pair<int, int>> pos;
queue<pair<int, int>> dir_num;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(){
    int M, N;
    cin>>M>>N;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }
    int start_x, start_y, start_d, dest_x, dest_y, dest_d;
    cin>>start_x>>start_y>>start_d>>dest_x>>dest_y>>dest_d;
    
    visit[start_x - 1][start_y - 1][start_d - 1] = 1;
    pos.push({start_x - 1, start_y - 1});
    dir_num.push({start_d - 1, 0});
    
    int result = 0;
    
    while(!pos.empty()){
        int curX = pos.front().first;
        int curY = pos.front().second;
        int dir = dir_num.front().first;
        int num = dir_num.front().second;
        pos.pop();
        dir_num.pop();
        
        if(curX == dest_x - 1 && curY == dest_y - 1 && dir == dest_d - 1){
            result = num;
            break;
        }
        
        //1, 2, 3칸 이동
        for(int i=1; i<=3; i++){
            int nextX = curX + dx[dir] * i;
            int nextY = curY + dy[dir] * i;
            if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N
               && visit[nextX][nextY][dir] == 0 && map[nextX][nextY] == 0){
                visit[nextX][nextY][dir] = 1;
                pos.push({nextX, nextY});
                dir_num.push({dir, num + 1});
            }
            else if(nextX >= 0 && nextX < M && nextY >= 0 && nextY < N
                    && map[nextX][nextY] == 1) break;
        }
        //90도 회전
        if(dir == 0 || dir == 1){
            for(int i=2; i<=3; i++){
                if(visit[curX][curY][i] == 0){
                    visit[curX][curY][i] = 1;
                    pos.push({curX, curY});
                    dir_num.push({i, num + 1});
                }
            }
        }
        else if(dir == 2 || dir == 3){
            for(int i=0; i<=1; i++){
                if(visit[curX][curY][i] == 0){
                    visit[curX][curY][i] = 1;
                    pos.push({curX, curY});
                    dir_num.push({i, num + 1});
                }
            }
        }
    }
    cout<<result<<"\n";
    
}
