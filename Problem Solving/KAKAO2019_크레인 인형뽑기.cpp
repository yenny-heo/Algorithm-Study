//
//  main.cpp
//  KAKAO2019_크레인 인형뽑기
//
//  Created by 허예은 on 03/04/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int bucket[1001];
    int pnt = 0;
    for(int i=0; i<moves.size(); i++){
        int pos = moves[i] - 1;
        for(int j=0; j<board[0].size(); j++){
            if(board[j][pos] != 0){
                bucket[pnt] = board[j][pos];
                board[j][pos] = 0;
                pnt++;
                break;
            }
        }
        if(pnt >= 2 && bucket[pnt-1] == bucket[pnt-2]){
            bucket[pnt-1] = 0;
            bucket[pnt-2] = 0;
            pnt = pnt - 2;
            answer += 2;
        }
    }
    return answer;
}
