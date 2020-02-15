//
//  main.cpp
//  BOJ14503_Robot
//
//  Created by 허예은 on 15/02/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
int map[51][51];
bool visit[51][51];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
    int N, M, r, c, d;
    cin>>N>>M>>r>>c>>d;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    int cx = r, cy = c;
    int nx, ny;
    bool flag = 0;
    int result = 0;
    while(!flag){
        visit[cx][cy] = 1;
        result++;
        
        int cd = d;
        
        if(d == 0) d = 3;
        else d -= 1;
        
        nx = cx + dx[d];
        ny = cy + dy[d];
        
        int cnt = 0;
        //왼쪽 방향 탐색
        while(nx < 0 || nx >= N || ny < 0 || ny >= M
              || map[nx][ny] == 1 || visit[nx][ny] == 1){
            
            if(d == 0) d = 3;
            else d -= 1;
            
            nx = cx + dx[d];
            ny = cy + dy[d];
            cnt++;
            //후진
            if(cnt >= 4){
                d = cd; //처음 방향으로
                if(d >= 2) d -= 2;
                else d += 2;
                cx = cx + dx[d];
                cy = cy + dy[d];
                nx = cx;
                ny = cy;
                cnt = 0;
                d = cd; //바라보는 방향 유지
                
                //후진도 안되는 경우
                if(cx < 0 || cx >= N || cy < 0 || cy >= M
                   || map[cx][cy] == 1){
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1) break;
        
        //한칸 전진
        cx = nx;
        cy = ny;
        
    }
    cout<<result<<"\n";
}
