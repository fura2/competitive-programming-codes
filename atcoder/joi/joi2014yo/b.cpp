#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(n),b(m);
	rep(i,n) scanf("%d",&a[i]);
	rep(j,m) scanf("%d",&b[j]);

	vector<int> cnt(n);
	rep(j,m){
		rep(i,n) if(a[i]<=b[j]) {
			cnt[i]++;
			break;
		}
	}
	printf("%d\n",max_element(cnt.begin(),cnt.end())-cnt.begin()+1);

	return 0;
}
