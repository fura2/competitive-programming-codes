#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	if(n%2==0) cout<<string(n/2,'1')<<'\n';
	else       cout<<"7"+string(n/2-1,'1')<<'\n';
	return 0;
}
