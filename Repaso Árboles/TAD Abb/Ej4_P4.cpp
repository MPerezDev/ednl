#include <iostream>
#include <vector>
#include "abb.h"

using namespace std;

template <typename T>
Abb<T>& interseccionAbb(const Abb<T>& A,const Abb<T>& B){

    vector<T> v;
    recorrerInterseccionAbb(v,A,B);
    Abb<T> nuevo;
    equilibrarAbb(0,v.size()-1,v,nuevo);

    return nuevo;

}

template <typename T>
void recorrerInterseccionAbb(vector<T>& v, const Abb<T>& A, const Abb<T>& B){

    if(!B.vacio()){

        recorrerInterseccionAbb(v,A,B.izqdo());
        if(!A.buscar(B.elemento()).vacio()){
            v.push_back(B.elemento());
        }
        recorrerInterseccionAbb(v,A,B.drcho());

    }
    
}

template <typename T>
void equilibrarAbb(int inicio,int fin, const vector<T>& v, Abb<T>& A){

    A.insertar(v[((inicio + fin)/2)] );
    equilibrarAbb(inicio,(inicio + fin)/2,v,A);
    equilibrarAbb((inicio + fin)/2,fin,v,A);

}
