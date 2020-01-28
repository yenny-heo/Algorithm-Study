//
//  main.cpp
//  BOJ7569_Tomato
//
//  Created by 허예은 on 28/01/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
#include <utility>
#include <queue>

using namespace std;
int tomato[100][100][100];
bool visit[100][100][100];
//상 하 좌 우 위 아래
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
queue <pair<int, pair<int, int>>> q;
queue <int> day;
int main(){
    int M, N, H;
    cin>>M>>N>>H;
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin>>tomato[i][j][k];
                if(tomato[i][j][k] == 1){
                    visit[i][j][k] = 1;
                    q.push({i, {j, k}});
                    day.push(0);
                }
            }
        }
    }
    int result = 0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second.first;
        int z = q.front().second.second;
        int d = day.front();
        if(result < d){
            result = d;
        }
        q.pop();
        day.pop();
        for(int i=0; i<6; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nz = z+dz[i];
            if(nx >= 0 && nx < H && ny >= 0 && ny < N && nz >= 0 && nz < M
               && tomato[nx][ny][nz] == 0 && visit[nx][ny][nz] == 0){
                visit[nx][ny][nz] = 1;
                tomato[nx][ny][nz] = 1;
                q.push({nx, {ny, nz}});
                day.push(d+1);
            }
        }
        
    }
    bool flag = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(tomato[i][j][k] == 0){
                    flag = 1;
                    break;
                }
            }
        }
    }
    if(!flag) cout<<result<<"\n";
    else cout<<-1<<"\n";
}
