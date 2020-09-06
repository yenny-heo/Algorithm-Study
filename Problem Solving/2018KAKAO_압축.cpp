#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    //A to Z 사전 추가
    for(int i=0; i<26; i++){
        string a = "";
        char c = 'A' + i;
        a += c;
        m.insert({a, i+1});
    }
    int key = 27;
    int len;
    for(int i=0; i < msg.length();){
        len = 0;
        int val;
        for(int j=1; j <= msg.length()-i; j++){
            string word = msg.substr(i, j);
            map<string, int>::iterator iter = m.find(word);
            if(iter != m.end()){//사전에 있는 경우
                val = iter->second;
                len++;
                if(i+len >= msg.length()){
                    answer.push_back(val);
                }
            }
            else{//사전에 없는 경우
                answer.push_back(val);
                m.insert({word, key});
                key++;
                break;
            }
        }
        i += len;
    }
    return answer;
}
