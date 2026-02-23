#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	string s="DiscoPresentsDiscoveryChannelProgrammingContest2016";
	rep(i,s.length()){
		putchar(s[i]);
		if(i==s.length()-1 || (i+1)%n==0) puts("");
	}
	return 0;
}
