/*#include <iostream>
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
}*/
#include <iostream>
using namespace std;
int main()
{
	int N = 0, M = 0, L = 0, f = 0, f1 = 1, f0 = 0;
	cin >> N;
	while (1)
	{
		f = f1 + f0;
		f0 = f1;
		f1 = f;
		if (f < N)
		{
			M = N - f;
		}
		else
		{
			L = f - N;
			break;
		}
	}
	cout << min(M, L) << endl;
	return 0;
}
