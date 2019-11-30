#ifndef NODO_H
#define NODO_H
#include <string>
#include <vector>
using namespace std;


class Nodo
{
    public:
        Nodo(string ciudad);
        bool revisado = false;
        int cantidad_nodos = 0;
        virtual ~Nodo();

        void agregarNodo(Nodo* nodo){
            nodos.push_back(nodo);
            cantidad_nodos++;
        }
        void setCiudad(string ciudad){
            ciudad = ciudad;
        }
        vector<Nodo*> getNodos(){
            return nodos;
        }

        string getCiudad(){
            return ciudad;
        }
    protected:

    private:
        string ciudad;
        vector<Nodo*> nodos;
};

#endif // NODO_H
