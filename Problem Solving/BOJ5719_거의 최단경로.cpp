#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 99999999

vector<pair<int, int>> v[501];
priority_queue<pair<int, int>> pq;
vector<int> route[501];

int dist[501];

void dijkstra(int start, int N){
    for(int i=0; i<N; i++){
        dist[i] = INF;
    }
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int weight = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        for(int i=0; i<v[cur_node].size(); i++){
            int next_node = v[cur_node][i].first;
            int w = v[cur_node][i].second;
            if(dist[next_node] > weight + w){
                dist[next_node] = weight + w;
                pq.push({-dist[next_node], next_node});
                //경로 저장
                route[next_node].clear();
                route[next_node].push_back(cur_node);
            }
            else if(dist[next_node] == weight + w){
                route[next_node].push_back(cur_node);
            }
            
        }
    }
}

void BFS(int S, int D){
    queue<int> q;
    q.push(D);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == S) continue;
        for(int i=0; i<route[cur].size(); i++){
            int nxt = route[cur][i];
            q.push(nxt);
            for(int j=0; j<v[nxt].size(); j++){
                if(v[nxt][j].first == cur){
                    v[nxt].erase(v[nxt].begin()+j);
                    break;
                }
            }
        }
    }
}

int main(){
    
    while(1){
        int N, M, S, D;
        cin>>N>>M;
        if(N == 0 && M == 0) break;
        
        cin>>S>>D;

        for(int i=0; i<N; i++){
            v[i].clear();
            route[i].clear();
        }
        
        int U, V, P;
        for(int i=0; i<M; i++){
            cin>>U>>V>>P;
            v[U].push_back({V, P});
        }
        dijkstra(S, N);
        
        BFS(S, D);
        
        dijkstra(S, N);
        
        if(dist[D] == INF) cout<<"-1\n";
        else cout<<dist[D]<<"\n";
    }
    
    
}
