#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,L; scanf("%d%d",&n,&L);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	priority_queue<pair<lint,int>> Q;
	rep(i,n){
		bool ok=true;
		if(i> 0  && a[i-1]>=a[i]) ok=false;
		if(i<n-1 && a[i+1]>=a[i]) ok=false;
		if(ok) Q.emplace(a[i],i);
	}

	lint t=0;
	while(!Q.empty()){
		lint h;
		int i; tie(h,i)=Q.top(); Q.pop();
		t+=L-(h+t);
		a[i]=0;
		if(i> 0  && a[i-1]>0 && (i-1== 0  || a[i-2]<a[i-1])) Q.emplace(a[i-1]-t,i-1);
		if(i<n-1 && a[i+1]>0 && (i+1==n-1 || a[i+2]<a[i+1])) Q.emplace(a[i+1]-t,i+1);
	}
	printf("%lld\n",t);

	return 0;
}
