#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double EPS=1e-8;
const double PI=acos(-1);

int solve(vector<pair<double,double>> I){
	int n=I.size();
	sort(I.begin(),I.end(),[](pair<double,double> I,pair<double,double> J){
		return I.second+EPS<J.second;
	});

	int res=0;
	double x=-1e9;
	rep(i,n){
		if(x+EPS<I[i].first){
			res++;
			x=I[i].second;
		}
	}
	return res;
}

int main(){
	int n; scanf("%d",&n);
	vector<double> x1(n),y1(n),x2(n),y2(n);
	rep(i,n) scanf("%lf%lf%lf%lf",&x1[i],&y1[i],&x2[i],&y2[i]);

	vector<pair<double,double>> I(n);
	rep(i,n){
		double t1=atan2(y1[i],x1[i]);
		double t2=atan2(y2[i],x2[i]);
		if(t1<-EPS) t1+=2*PI;
		if(t2<-EPS) t2+=2*PI;
		if(t2<t1) swap(t1,t2);
		if(t2-t1>PI){
			swap(t1,t2);
			t2+=2*PI;
		}
		I[i]={t1,t2};
	}

	int ans=n;
	rep(i,n) rep(k,2) {
		double x=(k==0?I[i].first:I[i].second);
		vector<pair<double,double>> J;
		rep(j,n){
			if((I[j].second     +EPS<x || x+EPS<I[j].first)
			&& (I[j].second-2*PI+EPS<x || x+EPS<I[j].first-2*PI)
			&& (I[j].second+2*PI+EPS<x || x+EPS<I[j].first+2*PI)){
				J.emplace_back(I[j]);
			}
		}
		ans=min(ans,solve(J)+1);
	}
	printf("%d\n",ans);

	return 0;
}
