//
//  main.cpp
//  BOJ4179_Fire
//
//  Created by 허예은 on 28/01/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
#include <utility>
#include <queue>

using namespace std;
char maze[1000][1000];
queue <pair<pair<int,int>, int>> q;
queue <pair<pair<int, int>, int>> fire;
bool Jvisit[1000][1000];
bool Fvisit[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main(){
    int R, C;
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>maze[i][j];
            if(maze[i][j] == 'J'){
                Jvisit[i][j] = 1;
                q.push({{i,j}, 0});
                maze[i][j] = '.';
            }
            else if(maze[i][j] == 'F'){
                Fvisit[i][j] = 1;
                fire.push({{i, j}, 0});
            }
        }
    }
    int cur = 0;
    int flag = 0;
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        if(t > cur){//시간 증가하면
            cur = t;
            while(!fire.empty()){//불 이동
                int fx = fire.front().first.first;
                int fy = fire.front().first.second;
                int ft = fire.front().second;
                if(ft == t) break; //현재 시간까지만 불 번짐
                fire.pop();
                for(int i=0; i<4; i++){
                    int fnx = fx+dx[i];
                    int fny = fy+dy[i];
                    if(fnx >= 0  && fnx < R && fny >= 0 && fny < C
                       && Fvisit[fnx][fny] == 0 && maze[fnx][fny] != '#'){
                        Fvisit[fnx][fny] = 1;
                        maze[fnx][fny] = 'F';
                        fire.push({{fnx, fny}, ft + 1});
                    }
                }
            }
        }
        q.pop();
        //지훈이 위치에 불이 붙었다면, break
        if(maze[x][y] == 'F'){
            //nothing
        }
        
        //지훈이가 맵 끝까지 도달했다면, break
        else if(x == R-1 || y == C-1 || x == 0 || y == 0){
            flag = 2;
            break;
        }
        else{
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>= 0 && nx < R && ny >=0 && ny <C
                   && Jvisit[nx][ny] == 0 && maze[nx][ny] == '.'){
                    Jvisit[nx][ny] = 1;
                    q.push({{nx, ny}, t+1});
                }
            }
        }
    }
    if(flag == 2) cout<<cur+1<<"\n";
    else cout<<"IMPOSSIBLE\n";
}
