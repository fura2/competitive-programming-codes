// Day 3: Anagram

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint fact[21];

lint dfs(string s){
	int n=s.length();
	if(n==1) return 1;

	int freq[128]={};
	rep(i,n) freq[s[i]]++;

	lint res=dfs(s.substr(1));
	for(char c='A';c<s[0];c++) if(freq[c]>0) {
		freq[c]--;

		lint tmp=fact[n-1];
		for(char d='A';d<='Z';d++) tmp/=fact[freq[d]];
		res+=tmp;

		freq[c]++;
	}
	return res;
}

int main(){
	fact[0]=1;
	rep(i,20) fact[i+1]=(i+1)*fact[i];

	string s; cin>>s;
	cout<<dfs(s)<<'\n';
	return 0;
}
