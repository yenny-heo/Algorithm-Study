#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define INF 9999999

vector <vector<pair<int, int>>> route;
priority_queue <pair<int, int>> pq;

int dist[20001];
bool visit[20001];


void dijkstra(int start, int V){
    
    pq.push({0, start});
    dist[start] = 0;
    visit[start] = 1;
    //갱신하기
    while(!pq.empty()){
        int weight = -pq.top().first;
        int cur = pq.top().second;
        visit[cur] = 1;
        pq.pop();
        
        for(int j=0; j<route[cur].size(); j++){
            int nxt = route[cur][j].first;
            int w = route[cur][j].second;
            if(!visit[nxt] && dist[nxt] > weight + w){
                dist[nxt] = weight + w;
                pq.push({-dist[nxt], nxt});
            }
            
        }
    }
    
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int V, E, K;
    cin>>V>>E>>K;

    vector<pair<int, int>> a;
    for(int i=0; i<=V; i++){
        route.push_back(a);
        dist[i] = INF;
    }
    
    for(int i=0; i<E; i++){
        int u, v, w;
        cin>>u>>v>>w;
        route[u].push_back({v, w});
    }
    
    dijkstra(K, V);
    
    for(int i=1; i<=V; i++){
        if(dist[i] == INF)
            cout<<"INF\n";
        else cout<<dist[i]<<"\n";
    }
    
}
