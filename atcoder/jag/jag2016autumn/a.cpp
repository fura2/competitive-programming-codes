#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool check(int a){
	string s=to_string(a);
	int n=s.length();
	rep(i,n-1) if(s[i]+1!=s[i+1]) return false;
	return true;
}

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int ans=-1;
	rep(i,n) for(int j=i+1;j<n;j++) if(check(a[i]*a[j])) ans=max(ans,a[i]*a[j]);
	printf("%d\n",ans);

	return 0;
}
