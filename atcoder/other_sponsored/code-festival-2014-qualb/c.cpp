#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s1,s2,s3; cin>>s1>>s2>>s3;
	int n=s1.length()/2;

	int hist1[128]={},hist2[128]={},hist3[128]={};
	rep(i,2*n){
		hist1[s1[i]]++;
		hist2[s2[i]]++;
		hist3[s3[i]]++;
	}

	int cnt1=0,cnt2=0,r=0; // s1 から必ず選ぶ分, s2 から必ず選ぶ分, どちらからも選べる分
	for(char c='A';c<='Z';c++){
		if(hist1[c]+hist2[c]<hist3[c]) return puts("NO"),0;
		int tmp1=max(hist3[c]-hist2[c],0);
		int tmp2=max(hist3[c]-hist1[c],0);
		cnt1+=tmp1;
		cnt2+=tmp2;
		r+=hist3[c]-tmp1-tmp2;
	}
	puts(cnt1<=n&&cnt2<=n?"YES":"NO");

	return 0;
}
