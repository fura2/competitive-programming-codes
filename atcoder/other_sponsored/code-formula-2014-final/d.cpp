#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

struct interval{
	int l,r,id;
	interval(){}
	interval(const int& l,const int& r,int id):l(l),r(r),id(id){}
	bool operator<(const interval& I)const{ return make_tuple(l,r)<make_tuple(I.l,I.r); }
};

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n),asum(n+1);
	rep(i,n){
		scanf("%d",&a[i]);
		asum[i+1]=asum[i]+a[i];
	}

	vector<interval> I(n);
	rep(i,n) scanf("%d%d%d",&I[i].id,&I[i].l,&I[i].r);
	sort(I.begin(),I.end());

	vector<int> dp(n,a[0]);
	rep(i,n){
		rep(j,i) if(I[j].r<=I[i].l) dp[i]=max(dp[i],dp[j]+a[0]);

		int cnt=0,left=I[i].l;
		for(int j=i-1;j>=0;j--) if(I[j].r<=left && I[j].id==I[i].id) {
			cnt++;
			left=I[j].l;
			dp[i]=max(dp[i],dp[j]+asum[cnt+1]-a[0]);
		}
	}

	printf("%d\n",*max_element(dp.begin(),dp.end()));

	return 0;
}
