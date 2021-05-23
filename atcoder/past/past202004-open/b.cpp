#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int hist[128]={};
	for(char c:s) hist[c]++;
	printf("%c\n",max_element(hist+'a',hist+'d')-hist);
	return 0;
}
