#include "agenDinamica.h"
#include <iostream>

template <typename T>
void podaAgen(int x, Agen<T>& A){

    podaAgen_Rec(x,A.raiz(),A);

}

template <typename T>
void podaAgen_Rec(int x, typename Agen<T>::nodo n, Agen<T>& A){

    if(n!=Agen<T>::NODO_NULO){
        if(A.elemento(n) == x){

            funcionPoda(n,A);

        }else{

            if(A.hijoIzqdo(n)!=Agen<T>::NODO_NULO){

                typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
                while(hijo!=Agen<T>::NODO_NULO){
                    podaAgen_Rec(x,hijo,A);
                    hijo = A.hermDrcho(hijo);
                }

            }

        }
    }

}


//Si queremos no borrar el nodo en cuestión, simplemente tenemos que pasar
// el elemento para comparar, o hacer comprobación en la función de búsqueda.
template <typename T>
void funcionPoda(typename Agen<T>::nodo n, Agen<T>& A){

    if(A.hijoIzqdo(n)==Agen<T>::NODO_NULO){

        if(n == A.raiz(){

            A.eliminarRaiz();

        }else if(n == A.hijoIzqdo(A.padre(n))){

            A.eliminarHijoIzqdo(A.padre(n));

        }else{
            //Tenemos que buscarlo dentro de los distintos hijos de su padre
            typename Agen<T>::nodo hijo = A.hijoIzqdo(A.padre(n));
            while(hijo != n){

                hijo = A.hermDrcho(hijo);
                
            }

            A.eliminarHermDrcho(hijo);

        }
        

    }else{

        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        
        while(hijo!=Agen<T>::NODO_NULO){
            funcionPoda(hijo,A);
            hijo = A.hermDrcho(hijo);
        }

    }

}
