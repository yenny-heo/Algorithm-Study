//
//  main.cpp
//  BOJ5549_Planet
//
//  Created by 허예은 on 27/01/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
char map[1001][1001];
int dpJ[1001][1001];
int dpO[1001][1001];
int dpI[1001][1001];
int J[1001][1001];
int O[1001][1001];
int I[1001][1001];
int main(){
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int M, N, K;
    cin>>M>>N>>K;
    for(int i=1; i<=M; i++){
        int rowJ=0, rowO=0, rowI=0;
        for(int j=1; j<=N; j++){
            cin>>map[i][j];
            if(map[i][j] == 'J')
                rowJ++;
            else if(map[i][j] == 'O')
                rowO++;
            else
                rowI++;
            
            dpJ[i][j] = dpJ[i-1][j] + rowJ;
            dpO[i][j] = dpO[i-1][j] + rowO;
            dpI[i][j] = dpI[i-1][j] + rowI;
                
        }
    }
    
    
    for(int i=0; i<K; i++){
        int a, b, c, d;
        cin>> a>>b>>c>>d;
        int rJ = dpJ[c][d] - dpJ[a-1][d] - dpJ[c][b-1] + dpJ[a-1][b-1];
        int rO = dpO[c][d] - dpO[a-1][d] - dpO[c][b-1] + dpO[a-1][b-1];
        int rI = dpI[c][d] - dpI[a-1][d] - dpI[c][b-1] + dpI[a-1][b-1];
            
        cout<<rJ<<" "<<rO<<" "<<rI<<"\n";
    }
    
}
