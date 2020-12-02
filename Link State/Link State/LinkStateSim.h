#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <stdlib.h>

using namespace std;

int ObtenerTamano(string ubicacion);

int** GenerarMatriz(string ubicacion);

void ImprimirMatriz(int** matriz, int tam);

int* Dijkstra(int** matriz, int tam);

void ImprimirArreglo(int* arreglo, int tam);

void ImprimirTabla(int* arreglo, int tam);