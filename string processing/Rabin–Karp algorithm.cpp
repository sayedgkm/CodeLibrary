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
string txt,pt;ll ht,hp,h=1; int base=101;int prime=29;
void rabin(){
     int ans=0;
  int lt=txt.length();
  int lp=pt.length();
  f(i,0,lp-1) //calculate b^(lp-1)
     h=(h*base)%prime;
  for(int i=0;i<lp;i++) hp=(hp*base+pt[i])%prime; //hash table of pattern
  for(int i=0;i<lp;i++) ht=(ht*base+txt[i])%prime;  //hash table of text for 1st segment
   if(hp==ht) cout<<"0"<<endl;
    for(int i=lp;i<lt;i++){
        ht=ht-(txt[i-lp]*h);
        ht=(base*ht+txt[i])%prime;
         if(ht<0){
            ht+=prime;
         }
        if(hp==ht){
                int j=0;
        for(;j<lp;j++){
            if(pt[j]!=txt[i-lp+j+1])
                 break;
         }
         if(j==lp)
          cout<<i-lp+1<<endl;
        }

    }
}
int main()
{
    cin>>txt>>pt;
    rabin();
      return 0;
}
