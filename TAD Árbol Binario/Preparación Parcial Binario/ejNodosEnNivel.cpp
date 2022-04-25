#include <algorithm> //max y min

#include <cmath>

template <typename T>
int nodosNivel(const Abin<T>& A){

    if(A.arbolVacio()){
        return 0;
    }else{
        return nodosNivel_Rec(A.raiz(),A);
    }

}

template<typename T>
int nodosNivel_Rec(typename Abin<T>::nodo n,const Abin<T>& A){

    if(n==Abin<T>::NODO_NULO){

        return 0;

    }else{

        if(contarNodos(A.raiz(),profundidadNodo(n,A),A) -1 == 2){ //El -1 surge porque contamos con el propio nodo.
            return 1 + nodosNivel_Rec(A.hijoIzqdo(n),A) + nodosNivel_Rec(A.hijoDrcho(n),A);
        }else{
            return 0 + nodosNivel_Rec(A.hijoIzqdo(n),A) + nodosNivel_Rec(A.hijoDrcho(n),A);
        }


    }

}
template <typename T>
int profundidadNodo(typename Abin<T>::nodo n,const Abin<T>& A){

    if(n==Abin<T>::NODO_NULO){
        return -1;
    }else{
        return 1 + profundidadNodo(A.padre(n));
    }

}

template <typename T>
int contarNodos(int prof,typename Abin<T>::nodo n,const Abin<T>& A){

    if(n==Abin<T>::NODO_NULO){
        return 0;
    }else{
        if(profundidadNodo(n,A)<prof){
            return 0 + contarNodos(prof,A.hijoIzqdo(n),A) + contarNodos(prof,A.hijoDrcho(n),A);
        }else if (profundidadNodo(n,A)==prof){
            return 1;
        }
    }

}
