#include<bits/stdc++.h>
using namespace std;
int histogram(int m) {

    int i=0;
    stack<int>st;
    int mx=0;
    int area;
    while(i<m) {
        if(st.empty()||ar[st.top()]<ar[i])
            st.push(i++);
        else {
            int x=st.top();
            st.pop();
            area=ar[x]*(st.empty()?i:i-st.top()-1);
            mx=max(mx,area);
        }
    }
    while(!st.empty()) {
        int x=st.top();
        st.pop();
        area=ar[x]*(st.empty()?i:i-st.top()-1);
        mx=max(mx,area);
    }
    return mx;
}
