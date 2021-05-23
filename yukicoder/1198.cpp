#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	bool four=(stoi(s.substr(max(n-2,0)))%4==0);
	bool odd=(s.back()-'0')%2;

	if((odd && s!="1") || (four && s!="4")){
		puts("1");
	}
	else{
		puts("-1");
	}

	return 0;
}
