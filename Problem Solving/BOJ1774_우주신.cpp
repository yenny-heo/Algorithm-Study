#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
using namespace std;
vector <pair<int, int>> v;
vector <pair<double, pair<int, int>>> dist;
int root[1001];

int getRoot(int cur){
    if(root[cur] == cur)
        return cur;
    else return getRoot(root[cur]);
}
void unionRoot(int a, int b){
    int aRoot = getRoot(a);
    int bRoot = getRoot(b);
    root[aRoot] = bRoot;
}
bool cycle(int a, int b){
    int aRoot = getRoot(a);
    int bRoot = getRoot(b);
    if(aRoot == bRoot) return true;
    else return false;
}

int main() {
    int N, M;
    double result = 0;
    cin>>N>>M;
    int x, y;
    for(int i=1; i<=N; i++){
        cin>>x>>y;
        v.push_back({x, y});
        root[i] = i;
    }
    
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            double dis = pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2);
            dis = sqrt(dis);
            dist.push_back({dis, {i+1, j+1}});
        }
    }
    
    sort(dist.begin(), dist.end());
    
    for(int i=0; i<M; i++){
        cin>>x>>y;
        unionRoot(x, y);
    }
    
    for(int i=0; i<dist.size(); i++){
        double d = dist[i].first;
        int a = dist[i].second.first;
        int b = dist[i].second.second;
        if(!cycle(a, b)){
            unionRoot(a, b);
            result += d;
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<result<<endl;
}
