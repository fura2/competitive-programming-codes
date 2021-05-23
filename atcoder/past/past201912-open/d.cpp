#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	bool ok=true;
	rep(i,n) if(a[i]!=i+1) ok=false;
	if(ok) return puts("Correct"),0;

	int x=n,y;
	rep(i,n-1){
		if(a[i]+1<a[i+1]) x=a[i]+1;
		if(a[i]==a[i+1])  y=a[i];
	}
	printf("%d %d\n",y,x);

	return 0;
}
