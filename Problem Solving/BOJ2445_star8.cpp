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
    for(int i=0; i<N-1; i++){
        for(int j=0; j<=i; j++){
            cout<<"*";
        }
        for(int j=i*2; j<N*2-2; j++){
            cout<<" ";
        }
        for(int j=0; j<=i; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            cout<<"*";
        }
        for(int j=0; j<2*i; j++){
            cout<<" ";
        }
        for(int j=i; j<N; j++){
            cout<<"*";
        }
        cout<<"\n";
    }
}
