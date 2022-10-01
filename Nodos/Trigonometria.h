#include <iostream>
using namespace std;

double coseno(int x);
double seno(int x);
double tang(int x);

double potenciaRecursiva(double numero, long potencia)
{
	if (potencia <= 0)
	{
		return 1;
	}
	else
	{
		return numero * potenciaRecursiva(numero, potencia - 1);
	}
}

double coseno(int x)
{
	double rad = 0;
	int i, j, expo = 0, signo = -1;
	double resp = 0, fact = 1;

	rad = (x * 3.141592654) / 180; //conversion de un grados a radianes

	for (i = 0; i <= 100; i++) // el 100 representa la cantidad de sumas que se haran en la serie de taylor
	{
		fact = 1;
		for (j = 1; j <= expo; j++)
		{
			fact *= j;
		}
		signo *= -1;
		resp += signo * potenciaRecursiva(rad,expo)/ fact; // si colocas x como parametro en lugar de "rad" el resultado sera el coseno en radianes
		expo = expo + 2;		
	}
	return resp;
}

double seno(int x)
{
	double rad = 0;
	int i, j, expo = 1;
	double resp = 0, fact = 0;

	rad = (x * 3.141592654) / 180; //conversion de un grados a radianes

	for (i = 0; i <= 100; i++) // el 100 representa la cantidad de sumas que se haran en la serie de taylor
	{
		fact = 1;
		for (j = 1; j <= expo; j++)
		{
			fact *= j;
		}
		if (i % 2 == 0)
		{
			resp = resp - potenciaRecursiva(rad, expo) / fact;
		}
		else
		{
			resp = resp + potenciaRecursiva(rad, expo) / fact;
		}
		expo = expo + 2;
	}
	return resp;
}

double tang(int x) {

	double rad = 0;
	rad = (x * 3.141592654) / 180; //conversion de un grados a radianes

	if (rad / (3.141592654 / 2) == (int)(rad / (3.141592654 / 2))) {
		cout << "Error: el angulo no debe ser multiplo de 90" << endl;
		return 0;
	}

	//trampa... pero la serie de taylor para tangente es computacionalmente muy pesada
	//este metodo aunque ligeramente menos preciso, resuelve el problema mucho más facil
	return seno(x) / coseno(x);
}

