#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a; scanf("%d",&a);
	for(int i=1;i*i*i<=a;i++) if(i*i*i==a) return puts("YES"),0;
	puts("NO");
	return 0;
}
