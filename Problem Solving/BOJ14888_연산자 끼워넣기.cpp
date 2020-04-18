
#include <iostream>
#include <math.h>
using namespace std;
int num[12];
int N;
int r_min = 1000000001;
int r_max = -1000000001;
void cal(int *oper, int M, int result){
    
    if(M == N){
        if(r_min > result) r_min = result;
        if(r_max < result) r_max = result;
    } else{
        if(oper[0] > 0){
            oper[0] -= 1;
            cal(oper, M + 1, result + num[M]);
            oper[0] += 1;
        }if(oper[1] > 0){
            oper[1] -= 1;
            cal(oper, M + 1, result - num[M]);
            oper[1] += 1;
            
        }if(oper[2] > 0){
            oper[2] -= 1;
            cal(oper, M + 1, result * num[M]);
            oper[2] += 1;
            
        }if(oper[3] > 0){
            oper[3] -= 1;
            cal(oper, M + 1, result / num[M]);
            oper[3] += 1;
            
        }
    }
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num[i];
    }
    int oper[4];
    for(int i=0; i<4; i++){
        cin>>oper[i];
    }
    cal(oper, 1, num[0]);
    
    cout<<r_max<<"\n"<<r_min<<"\n";
    return 0;
}

