#include <iostream>
#include <queue>
#include <utility>
using namespace std;
bool map[50][50];
bool visit[50][50];
queue <pair<int, int>> q;
//상, 하, 좌, 우, 좌상, 우상, 좌하, 우하
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int w, h;
int result = 0;

pair<int, int> find(){
    int x = -1, y = -1;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(!visit[i][j] && map[i][j]){
                x = i; y = j;
                break;
            }
        }
        if(x!=-1) break;
    }
    return {x, y};
}

int main(){
    while(1){
        result = 0;
        cin>>w>>h;
        if(w == 0 && h == 0) break;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin>>map[i][j];
                visit[i][j] = 0;
            }
        }
        
        pair<int, int> start = find();
        if(start.first != -1){
            q.push({start});
            visit[start.first][start.second] = 1;
            result++;
        }
        
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<h && ny>=0 && ny<w
                   && !visit[nx][ny] && map[nx][ny]){
                    visit[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            if(q.empty()){
                pair<int, int> f = find();
                if(f.first == -1) break;
                q.push({f});
                visit[f.first][f.second] = 1;
                result++;
            }
        }
        cout<<result<<"\n";
        
    }
}
