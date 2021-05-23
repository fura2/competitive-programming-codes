#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const double PI=acos(-1);

int main(){
	int k; scanf("%d",&k);

	if(k==0){
		printf("%.15f\n",PI*PI/6);
	}
	else{
		double ans=0;
		rep(i,k) ans+=1.0/(i+1);
		ans/=k;
		printf("%.15f\n",ans);
	}

	return 0;
}
