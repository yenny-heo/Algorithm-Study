//
//  main.cpp
//  BOJ16236_아기상어
//
//  Created by 허예은 on 07/03/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int map[21][21];
bool visit[21][21];
queue<pair<pair<int, int>, int>> q;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main(){
    int N, x, y, size = 2, exp = 0, time = 0;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            if(map[i][j] == 9){
                x = i;
                y = j;
                map[i][j] = 0;
            }
        }
    }
    
    while(1){
        //initialize
        while(!q.empty()){
            q.pop();
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                visit[i][j] = 0;
            }
        }
        //BFS
        q.push({{x, y}, 0});
        visit[x][y] = 1;
        bool flag = 0;
        int fx = 99, fy = 99, fd = 9999;
        while(!q.empty()){
            int cx = q.front().first.first;
            int cy = q.front().first.second;
            int cnt = q.front().second;
            q.pop();
            //크기 작은 물고기 만난 경우
            if(map[cx][cy] != 0 && map[cx][cy] < size){
                if(fd >= cnt){
                    if(cx < fx || (cx == fx && cy < fy)){
                        fd = cnt;
                        fx = cx;
                        fy = cy;
                    }
                }

            }
            if(fd < cnt || (q.empty() && fd != 9999)){
                time += fd;
                exp++;
                x = fx; y = fy;
                if(exp >= size){
                    size++;
                    exp = 0;
                }
                map[x][y] = 0;
                flag = 1;
                break;
            }
            
            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx>=0 && nx<N && ny>=0 && ny<N && visit[nx][ny] == 0 && map[nx][ny] <= size){
                    q.push({{nx, ny}, cnt+1});
                    visit[nx][ny] = 1;
                    
                }
            }
        }
      
        if(flag == 0){
            break;
        }
        
    }
    
    cout<< time << "\n";
    
}
