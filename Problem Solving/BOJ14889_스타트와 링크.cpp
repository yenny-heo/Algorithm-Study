//
//  main.cpp
//  BOJ14888_연산자 끼워넣기
//
//  Created by 허예은 on 14/04/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int abil[21][21];
vector <int> team1;
vector <int> team2;
int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>abil[i][j];
        }
    }
    
    int min = pow(2, N/2) - 1;
    int max = pow(2, N) - pow(2, 2/N);
    
    int result = 9999;
    
    for(int i=min; i<max; i++){
        int start = 0;
        int link = 0;
        //팀 나누기
        int cur = i;
        for(int j=0; j<N; j++){
            int comp = cur & 1;
            if(comp == 1){
                team1.push_back(j);
            }else{
                team2.push_back(j);
            }
            cur = cur >> 1;
        }
        
        //반반씩 나뉜경우
        if(team1.size() == N/2 && team2.size() == N/2){
            for(int a=0; a<N/2; a++){
                for(int b=a+1; b<N/2; b++){
                    start += abil[team1[a]][team1[b]] + abil[team1[b]][team1[a]];
                }
            }
            for(int a=0; a<N/2; a++){
                for(int b=a+1; b<N/2; b++){
                    link += abil[team2[a]][team2[b]] + abil[team2[b]][team2[a]];
                }
            }
            
            if(abs(start-link)<result){
                result = abs(start-link);
            }
        }
        
        team1.clear();
        team2.clear();
    }
    cout<<result<<"\n";

}
