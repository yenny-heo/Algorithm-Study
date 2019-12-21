//
//  main.cpp
//  BOJ2438_star1
//
//  Created by 허예은 on 21/12/2019.
//  Copyright © 2019 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        for(int j=N-i; j>0; j--){
            cout<<"*";
        }
        cout<<"\n";
    }
}
