//
//  main.cpp
//  BOJ2479_hammingDistance
//
//  Created by 허예은 on 28/11/2019.
//  Copyright © 2019 허예은. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

char input[1001][31];
vector <int> v[1001];
queue <int> q;
bool visit[1001];
int route[1001], result[1001];

int main(){
    int N, K, start, end;
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        for(int j=0; j<K; j++){
            cin>>input[i][j];
        }
    }
    cin >> start >> end;
    //calc hamming distance
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            int hd = 0;
            for(int k=0; k<K; k++){
                if(input[i][k] != input[j][k])
                    hd++;
            }
            if(hd == 1)
            {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }
    
    //BFS
    bool flag = 0;
    q.push(start);
    visit[start] = 1;
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == end){
            flag = 1;
            break;
        }
        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i];
            if(visit[next] == 0){
                q.push(next);
                visit[next] = 1;
                route[next] = cur;
            }
        }
    }
    
    //print route
    if(!flag) cout<< "-1" <<endl;
    else{
        int node = end, i = 0;
        while(1){
            result[i] = route[node];
            if(route[node] == start) break;
            node = route[node];
            i++;
        }
        
        for(int j = i; j>=0; j--){
            cout<<result[j]<<" ";
        }
        cout<<end<<endl;
    }
    
    
}
