#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint w,h,n; scanf("%lld%lld%lld",&w,&h,&n);
	vector<int> row(n),col(n);
	rep(i,n) scanf("%d%d",&col[i],&row[i]);

	sort(row.begin(),row.end());
	sort(col.begin(),col.end());
	row.erase(unique(row.begin(),row.end()),row.end());
	col.erase(unique(col.begin(),col.end()),col.end());

	cout<<w*row.size()+h*col.size()-1LL*row.size()*col.size()-n<<'\n';

	return 0;
}
