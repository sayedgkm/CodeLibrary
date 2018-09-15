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
#define N 1000100
#define f(x,y,z) for(int x=y;x<z;x++)
using namespace std;
ll unsigned phi[N+ 5];
void sieveofphi(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!phi[i]) {  /// i is a prime
            phi[i] = i - 1;
            for (int j = i * 2; j <= n; j += i) {
                if (!phi[j]) phi[j] = j;
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
}

int main() {
    sieveofphi(100);
    cout<<phi[23]<<endl;
    f(i, 1,21) {
        cout << phi[i] << endl;

    }

    return 0;
}

