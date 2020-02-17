//
//  main.cpp
//  BOJ14890_runway
//
//  Created by 허예은 on 17/02/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
using namespace std;
int map[101][101];
int main(){
    int N, L;
    cin>>N>>L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
        }
    }
    int result = 0;
    
    for(int i=0; i<N; i++){
        int cnt = 1;
        bool flag = 0;
        for(int j=1; j<N; j++){
            if(map[i][j-1] == map[i][j]){
                cnt++;
            }
            else if(map[i][j-1] == map[i][j] + 1){//내려가는 경사로
                for(int k=1; k<L; k++){
                    if(map[i][j] != map[i][j+k]){
                        flag = 1;
                        break;
                    }
                }
                j += L-1;
                cnt = 0;
            }
            else if(map[i][j-1] == map[i][j] - 1){//올라가는 경사로
                if(cnt < L){
                    flag = 1;
                    break;
                }
                cnt = 1;
            }
            else{//2칸 이상 차이나는 경우
                flag = 1;
                break;
            }
            
            if(flag) break;
        }
        if(!flag)
            result ++;
        
    }
    for(int j=0; j<N; j++){
        int cnt = 1;
        bool flag = 0;
        for(int i=1; i<N; i++){
            if(map[i-1][j] == map[i][j]){
                cnt++;
            }
            else if(map[i-1][j] == map[i][j] + 1){//내려가는 경사로
                for(int k=1; k<L; k++){
                    if(map[i][j] != map[i+k][j]){
                        flag = 1;
                        break;
                    }
                }
                i += L-1;
                cnt = 0;
            }
            else if(map[i-1][j] == map[i][j] - 1){//올라가는 경사로
                if(cnt < L){
                    flag = 1;
                    break;
                }
                cnt = 1;
            }
            else{//2칸 이상 차이나는 경우
                flag = 1;
                break;
            }
            if(flag) break;
            
        }
        if(!flag)
            result ++;
    }
    
    cout<<result<<"\n";
}
