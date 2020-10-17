#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
using namespace std;

int map[50][50];
int visit[50][50];
int unite[2500];
queue<pair<int,int>> q;
vector<int> unite_v;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int result = 0;

int main(){
    int N, L, R;
    cin>>N>>L>>R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }
    bool flag = 0;
    while(1){
        int uniteNum = 0;
        int cnt = 1;
        for(int sx=0; sx<N; sx++){
            for(int sy=0; sy<N; sy++){
                if(visit[sx][sy] == 0){
                    int popul = map[sx][sy];
                    int unite = 1;
                    q.push({sx, sy});
                    visit[sx][sy] = cnt;
                    
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int i=0; i<4; i++){
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            int gap = abs(map[nx][ny]-map[x][y]);
                            if(nx>=0 && nx<N && ny>=0 && ny<N
                               && visit[nx][ny] == 0 && gap >= L && gap <= R ){
                                q.push({nx, ny});
                                visit[nx][ny] = cnt;
                                popul += map[nx][ny];
                                unite++;
                            }
                        }
                    }
                    unite_v.push_back(popul/unite);
                    if(unite == 1){
                        uniteNum++;
                    }

                    if(uniteNum == N*N){
                        flag = 1;
                        break;
                    }
                    cnt++;
                }
                
            }
        }
        if(flag) break;
        
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                int cur = visit[i][j];
                map[i][j] = unite_v[cur-1];
                visit[i][j] = 0;
            }
        }
        unite_v.clear();
        result++;
    }
    
    cout<<result<<"\n";
}
