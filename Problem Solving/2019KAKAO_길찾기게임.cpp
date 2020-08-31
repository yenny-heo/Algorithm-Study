#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> pre;
vector<int> post;
class Node{
public:
    int x;
    int y;
    int n;
    Node* left;
    Node* right;
};
bool cmp(vector<int> &a, vector<int> &b){
    if(a[1] == b[1]){
        return a[0] < b[0];
    }
    return a[1] > b[1];
}
void tree(Node* parent, Node* child){
    if(parent->x > child->x){
        if(parent->left == NULL)
            parent->left = child;
        else
            tree(parent->left, child);
    }
    else{
        if(parent->right == NULL)
            parent->right = child;
        else
            tree(parent->right, child);
    }
}

void preorder(Node* cur){
    if(cur != NULL){
        pre.push_back(cur->n);
        preorder(cur->left);
        preorder(cur->right);
    }
}
void postorder(Node* cur){
    if(cur != NULL){
        postorder(cur->left);
        postorder(cur->right);
        post.push_back(cur->n);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node*> v;
    for(int i=0; i<nodeinfo.size(); i++){
        nodeinfo[i].push_back(i+1);
    }
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    for(int i=0; i<nodeinfo.size(); i++){
        Node* node = new Node;
        node->x = nodeinfo[i][0];
        node->y = nodeinfo[i][1];
        node->n = nodeinfo[i][2];
        node->left = NULL;
        node->right = NULL;
        v.push_back(node);
    }
    
    for(int i=1; i<v.size(); i++){
        tree(v.front(), v[i]);
    }
    Node* root = v.front();
    //전위순회 root->left->right
    preorder(root);
    
    //후위순회 left->right->root
    postorder(root);
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}
