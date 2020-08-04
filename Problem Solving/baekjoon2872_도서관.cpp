
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    int result = 0;
    cin>>N;
    int book;
    vector<int> v;
    for(int i=0; i<N; i++){
        cin>>book;
        v.push_back(book);
    }
    int cur = N;
    for(int i=(int)v.size()-1; i>=0; i--){
        if(v[i] == cur){
            result++;
            cur -= 1;
        }
    }
    cout<<N-result<<"\n";
 
}
