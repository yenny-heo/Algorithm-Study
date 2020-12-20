#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
bool pillar[101][101];
bool bo[101][101];

bool compare(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        if(a[1] == b[1]){
            return a[2] < b[2];
        }
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

bool check(int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            //기둥 조건 체크
            if(pillar[i][j]){
                if(j == 0) ;//바닥 위에 있는 경우
                else if(pillar[i][j-1]) ;//다른 기둥 위에 있는 경우
                else if((i-1>=0 && bo[i-1][j]) || bo[i][j]) ;//보의 한쪽 끝 부분 위에 있는 경우
                else return false;//조건에 만족하지 않는 경우
            }
            
            //보 조건 체크
            if(bo[i][j]){
                //한쪽 끝 부분이 기둥 위에 있는 경우
                if(pillar[i][j-1] || (i+1 <= n && pillar[i+1][j-1])) ;
                //양쪽 끝 부분이 다른 보와 동시에 연결되어 있는 경우
                else if(i-1 >= 0 && i+1 < n && bo[i-1][j] && bo[i+1][j]) ;
                else return false;//조건에 만족하지 않는 경우
            }
        }
    }
    
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for(int i=0; i<build_frame.size(); i++){
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        
        switch(b){
            case 0://삭제
                switch(a){
                    case 0://기둥
                        pillar[x][y] = 0;
                        if(!check(n)) pillar[x][y] = 1;
                        break;
                        
                    case 1://보
                        bo[x][y] = 0;
                        if(!check(n)) bo[x][y] = 1;
                        break;
                }
                break;
            case 1://설치
                switch(a){
                    case 0://기둥
                        pillar[x][y] = 1;
                        if(!check(n)) pillar[x][y] = 0;
                        break;
                        
                    case 1://보
                        bo[x][y] = 1;
                        if(!check(n)) bo[x][y] = 0;
                        break;
                }
                break;
        }
    }
    
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            vector<int> v;
            if(pillar[i][j]){
                v.push_back(i);
                v.push_back(j);
                v.push_back(0);
                answer.push_back(v);
                v.clear();
            }
            if(bo[i][j]){
                v.push_back(i);
                v.push_back(j);
                v.push_back(1);
                answer.push_back(v);
                v.clear();
            }
            
        }
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}
