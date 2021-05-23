#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

double F(int n){
	double sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		sum1+=pow(0.81,i);
		sum2+=pow(0.9,i);
	}
	return sqrt(sum1)/sum2;
}

double f(int n){
	double F_inf=sqrt(1/0.19-1)/(1/0.1-1);
	return (F(n)-F_inf)/(F(1)-F_inf)*1200;
}

double g(double x){
	return pow(2,x/800);
}
double g_inv(double x){
	return 800*log2(x);
}

int main(){
	int n; scanf("%d",&n);
	vector<double> a(n);
	rep(i,n) scanf("%lf",&a[i]);

	double sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		sum1+=g(a[i-1])*pow(0.9,i);
		sum2+=pow(0.9,i);
	}
	printf("%.0f\n",g_inv(sum1/sum2)-f(n));

	return 0;
}
