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
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
vector<int>primes;
bool mark[N];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
        for(int j = i*i; j <= n; j += i * 2)
            mark[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!mark[i]) primes.push_back(i);
}
int segmentedSieve(ll a,ll b) {
    if(a==1) a++;
    int res=0;
    memset(mark,0,sizeof mark);
    int sqrtn=sqrt(b);
    for(int i=0; i<primes.size()&&primes[i]<=sqrtn; i++) {
        ll p=primes[i];
        ll j=((a+p-1)/p)*p;
        if(j==p) j+=p;
        for(; j<=b; j+=p)
            mark[j-a]=1;
    }
    for(ll i=a; i<=b; i++)
        if(!mark[i-a]) cout<<i<<endl;

    return res;
}
int main() {
    sieve(1000000);
    int n, a, b;
    cout<< segmentedSieve(10000000000,10000000110)<<endl;;

    return 0;
}
