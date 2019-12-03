//
//  main.cpp
//  BOJ4378_qwerty
//
//  Created by 허예은 on 03/12/2019.
//  Copyright © 2019 허예은. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
char qwerty[50] = {
    '`','1','2','3','4','5','6','7','8','9','0','-','=',
    'Q','W','E','R','T','Y','U','I','O','P','[',']','\\',
    'A','S','D','F','G','H','J','K','L',';','\'',
    'Z','X','C','V','B','N','M',',','.','/'};
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    while(1){
    getline(cin, input);
    if(input == "\0") break;
    char modi;
    for(int i=0; i<input.length(); i++){
        if(input[i] != ' ')
        {
            int j;
            for(j=0; j<47; j++){
                if(qwerty[j] == input[i])
                    break;
            }
            modi = qwerty[j-1];
        }
        else modi = ' ';
        cout << modi;
    }
        cout << "\n";
    }
}
