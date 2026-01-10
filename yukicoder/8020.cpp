#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int hist[128]={};
	for(char c:s) hist[c]++;
	printf("%d %d %d %d %d\n",hist['Y'],hist['E'],hist['A'],hist['H'],hist['!']);
	return 0;
}
