#include <iostream>


//lucas lehmer
//mersenne
// próbne dzielenie


using namespace std;
//ile jest liczb pierwszych od 7-8 mln  11-12
bool czy_pierwsza(unsigned long long n)
{
	if (n < 2) return false;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}
bool lucasLehmer(unsigned long long m, int i)
{
	if (i == 2) return true;
	int s = 4;
	for (int j = 3; j < i - 2; j++)
	{
		s = ((s * s) - 2);
		s=s % m;
	}
	
	if (s == 0) return true;
	else return false;
}

unsigned long long power(int x, int y)
{
	unsigned long long result = 1;
	for (int i = 0; i < y; i++)
	{
		result = result * x;
	}
	return result;
}

int main()
{
	for (int i = 2; i < 33; i++)
	{
		if (czy_pierwsza(i))
		{
			if (czy_pierwsza(power(2, i) - 1)) cout << "w TD 2 do " << i << " -1 jest liczba pierwsza " << endl;
			if (lucasLehmer(power(2, i) - 1, i)) cout << "w lucasLehmer 2 do " << i << " -1 jest liczba pierwsza" << endl;
		}
	}

	system("pause");
	return 0;
}