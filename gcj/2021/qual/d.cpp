#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int ask(int i,int j,int k){
	printf("%d %d %d\n",i+1,j+1,k+1);
	fflush(stdout);
	int res; scanf("%d",&res); res--;
	return res;
}

void answer(vector<int> ans){
	int n=ans.size();
	rep(i,n) printf("%d%c",ans[i]+1,i<n-1?' ':'\n');
	fflush(stdout);
	int res; scanf("%d",&res);
	assert(res==1);
}

void solve(int n){
	vector<int> A;
	{
		int r=ask(0,1,2);
		if     (r==0) A.emplace_back(1), A.emplace_back(0), A.emplace_back(2);
		else if(r==1) A.emplace_back(0), A.emplace_back(1), A.emplace_back(2);
		else          A.emplace_back(0), A.emplace_back(2), A.emplace_back(1);
	}

	for(int i=3;i<n;i++){
		int m=A.size();

		int lo=0,hi=m;
		while(hi-lo>0){
			int mi=(lo+hi)/2-1;
			if(mi<0) mi++;

			int r=ask(A[mi],A[mi+1],i);
			if(r==i){
				lo=mi+1;
				break;
			}
			else if(r==A[mi]){
				hi=mi;
			}
			else{
				lo=mi+2;
			}
		}
		A.insert(A.begin()+lo,i);
	}

	answer(A);
}

int main(){
	int t,n,q; scanf("%d%d%d",&t,&n,&q);
	rep(_,t){
		solve(n);
	}
	return 0;
}
