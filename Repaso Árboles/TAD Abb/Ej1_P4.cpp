#include "abb.h"

//Falta incluirle en la declaración el Abb<T>:: para que sea método.
template <typename T>
void suprimir(T& e){

    Abb<T>* A = this;
    while(e!=A->elemento()){

        if(e<A->elemento(){
            A = A->izq;
        }else{
            A = A->der;
        }

    }

    while(A->elemento()!=nullptr){
        A->eliminar(A->elemento());
    }

}



