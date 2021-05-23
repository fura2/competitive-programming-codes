#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

int main(){
	const lint L=10000000000LL;

	int n; scanf("%d",&n);
	vector<lint> a(n),b(n);
	rep(i,n){
		string s; cin>>s;
		if(count(s.begin(),s.end(),'.')==0) s+='.';
		int pos=find(s.begin(),s.end(),'.')-s.begin();
		s+=string(11-(s.length()-pos),'0');

		a[i]=stoll(s.substr(0,pos));
		b[i]=stoll(s.substr(pos+1));
		if(s[0]=='-' && b[i]>0){
			a[i]--;
			b[i]=L-b[i];
		}
	}

	lint ans1=accumulate(a.begin(),a.end(),0LL);
	lint ans2=accumulate(b.begin(),b.end(),0LL);
	ans1+=ans2/L;
	ans2%=L;
	if(ans1<0 && ans2>0){
		ans1++;
		ans2=L-ans2;
		if(ans1==0) printf("-0");
		else        printf("%lld",ans1);
		printf(".%010lld\n",ans2);
	}
	else{
		printf("%lld.%010lld\n",ans1,ans2);
	}

	return 0;
}
