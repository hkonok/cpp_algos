/*
 * GCD and extended euclidean algorithm GCD = (q1)*a + (q1)*b
 */
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <utility>
 using namespace std;

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


 int main(){
 	int a,b,c,d;
 	cin>>a>>b;
 	cout<<ext_GCD(a, b, &c, &d)<<endl;
 	cout<<"c: "<<c<<" d: "<<d<<endl;
 	cout<<"c*a+d*b = gcd : "<<(c*a+d*b)<<endl;
 	return 0;
 }
