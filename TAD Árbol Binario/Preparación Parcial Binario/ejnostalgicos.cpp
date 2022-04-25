#include "celdas_enlazadas.hpp"

template <typename T>
int nodosNostalgicos(Abin<T>& A){

    if(A.arbolVacio()){
        return 0;
    }else{

        return nodosNostalgicos_Rec(A.raiz(),A);

    }

}

template <typename T>
int nodosNostalgicos_Rec(typename Abin<T>::nodo n,const Abin<T>& A){

    if(n == Abin<T>::NODO_NULO){
    
       return 0;
        
    }else{ 
        
        if(numAncestros(n,A) > numDescendientes(n,A) -1){ //Añadimos el -1 a numDescendientes para descontar el nodo n como tal.

            return 1 + nodosNostalgicos_Rec(A.hijoIzqdo(n)) + nodosNostalgicos_Rec(A.hijoDrcho(n));

        }else{

            return 0 + nodosNostalgicos_Rec(A.hijoIzqdo(n)) + nodosNostalgicos_Rec(A.hijoDrcho(n));

        }
        

    }

}

template <typename T>
int numAncestros(typename Abin<T>::nodo n,const Abin<T>& A){

    if(n==Abin<T>::NODO_NULO){

        return -1;

    }else{

        return 1 + numAncestros(A.padre(n),A);

    }

}

template <typename T>
int numDescendientes(typename Abin<T>::nodo n,const Abin<T>& A){

    if(n==Abin<T>::NODO_NULO){

        return 0;

    }else{

        return 1 + numDescendientes(A.hijoIzqdo(n),A) + numDescendientes(A.hijoDrcho(n),A);

    }

}