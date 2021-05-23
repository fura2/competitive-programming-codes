#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	lint sum=accumulate(a.begin(),a.end(),0LL);

	priority_queue<int> Q(a.begin(),a.end());

	int q; scanf("%d",&q);
	rep(_,q){
		int x; scanf("%d",&x);

		vector<int> next;
		while(!Q.empty() && Q.top()>=x){
			sum-=Q.top();
			next.emplace_back(Q.top()%x);
			Q.pop();
		}

		rep(i,next.size()){
			sum+=next[i];
			Q.emplace(next[i]);
		}

		printf("%lld\n",sum);
	}

	return 0;
}
