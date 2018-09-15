#include <bits/stdc++.h>
#define  ll         long long
#define  pb         push_back
#define  CLR(ar)    memset(ar,0,sizeof(ar))
#define  N          200010
inline int nxt() {int aaa;scanf("%d",&aaa);return aaa;}
int ar[N];
struct node{
    node *left,*right;
    ll val;
};
void segment_tree(node *cur,int l,int r) {
    if(l==r) {
        cur->val = ar[l];
        return ;
    }
    int mid = (l+r)/2; cur->left = new node(); cur->right = new node();
    segment_tree(cur->left,l,mid);segment_tree(cur->right,mid+1,r);
    cur->val = cur->left->val+cur->right->val;
}
void update(node *cur,int l,int r,int i,ll val) {
    if(l==r) {
        cur->val = val;
        return ;
    }
    int mid = (l+r)/2;
    if(cur->left==NULL) cur->left = new node();
    if(cur->right==NULL) cur->right = new node();
    if(i<=mid)
        update(cur->left,l,mid,i,val);
    else
        update(cur->right,mid+1,r,i,val);
    cur->val = cur->left->val+cur->right->val;
}
ll query(node *cur,int l,int r,int i,int j) {
    if(r<i||l>j) {
        return 0;
    }
    if(l>=i&&r<=j) return cur->val;
    int mid = (l+r)/2;
    return query(cur->left,l,mid,i,j)+query(cur->right,mid+1,r,i,j);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    node *head=new node();


    return 0;
}
