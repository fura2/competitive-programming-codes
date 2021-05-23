#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int l=0,r=0;
	rep(i,s.length()-1){
		if(s[i]=='*' && s[i+1]==')') l++;
		if(s[i]=='(' && s[i+1]=='*') r++;
	}
	printf("%d %d\n",l,r);

	return 0;
}
