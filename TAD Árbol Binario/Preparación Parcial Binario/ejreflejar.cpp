#include "celdas_enlazadas.hpp"

template <typename T>
Abin<T> arbolReflejado(const Abin<T>& A){

    if(!A.arbolVacio()){
        
        Abin<T> B;
        B.insertarRaiz(A.elemento(A.raiz()));
        arbolReflejado_Rec(A.raiz(),B.raiz(),A,B); //Preguntar a pedro

    }
    
    return B;


}

template <typename T>
void arbolReflejado_Rec(typename Abin<T>::nodo nA,typename Abin<T>::nodo nB, const Abin<T>& A, Abin<T>& B){

    if(n!=Abin<T>::NODO_NULO){

        if(A.hijoIzqdo(nA)!=Abin<T>::NODO_NULO){
            B.insertarHijoDrcho(nB,A.elemento(A.hijoIzqdo(nA)));
            arbolReflejado_Rec(A.hijoIzqdo(nA),B.hijoDrcho(nB),A,B);
        }

        if(A.hijoDrcho(nA)!= Abin<T>::NODO_NULO){
            B.insertarHijoIzqdo(nB,A.elemento(A.hijoDrcho(nA)));
            arbolReflejado_Rec(A.hijoDrcho(nA),B.hijoIzqdo(nB),A,B);
        }

    }

}
