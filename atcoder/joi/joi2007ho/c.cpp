#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n; scanf("%d",&n);
	vector<pair<int,int>> p(n);
	rep(i,n) scanf("%d%d",&p[i].first,&p[i].second);

	sort(p.begin(),p.end());

	double ans=0;
	rep(i,n) for(int j=i+1;j<n;j++) {
		auto [x1,y1]=p[i];
		auto [x2,y2]=p[j];
		double cx=(x1+x2)/2.0;
		double cy=(y1+y2)/2.0;
		double vx=(x2-x1)/2.0;
		double vy=(y2-y1)/2.0;
		double x3=cx-vy,y3=cy+vx;
		double x4=cx+vy,y4=cy-vx;
		if(int(x3)==x3 && int(y3)==y3){
			if(binary_search(p.begin(),p.end(),make_pair(int(x3),int(y3)))
			&& binary_search(p.begin(),p.end(),make_pair(int(x4),int(y4)))){
				ans=max(ans,hypot(x2-x1,y2-y1)*hypot(x2-x1,y2-y1)/2);
			}
		}
	}
	printf("%.0f\n",ans);

	return 0;
}
