#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int land[10][10];
int add[10][10];
vector<int> tree[10][10];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int result = 0;
int main(){
    int N, M, K;
    cin>>N>>M>>K;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>add[i][j];
            land[i][j] = 5;
        }
    }
    int x, y, z;
    for(int i=0; i<M; i++){
        cin>>x>>y>>z;
        tree[x-1][y-1].push_back(z);
    }
    
    for(int year=0; year<K; year++){
        //봄 & 여름
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                //나이를 오름차순으로 정렬
                sort(tree[i][j].begin(), tree[i][j].end());
                int summer = 0;
                int death = -1;
                for(int k=0; k<tree[i][j].size(); k++){
                    //봄: 자신의 나이만큼 양분 먹기
                    if(land[i][j] >= tree[i][j][k]){
                        land[i][j] -= tree[i][j][k];
                        tree[i][j][k]++;
                    }
                    else{
                        summer += tree[i][j][k]/2;
                        if(death == -1)  death = k;
                    }
                }
                //양분이 없는 나무들은 죽음
                if(death != -1){
                    tree[i][j].erase(tree[i][j].begin()+death, tree[i][j].end());
                }
                //여름: 죽은 나무가 양분으로 추가
                land[i][j] += summer;
            }
        }
        //가을 & 겨울
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                for(int k=0; k<tree[i][j].size(); k++){
                    //가을: 나이가 5의 배수인 경우 주변 8칸에 나무 번식
                    if(tree[i][j][k] % 5 == 0){
                        for(int d=0; d<8; d++){
                            int nx = i + dx[d];
                            int ny = j + dy[d];
                            if(nx>=0 && nx<N && ny>=0 && ny<N){
                                tree[nx][ny].push_back(1);
                            }
                        }
                    }
                }
                //겨울: 양분 추가
                land[i][j] += add[i][j];
            }
        }
        
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            result += tree[i][j].size();
        }
    }
    cout<<result<<"\n";
}
