#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstdlib>
using namespace std;
vector<int> shot;

int least_gap(int a, int M){
    int lGap = 9999999;
    int start = 0;
    int end = M-1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(abs(a - shot[mid]) < lGap)
            lGap = abs(a - shot[mid]);
        if(shot[mid] == a){
            return 0;
        }
        else if(shot[mid] < a){
            start = mid + 1;
        }
        else if(shot[mid] > a){
            end = mid - 1;
        }
    }
    return lGap;
}

int main(){
    int M, N, L;
    cin>>M>>N>>L;
    for(int i=0; i<M; i++){
        int pos;
        cin>>pos;
        shot.push_back(pos);
    }
    sort(shot.begin(), shot.end());
    
    int result = 0;
    
    for(int i=0; i<N; i++){
        int x, y;
        cin>>x>>y;
        int least_gap_x = least_gap(x, M);
        if(least_gap_x + y <= L){
            result++;
        }
    }
    cout<<result<<"\n";

}
