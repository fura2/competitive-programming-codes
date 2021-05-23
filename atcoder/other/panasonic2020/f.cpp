#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;
using lint=long long;

lint pow3[31]; // pow3[i] = 3^i

lint to_int(vector<int> s){
	lint a=0;
	rep(i,s.size()) a=a*3+s[i];
	return a;
}

lint solve(vector<int> x1,vector<int> y1,vector<int> x2,vector<int> y2){
	int n=x1.size();
	if(n==0) return 0;

	lint dist_x=abs(to_int(x1)-to_int(x2));
	lint dist_y=abs(to_int(y1)-to_int(y2));

	if(y1[0]==y2[0] && x1[0]==x2[0]){
		x1=vector<int>(x1.begin()+1,x1.end());
		y1=vector<int>(y1.begin()+1,y1.end());
		x2=vector<int>(x2.begin()+1,x2.end());
		y2=vector<int>(y2.begin()+1,y2.end());
		return solve(x1,y1,x2,y2);
	}
	else if(y1[0]!=y2[0] && x1[0]!=x2[0]){
		return dist_x+dist_y;
	}
	else if(abs(y1[0]-y2[0])==2 && x1[0]==1 && x2[0]==1) {
		vector<int> xl(n,2); xl[0]=0;
		vector<int> xr(n,0); xr[0]=2;
		lint dist_l=to_int(x1)-to_int(xl)+to_int(x2)-to_int(xl); // 左回り
		lint dist_r=to_int(xr)-to_int(x1)+to_int(xr)-to_int(x2); // 右回り
		return min(dist_l,dist_r)+dist_y;
	}
	else if(abs(x1[0]-x2[0])==2 && y1[0]==1 && y2[0]==1) {
		return solve(y1,x1,y2,x2);
	}
	else{
		// (x1,y1) が左上のブロックに来るように調整
		if(y1[0]==1 || x1[0]==1){
			swap(y1,y2);
			swap(x1,x2);
		}
		if(x1[0]==2){
			rep(i,n){
				x1[i]=2-x1[i];
				x2[i]=2-x2[i];
			}
		}
		if(y1[0]==2){
			rep(i,n){
				y1[i]=2-y1[i];
				y2[i]=2-y2[i];
			}
		}

		// (x2,y2) が上段に来るように調整
		if(y2[0]!=0){
			swap(x1,y1);
			swap(x2,y2);
		}

		if(n==1 || y1[1]!=y2[1]){ // 上段の中で違う高さにある
			return dist_x+dist_y;
		}
		else{ // 上段の中で同じ高さにある
			if(x1[1]==2 && x2[0]==1 && x2[1]==0){ // 隣接している
				y1[1]=0;
				y2[1]=0;
				x1[1]=1;
				x2[0]=0;
				x2[1]=2;
				return solve(x1,y1,x2,y2);
			}
			else{
				lint cost=0;
				cost-=x1[1]*pow3[n-2];
				x1[1]=0;
				cost+=x2[0]*pow3[n-1]-(2-x2[1])*pow3[n-2];
				x2[0]=0;
				x2[1]=2;
				return solve(x1,y1,x2,y2)+cost;
			}
		}
	}
}

int main(){
	pow3[0]=1;
	rep(i,30) pow3[i+1]=pow3[i]*3;

	int q; scanf("%d",&q);
	rep(_,q){
		lint a,b,c,d; scanf("%lld%lld%lld%lld",&a,&b,&c,&d); a--; b--; c--; d--;

		auto to_ternary=[](lint a){
			vector<int> s;
			rep(i,30){
				s.emplace_back(a%3);
				a/=3;
			}
			reverse(s.begin(),s.end());
			return s;
		};

		printf("%lld\n",solve(to_ternary(a),to_ternary(b),to_ternary(c),to_ternary(d)));
	}

	return 0;
}
