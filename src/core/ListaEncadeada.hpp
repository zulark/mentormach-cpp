
#ifndef LISTA_ENCADEADA_HPP
#define LISTA_ENCADEADA_HPP

template <typename T>
struct Node {
    T*    data;
    Node* next;
    Node* prev;

    Node(T* data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class ListaEncadeada {
private:
    Node<T>* head;
    Node<T>* tail;
    int      size;

public:
    ListaEncadeada() : head(nullptr), tail(nullptr), size(0) {}

    ~ListaEncadeada() {
        Node<T>* atual = head;
        while (atual) {
            Node<T>* temp = atual->next;
            delete atual;
            atual = temp;
        }
    }

    void inserir(T* data) {
        Node<T>* novo = new Node<T>(data);
        if (!head) {
            head = tail = novo;
        } else if (data->getId() <= head->data->getId()) {
            novo->next = head;
            head->prev = novo;
            head       = novo;
        } else {
            Node<T>* atual = head;
            while (atual->next && atual->next->data->getId() < data->getId())
                atual = atual->next;
            novo->next = atual->next;
            novo->prev = atual;
            if (atual->next) atual->next->prev = novo;
            else             tail              = novo;
            atual->next = novo;
        }
        size++;
    }

    void remover(int id) {
        Node<T>* atual = head;
        while (atual && atual->data->getId() != id)
            atual = atual->next;
        if (!atual) return;
        if (atual->prev) atual->prev->next = atual->next;
        else             head              = atual->next;
        if (atual->next) atual->next->prev = atual->prev;
        else             tail              = atual->prev;
        delete atual;
        size--;
    }

    T* buscar(int id) {
        Node<T>* atual = head;
        while (atual) {
            if (atual->data->getId() == id) return atual->data;
            atual = atual->next;
        }
        return nullptr;
    }

    T** paraArray(int& n) const {
        n = size;
        if (n == 0) return nullptr;
        T**      arr   = new T*[n];
        Node<T>* atual = head;
        for (int i = 0; i < n; i++) {
            arr[i] = atual->data;
            atual  = atual->next;
        }
        return arr;
    }

    Node<T>* getHead() const { return head; }
    Node<T>* getTail() const { return tail; }
    int      getSize() const { return size; }
};

#endif // LISTA_ENCADEADA_HPP
