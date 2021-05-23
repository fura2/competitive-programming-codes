#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	rep(m,n+1){
		int total=2*m+4*(n-m);
		vector<int> b(n);
		rep(i,n) b[i]=(i<m?total-2:total-4);
		reverse(b.begin(),b.end());
		if(a==b){
			printf("%d %d\n",m,n-m);
			break;
		}
	}

	return 0;
}
