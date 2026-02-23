#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

random_device seed_gen;
mt19937 rng(seed_gen());

int main(){
	int n=13;
	char B[13][14]={};
	while(1){
		set<string> S;
		rep(i,n) rep(j,n) {
			vector<int> p(27);
			iota(p.begin(),p.end(),0);
			shuffle(p.begin(),p.end()-1,rng);

			rep(l,27){
				char c='a'+p[l];
				B[i][j]=c;

				bool ok=true;
				vector<string> tmp;
				if(i>0){
					string s(2,c);
					s[0]=B[i-1][j];
					if(S.count(s)>0) ok=false;
					else tmp.emplace_back(s);
				}
				if(j>0){
					string s(2,c);
					s[0]=B[i][j-1];
					if(S.count(s)>0) ok=false;
					else tmp.emplace_back(s);
				}
				if(ok){
					for(auto s:tmp) S.emplace(s);
					break;
				}
			}
		}

		bool end=true;
		rep(i,n) rep(j,n) if(!isalpha(B[i][j])) end=false;
		if(end){
			rep(i,n) cout<<B[i]<<'\n';
			return 0;
		}
	}
}
