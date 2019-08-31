// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================

#include <bits/stdc++.h>
#define        ll                    long long
#define        f(x,y,z)              for(int x=y;x<z;x++)
#define        pii                   pair<int,int>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     1000010
#define        M                     1000000007
using namespace std;
int ar[N]= {0,1,2,3,4,5,6,7,8,9,10,11};
struct info
{
    ll sum;
    ll lazy;

} tree[N*4];
void segment_tree(int node,int low,int high)
{
    if(low==high)
    {
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
void propagate(int node,int low,int hi)
{
    int left=2*node;
    int right=left+1;
    int mid =(low+hi)/2;
    tree[node].sum+=(hi-low+1)*tree[node].lazy;
    if(hi!=low)
    {
        tree[left].lazy+=tree[node].lazy;
        tree[right].lazy+=tree[node].lazy;
    }
    tree[node].lazy=0;
}
void update(int node,int low,int hi,int i,int j,int value)
{
    int left=2*node;
    int right=left+1;
    if(tree[node].lazy)propagate(node,low,hi);
    if(hi<i||j<low) return;
    if(low>=i&&hi<=j)
    {
        tree[node].sum+=(hi-low+1)*value;
        if(hi!=low)
        {
            tree[left].lazy+=value;
            tree[right].lazy+=value;
        }
        tree[node].lazy=0;
        return ;
    }
    int mid=(low+hi)/2;
    update(left,low,mid,i,j,value);
    update(right,mid+1,hi,i,j,value);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
ll query(int node,int low,int hi,int i,int j)
{
    int left=2*node;
    int right=left+1;
    if(tree[node].lazy)propagate(node,low,hi);
    if(hi<i||j<low) return 0;
    if(low>=i&&hi<=j)
        return tree[node].sum;
    int mid=(low+hi)/2;
    ll x= query(left,low,mid,i,j);
    ll y= query(right,mid+1,hi,i,j);
    return x+y;

}
int main()
{
    segment_tree(1,1,10);
    update(1,1,10,7,10,5);
    cout<<query(1,1,10,7,10)<<endl;
    return 0;
}

