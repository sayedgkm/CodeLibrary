#include <bits/stdc++.h>
#define  ll         long long
#define  pb         push_back
#define  CLR(ar)    memset(ar,0,sizeof(ar))
#define  N          200010
using namespace std;
ll tree[1000]={0};
void update(int idx,int n,int x)
{
    while(idx<=n)
    {
        tree[idx]+=x;
        idx+= idx&(-idx);
    }
}
ll query(int idx){
     ll sum=0;
     while(idx>0)
     {
         sum+=tree[idx];idx-=idx&(-idx);
     }
   return sum;
}
int main() { return 0;}
