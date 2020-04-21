//
//  main.cpp
//  BOJ15683_감시
//
//  Created by 허예은 on 20/04/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
int N, M, result = 999999;
void init(int map1[][9], int map2[][9]){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            map1[i][j] = map2[i][j];
        }
    }
}
void up(int map[][9], int x, int y){
    for(int i = x - 1; i >= 0; i--){
        if(map[i][y] == 6)
            break;
        else if(map[i][y] != 0)
            continue;
        
        map[i][y] = 7;
    }
}

void down(int map[][9], int x, int y){
    for(int i = x + 1; i < N; i++){
        if(map[i][y] == 6)
            break;
        else if(map[i][y] != 0)
            continue;
        
        map[i][y] = 7;
    }
}

void left(int map[][9], int x, int y){
    for(int j = y - 1; j >= 0; j--){
        if(map[x][j] == 6)
            break;
        else if(map[x][j] != 0)
            continue;
        
        map[x][j] = 7;
    }
}

void right(int map[][9], int x, int y){
    for(int j = y + 1; j < M; j++){
        if(map[x][j] == 6)
            break;
        else if(map[x][j] != 0)
            continue;
        
        map[x][j] = 7;
    }
}
int func(int map[][9], int x, int y){
    bool flag = 0;
    int cctv, curX, curY;
    for(int i = x; i<N; i++){
        for(int j = 0; j<M; j++){
            if((i == x && j <= y) || i < 0) continue;
            if(map[i][j] != 0 && map[i][j] != 6 && map[i][j] != 7){
                flag = 1;
                cctv = map[i][j];
                curX = i; curY = j;
                break;
            }
        }
        if(flag) break;
    }
    
    if(!flag){
        int num = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(map[i][j] == 0)
                    num++;
            }
        }
        if(num < result) result = num;
        return 0;
    }
    int map2[9][9];
    init(map2, map);
    
    switch(cctv){
        case 1:
            //하
            down(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            //우
            right(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            //상
            up(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            //좌
            left(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            break;
        case 2:
            //상하
            up(map2, curX, curY);
            down(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            //좌우
            left(map2, curX, curY);
            right(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            break;
        case 3:
            //상우
            up(map2, curX, curY);
            right(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            //우하
            right(map2, curX, curY);
            down(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            //하좌
            down(map2, curX, curY);
            left(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            //좌상
            left(map2, curX, curY);
            up(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            break;
        case 4:
            //상 빠짐
            down(map2, curX, curY);
            left(map2, curX, curY);
            right(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            //하 빠짐
            up(map2, curX, curY);
            left(map2, curX, curY);
            right(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            //좌 빠짐
            up(map2, curX, curY);
            down(map2, curX, curY);
            right(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            //우 빠짐
            up(map2, curX, curY);
            down(map2, curX, curY);
            left(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            break;
        case 5:
            up(map2, curX, curY);
            down(map2, curX, curY);
            left(map2, curX, curY);
            right(map2, curX, curY);
            func(map2, curX, curY);
            init(map2, map);
            break;
    }
    
    return 0;
}
int main(){
    cin>>N>>M;
    int map[9][9];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }
    func(map, -1, 0);
    cout<<result<<"\n";
}
