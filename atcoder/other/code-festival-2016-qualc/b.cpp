#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int k,n; scanf("%d%d",&k,&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int mx=*max_element(a.begin(),a.end());
	printf("%d\n",max(mx-1-(k-mx),0));

	return 0;
}
