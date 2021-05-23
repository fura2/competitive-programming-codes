#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int solve(vector<bool> a){
	int n=a.size();
	int res=0;
	rep(i,n) if(a[i]) {
		a[i]=false;
		if(i+1<n) a[i+1]=false;
		if(i+2<n) a[i+2]=false;
		res++;
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<lint> b(n);
	rep(i,n) scanf("%lld",&b[i]);

	vector<bool> ng(n);
	rep(i,n) ng[i]=(b[i]%gcd(b[(i-1+n)%n],b[(i+1)%n])!=0);

	if(n<=2){
		printf("%d\n",count(ng.begin(),ng.end(),true)>0?1:0);
		return 0;
	}

	auto ng2=ng,ng3=ng;
	ng2[1]=ng2[ 0 ]=ng2[n-1]=false;
	ng3[0]=ng3[n-1]=ng3[n-2]=false;

	printf("%d\n",min({solve(ng),solve(ng2)+1,solve(ng3)+1}));

	return 0;
}
