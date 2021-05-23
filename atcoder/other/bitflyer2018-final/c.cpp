#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	string s; cin>>s;
	int n=s.length();

	int _cnt[200001]={};
	int* cnt=&_cnt[100000];
	cnt[0]=1;

	lint ans=0;
	int h=0;
	rep(i,n){
		if(s[i]=='('){
			h++;
			cnt[h]++;
		}
		else{
			cnt[h]=0;
			h--;
			ans+=cnt[h];
			cnt[h]++;
		}
	}
	printf("%lld\n",ans);

	return 0;
}
