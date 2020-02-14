//
//  main.cpp
//  BOJ12100_2048
//
//  Created by 허예은 on 05/02/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int board[21][21];
int simul[21][21];
queue <int> q[21];

int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>board[i][j];
        }
    }
    int result = 0;
    //brute force
    for(int a=0; a<4; a++){
        for(int b=0; b<4; b++){
            for(int c=0; c<4; c++){
                for(int d=0; d<4; d++){
                    for(int e=0; e<4; e++){
                        
                        //clone(initialize)
                        for(int i=0; i<N; i++){
                            for(int j=0; j<N; j++){
                                simul[i][j] = board[i][j];
                            }
                        }
                        
                        //order a, b, c, d, e 를 순차적으로 돌린다
                        for(int f=0; f<5; f++){
                            int ord;//순서
                            if(f == 0) ord = a;
                            else if(f == 1) ord = b;
                            else if(f == 2) ord = c;
                            else if(f == 3) ord = d;
                            else ord = e;
                            
                            switch(ord){
                                case 0://상
                                    for(int j=0; j<N; j++){
                                        for(int i=0; i<N; i++){
                                            if(simul[i][j]!=0){
                                                q[j].push(simul[i][j]);
                                                simul[i][j] = 0;
                                            }
                                        }
                                    }

                                    for(int j=0; j<N; j++){
                                        for(int i=0; i<N; i++){
                                            if(!q[j].empty()){
                                                int cur = q[j].front();
                                                q[j].pop();
                                                if(!q[j].empty() && cur == q[j].front()){
                                                    simul[i][j] = 2*cur;
                                                    q[j].pop();
                                                } else{
                                                    simul[i][j] = cur;
                                                }
                                            }
                                        }
                                    }

                                    break;
                                    
                                case 1://하
                                    for(int j=0; j<N; j++){
                                        for(int i=N-1; i>=0; i--){
                                            if(simul[i][j]!=0){
                                                q[j].push(simul[i][j]);
                                                simul[i][j] = 0;
                                            }
                                        }
                                    }

                                    for(int j=0; j<N; j++){
                                        for(int i=N-1; i>=0; i--){
                                            if(!q[j].empty()){
                                                int cur = q[j].front();
                                                q[j].pop();
                                                if(!q[j].empty() && cur == q[j].front()){
                                                    simul[i][j] = 2*cur;
                                                    q[j].pop();
                                                } else{
                                                    simul[i][j] = cur;
                                                }
                                            }
                                        }
                                    }

                                    break;
                                    
                                case 2://좌
                                    for(int i=0; i<N; i++){
                                        for(int j=0; j<N; j++){
                                            if(simul[i][j]!=0){
                                                q[i].push(simul[i][j]);
                                                simul[i][j] = 0;
                                            }
                                        }
                                    }
                                    
                                    for(int i=0; i<N; i++){
                                        for(int j=0; j<N; j++){
                                            if(!q[i].empty()){
                                                int cur = q[i].front();
                                                q[i].pop();
                                                if(!q[i].empty() && cur == q[i].front()){
                                                    simul[i][j] = 2*cur;
                                                    q[i].pop();
                                                } else{
                                                    simul[i][j] = cur;
                                                }
                                            }
                                        }
                                    }
                                    
                                    break;
                                    
                                case 3://우
                                    for(int i=0; i<N; i++){
                                        for(int j=N-1; j>=0; j--){
                                            if(simul[i][j]!=0){
                                                q[i].push(simul[i][j]);
                                                simul[i][j] = 0;
                                            }
                                        }
                                    }
                                    
                                    for(int i=0; i<N; i++){
                                        for(int j=N-1; j>=0; j--){
                                            if(!q[i].empty()){
                                                int cur = q[i].front();
                                                q[i].pop();
                                                if(!q[i].empty() && cur == q[i].front()){
                                                    simul[i][j] = 2*cur;
                                                    q[i].pop();
                                                } else{
                                                    simul[i][j] = cur;
                                                }
                                            }
                                        }
                                    }
                                    break;
                            }
                            
                        }
                        
                        for(int i=0; i<N; i++){
                            for(int j=0; j<N; j++){
                                if(simul[i][j] > result){
                                    result = simul[i][j];
                                }
                            }
                        }
                        
                    }
                }
            }
        }
    }
    
    cout<<result<<"\n";
}
