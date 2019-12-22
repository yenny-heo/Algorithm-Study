//
//  main.cpp
//  BOJ2438_star1
//
//  Created by 허예은 on 21/12/2019.
//  Copyright © 2019 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
char tree[3][5] ={
    {' ', ' ', '*', ' ', ' '},
    {' ', '*', ' ', '*', ' '},
    {'*', '*', '*', '*', '*'}
};
char arr[3100][7000];
int N;
void func(int K, int A){
    if(K == 3){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < A + 5; j++){
                if(j >= A)
                    arr[i][j] = tree[i][j-A];
                else arr[i][j] = ' ';
            }
        }
    }
    else{
        func(K/2, A + K/2);
        //복제
        for(int i = K/2; i<K; i++){
            for(int j = 0; j <= A+K-1; j++){
                if(j >= A && j < A+K-1)  {
                    if(!arr[i-K/2][j+K/2])
                        arr[i][j] = ' ';
                    else    arr[i][j] = arr[i - K/2][j + K/2];
                }
                else  arr[i][j] = ' ';
            }
        }
        for(int i= K/2; i<K; i++){
            for(int j = A+K; j < A+2*K-1; j++){
                arr[i][j] = arr[i - K/2][j - K/2];
            }
        }
    }
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<2*N-1; j++){
            arr[i][j] = ' ';
        }
    }
    if(N == 3){
        //tree 출력
        for(int i=0; i<3; i++){
            for(int j=0; j<5; j++){
                cout<<tree[i][j];
            }
            cout<<"\n";
        }
    }
    else{
        func(N, 0);
        for(int i=0; i<N; i++){
            for(int j=0; j<2*N-1; j++){
                cout<<arr[i][j];
            }
            cout<<"\n";
        }
    }
}
