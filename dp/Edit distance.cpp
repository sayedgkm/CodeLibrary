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
string a,b,c;
int lena,lenb;
int dp[100][100];
int mini(int xx,int yy,int zz) {
    return min(xx,min(yy,zz));
}
int edit(int i,int j) {
    if(i==lena)
        return lenb-j;
    if(j==lenb)
        return lena-i;
    if(a[i]==b[j]) {
        edit(i+1,j+1);
    } else return mini(
                          edit(i+1,j)+1,//delete 1st char from string a
                          edit(i,j+1)+1,  //insert 1st char of string b into string a
                          edit(i+1,j+1)+1 //replace 1st char of string a with string b
                      );
}
int main() {
    cin>>a>>b;
    lena=a.length();
    lenb=b.length();
    cout<<edit(0,0)<<endl;

    return 0;
}
