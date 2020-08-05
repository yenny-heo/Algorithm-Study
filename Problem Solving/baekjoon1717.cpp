#include<iostream>
#include<vector>
using namespace std;
class Node;
class Root;

class Node{
public:
    Node* nextPtr;
    Root* root;
};

class Root{
public:
    Node* head;
    Node* tail;
    int num;
};
vector<Node*> v;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin>>n>>m;
    for(int i=0; i<=n; i++){
        Root *r = new Root();
        Node *n = new Node();
        r->head = n;
        r->tail = n;
        r->num = 1;
        
        n->nextPtr = NULL;
        n->root = r;
        v.push_back(n);
    }
    
    for(int i=0; i<m; i++){
        int o, a, b;
        cin>>o>>a>>b;
        Root* aRoot = v[a]->root;
        Root* bRoot = v[b]->root;
        if(o == 0 && aRoot != bRoot){
            //크기가 작은걸 b에 놓기
            if(bRoot->num > aRoot->num){
                Root* tmp = aRoot;
                aRoot = bRoot;
                bRoot = tmp;
            }
            //b를 a로 합치는 작업
            aRoot->tail->nextPtr = bRoot->head;
            aRoot->tail = bRoot->tail;
            Node* cur = bRoot->head;
            while(cur != NULL){
                cur->root = aRoot;
                cur = cur->nextPtr;
            }
            aRoot->num += bRoot->num;
            delete bRoot;
        }
        else if(o == 1){
            if(aRoot == bRoot){
                cout<<"YES\n";
            }
            else cout<<"NO\n";
        }
    }
}
