#include <iostream>
#include <stdlib.h>
#include "Trigonometria.h"

using namespace std;

/*#include <algorithm>
#include <vector>

int main()
{
	vector <int> a{ 2,101,2017,50 };
	auto evaNum = find_if (a.cbegin(), a.cend(), [](const int& num){
			return ((num % 2) == 0);
	});

	//cout << a[0];
	cout << *evaNum;
}*/


class Matriz
{
private:
	int fa, ca, fb, cb;
public:
	Matriz(int ax, int ay, int bx, int by)
	{
		fa = ax;
		ca = ay;
		fb = bx;
		cb = by;
	}
	void multiMatriz()
	{
		int A[100][100], B[100][100], C[100][100], i, j;

		if (ca == fb)
		{
			cout << "Introduzca los datos de la matriz A: " << endl;
			for (i = 0; i < fa; i++)
			{
				for (j = 0; j < ca; j++)
				{
					cout << "A[" << i << "]" << "[" << j << "] = ";
					cin >> A[i][j];
				}
			}
			cout << "\nIntroduzca los datos de la matriz B: " << endl;
			for (i = 0; i < fb; i++)
			{
				for (j = 0; j < cb; j++)
				{
					cout << "B[" << i << "]" << "[" << j << "] = ";
					cin >> B[i][j];
				}
			}
			for (i = 0; i < fa; i++)
			{
				for (j = 0; j < cb; j++)
				{
					C[i][j] = 0;
					for (int k = 0; k < ca; k++)
					{
						C[i][j] += A[i][k] * B[k][j];
					}
				}				
			}
			cout << "\nMatriz A*B\n";
			for (i = 0; i < fa; i++)
			{
				for (j = 0; j < cb; j++)
				{
					cout << "C[" << i << "]" << "[" << j << "] = " << C[i][j] << endl;
				}
			}
		}
		else
		{
			cout << "\nla multiplicacion de matrices no se puede realizar ya que las filas de la primera matriz no coinciden con las columnas de la segunda matriz\n" << endl;
		}
	}
	void funcionesTri()
	{
		int A[100][100], i, j, op;
		float a;

		cout << "Introduzca los datos de la matriz: " << endl;
		for (i = 0; i < fa; i++)
		{
			for (j = 0; j < ca; j++)
			{
				cout << "A[" << i << "]" << "[" << j << "] = ";
				cin >> A[i][j];
			}
		}
		cout << "\nElija una opcion de operacion\n1.Coseno\n2.Seno\n3.Tangente" << endl;
		cin >> op;
		switch (op)
		{
		case 1:
			for (i = 0; i < fa; i++)
			{
				for (j = 0; j < ca; j++)
				{
					a = A[i][j];
					cout << "\n El resultado del coseno en A[" << i << "]" << "[" << j << "] es: " << coseno(a);
				}
			}
			break;
		case 2:
			for (i = 0; i < fa; i++)
			{
				for (j = 0; j < ca; j++)
				{
					a = A[i][j];
					cout << "\n El resultado del seno en A[" << i << "]" << "[" << j << "] es: " << seno(a);
				}
			}
			break;

		case 3:
			for (i = 0; i < fa; i++)
			{
				for (j = 0; j < ca; j++)
				{
					a = A[i][j];
					cout << "\n El resultado de la tangente en A[" << i << "]" << "[" << j << "] es: " << tang(a);
				}
			}
			break;
		}
	}
};
class Inicio
{
private:
	int ax, ay, bx, by, op1, op2;
public:
	Inicio()
	{
		ax = 0; //filas a
		ay = 0; //columnas a
		bx = 0; //filas b
		by = 0; //columnas b
		op1 = 0;
		op2 = 0;
	}
	void run()
	{
		do {
			cout << "Bienvenido elija una opcion para continuar\n\n1. Calcular el producto de 2 matrices\n2. Calcular las funciones trigonometricas de cada dato de una matriz" << endl;
			cin >> op1;
			system("cls");
			Matriz* matriz;
			Matriz* matriz2;
			switch (op1)
			{
			case 1:
				cout << "Introduzca el numero de Filas en la matriz A: " << endl;
				cin >> ax;
				cout << "Introduzca el numero de Columnas en la matriz A: " << endl;
				cin >> ay;
				cout << "Introduzca el numero de Filas en la matriz B: " << endl;
				cin >> bx;
				cout << "Introduzca el numero de Columnas en la matriz B: " << endl;
				cin >> by;

				matriz= new Matriz(ax, ay, bx, by);
				matriz->multiMatriz();

				break;

			case 2:
				cout << "Introduzca el numero de Filas en la matriz: " << endl;
				cin >> ax;
				cout << "Introduzca el numero de Columnas en la matriz: " << endl;
				cin >> ay;

				matriz2 = new Matriz(ax, ay, 0, 0);
				matriz2->funcionesTri();

				break;
			}
			cout << "\n\nIntroduzca la opcion\n1. Seguir en el programa\n2. Salir del programa" << endl;
			cin >> op2;
			system("cls");
		} while (op2 != 2);
	}
};
int main()//llama a todas las funciones
{
	Inicio menu;
	menu.run();
}