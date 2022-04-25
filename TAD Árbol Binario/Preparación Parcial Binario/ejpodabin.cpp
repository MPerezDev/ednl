#include "celdas_enlazadas.hpp"

template <typename T>
void podaArbolBin(typename Abin<T>::nodo& n, const Abin<T>& A){

    busquedaNodo_Rec(A.raiz(),n,A);

}

template <typename T>
void busquedaNodo_Rec(typename Abin<T>::nodo& aux, typename Abin<T>::nodo& n, const Abin<T>& A){

    //En estos casos es recomendable hacer el codigo del else dentro del if dándole la vuelta a la condición. Ya está corregido.
    if(aux != Abin<T>::NODO_NULO){
        
        if(aux == n){

            podaArbolNodo(aux,A);

        }else{

            busquedaNodo_Rec(A.hijoIzqdo(aux),n,A);
            busquedaNodo_Rec(A.hijoDrcho(aux),n,A);

        }

    }

}

template <typename T>
void podaArbolNodo(typename Abin<T>::nodo n, Abin<T>& A){

    if(n != Abin<T>::NODO_NULO){

        if(A.hijoIzqdo(n)!= Abin<T>::NODO_NULO){
            podaArbolNodo(A.hijoIzqdo(n),A);
        }
        
        if(A.hijoDrcho(n)!= Abin<T>::NODO_NULO){
            podaArbolNodo(A.hijoDrcho(n),A);
        }
        
        if(n == A.hijoIzqdo(A.padre(n))){
            eliminarHijoIzqdo(A.padre(n));
        }else{
            eliminarHijoDrcho(A.padre(n));
        }

    }
    
}




