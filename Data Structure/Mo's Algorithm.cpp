#include <bits/stdc++.h>
#define  ll         long long
#define  pb         push_back
#define  CLR(ar)    memset(ar,0,sizeof(ar))
#define  N          200010
inline int nxt() {int aaa;scanf("%d",&aaa);return aaa;}
using namespace std;
struct info{
    int l,r,id,block;
}query[N];
int ar[N];
ll sum,ans[N];
int l=0,r=-1,k=2;
void add(int i) {sum+=ar[i];}
void remove(int i) {sum-=ar[i];}
bool cmp(info a,info b){
    if(a.block==b.block)  return a.r<b.r;
    return (a.block)<(b.block);
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
        query[i].block= l/k;
    }
    sort(query,query+n,cmp);
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
