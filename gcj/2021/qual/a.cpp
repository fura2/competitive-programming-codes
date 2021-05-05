#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int solve(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]), a[i]--;

	int ans=0;
	rep(i,n-1){
		int j=min_element(a.begin()+i,a.end())-a.begin();
		ans+=j-i+1;
		reverse(a.begin()+i,a.begin()+j+1);
	}
	return ans;
}

int main(){
	int t; scanf("%d",&t); rep(_,t) printf("Case #%d: %d\n",_+1,solve());
	return 0;
}
