#include <iostream>

template <typename T>
class ApoMinMax{

    public:
        explicit ApoMinMax(size_t maxNodos);
        void insertar(const T& e);
        void suprimir();
        const T& cima() const;
        bool vacio() const;
        ApoMinMax(const ApoMinMax<T>& A);

    private:
        typedef size_t nodo;
        T* nodos;
        size_t maxNodos;
        size_t numNodos;
        nodos padre(nodo i) const {return (i-1)/2;}
        nodo hIzq(nodo i) const {return 2*i+1;}
        nodo hDer(nodo i) const {return 2*i+2;}
        void flotarPar(nodo i);
        void flotarImpar(nodo i);
        void hundirPar(nodo i);
        void hundirImpar(nodo i);
        void nivelNodo(nodo i);

};


