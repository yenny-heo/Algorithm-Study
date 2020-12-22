#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;
int map[65][65];
bool visit[65][65];
queue <pair<int, int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void rotate(int len, int s){
    int map2[65][65];
    //90도 회전
    for(int i=0; i<len; i += s){
        for(int j=0; j<len; j += s){
            for(int x=0; x<s; x++){
                for(int y=0; y<s; y++){
                    map2[x+i][y+j] = map[s-1-y+i][x+j];
                }
            }
            
        }
    }
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            map[i][j] = map2[i][j];
        }
    }
}
void reduce(int len){
    int map2[65][65];
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            //인접해있는 얼음 계산
            int cnt = 0;
            for(int a=0; a<4; a++){
                int x = i + dx[a];
                int y = j + dy[a];
                if(x >= 0 && x < len && y >= 0 && y < len
                   && map[x][y] > 0){
                    cnt++;
                }
            }
            if(cnt < 3 && map[i][j] > 0){
                map2[i][j] = map[i][j] - 1;
            }
            else{
                map2[i][j] = map[i][j];
            }
        }
    }
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            map[i][j] = map2[i][j];
        }
    }
}

pair<int, int> find(int len){
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(visit[i][j] == 0 && map[i][j] > 0){
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main(){
    int N, Q;
    cin>>N>>Q;
    int len = pow(2, N);
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<Q; i++){
        int L;
        cin>>L;
        int s = pow(2, L);
        rotate(len, s);

        reduce(len);

    }
    
    //bfs
    int size = 0;
    while(1){
        pair<int, int> start = find(len);
        if(start.first == -1) break;
        int x = start.first;
        int y = start.second;
        visit[x][y] = 1;
        q.push({x, y});
        int cnt = 0;
        while(!q.empty()){
            int cx = q.front().first;
            int cy = q.front().second;
            cnt++;
            q.pop();
            for(int i=0; i<4; i++){
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx >= 0 && nx < len && ny >= 0 && ny < len
                   && visit[nx][ny] == 0 && map[nx][ny] > 0){
                    visit[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        if(cnt > size) size = cnt;
    }
    
    int result = 0;
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
           result += map[i][j];
        }
    }
    cout<<result<<"\n"<<size<<endl;
    
    
}
