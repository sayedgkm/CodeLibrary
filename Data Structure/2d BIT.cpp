#include <bits/stdc++.h>
#define  ll   long long
using namespace std;
int tree[505][505];
int n=10;
void update(int x,int y, int value) {
    for(int i=x; i<=n; i+=i&(-i))
        for(int j=y; j<=n; j+=j&(-j))
            tree[i][j]+=value;
}
int query(int x,int y) {
    int sum=0;
    for(int i=x; i>0; i-=i&(-i))
        for(int j=y; j>0; j-=j&(-j))
            sum+=tree[i][j];
    return sum;
}
int main() {
    update(1,1,1);
    cout<<query(5,5)<<endl;
    update(1,2,1);
    update(1,3,1);
    update(1,4,1);
    update(1,7,1);
    update(2,4,1);
    cout<<query(2,7)<<endl;
    cout<<query(2,3)+query(0,0)-query(2,0)-query(0,3)<<endl;

}
