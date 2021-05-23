#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	vector<int> X;
	rep(i,n) if(s[i]=='#') X.emplace_back(i);

	int ans=X[0]+(n-1-X.back());
	rep(i,X.size()-1) ans=max(ans,X[i+1]-X[i]-1);
	printf("%d %d\n",X[0],ans-X[0]);

	return 0;
}
