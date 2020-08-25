#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int roundScore[3];
    int round = 0;
    for(int i=0; i<dartResult.length(); i++){
        int score = 0;
        if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
            if(dartResult[i-2] == '1'){
                score = 10;
            }
            else{
                score = dartResult[i-1] - '0';
            }
            if(dartResult[i] == 'S') roundScore[round] = score;
            else if(dartResult[i] == 'D') roundScore[round] = pow(score, 2);
            else if(dartResult[i] == 'T') roundScore[round] = pow(score, 3);
            if(dartResult[i+1] == '*'){
                if(round-1 >= 0) roundScore[round-1] *= 2;
                roundScore[round] *= 2;
            }
            else if(dartResult[i+1] == '#'){
                roundScore[round] *= -1;
            }
            
            round++;
        }
    }
    answer = roundScore[0] + roundScore[1] + roundScore[2];
    return answer;
}
