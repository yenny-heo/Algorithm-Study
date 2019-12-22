//
//  main.cpp
//  BOJ2438_star1
//
//  Created by 허예은 on 21/12/2019.
//  Copyright © 2019 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
char arr[3000][3000] = {{'*', '*', '*'},
    {'*', ' ', '*'},
    {'*', '*', '*'}
};
int N;
void func(int K){
    if(K != N){
        for(int i=0; i<3*K; i++){
            for(int j=0; j<3*K; j++){
                if(i >= K || j >= K){
                    if(i >= K && j >= K && i <= 2 * K - 1 && j <= 2 * K - 1)
                        arr[i][j] = ' ';
                    else    arr[i][j] = arr[i % K][j % K];
                }
            }
        }
        func(3 * K);
    }
}
int main(){
    cin>>N;
    func(3);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}
