// Day 2: a + b problem

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

const long long INF=1LL<<61;

int main(){
	auto input=[](){
		int n; scanf("%d",&n);
		vector<pair<int,lint>> res(n);
		rep(i,n) scanf("%d%lld",&res[i].first,&res[i].second);
		return res;
	};

	auto a=input();
	auto b=input();

	deque<pair<int,lint>> res;
	int carry=0;
	while(!a.empty() || !b.empty()){
		int d1,d2;
		lint m1,m2;

		if(!a.empty()){
			tie(d1,m1)=a.back();
			a.pop_back();
		}
		else{
			d1=0;
			m1=INF;
		}
		if(!b.empty()){
			tie(d2,m2)=b.back();
			b.pop_back();
		}
		else{
			d2=0;
			m2=INF;
		}

		lint m=min(m1,m2);
		if(m2<m1 && m1<INF){
			a.emplace_back(d1,m1-m2);
		}
		else if(m1<m2 && m2<INF){
			b.emplace_back(d2,m2-m1);
		}

		if(carry==0){
			if(d1+d2<=9){
				res.emplace_front(d1+d2,m);
				carry=0;
			}
			else{
				res.emplace_front((d1+d2)%10,1);
				if(m>1) res.emplace_front((d1+d2+1)%10,m-1);
				carry=1;
			}
		}
		else{
			if(d1+d2<9){
				res.emplace_front(d1+d2+1,1);
				if(m>1) res.emplace_front(d1+d2,m-1);
				carry=0;
			}
			else{
				res.emplace_front((d1+d2+1)%10,m);
				carry=1;
			}
		}
	}
	if(carry==1){
		res.emplace_front(1,1);
	}

	vector<pair<int,lint>> ans;
	lint sum=0;
	rep(i,res.size()+1){
		if(i==res.size() || (i>0 && res[i-1].first!=res[i].first)){
			ans.emplace_back(res[i-1].first,sum);
			sum=0;
		}
		if(i<res.size()) sum+=res[i].second;
	}

	printf("%ld\n",ans.size());
	rep(i,ans.size()) printf("%d %lld\n",ans[i].first,ans[i].second);

	return 0;
}
