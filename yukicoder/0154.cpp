#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool solve(string s){
	int n=s.length();

	vector<int> a;
	for(int i=n-1;i>=0;i--){
		if(s[i]=='R'){
			a.emplace_back(0);
		}
		else if(s[i]=='G'){
			bool ok=false;
			rep(j,a.size()) if(a[j]==0) {
				a[j]++;
				ok=true;
				break;
			}
			if(!ok) return false;
		}
		else{ // 'W'
			bool ok=false;
			rep(j,a.size()) if(a[j]==1) {
				a[j]++;
				ok=true;
				break;
			}
			if(!ok){
				rep(j,a.size()) if(a[j]>=2) {
					a[j]++;
					ok=true;
					break;
				}
			}
			if(!ok) return false;
		}
	}
	rep(j,a.size()) if(a[j]<=1) return false;
	return true;
}

int main(){
	int q; scanf("%d",&q);
	rep(_,q){
		string s; cin>>s;
		puts(solve(s)?"possible":"impossible");
	}
	return 0;
}
