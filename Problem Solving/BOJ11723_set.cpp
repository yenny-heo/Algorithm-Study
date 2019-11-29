//
//  main.cpp
//  BOJ11723_set
//
//  Created by 허예은 on 29/11/2019.
//  Copyright © 2019 허예은. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int S = 0, M, x;
    cin>>M;
    char oper[7];
    for(;M>0; M--){
        cin>>oper;
        if(!strcmp(oper, "add")){
            cin>>x;
            int y = 1 << x;
            S = S | y;
        } else if(!strcmp(oper, "remove")){
            cin>>x;
            int y = 1 << x;
            int z = y ^ 0b111111111111111111111;
            S = S & z;
        } else if(!strcmp(oper, "check")){
            cin>>x;
            int y = 1 << x;
            if((y & S) ==  0) cout<<"0\n";
            else cout<<"1\n";
        } else if(!strcmp(oper, "toggle")){
            cin>>x;
            int y = 1 << x;
            if((y & S) == 0) S = S | y;
            else{
                int z = y ^ 0b111111111111111111111;
                S = S & z;
            }
        } else if(!strcmp(oper, "all")){
            S = 0b111111111111111111111;
        } else if(!strcmp(oper, "empty")){
            S = 0;
        }
    }
}
