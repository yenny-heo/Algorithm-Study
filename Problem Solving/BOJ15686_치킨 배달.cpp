#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<stdlib.h>
#define INF 9999999
using namespace std;
int map[50][50];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector <pair<int,int>> chicken;
vector <pair<int,int>> home;
int result = INF;
int N, M;

int calDist(){
    int distSum = 0;
    for(int i=0; i<home.size(); i++){
        if(distSum >= result) return result;
        int x = home[i].first;
        int y = home[i].second;
        int min = INF;
        for(int j=0; j<chicken.size(); j++){
            int cx = chicken[j].first;
            int cy = chicken[j].second;
            if(map[cx][cy] == 2 && abs(x-cx) + abs(y-cy) < min){
                min = abs(x-cx) + abs(y-cy);
            }
        }
        distSum += min;
    }
    return distSum;
}

void deleteChicken(int num, int next){
    if(num == chicken.size() - M){
        int distSum = calDist();
        if(distSum < result) result = distSum;
        return;
    }
    else if(num > chicken.size() - M) return;
    
    for(int i=next; i<chicken.size(); i++){
        int x = chicken[i].first;
        int y = chicken[i].second;
        map[x][y] = 0;
        deleteChicken(num+1, i+1);
        map[x][y] = 2;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            if(map[i][j] == 1){
                home.push_back({i, j});
            }
            else if(map[i][j] == 2){
                chicken.push_back({i, j});
            }
        }
    }
    deleteChicken(0, 0);
    
    cout<<result<<"\n";
    
}
