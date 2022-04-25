#include "agenDinamica.h"

template <typename T>
int gradoAgen(Agen<T>& A){
    return gradoAgen_Rec(A.raiz(), A);
}

template <typename T>
int gradoAgen_Rec(typename Agen<T>::nodo n, Agen<T>& A){
    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
        return 0;
    }
    else{
        Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int contador = gradoNodo(n, A);
        while(hijo != Agen<T>::NODO_NULO){
            contador = max(contador, gradoAgen_Rec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return contador;
    }
}

template <typename T>
int gradoNodo(typename Agen<T>::nodo n, Agen<T>& A){
    int contador = 0;
    if(n != Agen<T>::NODO_NULO){
        Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(A.hermDrcho(n) != Agen<T>::NODO_NULO){
            contador++;
            n = A.hermDrcho(n);
        }
    }
    return contador;
}