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
#define N 100010
#define f(x,y,z) for(int x=y;x<z;x++)
using namespace std;
vector<int>divisor[N];
void t()
{

	for (int i = 1; i <= N; i++)
	{
	    int sq=sqrt(i);
		for(int j=1;j<=sq;j++)
        {
            if(i%j==0)
            {
             divisor[i].push_back(j);
                if(sq*sq!=i)
                 divisor[i].push_back(i/j);
            }


        }

	}


}
int main()
{
	t();
	int n, a, b;

	scanf("%d", &n);
	printf("%d\n",divisor[n].size());

	return 0;
}
