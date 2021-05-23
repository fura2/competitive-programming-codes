#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int n=0;
	rep(i,s.length()) n=(4*n+(s[i]-'0'))%15;

	if(n==0) puts("FizzBuzz");
	else if(n%3==0) puts("Fizz");
	else if(n%5==0) puts("Buzz");
	else cout<<s<<'\n';

	return 0;
}
