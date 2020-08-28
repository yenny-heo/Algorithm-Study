#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int M = key.size();
    int N = lock.size();
    bool flag = 1;
    int rotate[20][20];
    int r = 0;
    while(r<4){
        for(int a=-(M-1); a<N; a++){
            for(int b=-(M-1); b<N; b++){
                flag = 1;
                for(int i=0; i<N; i++){
                    for(int j=0; j<N; j++){
                        if(i-a>=0 && i-a<M && j-b>=0 && j-b<M){
                            if(key[i-a][j-b] + lock[i][j] != 1){
                                flag = 0; break;
                            }
                        }
                        else if(lock[i][j] == 0){
                            flag = 0; break;
                        }
                    }
                    if(!flag) break;
                }

                if(flag){
                    answer = true; break;
                }
            }
            if(flag) break;
        }
        if(flag) break;
        
        for(int i=0; i<M; i++){
            for(int j=0; j<M; j++){
                rotate[i][j] = key[M-j-1][i];
            }
        }

        for(int i=0; i<M; i++){
            for(int j=0; j<M; j++){
                key[i][j] = rotate[i][j];
            }
        }
        
        r++;
    }
    
    
    if(!flag) answer = false;
    
    return answer;

}
