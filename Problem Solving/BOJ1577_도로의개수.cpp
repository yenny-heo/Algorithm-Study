#include <iostream>
using namespace std;
bool horizontal[101][101];
bool vertical[101][101];
long long dp[101][101];
int main(){
    int N, M, K;
    cin>>N>>M>>K;
    for(int i=0; i<K; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        
        int x_gap = a - c;
        int y_gap = b - d;
        if(x_gap > 0 || y_gap > 0){
            //swap
            int x_tmp = a, y_tmp = b;
            a = c; b = d;
            c = x_tmp; d = y_tmp;
        }
        if(x_gap == 0) horizontal[a][b] = 1;
        else vertical[a][b] = 1;
    }
    
    dp[0][0] = 1;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=M; j++){
            //i-1, j
            if(i-1 >= 0 && vertical[i-1][j] == 0){
                dp[i][j] += dp[i-1][j];
            }
            //i, j-1
            if(j-1 >= 0 && horizontal[i][j-1] == 0){
                dp[i][j] += dp[i][j-1];
            }
        }
    }
    
    cout<<dp[N][M]<<"\n";
    
    
}
