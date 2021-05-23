#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c; cin>>a>>b>>c;

	if(c==0){
		cout<<"ccW\n";
		return 0;
	}

	for(int x=1;x<=5000;x++) if(a*x==c) {
		cout<<string(x,'c')<<string(x-1,'C')<<"\n";
		return 0;
	}
	for(int y=1;y<=5000;y++) if(b*y==c) {
		cout<<string(y,'w')<<string(y-1,'C')<<"\n";
		return 0;
	}
	for(int x=1;x<=5000;x++) for(int y=1;y<=5000-x;y++) {
		if(a*x+b*y==c){
			cout<<string(y,'w')<<string(y-1,'C')<<string(x,'c')<<string(x-1,'C')<<"C\n";
			return 0;
		}
		if(a*x-b*y==c){
			cout<<string(y,'w')<<string(y-1,'C')<<string(x,'c')<<string(x-1,'C')<<"W\n";
			return 0;
		}
		if(-a*x+b*y==c){
			cout<<string(x,'c')<<string(x-1,'C')<<string(y,'w')<<string(y-1,'C')<<"W\n";
			return 0;
		}
	}
	cout<<"NO\n";

	return 0;
}
