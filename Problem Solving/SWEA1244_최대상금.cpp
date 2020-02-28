//
//  main.cpp
//  SWEA1244_최대상금
//
//  Created by 허예은 on 24/02/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;
bool visit [1000000][10];
queue <pair<int, int>> q;
int main(){
    int T;
    cin>>T;
    for(int k=1; k<=T; k++){
        int num, cnt;
        cin>>num>>cnt;
        //initialize
        for(int i=0; i<num; i++){
            for(int j=0; j<cnt; j++){
                visit[i][j] = 0;
            }
        }
        //자릿수 구하기
        int n = num;
        int len = 0;
        while(n != 0){
            n /= 10;
            len++;
        }
        //BFS
        int result = 0;
        q.push({num, cnt});
        visit[num][cnt] = 1;
        while(!q.empty()){
            int curN = q.front().first;
            int curC = q.front().second;
            q.pop();
            
            for(int i=0; i<len-1; i++){
                int tmp1 = curN / (int)pow(10, i) % 10;
                for(int j=i+1; j<len; j++){
                    int tmp2 = curN / (int)pow(10, j) % 10;
                    int nxtN = curN - (tmp1 * (int)pow(10, i)) - (tmp2 * (int)pow(10, j))
                                    + (tmp1 * (int)pow(10, j)) + (tmp2 * (int)pow(10, i));
                    
                    if(visit[nxtN][curC-1] == 0 && curC - 1 > 0){
                        visit[nxtN][curC-1] = 1;
                        q.push({nxtN, curC-1});
                    }
                    if(curC - 1 == 0){
                        if(result < nxtN)
                            result = nxtN;
                    }
                }
            }
            
        }
        cout<<"#"<<k<<" "<<result<<"\n";
    }
}
