#include <iostream>
#include "agenDinamica.h"

template <typename T>
Agen<T> reflejarAgen(const Agen<T>& A){

    if(!A.arbolVacio()){
        Agen<T> A_Reflejado;
        A_Reflejado.insertarRaiz(A.raiz());
        reflejarAgen_Rec(A.raiz(),A_Reflejado.raiz(),A,A_Reflejado);
        return A_Reflejado;
    }else{
        return A;
    }

}

template <typename T>
void reflejarAgen_Rec(typename Agen<T>::nodo nA, typename Agen<T>::nodo nB, const Agen<T>& A, Agen<T>& B){

    if(nA!=Agen<T>::NODO_NULO && nB!=Agen<T>::NODO_NULO){
        typename Agen<T>::nodo hijo = A.hijoIzqdo(nA);
        while(hijo!=Agen<T>::NODO_NULO){
            B.insertarHijoIzqdo(nB,A.elemento(hijo));
            reflejarAgen_Rec(hijo,B.hijoIzqdo(nB),A,B);
            hijo = A.hermDrcho(hijo);

        }
    }


}


