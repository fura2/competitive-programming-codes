#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(){
	int n,x,y; scanf("%d%d%d",&n,&x,&y);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	sort(a.rbegin(),a.rend());

	rep(i,n/2){
		x+=a[2*i];
		y+=a[2*i+1];
	}

	puts(x>y?"Takahashi":x<y?"Aoki":"Draw");

	return 0;
}
