#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int sum=0;
	rep(i,n+1){
		if(i<n) sum+=a[i];
		if(i==n || sum>2018){
			printf("%d\n",i);
			break;
		}
	}

	return 0;
}
