#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<string>> cases;
set<string> result;

void dfs(int n, vector<string> sum){
    if(cases.size() <= n+1){
        sort(sum.begin(), sum.end());
        string one = "", cur = "";
        bool flag = 0;
        for(int i=0; i<sum.size(); i++){
            if(cur == sum[i]){
                flag = 1; break;
            }
            else{
                cur = sum[i];
                one += sum[i];
            }
        }
        if(!flag){
            result.insert(one);
        }
    }
    else{
        for(int i=0; i<cases[n+1].size(); i++){
            vector<string> a = sum;
            a.push_back(cases[n+1][i]);
            dfs(n+1, a);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    for(int i=0; i<banned_id.size(); i++){
        vector<string> oneCase;
        for(int j=0; j<user_id.size(); j++){
            if(banned_id[i].length() != user_id[j].length())
                continue;
            bool flag = 0;
            for(int k=0; k<banned_id[i].length(); k++){
                if(banned_id[i][k] != user_id[j][k] && banned_id[i][k] != '*'){
                    flag = 1; break;
                }
            }
            if(!flag){
                oneCase.push_back(user_id[j]);
            }
        }
        cases.push_back(oneCase);
    }
    
    for(int i=0; i<cases[0].size(); i++){
        vector<string> a;
        a.push_back(cases[0][i]);
        dfs(0, a);
    }
    answer = result.size();
    return answer;
}
