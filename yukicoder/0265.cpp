#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int n,d,idx;
string s;

vector<lint> expr();

vector<lint> term(){
	if(s[idx]=='d'){
		idx+=2;
		auto res=expr();
		assert(idx<n && s[idx]=='}');
		idx++;
		rep(i,d) res[i]=(i+1)*res[i+1];
		res[d]=0;
		return res;
	}
	else{
		int deg=0,coef=1;
		while(1){
			assert(idx<n && (isdigit(s[idx]) || s[idx]=='x'));
			if(isdigit(s[idx])){
				coef=s[idx]-'0';
			}
			else{
				deg++;
			}
			idx++;
			if(idx==n || s[idx]!='*') break;
			idx++;
		}

		vector<lint> res(d+1);
		res[deg]=coef;
		return res;
	}
}

vector<lint> expr(){
	vector<lint> res(d+1);
	if(idx==n) return res;
	while(1){
		auto tmp=term();
		rep(i,d+1) res[i]+=tmp[i];
		if(idx==n || s[idx]=='}') break;
		if(s[idx]=='+') idx++;
	}
	return res;
}

int main(){
	cin>>n>>d>>s;

	auto res=expr();
	rep(i,d+1) printf("%lld%c",res[i],i<d?' ':'\n');

	return 0;
}
