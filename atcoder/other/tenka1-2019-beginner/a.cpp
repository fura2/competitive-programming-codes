#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);
	puts(min(a,b)<=c&&c<=max(a,b)?"Yes":"No");
	return 0;
}