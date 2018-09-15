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
ll nod(ll n){
      ll result=1;
    for(ll i=0;primes[i]*primes[i]<=n;i++){
          if(n%primes[i]==0){
            int c=1;
        while(n%primes[i]==0){
                n/=primes[i];
                c++;
        }
       result=result*c;
    }
 }
  if(n>1)
      result=result*2;
  return result;
}
int main()
{
    sieve(100);
    cout<<nod(20)<<endl;
    f(i,1,100+1)
    //  cout<<nod(i)<<" "<<i<<endl;
      return 0;
}
