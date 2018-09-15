#include <bits/stdc++.h>
#define  ll         long long
#define  pb         push_back
#define  CLR(ar)    memset(ar,0,sizeof(ar))
#define  N          1000010
inline int nxt() {int aaa;scanf("%d",&aaa);return aaa;}
using namespace std;
struct query{
    int l,r,id,t;
    query(){}
    query(int _l,int _r,int _id,int _t):l(_l),r(_r),id(_id),t(_t){}
}Q[N];
struct update{
    int x,pre,now;
    update() {}
    update(int _x,int _pre,int _now) : x(_x),pre(_pre),now(_now){}
}U[N];

int ar[N];
int last[N];
ll sum,ans[N];
int mark[1000100];
int l=0,r=-1,t,k=320;   /// change this value to ( k = 4*root(n) or root(n))
void add(int i) {
    if(mark[ar[i]]==0) sum++;
    mark[ar[i]]++;
}
void remove(int i) {
    mark[ar[i]]--;
    if(mark[ar[i]]==0) sum--;
}
void apply(int x, int y) {

    if(l <= x&&x <= r) {  // l, r is the l, r from MO's algo
        remove(x);
        ar[x] = y;
        add(x);
    } else ar[x] = y;
}
bool cmp(query a,query b){
    int l1 = a.l/k,l2= b.l/k;
    int r1= a.r/k,r2= b.r/k;
    if(l1!=l2) return l1<l2;
    if(r1!=r2) return r1<r2;
    return a.t<b.t;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();int q = nxt();
    for(int i =0;i<n;i++) {
        ar[i] =nxt();
        last[i] = ar[i];
    }
    int noOfUpdate=0,noOfQuery=0;
    for(int i =0;i<q;i++) {
        char c[2];
        scanf("%s",c);
        if(c[0]=='M') {
            int x = nxt();
            int y = nxt();
            U[noOfUpdate] = update(x,last[x],y);
            last[x] = y;
            noOfUpdate++;
        } else {
            int x= nxt();
            int y = nxt();
            y--;
            Q[noOfQuery]=query(x,y,noOfQuery,noOfUpdate);
            noOfQuery++;

        }

    }
    k = sqrt(n)*4;
    sort(Q,Q+noOfQuery,cmp);
    l = 0,r = -1,t= 0,sum=0;
    for(int i = 0;i<noOfQuery;i++) {
        while(t<Q[i].t) apply(U[t].x,U[t].now),t++;
        while(t>Q[i].t) t--,apply(U[t].x,U[t].pre);
        while(r<Q[i].r) add(++r);
        while(r>Q[i].r) remove(r--);
        while(l<Q[i].l) remove(l++);
        while(l>Q[i].l) add(--l);
        ans[Q[i].id]= sum;
    }
    for(int i = 0;i<noOfQuery;i++){
        printf("%d\n",ans[i]);
    }

    return 0;
}

