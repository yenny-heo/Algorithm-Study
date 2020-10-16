#include<iostream>
#include<vector>
#include<utility>
using namespace std;
bool curve[101][101];
vector <pair<int, int>> v;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

//x,y: 시작점, a,b: 끝점, n:현재세대, g:도달해야할 세대
void addCurve(int y, int x, int b, int a, int n, int g){
    if(n >= g) {
        v.clear();
        return;
    }
    vector <pair<int, int>> next;
    int a_axis = -1, b_axis = -1;
    //90도 회전
    for(int i=0; i<v.size(); i++){
        int cy = v[i].first;
        int cx = v[i].second;
        int ny = b + cx - a;
        int nx = a - cy + b;
        next.push_back({ny, nx});
        curve[ny][nx] = 1;
        //끝점 갱신
        if(cy == y && cx == x){
            a_axis = nx;
            b_axis = ny;
        }
    }
    v.insert(v.end(), next.begin(), next.end());
    next.clear();
    addCurve(y, x, b_axis, a_axis, n+1, g);
}
int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        int x, y, d, g;
        cin>>x>>y>>d>>g;
        curve[y][x] = 1;
        curve[y+dy[d]][x+dx[d]]=1;
        v.push_back({y, x});
        v.push_back({y+dy[d], x+dx[d]});
        addCurve(y, x, y+dy[d], x+dx[d], 0, g);
        
    }
    
    int result = 0;
    
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(curve[i][j] && curve[i+1][j] && curve[i][j+1] && curve[i+1][j+1]){
                result++;
            }
        }
    }
    cout<<result<<"\n";
}
