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
#define        N                     1000010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
string a,b,c;int lena,lenb; int dp[1005][1005];
int lcs(int i,int j){
   if(i>=lena||j>=lenb) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
   if(a[i]==b[j]){
       return  dp[i][j]=lcs(i+1,j+1)+1;
   }
   else
     {
         int p=lcs(i+1,j);
          int q=  lcs(i,j+1);
         return dp[i][j]= max(p,q);
     }
}
void printlcs(int i,int j){
       if(i==lena||j==lenb) {
       cout<<c<<endl;return;
       }
       if(a[i]==b[j]) {
           c+=a[i];
        printlcs(i+1,j+1);
       } else
       {
           if(dp[i+1][j]>dp[i][j+1]) printlcs(i+1,j);
            else printlcs(i,j+1);

       }
}
int main()
{
    mem(dp,-1);
    cin>>a>>b;
    lena=a.length();
    lenb=b.length();
   cout<<lcs(0,0)<<endl;
   printlcs(0,0);

return 0;
}
