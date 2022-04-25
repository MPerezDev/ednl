#include "celdas_enlazadas.hpp"


//Como preferencia, hijo izquierdo

template <typename T>
void hundirNodosAbin(const T& elem, Abin<T>& A){

    if(!A.arbolVacio()){

        hundirNodosAbin_Rec(A.raiz(),elem,A);

    }
}


template <typename T>
void hundirNodosAbin_Rec(typename Abin<T>::nodo n, const T& elem,Abin<T>& A){

    if(n!=Abin<T>::NODO_NULO){
    
        if(A.elemento(n)==elem){

            cambiarElementoAbin_Rec(n,elem,A);

        }else{

            hundirNodosAbin_Rec(A.hijoIzqdo(n),elem,A);
            hundirNodosAbin_Rec(A.hijoDrcho(n),elem,A);

        }
    
    }

}

template <typename T>
void cambiarElementoAbin_Rec(typename Abin<T>::nodo n,const T& elem,Abin<T>& A){

    if(A.hijoIzqdo(n)!=Abin<T>::NODO_NULO){
        T aux = A.elemento(n);
        A.elemento(n) = A.elemento(A.hijoIzqdo(n));
        A.elemento(A.hijoIzqdo(n)) = T;
        cambiarElementoAbin_Rec(A.hijoIzqdo(n),A);

    }else if(A.hijoDrcho(n)!=Abin<T>::NODO_NULO){
        T aux = A.elemento(n);
        A.elemento(n) = A.elemento(A.hijoDrcho(n));
        A.elemento(A.hijoDrcho(n)) = T;
        cambiarElementoAbin_Rec(A.hijoDrcho(n),A);
    }

    if(A.hijoIzqdo(n)==Abin<T>::NODO_NULO && A.hijoDrcho(n)==Abin<T>::NODO_NULO && A.elemento(n)==elem){
        if(A.padre(n)==Abin<T>::NODO_NULO){
            A.eliminarRaiz();
        }
        if(n==A.hijoIzqdo(A.padre(n))){
            A.eliminarHijoIzqdo(A.padre(n));
        }else{
            A.eliminarHijoDrcho(A.padre(n));
        }

    }

}