#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	for(int i=k;i<n;i++){
		puts(a[i]>a[i-k]?"Yes":"No");
	}

	return 0;
}
