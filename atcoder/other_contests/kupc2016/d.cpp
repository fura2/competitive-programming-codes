#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

bool ask(string s1,string s2){
	cout<<s1<<endl;
	cout<<s2<<endl;
	string res; cin>>res;
	if(res=="end") exit(0);
	return res=="T";
}

int main(){
	int n; cin>>n;

	string s1,s2;
	while(s1.length()<n){
		bool ok=false;
		rep(d1,2) if(!ok) rep(d2,2) if(!ok) {
			s1+=".#"[d1];
			s2+=".#"[d2];
			if(ask(s1,s2)){
				ok=true;
				break;
			}
			s1.pop_back();
			s2.pop_back();
		}
		if(!ok) break;
	}

	while(s1.length()<n){
		bool ok=false;
		rep(d1,2) if(!ok) rep(d2,2) if(!ok) {
			s1=".#"[d1]+s1;
			s2=".#"[d2]+s2;
			if(ask(s1,s2)){
				ok=true;
				break;
			}
			s1=s1.substr(1);
			s2=s2.substr(1);
		}
		if(!ok) break;
	}

	return 0;
}
