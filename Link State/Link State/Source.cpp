#include "LinkStateSim.h"


int main()
{
    string cadena;
    int tam;
    cadena = "C:\\Users\\Miguel Angel\\Desktop\\Ciclo 2020-II\\Redes de Computadoras\\Documentos\\Trabajo Final\\Escenario1.txt";  //Se debe modificar la ubicacion 
    tam = ObtenerTamano(cadena);

    int* pesos = new int[tam];
    int** matriz = GenerarMatriz(cadena);

    //std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    pesos = Dijkstra(matriz, tam);
    //std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

    //std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end2 - begin2).count() << "[ns]" << std::endl;
    
	return 0;
}
