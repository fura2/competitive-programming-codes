#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,T; cin>>n>>T;

	double sum1=0,sum2=0;
	rep(i,n){
		string s;
		char c;
		int r; cin>>s>>c>>r;
		if(c!='N' && s.find("Alicia")!=string::npos){
			sum1+=r;
		}
		sum2+=r;
	}
	printf("%.9f\n",(T-T/10)*sum1/sum2);

	return 0;
}
