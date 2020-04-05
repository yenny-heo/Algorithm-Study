//
//  main.cpp
//  BOJ1057_토너먼트
//
//  Created by 허예은 on 05/04/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int N, A, B;
    cin>>N>>A>>B;
    int round = 1;
    int a, b;
    while(1){
        if(A < B) {
            a = A; b = B;
        }
        else {
            a = B; b = A;
        }
        if(a % 2 == 1 && b == a + 1)
            break;
        
        A = (A+1)/2;
        B = (B+1)/2;
        round++;
    }
    cout<<round<<"\n";
}
