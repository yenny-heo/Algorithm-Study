//
//  main.cpp
//  BOJ2805_TreeCut
//
//  Created by 허예은 on 28/01/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
long tree[1000000];
int main(){
    int N, M;
    long end = 0;
    cin>>N>>M;
    for(int i=0; i<N; i++){
        cin>>tree[i];
        if(tree[i] > end) end = tree[i];
    }
    
    long start, mid;
    start = 0;
    
    long sum = 0;
    long result =0;
    while(start <= end){    // sum = M 이면 답이 나온거니까 sum != M이면서 이분탐색 다 할때까지 while문
        mid = (start + end) / 2;
        
        sum = 0;
        for(int i=0; i < N; i++){
            if(tree[i] > mid)
                sum += tree[i] - mid;
        }
        
        //가져가려고 하는 나무 길이 보다 합이 작을 때.
        if(sum >= M){                            // sum == M 인 경우?
            start = mid + 1;
            result = mid;
        }
        //가져가려고 하는 나무 길이 보다 합이 클 때.
        else {
            end = mid - 1;
        }
    }
    
    cout<< result <<endl;
}
