#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#define N 1000000
#define f(x,y,z) for(int x=y;x<z;x++)
using namespace std;
vector<int>primes;
bool mark[N];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
        if(mark[i]==0)
            for(int j = i*i; j <= n; j += i * 2)
                mark[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!mark[i]) primes.push_back(i);
}

int main() {
    sieve(N-1);
    cout<<primes.size()<<endl;
  return 0 ;
}
