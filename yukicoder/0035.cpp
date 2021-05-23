#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int ans1=0,ans2=0;
	rep(i,n){
		int t;
		string s; cin>>t>>s;
		ans1+=min((int)s.length(),12*t/1000);
		ans2+=max((int)s.length()-12*t/1000,0);
	}
	printf("%d %d\n",ans1,ans2);

	return 0;
}
