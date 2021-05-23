#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.rbegin(),a.rend());

	int ans=0;
	rep(i,n){
		if(m>0){
			m-=a[i];
			ans++;
		}
	}
	printf("%d\n",ans);

	return 0;
}
