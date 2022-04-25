#include "celdas_enlazadas.hpp"

int nodosRebeldes(const Abin<bool>& A){

    if(A.arbolVacio()){
        return 0;
    }else{
    return nodosRebeldes_Rec(A.raiz(), A);
    }

}


int nodosRebeldes_Rec(typename Abin<bool>::nodo n,const Abin<bool>& A){

    if(n == Abin<bool>::NODO_NULO){
        return 0;
    }else if(diferenciaAncestros(A.elemento(n),n,A) > 0){
            return 1 + nodosRebeldes_Rec(A.hijoIzqdo(n),A) + nodosRebeldes_Rec(A.hijoDrcho(n),A);
        }else{
            return 0 + nodosRebeldes_Rec(A.hijoIzqdo(n),A) + nodosRebeldes_Rec(A.hijoDrcho(n),A);
        }

    }

}

int diferenciaAncestros(const bool elemento, typename Abin<bool>::nodo n,const Abin<bool>& A){

    if(n == Abin<bool>::NODO_NULO){
        return 1;
    }else if(A.elemento(n) == elemento){

        return -1 + diferenciaAncestros(elemento,A.padre(n),A);

    }else{

        return 1 + diferenciaAncestros(elemento,A.padre(n),A);

    }
   

}

