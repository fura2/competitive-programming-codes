#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<pair<int,int>> a(n);
	rep(i,n) scanf("%d%d",&a[i].second,&a[i].first);
	vector<int> b(m);
	rep(i,m) scanf("%d",&b[i]);

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	int pos=m-1;
	for(int i=n-1;i>=0;i--){
		if(pos>=0 && a[i].second<=b[pos]) pos--;
	}
	printf("%d\n",m-pos-1);

	return 0;
}
