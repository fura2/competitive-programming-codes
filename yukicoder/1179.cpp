#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	double a,b,c; cin>>a>>b>>c;

	double D=b*b-4*a*c;
	if(D<0){
		puts("imaginary");
	}
	else if(D==0){
		printf("%.15f\n",-b/(2*a));
	}
	else{
		if(a<0){
			a*=-1;
			b*=-1;
			c*=-1;
		}
		printf("%.15f %.15f\n",(-b-sqrt(D))/(2*a),(-b+sqrt(D))/(2*a));
	}
	return 0;
}
