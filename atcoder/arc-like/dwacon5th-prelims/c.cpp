#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

long long solve(int n,const string &s,int k){
	vector<long long> dp1(n+1); // dp1[i+1] := # of D in s(i-k,i]
	vector<long long> dp2(n+1); // dp2[i+1] := # of M in s(i-k,i]
	vector<long long> dp3(n+1); // dp3[i+1] := # of subseq DM in s(i-k,i]

	rep(i,n){
		dp1[i+1]=dp1[i];
		dp2[i+1]=dp2[i];
		if(i-k>=0 && s[i-k]=='D') dp1[i+1]--;
		if(i-k>=0 && s[i-k]=='M') dp2[i+1]--;
		if(s[i]=='D') dp1[i+1]++;
		if(s[i]=='M') dp2[i+1]++;
	}

	rep(i,n){
		dp3[i+1]=dp3[i];
		if(i-k>=0 && s[i-k]=='D') dp3[i+1]-=dp2[i];
		if(s[i]=='M') dp3[i+1]+=dp1[i+1];
	}

	long long res=0;
	rep(i,n) if(s[i]=='C') res+=dp3[i+1];
	return res;
}

int main(){
	int n,q,k;
	string s; cin>>n>>s>>q;

	rep(i,q) cin>>k, cout<<solve(n,s,k)<<endl;

	return 0;
}
