#ifndef PILHA_HPP
#define PILHA_HPP

template <typename T>
class Pilha {
private:
    struct No {
        T*  dado;
        No* anterior;

        No(T* dado) : dado(dado), anterior(nullptr) {}
    };

    No* topoNo;
    int tamanho;

public:
    Pilha() : topoNo(nullptr), tamanho(0) {}

    ~Pilha() {
        while (!estaVazia()) desempilhar();
    }

    void empilhar(T* dado) {
        No* novo       = new No(dado);
        novo->anterior = topoNo;
        topoNo         = novo;
        tamanho++;
    }

    void desempilhar() {
        if (estaVazia()) return;
        No* temp = topoNo;
        topoNo   = topoNo->anterior;
        delete temp;
        tamanho--;
    }

    T* topo() const {
        if (estaVazia()) return nullptr;
        return topoNo->dado;
    }

    bool estaVazia()  const { return tamanho == 0; }
    int  getTamanho() const { return tamanho; }

    T** paraArray(int& n) const {
        n = tamanho;
        if (n == 0) return nullptr;
        T** arr   = new T*[n];
        No* atual = topoNo;
        for (int i = 0; i < n; i++) {
            arr[i] = atual->dado;
            atual  = atual->anterior;
        }
        return arr;
    }
};

#endif // PILHA_HPP
