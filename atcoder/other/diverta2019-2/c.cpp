#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	vector<int> P,M;
	rep(i,n) (a[i]>=0?P:M).emplace_back(a[i]);

	if(P.empty()){
		int x=*max_element(a.begin(),a.end());
		P={x};
		M.erase(find(M.begin(),M.end(),x));
	}
	if(M.empty()){
		int x=*min_element(a.begin(),a.end());
		M={x};
		P.erase(find(P.begin(),P.end(),x));
	}

	int np=P.size(),nm=M.size();
	vector<pair<int,int>> ans;
	for(int i=1;i<nm;i++){
		ans.emplace_back(P[0],M[i]);
		P[0]-=M[i];
	}
	for(int i=1;i<np;i++){
		ans.emplace_back(M[0],P[i]);
		M[0]-=P[i];
	}
	ans.emplace_back(P[0],M[0]);

	printf("%d\n",P[0]-M[0]);
	for(auto p:ans) printf("%d %d\n",p.first,p.second);

	return 0;
}
