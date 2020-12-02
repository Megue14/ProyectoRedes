#include "LinkStateSim.h"

int ObtenerTamano(string ubicacion)
{
    int tam = 0;
    string line;
    ifstream file(ubicacion);
    getline(file, line);
    tam = stoi(line);
    return tam;
}

int** GenerarMatriz(string ubicacion)
{
    string line;
    int tam = 0;

    ifstream file(ubicacion);
    getline(file, line);
    tam = stoi(line);

    int** matriz = new int* [tam];

    for (int i = 0; i < tam; i++)
    {
        matriz[i] = new int[tam];
    }

    int fila = 0;
    while (getline(file, line))
    {
        int col = 0;
        string word;
        istringstream ss(line);
        while (getline(ss, word, ' '))
        {
            int peso = stoi(word);
            matriz[fila][col] = peso;
            col++;
        }
        fila++;
    }
    return matriz;
}

void ImprimirMatriz(int** matriz, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void ImprimirArreglo(int* arreglo, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

void ImprimirTabla(int* arreglo, int tam)
{
    cout << "Nodo" << "\tDistancia" << endl;
    
    for (int i = 0; i < tam; i++)
    {
        cout << (i+1) << "\t" << arreglo[i] << endl;
    }
}

int* Dijkstra(int** matriz, int tam)
{  
    int* pesos = new int[tam];
    bool* visitado = new bool[tam];

    for (int i = 0; i < tam; i++)
    {
        pesos[i] = matriz[0][i];
        visitado[i] = false;
    }

    string a = "";

    cout << "Tabla de distancias del nodo 1" << endl << endl;
    ImprimirTabla(pesos, tam);
    cout << endl;

    cout << "Ingrese cualquier digito para comenzar: ";    
    cin >> a;
    cout << endl;
    system("CLS");

    for (int j = 0; j < tam; j++)
    {
        int minPeso = 9999999;
        int minNodo = 0;

        for (int i = 0; i < tam; i++)
        {
            if (visitado[i])
            {

            }
            else if (pesos[i] > 0 && pesos[i] < minPeso)
            {
                minPeso = pesos[i];
                minNodo = i;
            }
        }

        visitado[minNodo] = true;

        for (int i = 0; i < tam; i++)
        {
            if (matriz[minNodo][i] <= 0)
            {

            }
            else if (pesos[i] < 0)
            {
                pesos[i] = minPeso + matriz[minNodo][i];
            }
            else if (pesos[minNodo] + matriz[minNodo][i] < pesos[i])
            {
                pesos[i] = minPeso + matriz[minNodo][i];
            }   
        }
        cout << "Iteracion " << (j+1) << endl;
        ImprimirTabla(pesos, tam);
        cout << endl;
        
        cout << "Ingrese cualquier digito para continuar: ";
        cin >> a;
        cout << endl;
        system("CLS");
    }
    return pesos;
}
