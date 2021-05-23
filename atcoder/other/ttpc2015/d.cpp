#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

bool is_prime(long long a){
	if(a%2==0) return a==2;
	for(long long i=3;i*i<=a;i+=2) if(a%i==0) return false;
	return a!=1;
}

string s;
int f[128];
bool used[10];

lint dfs(int i){
	if(i==s.length()){
		lint res=0;
		rep(j,s.length()) res=res*10+f[s[j]];
		return is_prime(res)?res:-1;
	}

	if(f[s[i]]!=0){
		return dfs(i+1);
	}
	else{
		for(int d:{1,3,5,7,9}) if(!used[d]) {
			used[d]=true;
			f[s[i]]=d;
			lint res=dfs(i+1);
			if(res!=-1) return res;
			f[s[i]]=0;
			used[d]=false;
		}
		return -1;
	}
}

int main(){
	cin>>s;
	printf("%lld\n",dfs(0));
	return 0;
}
