#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;

	int freq[128]={};
	for(char c:s) freq[c]++;

	puts(freq['y']==1&&freq['a']==1&&freq['h']==1&&freq['o']==2?"YES":"NO");

	return 0;
}
