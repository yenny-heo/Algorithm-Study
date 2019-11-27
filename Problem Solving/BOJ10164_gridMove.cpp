//
//  main.cpp
//  BOJ10164_gridMove
//
//  Created by 허예은 on 27/11/2019.
//  Copyright © 2019 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[16][16];
int main(){
    int N, M, K;
    cin>>N>>M>>K;
    dp[1][1] = 1;
    int startToPoint = 0, pointToEnd = 0;
    int pointX = (K - 1) / M + 1;
    int pointY = K % M;
    if(pointY == 0) pointY = M;
    //시작점 부터 포인트까지
    for(int i=1; i<=pointX; i++){
        for(int j=1; j<=pointY; j++){
            if(i == 1 && j == 1) dp[i][j] = 1;
            else    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    startToPoint = dp[pointX][pointY];
    
    if(K == 0) K = 1;
    int K_ = N * M - K + 1;
    int endX = (K_ - 1) / M + 1;
    int endY = K_ % M;
    if(endY == 0) endY = M;
    //포인트 부터 끝점까지
    for(int i=1; i<=endX; i++){
        for(int j=1; j<=endY; j++){
            if(i == 1 && j == 1) dp[i][j] = 1;
            else    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    pointToEnd = dp[endX][endY];
    
    if(startToPoint == 0) cout<<pointToEnd<<endl;
    else if (pointToEnd == 0) cout<<startToPoint<<endl;
    else
        cout<<startToPoint*pointToEnd<<endl;
}
