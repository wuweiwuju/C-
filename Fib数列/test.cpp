#include <iostream>
using namespace std;
int main()
{    
	int N; 
	cin>>N; 
	int n1 = 0; 
	int n2 = 1;
	int num=0; 
	while(num<N)  
	{        
		num = n1 + n2; 
		n1 = n2;  
		n2 = num; 
	}   
	if(num == N)   
		cout<<0; 
	else // num > N        
		cout << ((num-N > N-n1)? (N-n1):(num-N)); 
	return 0;
}