#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int h,w,a,b;

int subst(int S,int pos,int bit){
	if(bit==0) return S&~(1<<pos);
	else       return S|(1<<pos);
}

int get(int S,int pos){
	return S>>pos&1;
}

char memo[9][9][37][37][2][1<<8];

char dfs(int i,int j,int ta,int tb,int V,int H){
	if(memo[i][j][ta][tb][V][H]!=-1){
		return memo[i][j][ta][tb][V][H];
	}

	char& res=memo[i][j][ta][tb][V][H];
	res=CHAR_MIN;
	if(j==w){
		res=dfs(i+1,0,ta,tb,0,H);
		return res;
	}
	if(i==h){
		if(ta>=a && tb<=b) res=0;
		return res;
	}

	// 四隅
	if(i==0 && j==0){
		rep(b1,2) rep(b2,2) {
			int H2=subst(H,j,b2);
			res=max<char>(res,dfs(i,j+1,ta,tb,b1,H2));
		}
		return res;
	}
	if(i==0 && j==w-1){
		rep(b2,2){
			int H2=subst(H,j,b2);
			res=max<char>(res,dfs(i,j+1,ta,tb,0,H2));
		}
		return res;
	}
	if(i==h-1 && j==0){
		rep(b1,2){
			res=max<char>(res,dfs(i,j+1,ta,tb,b1,H));
		}
		return res;
	}
	if(i==h-1 && j==w-1){
		res=max<char>(res,dfs(i,j+1,ta,tb,0,H));
		return res;
	}

	// 上辺
	if(i==0){
		rep(b1,2) rep(b2,2) {
			char tmp=0;
			if(V==1 && b1==0 && b2==0) tmp=1;
			int H2=subst(H,j,b2);
			res=max<char>(res,dfs(i,j+1,ta,tb,b1,H2)+tmp);
		}
		return res;
	}

	// 下辺
	if(i==h-1){
		rep(b1,2){
			char tmp=0;
			if(V==1 && b1==0 && get(H,j)==1) tmp=1;
			res=max<char>(res,dfs(i,j+1,ta,tb,b1,H)+tmp);
		}
		return res;
	}

	// 左辺
	if(j==0){
		rep(b1,2) rep(b2,2) {
			char tmp=0;
			if(b1==0 && get(H,j)==1 && b2==0) tmp=1;
			int H2=subst(H,j,b2);
			res=max<char>(res,dfs(i,j+1,ta,tb,b1,H2)+tmp);
		}
		return res;
	}

	// 右辺
	if(j==w-1){
		rep(b2,2){
			char tmp=0;
			if(V==1 && get(H,j)==1 && b2==0) tmp=1;
			int H2=subst(H,j,b2);
			res=max<char>(res,dfs(i,j+1,ta,tb,V,H2)+tmp);
		}
		return res;
	}

	// 内部
	rep(b1,2) rep(b2,2) {
		int ta2=ta,tb2=tb;
		if(V==1 && b1==0 && get(H,j)==1 && b2==0) ta2++;
		if(V==0 && b1==1 && get(H,j)==0 && b2==1) tb2++;
		int H2=subst(H,j,b2);
		res=max<char>(res,dfs(i,j+1,ta2,tb2,b1,H2));
	}
	return res;
}

int main(){
	scanf("%d%d%d%d",&h,&w,&a,&b);

	memset(memo,-1,sizeof memo);
	printf("%d\n",int(dfs(0,0,0,0,0,0)));

	return 0;
}
