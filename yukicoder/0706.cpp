#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int hist[1000]={};
	rep(i,n){
		string s; cin>>s;
		hist[s.length()-2]++;
	}
	int mx=*max_element(hist,hist+1000);

	int ans;
	rep(i,1000) if(hist[i]==mx) ans=i;
	printf("%d\n",ans);

	return 0;
}
