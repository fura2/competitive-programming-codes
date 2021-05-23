#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

template<class T>
vector<pair<T,int>> run_length_encoding(const vector<T>& a){
	vector<pair<T,int>> res;
	int n=a.size(),pre=0;
	rep(i,n) if(i==n-1 || a[i]!=a[i+1]) res.emplace_back(a[i],i-pre+1), pre=i+1;
	return res;
}

int fact[]={1,1,2,6,24,120,720};

int f(const vector<int> A){ // multinomial coefficient
	int res=fact[6];
	for(auto p:run_length_encoding(A)) res/=fact[p.second];
	return res;
}

int main(){
	int x;
	{
		int x1,x2; scanf("%d.%d",&x1,&x2);
		x=4*x1+4*x2/100;
	}

	lint ans=0;
	rep(a2,101) for(int a3=a2;a3<=100;a3++) for(int a4=a3;a4<=100;a4++) {
		int a5=x-(a2+a3+a4);
		if(!(a4<=a5 && a5<=100)) continue;

		vector<int> A={0,a2,a3,a4,a5,0};
		// a1 = a2 and a5 = a6
		A[0]=a2; A[5]=a5;
		ans+=f(A);
		// a1 = a2 and a5 < a6
		A[0]=a2; A[5]=a5+1;
		ans+=f(A)*(100-a5);
		// a1 < a2 and a5 = a6
		A[0]=a2-1; A[5]=a5;
		ans+=f(A)*a2;
		// a1 < a2 and a5 < a6
		A[0]=a2-1; A[5]=a5+1;
		ans+=f(A)*a2*(100-a5);
	}
	printf("%lld\n",ans);

	return 0;
}
