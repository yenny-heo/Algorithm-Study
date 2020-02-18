//
//  main.cpp
//  BOJ17144_ByeFineDust
//
//  Created by 허예은 on 18/02/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
int map[51][51];
int diff[51][51];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main(){
    int R, C, T;
    cin>>R>>C>>T;
    bool ap = 0;
    int tx, ty, bx, by;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>map[i][j];
            //공기청정기
            if(!ap && map[i][j] == -1){
                tx = i; ty = j;
                ap = 1;
            }
            else if(ap && map[i][j] == -1){
                bx = i; by = j;
            }
        }
    }
    
    for(; T>0; T--){
        //먼지 확산
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(map[i][j] > 0){
                    int cnt = 0;
                    int dust = map[i][j] / 5;
                    for(int k=0; k<4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx>=0 && nx<R && ny>=0 && ny<C
                           && map[nx][ny] != -1){
                            diff[nx][ny] += dust;
                            cnt++;
                        }
                    }
                    diff[i][j] += map[i][j] - dust * cnt;
                }
            }
        }
        diff[tx][ty] = -1;
        diff[bx][by] = -1;
        //공기청정기 순환
        //위
        for(int i = tx-1; i>=0; i--){
            if(diff[i+1][0] != -1)
                diff[i+1][0] = diff[i][0];
            else
                diff[i][0] = 0;
        }
        for(int j=1; j<C; j++){
            diff[0][j-1] = diff[0][j];
        }
        for(int i=1; i<=tx; i++){
            diff[i-1][C-1] = diff[i][C-1];
        }
        for(int j=C-2; j>=0; j--){
            if(j == 0)
                diff[tx][j+1] = 0;
            else
                diff[tx][j+1] = diff[tx][j];
        }
        //아래
        for(int i = bx+1; i<R; i++){
            if(diff[i-1][0] != -1)
                diff[i-1][0] = diff[i][0];
            else
                diff[i][0] = 0;
        }
        for(int j=1; j<C; j++){
            diff[R-1][j-1] = diff[R-1][j];
        }
        for(int i=R-2; i>=bx; i--){
            diff[i+1][C-1] = diff[i][C-1];
        }
        for(int j=C-2; j>=0; j--){
            if(j == 0)
                diff[bx][j+1] = 0;
            else
                diff[bx][j+1] = diff[bx][j];
        }

        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                map[i][j] = diff[i][j];
                diff[i][j] = 0;
            }
        }
        
    }
    int result = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] != -1){
                result += map[i][j];
            }
        }
    }
    
    cout<<result<<"\n";
    
}
