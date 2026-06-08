#ifndef FILA_HPP
#define FILA_HPP

template <typename T>
class Fila {
private:
    struct No {
        T*  dado;
        No* proximo;

        No(T* dado) : dado(dado), proximo(nullptr) {}
    };

    No* inicio;
    No* fim;
    int tamanho;

public:
    Fila() : inicio(nullptr), fim(nullptr), tamanho(0) {}

    ~Fila() {
        while (!estaVazia()) desenfileirar();
    }

    void enfileirar(T* dado) {
        No* novo = new No(dado);
        if (fim) fim->proximo = novo;
        else     inicio       = novo;
        fim = novo;
        tamanho++;
    }

    void desenfileirar() {
        if (estaVazia()) return;
        No* temp  = inicio;
        inicio    = inicio->proximo;
        if (!inicio) fim = nullptr;
        delete temp;
        tamanho--;
    }

    T* frente() const {
        if (estaVazia()) return nullptr;
        return inicio->dado;
    }

    bool estaVazia()   const { return tamanho == 0; }
    int  getTamanho()  const { return tamanho; }

    T** paraArray(int& n) const {
        n = tamanho;
        if (n == 0) return nullptr;
        T** arr   = new T*[n];
        No* atual = inicio;
        for (int i = 0; i < n; i++) {
            arr[i] = atual->dado;
            atual  = atual->proximo;
        }
        return arr;
    }
};

#endif // FILA_HPP
