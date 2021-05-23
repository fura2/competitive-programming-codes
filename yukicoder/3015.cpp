#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

unsigned long long get_hash(string s, unsigned long long a, unsigned long long b){
	unsigned long long hash = 0;

	for(int i = 0; i < s.size(); i++){
		hash = (hash * a + s[i]) % b;
	}

	return hash;
}

random_device seed_gen;
mt19937 rng(seed_gen());

int main(){
	int a,b; cin>>a>>b;

	vector<string> H(b);
	while(1){
		string s;
		rep(i,30) s+='a'+rng()%26;
		int h=get_hash(s,a,b);
		if(H[h].empty()){
			H[h]=s;
		}
		else if(H[h]!=s){
			cout<<H[h]<<'\n'<<s<<'\n';
			break;
		}
	}
	return 0;
}
