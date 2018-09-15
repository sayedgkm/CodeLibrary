// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
using namespace std;
int nxt(){
  int a;
  scanf("%d",&a);
  return a;
}
pll extendedEuclid(ll a, ll b) { /// returns x,y where ax+by=gcd(a,b)
    if (b == 0)
        return pll(1, 0);
    else {
        pll d = extendedEuclid(b, a % b);
        return pll(d.ss, d.ff - d.ss * (a / b));
    }
}
ll modularInverse(ll a, ll n) { /// returns a^-1%n
    pll ret = extendedEuclid(a, n);
    return ((ret.ff % n) + n) % n;
}

int main()
{
    cout<<0%5<<endl;
   cout<< modularInverse(2,M)<<endl;//finding 4^-1%1e9+7
      return 0;
}

