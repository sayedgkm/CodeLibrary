#include <bits/stdc++.h>
#define  ll         long long
#define  pb         push_back
#define  CLR(ar)    memset(ar,0,sizeof(ar))
#define  SET(ar)    memset(ar,-1,sizeof(ar))
#define  N          200010
using namespace std;

 struct info {
    int pr, sf, mx, total;
} tree[N*3];

int ar[N];
info go(info a,info b) {
    info temp;
    temp.total=a.total+b.total;
    temp.mx=max(a.mx,max(b.mx,temp.total));
    temp.mx=max(temp.mx,a.sf+b.pr);
    temp.sf=max(b.sf,b.total+a.sf);
    temp.pr=max(a.pr,a.total+b.pr);
    return temp;

}
void segment_tree(int node,int low,int hi) {
    if(low==hi) {
        tree[node].mx=tree[node].sf=tree[node].pr=tree[node].total=ar[low];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+hi)/2;
    segment_tree(left,low,mid);
    segment_tree(right,mid+1,hi);
    tree[node]=go(tree[left],tree[right]);
}
info query(int node,int low,int hi,int i,int j) {
    if(low>=i&&hi<=j) {
        return tree[node];
    }
    int mid=(low+hi)/2;
    int left=2*node;
    int right=left+1;
    info x,y;
    if(j<=mid) return query(left,low,mid,i,j);
    else if(i>mid)  return query(right,mid+1,hi,i,j);
    else return go(query(left,low,mid,i,j),query(right,mid+1,hi,i,j));
}
int main() {

    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>ar[i];
    segment_tree(1,1,n);
    int a,b;cin>>a>>b;
    info f=query(1,1,n,a,b);
    printf("%d\n",f.mx);
    return 0;
}

