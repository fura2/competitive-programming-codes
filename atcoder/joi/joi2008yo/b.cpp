#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int n=s.length();

	int ans1=0,ans2=0;
	rep(i,n-2){
		if(s.substr(i,3)=="JOI") ans1++;
		if(s.substr(i,3)=="IOI") ans2++;
	}
	printf("%d\n%d\n",ans1,ans2);

	return 0;
}
