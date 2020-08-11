#include <iostream>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;
char map[1501][1501];
int melt_map[1501][1501];
int visit[1501][1501];
queue <pair<int, int>> water;
queue<pair<int,int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int R, C, wx1, wy1, wx2 = 0, wy2 = 0;
    cin>>R>>C;
    bool flag = 0;
    int cnt = 0;
    char a;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>a;
            melt_map[i][j] = 0;
            if(a == '.') {
                water.push({i,j});
                map[i][j] = a;
                cnt++;
            }
            else if(a == 'X') map[i][j] = a;
            else if(a == 'L'){
                if(!flag){
                    wx1 = i; wy1 = j;
                    flag = 1;
                }else{
                    wx2 = i; wy2 = j;
                }
                water.push({i,j});
                map[i][j] = '.';
                cnt++;
            }
        }
    }
    for(int a=1; !water.empty(); a++){
        int icnt = 0;
        for(int i=0; i<cnt; i++){
            int cx = water.front().first;
            int cy = water.front().second;
            water.pop();
            for(int j=0; j<4; j++){
                int nx = cx + dx[j];
                int ny = cy + dy[j];
                if(nx>=0 && nx<R && ny>=0 && ny<C && map[nx][ny]=='X'){
                    melt_map[nx][ny] = a;
                    map[nx][ny] = '.';
                    water.push({nx,ny});
                    icnt++;
                }
            }
        }
        cnt = icnt;
    }
    
    bool meet;
    int result = 0;
    int vcnt = 0;
    int start = 0, end = R + C, mid;
    while(start <= end){
        meet = false;
        mid = (start + end) / 2;
        //initialize
        while(!q.empty()){
            q.pop();
        }
        q.push({wx1,wy1});
        visit[wx1][wy1] = vcnt + 1;
        //BFS
        while(!q.empty()){
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            if(cx == wx2 && cy == wy2){
                meet = true;
                result = mid;
                break;
            }
            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx>=0 && nx<R && ny>=0 && ny<C && visit[nx][ny] != vcnt+1 && melt_map[nx][ny] <= mid){
                    q.push({nx,ny});
                    visit[nx][ny] = vcnt+1;
                }
            }
        }
        if(meet){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
        vcnt++;
    }
    if(meet) result = mid;
    cout<<result<<endl;
}
