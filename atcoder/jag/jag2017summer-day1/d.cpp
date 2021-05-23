#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double x,y,z; cin>>x>>y>>z;
	printf("%.9f\n",2*x*z/(hypot(x,y)+z));
	return 0;
}
