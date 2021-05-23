#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

vector<int> a(3);

vector<int> solve(vector<int> b){
	int n=b.size();
	vector<int> cnt(8);
	rep(S,1<<n){
		int ok=0;
		rep(i,n) if(S>>i&1) {
			rep(j,3) if((ok>>j&1)==0 && a[j]<=b[i]) {
				ok|=1<<j;
				break;
			}
		}
		cnt[ok]++;
	}
	return cnt;
}

int main(){
	int n; scanf("%d%d%d%d",&a[0],&a[1],&a[2],&n);
	vector<int> b(n);
	rep(i,n) scanf("%d",&b[i]);

	sort(a.rbegin(),a.rend());
	sort(b.rbegin(),b.rend());

	auto cnt1=solve(vector(b.begin(),b.begin()+n/2));
	auto cnt2=solve(vector(b.begin()+n/2,b.end()));

	int ans=0;
	rep(S,8) rep(T,8) {
		bool ok=true;
		int carry=0;
		rep(i,3){
			int b1=S>>i&1;
			int b2=T>>i&1;
			if(b1+b2+carry==0){
				ok=false;
			}
			else{
				carry=b1+b2+carry-1;
			}
		}
		if(ok) ans+=cnt1[S]*cnt2[T];
	}
	printf("%d\n",ans);

	return 0;
}
