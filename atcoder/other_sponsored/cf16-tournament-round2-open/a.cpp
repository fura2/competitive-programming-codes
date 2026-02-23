#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int x;
	double p; scanf("%d%lf",&x,&p);
	p/=100;

	if(x%2==0){
		printf("%.9f\n",(x/2)/p);
	}
	else{
		double res1=(x/2)/p;
		double res2=(x/2+1)/p;
		printf("%.9f\n",1+p*res1+(1-p)*res2);
	}

	return 0;
}
