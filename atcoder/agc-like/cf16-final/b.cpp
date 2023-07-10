#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);

	int lo=0,hi=1e4;
	vector<int> Ans;
	while(hi-lo>1){
		int mi=(lo+hi)/2;
		int sum=0;
		vector<int> S;
		for(int x=mi;x>0;x--) if(sum+x<=n) {
			sum+=x;
			S.emplace_back(x);
		}
		if(sum==n) hi=mi, Ans=S;
		else       lo=mi;
	}

	for(int x:Ans) printf("%d\n",x);

	return 0;
}
