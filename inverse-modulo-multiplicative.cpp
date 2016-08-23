/*
 * Inverse module multiplicative algorithm
 */
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <utility>
 using namespace std;

 #define MOD 100003

 int ext_GCD(int a, int b, int *c, int *d){
 	int q,r_prev,r,r_tmp,xa_prev,xa,xa_tmp,xb_prev,xb,xb_tmp;
 	r_prev = a;
 	r = b;
 	xa_prev = 1;
 	xa = 0;
 	xb_prev = 0;
 	xb = 1;
 	while(r){
 		q = (r_prev/r);
 		r_tmp = r_prev%r;

 		xa_tmp = xa_prev - (q*xa);
 		xb_tmp = xb_prev - (q*xb);

 		xa_prev = xa;
 		xa = xa_tmp;

 		xb_prev = xb;
 		xb = xb_tmp;

 		r_prev = r;
 		r = r_tmp;
 	}
 	*c = xa_prev;
 	*d = xb_prev;

 	return r_prev;
 }

 int inverse_modulo_multipicative(int a, int m){
 	int x,y;
 	ext_GCD(a, m, x, y);
 	if(x<0)x+=m;
 	return x;
 }


 int main(){
 	int a;
 	cin>>a;
 	cout<<"inverse modulo multiplicative: "<<inverse_modulo_multipicative(a, MOD)<<endl;
 	return 0;
 }