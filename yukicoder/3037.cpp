#include <iostream>

#define rep(i,n) for(int i=ZERO;i<(n);i=add(i,ONE))

using namespace std;

const int ZERO=false;
const int ONE=true;
const int TWO=ONE<<ONE;

int MOD;

int add(int a,int b){
	if(b==ZERO){
		return a;
	}
	else if(b>ZERO){
		return add(a^b,(a&b)<<ONE);
	}
	else{
		if(a>=ZERO) return add(b,a);
		else        return add(~add(add(~a,ONE),add(~b,ONE)),ONE);
	}
}

int sub(int a,int b){
	return add(a,add(~b,ONE));
}

int modadd(int a,int b){
	if(a<ZERO) a=add(a,MOD);
	if(a>=MOD) a=sub(a,MOD);
	if(b<ZERO) b=add(b,MOD);
	if(b>=MOD) b=sub(b,MOD);
	int res=add(a,b);
	if(res<ZERO) res=add(res,MOD);
	if(res>=MOD) res=sub(res,MOD);
	return res;
}

int modmul(int a,int b){
	return b==ZERO?ZERO:modadd(modmul(a,b>>ONE)<<ONE,b&ONE?a:ZERO);
}

void modmul(int A[TWO][TWO],int B[TWO][TWO],int C[TWO][TWO]){
	int tmp[TWO][TWO]={};
	rep(i,TWO) rep(j,TWO) rep(k,TWO) {
		tmp[i][j]=modadd(tmp[i][j],modmul(A[i][k],B[k][j]));
	}
	rep(i,TWO) rep(j,TWO) C[i][j]=tmp[i][j];
}

void solve(){
	int A[TWO][TWO]={{ZERO,ONE},{ONE,ONE}};
	int B[TWO][TWO]={{ONE,ZERO},{ZERO,ONE}};

	int k; cin>>k;
	for(;k>ZERO;k>>=ONE){
		if(k&ONE) modmul(B,A,B);
		modmul(A,A,A);
	}

	cout<<modadd(modmul(B[ZERO][ZERO],TWO),B[ZERO][ONE])<<endl;
}

int main(){
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ZERO);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ONE);
	MOD=add(MOD<<ONE,ONE);

	int q; cin>>q; rep(_,q) solve();

	return ZERO;
}
