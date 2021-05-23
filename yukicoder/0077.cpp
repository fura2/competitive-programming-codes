#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int f(vector<int> a,vector<int> b){
	while(a.size()<b.size()) a.emplace_back(0);
	while(b.size()<a.size()) b.emplace_back(0);

	int n=a.size(),d1=0,d2=0;
	rep(i,n){
		if(a[i]>=b[i]) d1+=a[i]-b[i];
		else           d2+=b[i]-a[i];
	}
	return d1<d2?INF:d1;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=INF;
	for(int r=1;r<=1000;r+=2){
		vector<int> b(r);
		rep(i,r) b[i]=min(i+1,r-i);
		ans=min(ans,f(a,b));
	}
	printf("%d\n",ans);

	return 0;
}
