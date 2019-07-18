#include <iostream>
#include <algorithm>
using namespace std;

int arr[200001];
int x[100000];
int idx = 0;
int main(){
    int N;
    cin>>N;
    for(int i = 0; i < N; i ++)
    {
        cin >> x[i];
        
    }
    for(int i = 0; i < N; i ++)
    {
        
        if(x[i] > 0)
        {
            idx++;
            int cur = idx;
            arr[cur] = x[i];
            while(cur != 1 && arr[cur] > arr[cur/2])
            {
                int tmp = arr[cur];
                arr[cur] = arr[cur/2];
                arr[cur/2] = tmp;
                cur = cur/2;
            }
            
        }
        else if(x[i] == 0)
        {
            if(idx <= 0)
                cout<< 0 <<"\n";
            else
            {
                int cur = 0;
                cout<< arr[1] <<"\n";
                arr[1] = arr[idx];//최댓값 루트노드 삭제
                idx--;
                while(arr[cur] < arr[cur * 2] || arr[cur] < arr[cur * 2 + 1]){
                    if(arr[cur * 2] > arr[cur * 2 + 1])
                    {
                        int tmp = arr[cur * 2];
                        arr[cur * 2] = arr[cur];
                        arr[cur] = tmp;
                        cur = cur * 2;
                    }
                    else
                    {
                        int tmp = arr[cur * 2 + 1];
                        arr[cur * 2 + 1] = arr[cur];
                        arr[cur] = tmp;
                        cur = cur * 2 + 1;
                    }
                }
            }
        }
    }
}

