//
//  main.cpp
//  BOJ1051_숫자 정사각형
//
//  Created by 허예은 on 03/04/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
char rect[51][51];
int main(){
    int N, M;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>rect[i][j];
        }
    }
    int result = 1;
    int max = 0;
    if(N>M) max = M;
    else max = N;
    for(int r=2; r<=max; r++){
        bool flag = 0;
        for(int i=0; i<=N-r; i++){
            for(int j=0; j<=M-r; j++){
                if(rect[i][j] == rect[i][j+r-1]
                   && rect[i][j] == rect[i+r-1][j]
                   && rect[i][j] == rect[i+r-1][j+r-1]){
                    result = r*r;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
    }
    cout<<result<<"\n";
}
