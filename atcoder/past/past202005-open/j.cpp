#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m; scanf("%d%d",&n,&m);
	vector<int> a(m);
	rep(i,m) scanf("%d",&a[i]), a[i]*=-1;

	vector<int> lis(n,INT_MAX);
	for(int x:a){
		auto it=upper_bound(lis.begin(),lis.end(),x);
		if(it!=lis.end()){
			*it=x;
			printf("%ld\n",it-lis.begin()+1);
		}
		else puts("-1");
	}

	return 0;
}
