#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	printf("%d\n",count(s.begin(),s.end(),'m'));
	return 0;
}
