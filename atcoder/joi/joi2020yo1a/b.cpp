#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n;
	string s; cin>>n>>s;
	int cnt=0;
	for(char c:s) if(strchr("aiueo",c)) cnt++;
	printf("%d\n",cnt);
	return 0;
}
