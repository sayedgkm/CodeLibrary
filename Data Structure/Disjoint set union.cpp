#include <bits/stdc++.h>
#define  ll         long long
#define  pb         push_back
#define  CLR(ar)    memset(ar,0,sizeof(ar))
#define  N          200010
using namespace std;
int path[N];
void root(int n) {
    for(int i=0; i<=n; i++)
        path[i]=i;
}
int findUnion(int x) {      ///Find root of x
    if(path[x]==x) return x;
    return path[x]=findUnion(path[x]);

}
void mergeUnion(int x,int y) {
    path[findUnion(x)]=findUnion(y); ///making same root of both x and y
}
bool sameset(int x,int y) { ///check two element are in same set or not
    return findUnion(x)==findUnion(y);
}
int main() {
    root(1000);
    cout<<sameset(5,6)<<endl;
    mergeUnion(5,6);
    mergeUnion(7,6);
    cout<<sameset(6,7)<<endl;



}
