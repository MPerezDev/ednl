#include <iostream>
#include "agenDinamica.h"

template <typename T>
bool ternarioAgen(const Agen<T>& A){

    return ternarioAgen_Rec(A.raiz(),A);

}

template <typename T>
bool ternarioAgen_Rec(typename Agen<T>::nodo n,const Agen<T>& A){

    if(n!=Agen<T>::NODO_NULO){

        if(A.hijoIzqdo(n)==Agen<T>::NODO_NULO){

            return true;

        }else if(numHijos(n)==3){

            bool aux = true;

            typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
            while(hijo!=Agen<T>::NODO_NULO){
                aux = aux && ternarioAgen_Rec(hijo,A);
                hijo = A.hermDrcho(hijo);
            }

            return aux;

        }else{

            return false;

        }

    }else{

        return true;

    }

}

template <typename T>
int numHijos(typename Agen<T>::nodo n,const Agen<T>& A){

    int aux = 0;

    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    while(hijo!=Agen<T>::NODO_NULO){
        aux++;
        hijo = A.hermDrcho(hijo);

    }

    return aux;

}