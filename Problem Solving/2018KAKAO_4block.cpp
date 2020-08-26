#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<pair<int, int>> erase;
    bool flag;
    while(1){
        flag = 0;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].length(); j++){
                if(i+1<board.size() && j+1<board[i].length() && board[i][j] != '0'
                   && board[i][j] == board[i][j+1] && board[i][j] == board[i+1][j]
                   && board[i][j] == board[i+1][j+1]){
                    flag = 1;
                    erase.push_back({i,j});
                    erase.push_back({i,j+1});
                    erase.push_back({i+1,j});
                    erase.push_back({i+1,j+1});
                }
            }
        }
        if(!flag) break;
        
        for(int i=0; i<erase.size(); i++){
            int x = erase[i].first;
            int y = erase[i].second;
            if(board[x][y] != '0'){
                answer++;
            }
            board[x][y] = '0';
        }
        erase.clear();
        for(int i=board.size()-2; i>=0; i--){
            for(int j=0; j<board[i].length(); j++){
                int cur = i;
                int down = i+1;
                while(down<board.size() && board[down][j] == '0'){
                    board[down][j] = board[cur][j];
                    board[cur][j] = '0';
                    cur++;
                    down++;
                }
            }
        }
    }
    return answer;
}
