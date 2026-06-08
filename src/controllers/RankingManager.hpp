#ifndef RANKINGMANAGER_HPP
#define RANKINGMANAGER_HPP

#include "../models/Match.hpp"
#include "../core/ListaEncadeada.hpp"
#include "../core/Pilha.hpp"

class GerenciadorRanking {
private:
    void quickSort(Mentor** arr, int esq, int dir);
    int  particionar(Mentor** arr, int esq, int dir);

public:
    Mentor** gerarRankingMentores(ListaEncadeada<Mentor>& lista, int& tamanho);
    void exibirEstatisticas(Pilha<Match>& historico);
};

#endif // RANKINGMANAGER_HPP
