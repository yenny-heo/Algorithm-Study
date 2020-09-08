#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
string toLower(string a){
    for(int i=0; i<a.length(); i++){
        if(a[i] >= 'A' && a[i] <= 'Z'){
            a[i] = a[i] - 'A' + 'a';
        }
    }
    return a;
}
bool compare(const vector<string> &v1, const vector<string> &v2){
    if(toLower(v1[0]) == toLower(v2[0])){
        return stoi(v1[1]) < stoi(v2[1]);
    }
    return toLower(v1[0]) < toLower(v2[0]);
    
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> v;
    for(int i=0; i<files.size(); i++){
        bool flag = 0;
        int ns = 0, ts = files[i].length();
        for(int j=0; j<files[i].length(); j++){
            if(!flag && files[i][j] >='0' && files[i][j] <= '9'){
                flag = 1;
                ns = j;
            }
            else if(flag && (files[i][j] <'0' || files[i][j] > '9' || j - ns >= 5)){
                ts = j;
                break;
            }
        }
        string head = files[i].substr(0, ns);
        string number = files[i].substr(ns, ts-ns);
        string tail = files[i].substr(ts);
        
        vector<string> file;
        file.push_back(head);
        file.push_back(number);
        file.push_back(tail);
        v.push_back(file);
    }
    stable_sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size(); i++){
        string result = v[i][0] + v[i][1] + v[i][2];
        answer.push_back(result);
    }
    return answer;
}
