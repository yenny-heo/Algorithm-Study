//
//  main.cpp
//  BOJ1939_Limit
//
//  Created by 허예은 on 03/02/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
vector <pair<int, int>> v[10001];
queue <int> q;
int main(){
    int N, M;
    cin>>N>>M;
    int A, B, C;
    int start = 1000000001, end = 0, mid = 0;
    for(int i=0; i<M; i++){
        cin>>A>>B>>C;
        v[A].push_back({B, C});
        v[B].push_back({A, C});
        if(C < start) start = C;
        if(C > end) end = C;
    }
    
    int P, Q;
    cin>>P>>Q;
    int save = 0;
    while(start <= end){
        mid = (start + end) / 2;
        bool visit[10001] = { 0 }; // initialize
        q.push(P);
        visit[P] = 1;
        //BFS
        while(!q.empty()){
            int cur = q.front(); // current node
            q.pop();
            for(int i=0; i<v[cur].size(); i++){
                int nxt = v[cur][i].first;  // next node
                int lmt = v[cur][i].second; // weight limit
                if(visit[nxt] == 0 && lmt >= mid){
                    visit[nxt] = 1;
                    q.push(nxt);
                }
            }
        }
        
        if(visit[Q] == 1){
            start = mid + 1;
            save = mid;
        }else{
            end = mid - 1;
        }
    }
    
    cout<<save<<"\n";
    
}
