#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int ans[4]={};
	rep(i,n) ans[s[i]-'1']++;
	printf("%d %d\n",*max_element(ans,ans+4),*min_element(ans,ans+4));

	return 0;
}
