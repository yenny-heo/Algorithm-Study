//
//  main.cpp
//  PRO_타일장식물
//
//  Created by 허예은 on 10/04/2020.
//  Copyright © 2020 허예은. All rights reserved.
//

#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long dpx[81], dpy[81];
    dpx[1] = 1; dpy[1] = 1;
    for(int i=2; i<=N; i++){
        if(dpx[i-1] > dpy[i-1]){
            dpx[i] = dpx[i-1];
            dpy[i] = dpx[i-1] + dpy[i-1];
        }
        else{
            dpx[i] = dpx[i-1] + dpy[i-1];
            dpy[i] = dpy[i-1];
        }
    }
    answer = (dpx[N] + dpy[N]) * 2;
    
    return answer;
}
