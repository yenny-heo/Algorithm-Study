#include <vector>
#include <queue>
#include <utility>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visit[101][101];
int N, M;

int dfs(int x, int y, int color, int cnt, vector<vector<int>> picture){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < M && ny >= 0 && ny < N &&
            picture[nx][ny] == color && visit[nx][ny] == 0){
            visit[nx][ny] = 1;
            cnt = dfs(nx, ny, color, cnt + 1, picture);
        }
    }
    return cnt;
}

pair<pair<int, int>, int> find(vector<vector<int>> picture){
    int x, y, color;
    bool flag = 0;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(picture[i][j] != 0 && visit[i][j] == 0){
                flag = 1;
                x = i; y = j;
                color = picture[i][j];
                break;
            }
        }
        if(flag) break;
    }
    if(!flag) return {{-1, -1}, -1};
    else return {{x, y}, color};
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    N = n;
    M = m;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            visit[i][j] = 0;
        }
    }
    
    pair<pair<int, int>, int> f = find(picture);
    int x = f.first.first;
    int y = f.first.second;
    int color = f.second;
    while(color != -1){
        visit[x][y] = 1;
        int a = dfs(x, y, color, 1, picture);
        if(a > max_size_of_one_area) max_size_of_one_area = a;
        number_of_area++;
        
        f = find(picture);
        x = f.first.first;
        y = f.first.second;
        color = f.second;
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
