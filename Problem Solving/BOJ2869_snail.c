//
//  main.cpp
//  BOJ2869_snail
//
//  Created by 허예은 on 29/11/2019.
//  Copyright © 2019 허예은. All rights reserved.
//

#include<stdio.h>
int main(){
    int A, B, V;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &V);
    if(((V-B)%(A-B)) != 0)
        printf("%d", (V-B)/(A-B)+1);
    else
        printf("%d", (V-B)/(A-B));
}
