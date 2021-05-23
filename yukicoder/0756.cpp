#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int d; scanf("%d",&d);
	string s="0.";
	for(int i=1;i<100;i++) s+=to_string(i);
	printf("%c\n",s[d+1]);
	return 0;
}
