#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> x(n+1);
	rep(i,n) scanf("%d",&x[i+1]);

	bool ok=true;
	rep(i,n) if(abs(x[i+1]-x[i])!=1) ok=false;
	puts(ok?"T":"F");

	return 0;
}
