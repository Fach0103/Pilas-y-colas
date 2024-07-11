#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// Función para ordenar una pila
void ordenarPila(stack<int>& pila) {
    stack<int> pila_auxiliar;
    while (!pila.empty()) {
        int elemento = pila.top();
        pila.pop();
        while (!pila_auxiliar.empty() && pila_auxiliar.top() < elemento) {
            pila.push(pila_auxiliar.top());
            pila_auxiliar.pop();
        }
        pila_auxiliar.push(elemento);
    }
    pila = pila_auxiliar;
}

// Función para ordenar una cola
void ordenarCola(queue<int>& cola) {
    vector<int> vector_auxiliar;
    while (!cola.empty()) {
        vector_auxiliar.push_back(cola.front());
        cola.pop();
    }
    sort(vector_auxiliar.begin(), vector_auxiliar.end());
    for (int elemento : vector_auxiliar) {
        cola.push(elemento);
    }
}

int main() {
    int n, opcion;
    cout << "¿Cuántas pilas o colas desea ordenar? ";
    cin >> n;

    vector<stack<int>> pilas;
    vector<queue<int>> colas;

    for (int i = 0; i < n; i++) {
        cout << "Pila o cola " << i + 1 << ": ";
        cin >> opcion;
        if (opcion == 1) {
            stack<int> pila;
            int elemento;
            cout << "Ingrese los elementos de la pila (terminar con -1): ";
            while (cin >> elemento && elemento != -1) {
                pila.push(elemento);
            }
            pilas.push_back(pila);
        } else {
            queue<int> cola;
            int elemento;
            cout << "Ingrese los elementos de la cola (terminar con -1): ";
            while (cin >> elemento && elemento != -1) {
                cola.push(elemento);
            }
            colas.push_back(cola);
        }
    }

    for (stack<int>& pila : pilas) {
        ordenarPila(pila);
    }

    for (queue<int>& cola : colas) {
        ordenarCola(cola);
    }

    cout << "Pilas ordenadas:" << endl;
    for (stack<int>& pila : pilas) {
        while (!pila.empty()) {
            cout << pila.top() << " ";
            pila.pop();
        }
        cout << endl;
    }

    cout << "Colas ordenadas:" << endl;
    for (queue<int>& cola : colas) {
        while (!cola.empty()) {
            cout << cola.front() << " ";
            cola.pop();
        }
        cout << endl;
    }

    return 0;
}

