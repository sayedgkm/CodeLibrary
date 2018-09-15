#include <bits/stdc++.h>
#define ll long long
#define  ALL(x)  x.begin(),x.end()
using namespace std;
string multiply(string a, long long b ) {
        reverse(ALL(a));
        int carry = 0;
        for( int i = 0; i < a.size(); i++ ) {
            carry += (a[i] - 48) * b;
            a[i] = ( carry % 10 + 48 );
            carry /= 10;
        }
        while( carry ) {
            a += ( carry % 10 + 48 );
            carry /= 10;
        }
        reverse(ALL(a));
        return a;
    }
int main()
{
    string a="1235345435453454354545454475745674547878784758847584574895747884765348";
    ll b=2545445;
    a=multiply(a,b);
    cout<<a<<endl;
    string fact="1";
    for(int i=1;i<=7;i++)
        fact=multiply(fact,i);
    cout<<fact<<endl;

      return 0;
}
