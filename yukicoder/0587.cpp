#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	string s; cin>>s;
	int hist[128]={};
	for(char c:s) hist[c]++;
	if(count(hist,hist+128,1)==1 && count(hist,hist+128,2)==6){
		printf("%c\n",find(hist,hist+128,1)-hist);
	}
	else puts("Impossible");
	return 0;
}
