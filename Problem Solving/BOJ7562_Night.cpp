//
//  main.cpp
//  BOJ7562_Night
//
//  Created by 허예은 on 28/01/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>
using namespace std;
bool visit[300][300];
queue <pair<pair<int, int>, int>> q;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int main(){
    int T, size, curX, curY, destX, destY;
    cin>>T;
    for(;T>0; T--){
        for(int i=0; i<300; i++){
            for(int j=0; j<300; j++)
                visit[i][j] = 0;
        }
        cin >> size >> curX >> curY >> destX >> destY;
        visit[curX][curY] = 1;
        q.push({{curX, curY}, 0});
        int result = 0;
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int t = q.front().second;
            q.pop();
            if(x == destX && y == destY){
                result = t;
                break;
            }
            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < size && ny >= 0 && ny < size && visit[nx][ny] == 0){
                    visit[nx][ny] = 1;
                    q.push({{nx, ny}, t + 1});
                }
            }
        }
        cout<<result<<endl;
        while(!q.empty()) q.pop();
    }
}
