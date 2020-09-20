#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int map[126][126];
int visit[126][126];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int main(){
    int T = 0;
    while(1){
        T++;
        int N;
        cin>>N;
        if(N == 0) break;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin>>map[i][j];
                visit[i][j] = 99999;
            }
        }
        queue <pair<int, pair<int, int>>> q;
        q.push({map[0][0], {0, 0}});
        visit[0][0] = map[0][0];
        
        while(!q.empty()){
            int curX = q.front().second.first;
            int curY = q.front().second.second;
            int curCost = q.front().first;
            q.pop();
            for(int i=0; i<4; i++){
                int nxtX = curX + dx[i];
                int nxtY = curY + dy[i];
                int nxtCost = curCost + map[nxtX][nxtY];
                if(nxtX >= 0 && nxtX < N && nxtY >= 0 && nxtY < N
                   && visit[nxtX][nxtY] > nxtCost){
                    q.push({nxtCost, {nxtX, nxtY}});
                    visit[nxtX][nxtY] = nxtCost;
                }
            }
        }
        cout<<"Problem "<<T<<": "<<visit[N-1][N-1]<<endl;
    }
}
