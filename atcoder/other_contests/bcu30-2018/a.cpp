#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);
	int m; scanf("%d",&m);
	vector<int> b(m);
	rep(i,m) scanf("%d",&b[i]);

	int prod1=1,prod2=1;
	rep(i,n) prod1*=a[i];
	rep(i,m) prod2*=b[i];

	if(prod1==1){
		puts(prod2==1&&m<=n?"Yes":"No");
		return 0;
	}

	puts(prod1==prod2?"Yes":"No");

	return 0;
}
