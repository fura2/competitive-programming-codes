#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,m,p,q,r;
	cin>>n>>m>>p>>q>>r;
	p--;

	vector<pair<int,int>> A{{0,n}};

	auto partition=[&](int x){
		int sum=0;
		rep(i,A.size()){
			sum+=A[i].second-A[i].first;
			if(sum==x) return;
			if(sum>x){
				A[i].second-=sum-x;
				A.insert(A.begin()+i+1,{A[i].second,A[i].second+sum-x});
				return;
			}
		}
	};

	auto find_pos=[&](int x){
		int sum=0;
		rep(i,A.size()){
			sum+=A[i].second-A[i].first;
			if(sum==x) return i+1;
		}
		return -1;
	};

	rep(_,m){
		int x,y; cin>>x>>y;

		partition(x);
		partition(y);

		int i0=find_pos(x);
		int i1=find_pos(y);

		vector<pair<int,int>> next;
		next.insert(next.end(),A.begin()+i1,A.end());
		next.insert(next.end(),A.begin()+i0,A.begin()+i1);
		next.insert(next.end(),A.begin(),A.begin()+i0);
		A=next;
	}

	partition(p);
	partition(q);
	int i0=find_pos(p);
	int i1=find_pos(q);

	int ans=0;
	for(int i=i0;i<i1;i++){
		ans+=max(min(A[i].second,r)-A[i].first,0);
	}
	cout<<ans<<endl;

	return 0;
}
