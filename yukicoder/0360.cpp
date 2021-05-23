#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	vector<int> a(7);
	rep(i,7) scanf("%d",&a[i]);

	sort(a.begin(),a.end());

	do{
		bool ok=true;
		rep(i,5){
			if(set<int>{a[i],a[i+1],a[i+2]}.size()!=3) ok=false;
			if(max({a[i],a[i+1],a[i+2]})!=a[i+1]
			&& min({a[i],a[i+1],a[i+2]})!=a[i+1]) ok=false;
			if(a[i]>a[i+2]) ok=false;
		}
		if(ok) return puts("YES"),0;
	}while(next_permutation(a.begin(),a.end()));
	puts("NO");

	return 0;
}
