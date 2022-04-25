#include "agenDinamica.h"
#include <iostream>
#include <fstream>
#include "agen_E-S.h"


using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura 






template <typename T>
int desequilibrioAgen(Agen<T>& A){
    if(A.arbolVacio()){
        return 0;
    }else{
        return desequilibrioAgen_Rec(A.raiz(),A);
    }
}

template <typename T>
int desequilibrioAgen_Rec(typename Agen<T>::nodo n,Agen<T>& A){
    if(n == Agen<T>::NODO_NULO){
        return 0;
    }else{
        int desequilibrio = calcularDesequilibrio(n,A);
        if(A.hijoIzqdo(n) != Agen<T>::NODO_NULO){
            typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
            while(hijo != Agen<T>::NODO_NULO){
                desequilibrio = std::max(desequilibrio,desequilibrioAgen_Rec(hijo,A));
                hijo = A.hermDrcho(hijo);
            }

        }

        return desequilibrio;
    }

}

template <typename T>
int calcularDesequilibrio(typename Agen<T>::nodo n,Agen<T>& A){

    if(A.hijoIzqdo(n) == Agen<T>::NODO_NULO){
        return 0;
    }else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int altMax = alturaNodo(hijo, A);
        int altMin = alturaNodo(hijo, A);
        if(A.hermDrcho(hijo)!=Agen<T>::NODO_NULO){
            typename Agen<T>::nodo hermDr = A.hermDrcho(hijo);
            while(hermDr != Agen<T>::NODO_NULO){
                altMax = std::max(altMax, alturaNodo(hermDr,A));
                altMin = std::min(altMin, alturaNodo(hermDr,A));
                hermDr = A.hermDrcho(hermDr);
            }
        }

        return altMax - altMin;
        
    }

}


template <typename T>
int alturaNodo(typename Agen<T>::nodo n, Agen<T>& A){
    if(n==Agen<T>::NODO_NULO){
        return 0;
    }else if(A.hijoIzqdo(n)==Agen<T>::NODO_NULO){
        return 0;
    }else{
        int aux = 0;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO){
            aux = std::max(aux,alturaNodo(hijo,A));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + aux;
    }

}
