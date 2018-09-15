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
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
using namespace std;
inline int nxt(){
  int a;
  scanf("%d",&a);
  return a;
}
ll x,y;
void extendedEuclid(ll a,ll b ){
     if(b==0){
        x=1;y=0;return;
     }
     extendedEuclid(b,a%b);//as a normal gcd
     ll x1=y;
      ll y1=x-(a/b)*y;
    x=x1;
    y=y1;
}
bool linearDiophantine(ll a,ll b,ll c){
      ll g=gcd(a,b);
      if(c%g!=0) return false;///no solution
      if(g<0){
        g*=-1;
      }
      a/=g;
      b/=g;
      c/=g;
      extendedEuclid(a,b);
     x=x*c;
     y=y*c;
     return true;

}
int main()
{
    int a=nxt();int b=nxt();
    int c=nxt();
    int g=gcd(a,b);
    if(g<0) g=g*-1;
      if(!linearDiophantine(a,b,c)){
        printf("No solution\n");

      }
      else {

        printf("solution exist\n");
        printf("x = %lld y= %lld\n",x,y);
        ///for another solution
                     ll k=1;
         printf("x = %lld y= %lld\n",(x+(b/g)*k),(y-(a/g)*k));
        }
      return 0;
}

