#include <iostream>
#include <algorithm>
using namespace std;
char map[1000][1000];
bool dp[1000][1000];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    int result = 0;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>map[i][j];
            if(map[i][j] == '1') {
                dp[i][j] = 1;
                result = 1;
            }
            else dp[i][j] = 0;
        }
    }
    
    for(int i=2; i <= min(n,m); i++){
        bool flag = false;
        for(int x=0; x<n; x++){
            for(int y=0; y<m; y++){
                if(x+1 < n && y+1 < m && dp[x][y] && dp[x][y+1]
                   && dp[x+1][y] && dp[x+1][y+1]){
                    result = i;
                    flag = true;
                    dp[x][y] = true;
                }else{
                    dp[x][y] = false;
                }
            }
        }
        if(!flag) break;
    }
    cout<<result*result<<"\n";
    
}
