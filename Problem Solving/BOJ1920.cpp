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
int A[100000];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    sort(A, A+N);
    cin>>M;
    int a;
    for(int i=0; i<M; i++){
        int left = 0, mid = N/2, right = N-1;
        cin>>a;
        bool flag = 0;
        while(left - right <= 0){
            if(A[mid] == a) {
                flag = 1;
                break;
            }
            else if(A[mid] >= a){
                right = mid - 1;
                mid = (left + right)/2;
            }
            else{
                left = mid + 1;
                mid = (left + right)/2;
            }
        }
        if(flag) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
    
}
