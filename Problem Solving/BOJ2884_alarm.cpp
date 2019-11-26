//
//  main.cpp
//  baekjoon2884
//
//  Created by 허예은 on 26/11/2019.
//  Copyright © 2019 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int H, M;
    cin>> H >> M;
    if(M >= 45){ // 45분 보다 크거나 같은 경우
        M -= 45;
    }else{ // 45분 보다 작은 경우
        M = M + 60 - 45;
        
        if(H == 0){ // 0시인 경우
            H = 23;
        } else{
            H--;
        }
    }
    
    cout<< H<<" "<<M<<"\n";
}
