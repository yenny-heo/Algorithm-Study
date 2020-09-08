#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    string s = "";
    for(int i=0; i<t*m; i++){
        string cur = "";
        int num = i;
        if(num == 0) cur = '0';
        while(num > 0){
            int rest = num % n;
            char a;
            if(rest < 10){
                a = rest + '0';
            }
            else{
                rest -= 10;
                a = rest + 'A';
            }
            cur = a + cur;
            num /= n;
        }
        s += cur;
    }
    
    for(int i=0; i<t*m; i+=m){
        answer += s[i+p-1];
    }
    
    return answer;
}
