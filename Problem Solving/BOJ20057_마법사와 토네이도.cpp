#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int result = 0;
int map[500][500];
//좌 하 우 상
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

vector<pair<pair<int,int>,int>> sand0;
vector<pair<pair<int,int>,int>> sand1;
vector<pair<pair<int,int>,int>> sand2;
vector<pair<pair<int,int>,int>> sand3;

void moving(int dir, int x, int y, int N){
    if(map[x][y] == 0) return;
    
    vector<pair<pair<int, int>, int>> sand;
    if(dir == 0) sand = sand0;
    else if(dir == 1) sand = sand1;
    else if(dir == 2) sand = sand2;
    else if(dir == 3) sand = sand3;
    
    int sum = 0;
    for(int i=0; i<sand.size(); i++){
        int mx = sand[i].first.first;
        int my = sand[i].first.second;
        int per = sand[i].second;
        
        int nx = x + mx;
        int ny = y + my;
        int add = map[x][y] * (float)per / 100;
        
        if(per == 0){//알파 위치의 경우, 남은 모래의 양 더하기
            add = map[x][y] - sum;
        }
        
        if(nx >= 0 && nx < N && ny >= 0 && ny < N){
            map[nx][ny] += add;
        }
        else{//판 밖으로 모래가 나간 경우
            result += add;
        }
        sum += add;
    }
    map[x][y] = 0;
}

int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }
    //모래 이동 비율: 왼쪽 기준
    sand0.push_back({{-1, 1}, 1});
    sand0.push_back({{1, 1}, 1});
    sand0.push_back({{-1, 0}, 7});
    sand0.push_back({{1, 0}, 7});
    sand0.push_back({{-2, 0}, 2});
    sand0.push_back({{2, 0}, 2});
    sand0.push_back({{-1, -1}, 10});
    sand0.push_back({{1, -1}, 10});
    sand0.push_back({{0, -2}, 5});
    sand0.push_back({{0, -1}, 0});
    
    for(int i=0; i<sand0.size(); i++){
        int x = sand0[i].first.first;
        int y = sand0[i].first.second;
        int per = sand0[i].second;
        
        sand1.push_back({{-y, -x}, per});//아래
        sand2.push_back({{-x, -y}, per});//오른쪽
        sand3.push_back({{y, x}, per});//위
        
    }
    
    //소용돌이
    int x = N/2, y = N/2;
    int num = 1, cnt = 0, dir = 0;
    bool flag = 0;
    while(1){
        for(int i=0; i<num; i++){
            //dir 방향으로 모래 이동
            x += dx[dir];
            y += dy[dir];
            if(x >= N || x < 0 || y >= N || y < 0){
                flag = 1;
                break;
            }
            moving(dir, x, y, N);
        }
        if(flag) break;
        cnt++;
        if(cnt >= 2){
            num++;
            cnt = 0;
        }
        dir = (dir + 1) % 4;
    }
    
    cout<<result<<"\n";
}
