#include <iostream>
#include "agenDinamica.h"

template <typename T>
int nNodosNivelAgen(int numNodos, const Agen<T>& A){

    return nNodosNivelAgen_Rec(numNodos,A.raiz(),A);

}

template <typename T>
int nNodosNivelAgen_Rec(int numNodos, typename Agen<T>::nodo n, const Agen<T>& A){

    if(n==Agen<T>::NODO_NULO){
        return 0;
    }else{

        aux = 0;
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo!=Agen<T>::NODO_NULO){
            aux += nNodosNivelAgen_Rec(numNodos,hijo,A);
            hijo = A.hermDrcho(hijo);
        }

        if(esNivel(profundidad(n,A),A.raiz(),A)==numNodos){
            return 1 + aux;
        }else{
            return 0 + aux;
        }

    }


}

template <typename T>
int profundidad(typename Agen<T>::nodo n, const Agen<T>& A){

    if(n==A.raiz()){
        return 0;
    }else{
        return 1 + profundidad(A.padre(n),A);
    }

}


template <typename T>
int esNivel(int profNivel, typename Agen<T>::nodo n, const Agen<T>& A){

    if(n==Agen<T>::NODO_NULO){

        return 0;

    }else{
        
        int prof = profundidad(n,A);


        if(prof<profNivel){

            int aux = 0;
            typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
            while(hijo!=Agen<T>::NODO_NULO){
                aux += esNivel(profNivel,hijo,A);
                hijo = A.hermDrcho(hijo);
            }

            return aux;

        }else if(prof==profNivel){
            return 1;
        }

        
    }

}