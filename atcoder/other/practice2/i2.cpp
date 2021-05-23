#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using namespace atcoder;
using lint=long long;

int main(){
	string s; cin>>s;
	int n=s.length();

	auto LCP=lcp_array(s,suffix_array(s));

	lint ans=n;
	rep(i,n-1){
		ans+=n-i-1-LCP[i];
	}
	printf("%lld\n",ans);

	return 0;
}
