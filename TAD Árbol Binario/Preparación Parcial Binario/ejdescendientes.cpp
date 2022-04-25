#include "celdas_enlazadas.hpp"

template <typename T>
int contarDescendientes(Abin<T>& A){

    if(A.arbolVacio()){
        return 0;
    }else{
        return contarDescendientes_Rec(A.raiz(),A);
    }

}

template <typename T>
int contarDescendientes_Rec(typename Abin<T>::nodo n, const Abin<T>& A){

    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else{
        
        if((numDescendientes(n,A)-1) == 4){
            return 1 + contarDescendientes_Rec(A.hijoIzqdo(n),A) + contarDescendientes_Rec(A.hijoDrcho(n),A);
        }else{
            return 0 + contarDescendientes_Rec(A.hijoIzqdo(n),A) + contarDescendientes_Rec(A.hijoDrcho(n),A);
        }

    }

}

//Hacemos numDescendientes - 1 porque en dicha función contamos al mismo nodo.

int numDescendientes(typename Abin<T>::nodo n, const Abin<T>& A){

    if(n == Abin<T>::NODO_NULO){
        return 0;
    }else{

        return 1 + numDescendientes(A.hijoIzqdo(n),A) + numDescendientes(A.hijoDrcho(n),A);

    }


}

