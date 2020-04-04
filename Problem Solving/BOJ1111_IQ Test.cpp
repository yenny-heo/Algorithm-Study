//
//  main.cpp
//  BOJ1111_IQ Test
//
//  Created by 허예은 on 04/04/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
int prob[51];
int flag = 0;

int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; i++)
    {
        cin>>prob[i];
    }
    int a, b;
    //해가 여러개인 경우
    if(N == 1 || (N == 2 && prob[0] != prob[1])){
        flag = 1;
    }
    //해가 있거나, 없는 경우
    else{
        if(prob[0] != prob[1] && N > 2){
            a = (prob[1] - prob[2])/(prob[0] - prob[1]);
            b = prob[1] - prob[0] * a;
        } else{
            a = 0;
            b = prob[1];
        }
        
        for(int i=0; i<N-1; i++){
            int cal = prob[i] * a + b;
            //해가 없는 경우
            if(prob[i+1] != cal){
                flag = 2;
                break;
            }
        }
    }
    
    //cout result
    if(flag == 1){
        cout<<'A'<<"\n";
    }
    else if(flag == 2){
        cout<<'B'<<"\n";
    }
    else{
        cout<< prob[N-1] * a + b<<"\n";
    }
}
