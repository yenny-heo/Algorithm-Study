//
//  main.cpp
//  APSS1
//
//  Created by 허예은 on 25/11/2019.
//  Copyright © 2019 허예은. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
int cost[1001];

int main() {
    int T;
    cin>>T;
    for(; T>0; T--){
        int N, L;
        cin>>N >>L;
        for(int i=0; i<N; i++){
            cin>>cost[i];
        }
        double result = 9999999;
        for(int i=L; i<=N; i++){
            for(int j=0; j<N - i + 1; j++){
                double sum = 0;
                for(int k = j; k < j + i; k++){
                    sum += cost[k];
                }
                if((sum/(double)i) < result){
                    result = sum/(double)i;
                }
            }
        }
        
        printf("%.12f\n", result);
        
    }
    return 0;
}
