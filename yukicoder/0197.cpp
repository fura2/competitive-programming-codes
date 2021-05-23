#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s,t;
	int n; cin>>s>>n>>t;

	bool ok;
	if(n==0){
		ok=(s!=t);
	}
	else{
		ok=(count(s.begin(),s.end(),'o')!=count(t.begin(),t.end(),'o'));
		if(n==1 && !ok){
			if(s=="oxx" && !(t=="oxx" || t=="xox")) ok=true;
			if(s=="xox" && !(t=="oxx" || t=="xxo")) ok=true;
			if(s=="xxo" && !(t=="xox" || t=="xxo")) ok=true;
			if(s=="xoo" && !(t=="xoo" || t=="oxo")) ok=true;
			if(s=="oxo" && !(t=="xoo" || t=="oox")) ok=true;
			if(s=="oox" && !(t=="oxo" || t=="oox")) ok=true;
		}
	}
	puts(ok?"SUCCESS":"FAILURE");

	return 0;
}
