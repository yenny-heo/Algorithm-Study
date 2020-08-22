#include <iostream>
#include <stack>
#include <utility>
using namespace std;
int arr[500000];
int result[500000];
stack <pair<int, int>> s;
int main() {
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    s.push({arr[N-1], N-1});
    for(int i=N-2; i>=0; i--){
        while(!s.empty()){
            int cur = s.top().first;
            if(cur < arr[i]){
                int num = s.top().second;
                result[num] = i+1;
                s.pop();
            }
            else break;
        }
        s.push({arr[i], i});
    }
    for(int i=0; i<N; i++){
        cout<<result[i]<<" ";
    }
}
