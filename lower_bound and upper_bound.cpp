#include <bits/stdc++.h>
using namespace std;
int main() {
    int i, num , key, a[150];
    cin >> num >> key;
    for(i = 0 ; i< num ; i++)
        cin >> a[i];
    int b = 0, e = num-1;
    while(b<=e) {
        int mid = (b+e)/2;
        if(a[mid] < key) /// its lower bound.for upper bound just write <=
            b = mid+1;
        else e = mid-1;
    }
    cout << b << endl;
}

