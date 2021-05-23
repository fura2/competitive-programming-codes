#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int L,n; scanf("%d%d",&L,&n);
	vector<int> w(n);
	rep(i,n) scanf("%d",&w[i]);

	sort(w.begin(),w.end());

	int sum=0;
	rep(i,n+1){
		if(i==n || sum+w[i]>L){ printf("%d\n",i); break; }
		sum+=w[i];
	}

	return 0;
}
