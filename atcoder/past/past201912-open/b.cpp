#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	rep(i,n-1){
		if(a[i]==a[i+1]) puts("stay");
		else printf("%s %d\n",a[i]>a[i+1]?"down":"up",abs(a[i+1]-a[i]));
	}

	return 0;
}
