#include <iostream>
#include "abb.h"

template <typename T>
const T& infimo(const T& x,const Abb<T>& A){

    T aux = x;
    infimoRec(aux,x,A);
    return aux;
    

}

template <typename T>
void infimoRec(T& aux,const T& x, const Abb<T>& A){

    if(!A.vacio()){

        if(x==A.elemento()){

            aux = A.elemento();

        }

        if(x<A.elemento()){
            if(A.izqdo().vacio() && A.drcho().vacio()){
                aux = A.elemento();
            }else{
                //Falta algo para comprobar
                infimoRec(aux,x,A.izqdo());
            }
            
        }

        if(x>A.elemento()){
            if(x==aux){
                aux=A.elemento();
            }else{
                aux = std::max(aux,A.elemento());
            }           
            
        }

    }

}

