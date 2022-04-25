/* a) Usamos un union con una variable de tipo
    char(para el operador) y otra de tipo float (para
    los operandos)


*/
#include "celdas_enlazadas.hpp"
union dato{
    char operador;
    float operando;
};

float resultadoAbin(Abin<dato>& A){

    if(!A.arbolVacio()){
        return resultadoAbin_Rec(A.raiz(),A);
    }
    

}


float resultadoAbin_Rec(typename Abin<dato>::nodo n, const Abin<dato>& A){

    if(n != Abin<dato>::NODO_NULO){

        if(A.hijoIzqdo(n)==Abin<dato>::NODO_NULO && A.hijoDrcho(n)==Abin<dato>::NODO_NULO){

            return A.elemento(n).operando;

        }else{
            switch(A.elemento(n).operador){

                case '+':
                    return resultadoAbin_Rec(A.hijoIzqdo(n),A) + resultadoAbin_Rec(A.hijoDrcho(n),A);
                    
                case '-':
                    return resultadoAbin_Rec(A.hijoIzqdo(n),A) - resultadoAbin_Rec(A.hijoDrcho(n),A);
                    
                case '*':
                    return resultadoAbin_Rec(A.hijoIzqdo(n),A) * resultadoAbin_Rec(A.hijoDrcho(n),A);
                    
                case '/':
                    return resultadoAbin_Rec(A.hijoIzqdo(n),A) / resultadoAbin_Rec(A.hijoDrcho(n),A);
                    
            }
            
        }

    }

}