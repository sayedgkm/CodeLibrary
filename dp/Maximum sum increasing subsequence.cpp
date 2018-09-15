#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<ll,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
using namespace std;
 ll tree[N];
void update(ll x,int idx,int n)
{
    while(idx<=n)
    {
        tree[idx]=max(x,tree[idx]);
        idx+= idx&(-idx);
    }
}
ll query(int idx){
     ll mx=0;
     while(idx>0)
     {
         mx=max(mx,tree[idx]);
         idx-=idx&(-idx);
     }
   return mx;
}
int main()
{
    int ar[]={0,6,3,2,1,5,9,7,8};
    int br[100]={0};
    int  n=8;
    for(int i= 1;i<=n;i++)
        br[i]=ar[i];
    sort(br+1,br+1+n);
    for(int i=1;i<=n;i++){
        int pos=lower_bound(br+1,br+1+n,ar[i])-br;
        ll val=query(pos-1);
        cout<<val<<endl;
        update(val+ar[i],pos,n);
    }
    cout<<query(n)<<endl;
      return 0;
}
