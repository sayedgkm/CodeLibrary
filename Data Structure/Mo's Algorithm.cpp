#include <bits/stdc++.h>
#define  ll         long long
#define  pb         push_back
#define  CLR(ar)    memset(ar,0,sizeof(ar))
#define  N          200010
inline int nxt() {int aaa;scanf("%d",&aaa);return aaa;}
using namespace std;
struct info{
    int l,r,id;
}query[N];
int ar[N];
ll sum,ans[N];
int l=0,r=-1,k=320;  /// change this value
void add(int i) {sum+=ar[i];}
void remove(int i) {sum-=ar[i];}
bool cmp(info a,info b){
    if(a.l/k==b.l/k)  return a.r<b.r;
    return (a.l)<(b.l);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();int q = nxt();
    for(int i =0;i<n;i++) {
        ar[i] =nxt();
    }
    for(int i =0;i<q;i++) {
        query[i].l = nxt();
        query[i].r = nxt();
        query[i].id = i;
    }
    sort(query,query+n,cmp);
      l = 0,r = -1,sum=0;
    for(int i = 0;i<q;i++) {
        while(r<query[i].r) add(++r);
        while(r>query[i].r) remove(r--);
        while(l<query[i].l) remove(l++);
        while(l>query[i].l) add(--l);
        ans[query[i].id]= sum;
    }
    for(int i = 0;i<q;i++){
        if(i) printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");

    return 0;
}
