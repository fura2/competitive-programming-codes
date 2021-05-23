#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> l(n),r(n);
	rep(i,n) scanf("%d%d",&l[i],&r[i]), r[i]++;

	vector<int> X;
	rep(i,n){
		X.emplace_back(l[i]);
		X.emplace_back(r[i]);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());

	int m=X.size();
	vector<int> sum(m+1);
	rep(i,n){
		sum[lower_bound(X.begin(),X.end(),l[i])-X.begin()]++;
		sum[lower_bound(X.begin(),X.end(),r[i])-X.begin()]--;
	}
	rep(i,m) sum[i+1]+=sum[i];

	rep(i,m-1){
		lint width=X[i+1]-X[i];
		if(k<=sum[i]*width){
			printf("%d\n",X[i]+(k-1)/sum[i]);
			break;
		}
		k-=sum[i]*width;
	}

	return 0;
}
