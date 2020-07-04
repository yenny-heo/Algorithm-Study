#include <string>
#include <vector>
using namespace std;

//true: 올바른 괄호 문자열
bool check(string s){
    int result = 0;
    bool flag = true;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            result++;
        }
        else result--;
        
        if(result < 0){
            flag = false;
            break;
        }
    }
    return flag;
}
//uv 분리
vector<string> makeUV(string s){
    vector <string> uv;
    string u, v;
    int result = 0;
    bool flag = true;
    
    for(int i=0; i < s.length(); i++){
        if(flag){
            if(s[i] == '('){
                u += s[i];
                result++;
            }
            else {
                u += s[i];
                result--;
            }
        }
        if(!flag){
            v += s[i];
        }
        
        if(result == 0) {
            flag = false;
        }
        
    }
    uv.push_back(u);
    uv.push_back(v);
    return uv;
}

string recurse(string s){
    if(s == "") return "";
    vector<string> uv = makeUV(s);
    string u = uv[0];
    string v = uv[1];
    if(check(u)){//u가 올바른 괄호 문자열인 경우
        return u + recurse(v);
    }
    else{
        string e = "";
        e += '(';
        e += recurse(v);
        e += ')';
        for(int i=0; i<u.length(); i++){
            if(i != 0 && i != u.length()-1){
                if(u[i] == '(')
                    e += ')';
                else e += '(';
            }
        }
        return e;
    }
}

string solution(string p) {
    string answer = "";
    answer = recurse(p);
    return answer;
}
