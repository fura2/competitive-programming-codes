#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string d[]={"Mon","Tue","Wed","Thu","Fri","Sat","Sun"};

	int n; cin>>n;
	rep(i,n){
		string s; cin>>s;
		rep(j,7) if(s==d[j]) cout<<d[(j+1)%7]<<'\n';
	}

	return 0;
}
