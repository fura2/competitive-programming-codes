// Day 3: JOIOJI

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;

	int ans=0,cnt[128]={};
	map<tuple<int,int,int>,int> f;
	rep(i,n+1){
		int a=cnt['J'];
		int b=cnt['O'];
		int c=cnt['I'];

		int mn=min({a,b,c});
		a-=mn;
		b-=mn;
		c-=mn;

		if(f.count(tie(a,b,c))==0){
			f[tie(a,b,c)]=i;
		}
		else{
			ans=max(ans,i-f[tie(a,b,c)]);
		}

		if(i<n) cnt[s[i]]++;
	}
	printf("%d\n",ans);

	return 0;
}
