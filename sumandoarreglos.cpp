// OMPVerificando.cpp : Este archivo contiene la funci�n "main". La ejecuci�n del programa comienza y termina ah�.
//

#include <iostream>
#include <omp.h>

// Declaraci�n de variables iniciales
#define N 1000
#define chunk 10
#define mostrar 10



// Declaraci�n del prototypo de la funci�n que imprimir� los arreglos

void imprimeArreglo(float* d);

int main()
{

	std::cout << "Sumando arreglos en paralelo!\n";
	float a[N], b[N], c[N];
	int i;

	for (i = 0; i < N; i++)
	{

		a[i] = i * 10;
		b[i] = (i + cos(90)) * 2;

	}

	int pedazos = chunk;

#pragma omp parallel for shared(a, b, c, pedazos) private(i) schedule(static, pedazos)

	for (i = 0; i < N; i++)
		c[i] = a[i] + b[i];

	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
	imprimeArreglo(a);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
	imprimeArreglo(b);
	std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
	imprimeArreglo(c);

}


void imprimeArreglo(float* d)
{
	for (int x = 0; x < mostrar; x++)
		std::cout << d[x] << " - ";
	std::cout << std::endl;
}