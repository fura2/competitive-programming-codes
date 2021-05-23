#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	lint a,b,c,d; cin>>a>>b>>c>>d;

	lint D=(a-c)*(a-c)-8*(b-d);
	if(D<0){
		puts("No");
	}
	else if(D==0){
		puts("Yes");
	}
	else{
		double x1=(-(a-c)+sqrt(D))/4;
		double x2=(-(a-c)-sqrt(D))/4;
		double y1=x1*x1+a*x1+b;
		double y2=x2*x2+a*x2+b;
		double p=(y2-y1)/(x2-x1);
		double q=y1-p*x1;
		printf("%.9f %.9f\n",p,q);
	}
	return 0;
}
