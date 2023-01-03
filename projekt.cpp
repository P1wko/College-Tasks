#include <iostream>
#include <cmath>
#include <functional>
using namespace std;

int t0(int l, int cond)
{
	int T[10000], min;
	for(int i = 0; i < l; i++)
	{
		cin >> T[i];
	}
	min = T[0];
	if(cond == 0)
	{
		for(int i = 1; i < l; i++)
		{
			if(T[i] < min) min = T[i];
		}
		for(int i = 0; i < l; i++)
		{
			if(min == T[i])
			{
				cout<<i + 1<<" ";
			}
		}
		
	}
	
	if(cond == 1)
	{
		for(int i = 0; i < l; i++)
		{
			for(int j = i + 1; j < l; j++)
			{
				if(T[i] < T[j])
				{
					int temp = T[i];
					T[i] = T[j];
					T[j] = temp;
				}
			}
		}
		for (int i = 0; i < l; i++)
		{
			cout<<T[i]<<" ";
		}
	}
	return 0;
	
}

void t2(int l, int cond)
{
	double T[10000], wynik;
	int suma = 0;
	for(int i = 0; i < l; i++)
	{
		cin>>T[i];
	}
	for(int i = 0; i < l; i++)
	{
		if(cond == 2)
		{
			suma = suma + (T[i] * T[i]);	
		}
		if(cond == 3)
		{
			suma += T[i];
		}
	}
	if(cond == 2)
	{
		wynik = int(sqrt(suma));
		cout<<wynik<<" ";	
	}
	if(cond == 3)
	{
		double odch = 0;	
		double srednia = (double)suma/l;
		for(int i = 0; i < l; i++)
		{
			odch += (T[i] - srednia) * (T[i] - srednia);
		}
		double odchsr = (double)odch / l;
		wynik = int(sqrt(odchsr));
		cout<<wynik<<" ";
	}
}

void t4(int l)
{
	int T[10000];
	for(int i = 0; i < l; i++)
	{
		cin>>T[i];
	}
	for(int i = 0; i < l/2; i++)
	{
		T[i] = T[i] + T[l-i-1];
		T[l-i-1] = T[i] - T[l-i-1];
		T[i] = T[i] - T[l-i-1];
	}
	for(int i = 0; i < l; i++)
	{
		cout<<T[i]<<" ";
	}
}

void t5(int l)
{
	int T[10000];
	for(int i = 0; i < l; i++)
	{
		cin>>T[i];
	}
	for(int i = 0; i < l; i++)
	{
		bool isPrime = true;
		if(T[i] == 0 || T[i] == 1 || T[i] < 0)
		{
			isPrime = false;
		}
		else
		{
			for(int j = 2; j <= T[i]/2; j++)
			{
				if(T[i] % j == 0)
				{
					isPrime = false;
					break;
				}
			} 
		}
		if(isPrime == true) cout<<1<<" ";
		if(isPrime == false) cout<<0<<" ";
	}
}

void t7(int l)
{
	long double a, b, c, d;
	if(l == 4) cin>>a>>b>>c>>d;
	if(a == 0)
	{
		long double delta, x1;
		delta = sqrt(c * c - (4 * b * d));
		if(delta == 0)
		{
			x1 = -c / (2 * b);
			cout<<floor(x1)<<" ";
		}
		if(delta > 0)
		{
			long double x2;
			x1 = (-c - delta) / (2 * b);
			x2 = (-c + delta) / (2 * b);
			if(x1 > x2)	cout<<floor(x2)<<" "<<floor(x1)<<" ";
			else cout<<floor(x1)<<" "<<floor(x2)<<" ";
		}
	}
}

// (1/12)*x(3x^3 + 14x^2 + 21x + 10) --- wzror po uproszczeniu
void t8()
{
	long long int x;
	long long int suma = 0;
	cin>>x;
	suma = ((3*x*x*x) + (14*x*x) + (21*x) + 10) * x;
	suma = suma / 12;
	cout<<suma<<endl;
}

void t9(int l)
{
	unsigned int T[10000];
	for(int i = 0; i < l; i++)
	{
		cin>>T[i];
	}
	for(int i = 0; i < l; i++)
	{
		int wynik = 0;
		unsigned int dana = T[i];
		while(dana >= 1)
		{
			if(dana % 2 == 1) wynik++;
			dana = dana / 2;
		}
		cout<<wynik<<" ";
	}
}

int main()
{
	int subprogram, ilosc;
	while(cin>>subprogram>>ilosc)
	{
		switch(subprogram)
		{
			case 0:
				{
					t0(ilosc, subprogram);
					break;
				}
			case 1:
				{
					t0(ilosc, subprogram);
					break;
				}
			case 2:
				{
					t2(ilosc, subprogram);
					break;
				}
			case 3:
				{
					t2(ilosc, subprogram);
					break;
				}
			case 4:
				{
					t4(ilosc);
					break;
				}
			case 5:
				{
					t5(ilosc);
					break;
				}
			case 7:
				{
					t7(ilosc);
					break;
				}
			case 8:
				{
					t8();
					break;
				}
			case 9:
				{
					t9(ilosc);
					break;
				}
			default: break;	
		}
		
	}
	return 0;
}
