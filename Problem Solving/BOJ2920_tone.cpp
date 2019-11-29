//
//  main.cpp
//  BOJ2920_tone
//
//  Created by 허예은 on 29/11/2019.
//  Copyright © 2019 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
int main(){
    int up = 0, down = 0;
    for(int i=1; i<=8; i++){
        int t;
        cin>>t;
        if(t == i){
            up++;
        }else if(t == 9 - i){
            down++;
        }
    }
    if(up == 8) cout<<"ascending\n";
    else if(down == 8) cout<<"descending\n";
    else cout<<"mixed\n";
}
