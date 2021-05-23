#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int a[3];
	rep(i,3) scanf("%d",&a[i]);

	if(a[0]==a[1] || a[0]==a[2] || a[1]==a[2]) return puts("0"),0;

	int mx=*max_element(a,a+3);
	int mn=*min_element(a,a+3);
	if(a[1]==mx || a[1]==mn) return puts("INF"),0;

	int ans=0;
	for(int p=1;p<=1000;p++){
		int b[3];
		rep(i,3) b[i]=a[i]%p;
		mx=*max_element(b,b+3);
		mn=*min_element(b,b+3);
		if(b[0]!=b[1] && b[0]!=b[2] && b[1]!=b[2] && (b[1]==mx || b[1]==mn)) ans++;
	}
	printf("%d\n",ans);

	return 0;
}
