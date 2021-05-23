#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());


	rep(i,n){
		int x=min(a[i],m);
		a[i]-=x;
		m-=x;
	}

	printf("%d\n",count(a.begin(),a.end(),0));

	return 0;
}
