#include <iostream>
#include "Nodo.h"
#include <stdlib.h>

using namespace std;

vector<Nodo*> rutas ;

void agregar(){
    cout << "Introduzca el nombre del destino: " ;
    string ciudad = "";
    cin.ignore();
    getline(cin, ciudad);
   //  cin >> ciudad;
    Nodo* nodo = new Nodo(ciudad);
    rutas.push_back(nodo);

}

void mostrar(){
    for(int i=0; i<rutas.size(); i++){
        cout << i+1 << " " << rutas[i]->getCiudad() << endl;
    }

}

void agregarRuta(){
    mostrar();
    cout << "Seleccione el destino de origen => ";
    int origen; cin >> origen;
    Nodo* orig = rutas[origen-1];
    cout << "Seleccione el destino de destinación => ";
    int destino; cin >> destino;
    Nodo* dest = rutas[destino-1];
    orig->agregarNodo(dest);
    cout << "\nRuta " << orig->getCiudad() << " a " << dest->getCiudad() << " creado con Exito.\n";

}

void verRutas(){
    for(int i=0; i<rutas.size(); i++){


            cout << rutas[i]->getCiudad() << endl;
            vector<Nodo*> n = rutas[i]->getNodos();
            for(int j = 0; j < n.size(); j++){
                cout << "-" << n[j]->getCiudad() << endl;
            }
            cout << endl;
    }

}

void removerRevisado(){
    for(int i=0; i<rutas.size(); i++){

            vector<Nodo*> n = rutas[i]->getNodos();
            for(int j = 0; j < n.size(); j++){
                n[j]->revisado = false;
            }

    }
}
bool revisar(vector<Nodo*> n, string dest){
    for(int b = 0; b < n.size(); b++){


        if(n[b]->getCiudad() == dest ){
            return true;
        }
        if(n[b]->cantidad_nodos > 0){
            revisar(n[b]->getNodos(), dest);
        }

    }
    return false;

}

string last = "";
int num = 1;
string recorrer(vector<Nodo*> n, string build, string dest){
    string temp = "";

    for(int b = 0; b < n.size(); b++){


        if(n[b]->getCiudad() == dest ){
            build += last + " hacia " + n[b]->getCiudad();
            temp = build;
            cout << "Opcion de Ruta: " << num << "\n" ;
            cout <<  temp << "\n\n";
            num++;
            return temp;
        }
        if(n[b]->cantidad_nodos > 0){
            if(revisar(n[b]->getNodos(), dest) == true){

                build += last + " hacia " + n[b]->getCiudad() + "\n";
                last = n[b]->getCiudad();

            }

            recorrer(n[b]->getNodos(), build, dest);

        }

    }


    return temp;

}

void encontrarRuta(){

    mostrar();
    cout << "Introduzca desde donde desea viajar => ";
    int origen; cin >> origen;
    Nodo* orig = rutas[origen-1];
    cout << "Introduzca hasta donde desea viajar => ";
    int destino; cin >> destino;
    Nodo* dest = rutas[destino-1];

    cout << "Para viajer desde " << orig->getCiudad() << " hacia " << dest->getCiudad() << ", tome los siguientes vuelos:" << endl;
    string ciudadOrigen = orig->getCiudad();
    string build = ciudadOrigen + " hacia ";

    vector<Nodo*> n = rutas[origen-1]->getNodos();

    for(int j = 0; j< n.size(); j++){
        build = ciudadOrigen + " hacia " + n[j]->getCiudad() + "\n";
        if(n[j]->getCiudad() == dest->getCiudad() ){
            cout << "Ruta : " << build << endl;
            goto finish;
        }
    }
     for(int j = 0; j< n.size(); j++){
        build = ciudadOrigen + " hacia " + n[j]->getCiudad() + "\n";
        last = n[j]->getCiudad();

        if(n[j]->cantidad_nodos > 0){

            vector<Nodo*> l = n[j]->getNodos();

            build = recorrer(l, build, dest->getCiudad());

            if(build.size() > 0){

                goto finish;

            }


        }
    }
    num=1;
    finish:;
    removerRevisado();
}

int main()
{
    int n = 0;
    do{

            cout << "---Rutas Aerolinea---\n\n";
            cout << "1- Introducir Destino\n";
            cout << "2- Introducir Ruta\n";
            cout << "3- Buscar Ruta\n";
            cout << "4- Mostrar Las Rutas\n";
            cout << "5- Salir\n";
            cout << "Seleccione una opcion: ";
            cin >> n;

            switch(n){
            case 1 : agregar();
                break;

            case 2 :
                    agregarRuta();

                     cout << "\n-- Presione ENTER para regresar al menu principal--";
                     system("pause");
                break;

            case 3 :    encontrarRuta();
                        system("pause");
                break;


            case 4 : verRutas();
                     cout << "\n-- Presione ENTER para regresar al menu principal--";
                     system("pause");
                 break;
            }
            system("cls");

    }while(n != 5);

    return 0;

}
