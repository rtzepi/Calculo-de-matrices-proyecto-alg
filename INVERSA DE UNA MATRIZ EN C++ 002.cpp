#include <iostream>
using namespace std;

int i,j, k, s;
float m1[1000][1000], coef, aux[1000], elemento;
     
int main()
{
	cout << "Generador de Matrices Inversas1";
	cout << "introduzca el tamaño de la matrizn";
	cin >> k;
	
	for (i=0;i<k;i++)
		{
			for (j=0;j<k;j++)
			{
				cout << "Ingrese el valor de [" <<i<<"]["<<j<<"]";
				cin >> m1 [i][j];
			}
		}

	for (i=0;i<k;i++)
		for(j=k;j<2*k;j++)
		{
			if(i==(j-k))
				m1[i][j]=1;
			else
				m1[i][j]=0;
		}
		//Iteraciones
		for (s=0;s<k;s++)
		{
			elemento=m1[s][s];
			for (j=0;j<2*k;j++)
				m1[s][j]=m1[s][j]/elemento;

			for(i=0;i<k;i++)
			{
				if (i==s)
					;
				else
				{
					coef= m1[i][s];
					for (j=0;j<2*k;j++)
						aux[j]=m1[s][j]*(coef*-1);
					for (j=0;j<2*k;j++)
						m1[i][j]=m1[i][j]+aux[j];
				}
			}
		}
		//Imprimir la matriz inversa
		
		for (i=0;i<k;i++)
		{
			for(j=k;j<2*k;j++)
				cout << "t"<<m1[i][j];
			if (j==k)
				cout <<"n";
		}
		
}

