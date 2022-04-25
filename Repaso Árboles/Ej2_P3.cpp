#include "agenDinamica.h"


//Iterativo
template <typename T>
int profundidadAgen(typename Agen<T>::nodo n, Agen<T>& A){

    int cont = 0;
    while(n!=A.raiz()){
        cont++;
        n = A.padre(n);
    }
    return cont++;

}

//Recursivo
template <typename T>
int profundidadAgen_Rec(typename Agen<T>::nodo n, Agen<T>& A){
    if(n == A.raiz()){
        return 0;
    }
    else{
        return 1 + profundidadNodo_Rec(A.padre(n), A);
    }
}