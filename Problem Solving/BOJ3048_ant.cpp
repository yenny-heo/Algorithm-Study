//
//  main.cpp
//  BOJ3048_ant
//
//  Created by 허예은 on 26/01/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
char ants[52];
bool dir[52];
int main(){
    int N1, N2, T;
    cin>>N1>>N2;
    for(int i=0; i<N1; i++){
        cin>>ants[N1-i-1];
        dir[N1-i-1] = 1;
    }
    for(int i=0; i<N2; i++){
        cin>>ants[N1+i];
        dir[N1+i] = 0;
    }
    cin>>T;
    while(T>0){
        for(int i=0; i<N1+N2-1; i++){
            if(dir[i] == 1 && dir[i+1] == 0){
                bool tmp = dir[i];
                dir[i] = dir[i+1];
                dir[i+1] = tmp;
                
                char tmp2 = ants[i];
                ants[i] = ants[i+1];
                ants[i+1] = tmp2;
                i++;
            }
        }
        
        T--;
    }
    for(int i=0; i<N1+N2; i++){
        cout<<ants[i];
    }
    cout<<endl;
}
