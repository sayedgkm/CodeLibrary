#include <bits/stdc++.h>
#define  ll         long long
#define  pb         push_back
#define  CLR(ar)    memset(ar,0,sizeof(ar))
#define  N          200010
inline int nxt() {int aaa;scanf("%d",&aaa);return aaa;}
using namespace std;
int ar[N]={0,1,2,3,4,5,6};
struct info{
   ll sum;
   ll mx;
}tree[N*4];
void segment_tree(int node,int low,int high){
     if(low==high){
        tree[node].sum=ar[low];
        return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
    segment_tree(left,low,mid);
    segment_tree(right,mid+1,high);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node,int low,int hi,int i,int value){

   if(low==hi){
    tree[node].sum+=value; return;
   }
   int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
   if(i<=mid)
      update(left,low,mid,i,value);
   else
      update(right,mid+1,hi,i,value);
   tree[node].sum=tree[left].sum+tree[right].sum;
}
ll query(int node,int low,int hi,int i,int j){
    if(i>hi||j<low) return 0;
    if(low>=i&&hi<=j)
      return tree[node].sum;
    int mid=(low+hi)/2;
    int left=2*node;
    int right=left+1;
    ll x= query(left,low,mid,i,j);
    ll y= query(right,mid+1,hi,i,j);
    return x+y;
}
int main()
{
   segment_tree(1,1,6);
   cout<<query(1,1,6,1,6)<<endl;
   update(1,1,6,1,15);
   cout<<query(1,1,6,1,1)<<endl;
  return 0;
}
