#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n,k;
	string s; cin>>n>>k>>s;

	int cnt=0;
	vector<int> a(n);
	rep(i,n){
		if(s[i]=='(') cnt++;
		else          cnt--;
		a[i]=cnt;
	}
	sort(a.rbegin(),a.rend());

	cout<<accumulate(a.begin(),a.begin()+k,0LL)<<'\n';

	return 0;
}
