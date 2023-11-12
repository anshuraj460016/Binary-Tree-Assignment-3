#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node*left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void leftview(Node *root,int &maxLevel,int currLevel,vector<int>&ans){
    if(root==NULL) return;
  if(maxLevel <currLevel){
    maxLevel=currLevel;
    ans.push_back(root->val);
  }
  leftview(root->left,maxLevel,currLevel+1,ans);
  leftview(root->right,maxLevel,currLevel+1,ans);
}



int main(){
    Node*a=new Node(1);
    Node*b=new Node(2);
    Node*c=new Node(3);
    Node*d=new Node(4);
    Node*e=new Node(5);
    Node*f=new Node(6);
    Node*g=new Node(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
 
    vector<int>ans;
    int maxLevel=-1;
    int currLevel=0;
    leftview(a,maxLevel,currLevel,ans);
    for(auto val:ans) cout<<val<<" ";
    cout<<endl;
    return 0;
}


