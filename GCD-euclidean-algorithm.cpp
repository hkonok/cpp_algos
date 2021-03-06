/*
 * GCD euclidean algorithm
 */
 #include <iostream>
 #include <cstdio>
 #include <cstring>
 #include <cstdlib>
 #include <utility>
 using namespace std;

 int GCD(int a, int b){
 	int r;
 	
 	while(a%b){
 		r=a%b;
 		a=b;
 		b=r;
 	}
 	return b;
 }


 int main(){
 	int a,b;
 	cin>>a>>b;
 	cout<<GCD(a, b)<<endl;
 	return 0;
 }
