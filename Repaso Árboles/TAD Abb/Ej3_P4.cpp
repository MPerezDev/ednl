#include <iostream>
#include <vector>
#include "abb.h"

template <typename T>
Abb<T> unionAbb(const Abb<T>& A, const Abb<T>& B){

    Abb<T> Nuevo = A;
    RecorrerUnionAbb(Nuevo,B);  
    equilibrar(Nuevo);

    return Nuevo;

}

template <typename T>
void RecorrerUnionAbb(Abb<T>& A,const Abb<T>& B){

    if(!B.vacio()){

        if(A.buscar(B.elemento()).vacio()){
            A.insertar(B.elemento());
        }

        RecorrerUnionAbb(A,B.izqdo());
        RecorrerUnionAbb(A,B.drcho());

    }

    
}

using namespace std;

template <typename T>
void equilibrar(Abb<T>& A){

    if(!A.vacio()){

        vector<T> v;
        //Recorremos el abb y recogemos sus valores.
        recorrerAbb(v,A);
        Abb<T> A_Equilibrado;
        equilibrarAbb(0,v.size()-1,v,A_Equilibrado);
        A = A_Equilibrado;

    }


}

template <typename T>
void recorrerAbb(vector<T>& v,const Abb<T>& A){

    if(!A.vacio()){

        recorrerAbb(v,A.izqdo());
        v.push_back(A.elemento());
        recorrerAbb(v,A.drcho());

    }

}

template <typename T>
void equilibrarAbb(int inicio,int fin, const vector<T>& v, Abb<T>& A){

    A.insertar(v[((inicio + fin)/2)] );
    equilibrarAbb(inicio,(inicio + fin)/2,v,A);
    equilibrarAbb((inicio + fin)/2,fin,v,A);

}