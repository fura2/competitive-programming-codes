#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,n;
	string s; cin>>a>>b>>n>>s;

	rep(i,n){
		if(s[i]=='S'){
			if(a>0) a--;
		}
		if(s[i]=='C'){
			if(b>0) b--;
		}
		if(s[i]=='E'){
			if(a>0 && a>=b) a--;
			else if(b>0) b--;
		}
	}

	printf("%d\n%d\n",a,b);

	return 0;
}
