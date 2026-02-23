#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

// (x から操作を始めたときの最大値) >= 2^a となる最大の a を求める
lint f(lint x){
	if(x== 1) return 0;
	if(x== 2) return 1;
	if(x== 3) return 1;
	if(x== 4) return 2;
	if(x== 5) return 2;
	if(x== 6) return 2;
	if(x== 7) return 3;
	if(x== 8) return 3;
	if(x== 9) return 4;
	if(x==10) return 4;
	if(x==11) return 4;
	if(x==12) return 5;
	if(x==13) return 5;
	if(x==14) return 6;

	lint num3=4-x%5;
	lint num4=(x-15)/5+(4-num3);

	lint num2=2*num4;
	if(num3==1) num2+=1;
	if(num3==2) num2+=3;
	if(num3==3) num2+=4;
	if(num3==4) num2+=6;
	return num2;
}

void solve(){
	lint l,a; scanf("%lld%lld",&l,&a);

	if(f(l)<a){
		puts("0");
		return;
	}

	lint lo=0,hi=l;
	while(hi-lo>1){
		lint mi=(lo+hi)/2;
		if(f(mi)>=a) hi=mi;
		else         lo=mi;
	}
	printf("%lld\n",l-lo);
}

int main(){
// experiment
/*
	vector<lint> a(80);
	vector<vector<lint>> v(a.size());
	for(int i=1;i<a.size();i++){
		a[i]=i;
		v[i]={i};
		for(int j=2;j<i;j++){
			if(a[i]<a[j-1]*a[i-j]){
				a[i]=a[j-1]*a[i-j];
				v[i].clear();
				v[i].insert(v[i].end(),v[j-1].begin(),v[j-1].end());
				v[i].insert(v[i].end(),v[i-j].begin(),v[i-j].end());
			}
		}
		sort(v[i].begin(),v[i].end());
	}
	rep(i,a.size()){
		printf("a[%2d]",i);
		rep(j,v[i].size()) printf(" %c %lld",j==0?'=':'*',v[i][j]);
		puts("");
	}
*/
	int q; scanf("%d",&q); rep(_,q) solve();
	return 0;
}
