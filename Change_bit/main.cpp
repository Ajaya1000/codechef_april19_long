#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define endl '\n'
using namespace std;
const int N=1e5+2;
int a[N],b[N],c[N];
string com[]{"set_a","set_b","get_c"};
struct Node{
  int v;
 struct Node *left;
 struct Node *right;
  Node(int x){
    v=x;
    left=right=NULL;
  }
};
struct Node* giveNode(int x){
  Node *root=new Node(x);
  root->left=NULL;
  root->right=NULL;
  return root;
}
struct Node* build_segment(int l,int r){
  if(l==r){
    return giveNode(a[l]+b[l]);
  }
  int m=l+(r-l)/2;

  Node *leftN=build_segment(l,m);
  Node *rightN=build_segment(m+1,r);

  Node* root=giveNode((((leftN->v)>>1)& 1 )+ rightN->v );
  root->left=leftN;
  root->right=rightN;
  return root;
}

int query(int i,struct Node* root,int l,int r){
  if(l>i)
    return 0;
  if(i>=r)
    return root->v;
    
  int m=l+(r-l)/2;
  return ((query(i,root->left,l,m)>>1) & 1) + query(i,root->right,m+1,r);
  
}
void update(int pos,struct Node* root,int l,int r){
  if(l==r && l==pos){
    root->v=a[pos]+b[pos];
    return;
  }

  int m=l+(r-l)/2;
  if(pos>=l && pos<=m){
    update(pos,root->left,l,m);
  }
  else if(pos>=m+1 && pos<=r){
    update(pos,root->right,m+1,r);
  }

  root->v=((root->left->v>>1) & 1) + (root->right->v);
}
//void show(struct Node *root){
//    queue<struct Node*> q;
//    q.push(root);
//    struct Node* temp;
//    while(q.size()){
//        temp=q.front();
//        q.pop();
//        cout<<temp->v<<" ";
//        if(temp->left)
//            q.push(temp->left);
//        if(temp->right)
//            q.push(temp->left);
//    }
//}
int main() {
  fastio;
  int n,q;cin>>n>>q;

  string sa,sb;
  cin>>sa>>sb;
  for(int i=0;i<n;i++)
    a[i]=sa[n-i-1]-'0';
  for(int i=0;i<n;i++)
    b[i]=sb[n-i-1]-'0';

  a[n]=a[n+1]=a[n+2]=0;
  b[n]=b[n+1]=b[n+2]=0;
    
  Node* root=build_segment(0,n+2);
  //show(root);
  while(q--){
    string s;cin>>s;
    if(s==com[2]){
      int i;cin>>i;
      int temp=query(i-1,root,0,n+2);
      cout<<(  ( (temp & 1) + (a[i]+b[i]) ) & 1 );
    }
    else if(s==com[0]){
      int pos,value;
      cin>>pos>>value;
      if(a[pos]==value)
        continue;
      a[pos]=value;
      update(pos,root,0,n+2);
    }
    else{
      int pos,value;
      cin>>pos>>value;
      if(b[pos]==value)
        continue;
      b[pos]=value;
      update(pos,root,0,n+2);
    }
        
  }
  return 0;
}
