#include <string>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int N = relation[0].size();
    vector<string> comp;
    vector<int> v;
    for(int i=1; i<=pow(2,N)-1; i++){
        for(int j=0; j<relation.size(); j++){
            string splice = "";
            int cur = i;
            int k=0;
            while(cur!=0){
                if(cur%2 == 1){
                    splice += relation[j][k];
                }
                cur /= 2;
                k++;
            }
            comp.push_back(splice);
        }
        
        //유일성 검사
        bool flag = 0;
        for(int p=0; p<comp.size(); p++){
            for(int q=p+1; q<comp.size(); q++){
                if(comp[p] == comp[q]){
                    flag = 1; break;
                }
            }
            if(flag) break;
        }
        comp.clear();
        if(!flag){//유일성 만족하는 경우
            //최소성 검사
            bool flag2 = 0;
            for(int j=0; j<v.size(); j++){
                if((v[j] | i) == i){
                    flag2 = 1;
                    break;
                }
            }
            if(!flag2) {//최소성 만족하는 경우
                v.push_back(i);
            }
        }
    }
    answer = v.size();
    return answer;
}
