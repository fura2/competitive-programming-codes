#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int solve(vector<int> a){
	int n=a.size();

	vector<int> I(n),D(n);

	vector<int> lis;
	rep(i,n){
		auto it=lower_bound(lis.begin(),lis.end(),a[i]);
		if(it!=lis.end()){
			*it=a[i];
			I[i]=it-lis.begin()+1;
		}
		else{
			lis.emplace_back(a[i]);
			I[i]=lis.size();
		}
	}

	lis.clear();
	for(int i=n-1;i>=0;i--){
		auto it=lower_bound(lis.begin(),lis.end(),a[i]);
		if(it!=lis.end()){
			*it=a[i];
			D[i]=it-lis.begin()+1;
		}
		else{
			lis.emplace_back(a[i]);
			D[i]=lis.size();
		}
	}

	int res=0;
	rep(i,n) res=max(res,min(I[i],D[i])-1);
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int res1=solve(a);

	rep(i,n) a[i]*=-1;
	int res2=solve(a);

	printf("%d\n",max(res1,res2));

	return 0;
}
