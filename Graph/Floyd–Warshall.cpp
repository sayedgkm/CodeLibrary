// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
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
#define        inf                             (int)1e9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <class T> inline T bigmod(T p,T e,T m){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % m;
        p = (p * p) % m;
    } return (T)ret;
}
inline int nxt(){
  int aaa;
  scanf("%d",&aaa);
  return aaa;
}
int mat[200][200];
void  reset(int n){
   FOR(i,0,n+1) FOR(j,0,n+1) mat[i][j]=inf;
 }
void warshall(int n){
   FOR(k,1,n+1) FOR(i,1,n+1) FOR(j,1,n+1)
       if(mat[i][k]+mat[k][j]<mat[i][j]) mat[i][j]=mat[i][k]+mat[k][j];
}
int main()
{
    reset(100);
    mat[1][2]=20;
    mat[2][3]=10;
    mat[7][2]=2;
    mat[1][7]=5;
    mat[1][4]=35;
    mat[4][5]=100;
    mat[3][5]=30;
    warshall(7);
    cout<<mat[4][5]<<endl;
     cout<<mat[1][2]<<endl;

      return 0;
}
