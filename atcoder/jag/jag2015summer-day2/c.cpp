#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int INF=1<<29;

int main(){
	string s; cin>>s;
	int n=s.length();

	int c[3];
	rep(i,3) c[i]=count(s.begin(),s.end(),'A'+i);

	vector<pair<int,int>> op;
	while(max({c[0],c[1],c[2]})>1){
		int mn=min({c[0],c[1],c[2]});
		if(mn<=0){
			puts("No");
			return 0;
		}

		int i_min=-1;
		rep(i,3) if(c[i]==mn) {
			if(i_min!=-1){
				puts("No");
				return 0;
			}
			i_min=i;
		}

		int k=INF;
		rep(i,3) if(i!=i_min) {
			k=min(k,(c[i]-1)/mn);
		}
		rep(i,3) if(i!=i_min) {
			c[i]-=k*mn;
		}
		op.emplace_back(i_min,k);
	}
	if(!(c[0]==1 && c[1]==1 && c[2]==1)){
		puts("No");
		return 0;
	}

	reverse(op.begin(),op.end());

	string t="ABC";
	for(auto [i,k]:op){
		string t2;
		if(i==0){ // A
			for(char c:t){
				t2+=c;
				if(c=='A') rep(_,k) t2+="BC";
			}
		}
		else if(i==1){ // B
			for(char c:t){
				if(c=='B') t2+=string(k,'A');
				t2+=c;
				if(c=='B') t2+=string(k,'C');
			}
		}
		else{ // C
			for(char c:t){
				if(c=='C') rep(_,k) t2+="AB";
				t2+=c;
			}
		}
		t=t2;
	}
	puts(t==s?"Yes":"No");

	return 0;
}
