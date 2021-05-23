#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	int cnt[7]={};
	rep(i,n){ int a; scanf("%d",&a); cnt[a]++; }
	int mx=*max_element(cnt,cnt+7);
	for(int i=6;;i--) if(cnt[i]==mx) { printf("%d\n",i); break; }
	return 0;
}
