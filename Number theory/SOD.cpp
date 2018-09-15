// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                    long long
#define        f(x,y,z)              for(int x=y;x<z;x++)
#define        take1(a);             int a;scanf("%d",&a);
#define        take2(a,b);           int a;int b;scanf("%d%d",&a,&b);
#define        take3(a,b,c);         int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);       int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                   pair<int,int>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     10000100
#define        M                     1000000007
#define        pi                    acos(-1.0)
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
ll sod(ll n){
      ll res=1;
     for(int i=0;i<primes.size()&&primes[i]*primes[i]<=n;i++){
         ll p=primes[i],temp=1;
         ll tempsum=1; ///Contains value of (p^0+p^1+...p^a)
         while(n%p==0){
            n/=p;
            temp*=p;
            tempsum+=temp;
         }
        res*=tempsum;
     }
   if(n>1) res*=(n+1);
   return res;
}

int main()
{
 sieve(100);
 cout<<sod(9)<<endl;

return 0;
}

