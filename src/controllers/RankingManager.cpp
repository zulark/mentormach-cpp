#include "RankingManager.hpp"
#include <iostream>
#include <iomanip>

void GerenciadorRanking::quickSort(Mentor** arr, int esq, int dir) {
    if (esq < dir) {
        int p = particionar(arr, esq, dir);
        quickSort(arr, esq, p - 1);
        quickSort(arr, p + 1, dir);
    }
}

int GerenciadorRanking::particionar(Mentor** arr, int esq, int dir) {
    Mentor* pivo  = arr[dir];
    int     i     = esq - 1;

    for (int j = esq; j < dir; j++) {
        if (arr[j]->getAvaliacao() > pivo->getAvaliacao()) {
            i++;
            Mentor* temp = arr[i];
            arr[i]       = arr[j];
            arr[j]       = temp;
        }
    }
    Mentor* temp = arr[i + 1];
    arr[i + 1]   = arr[dir];
    arr[dir]     = temp;
    return i + 1;
}

Mentor** GerenciadorRanking::gerarRankingMentores(ListaEncadeada<Mentor>& lista, int& tamanho) {
    tamanho = lista.getSize();
    if (tamanho == 0) return nullptr;

    Mentor** arr = lista.paraArray(tamanho);
    if (tamanho > 1) quickSort(arr, 0, tamanho - 1);
    return arr;
}

void GerenciadorRanking::exibirEstatisticas(Pilha<Match>& historico) {
    int n = historico.getTamanho();
    int totalMatches = n;
    float melhorAvaliacao = 0.0f;
    std::string mentorMaisRequisitado = "N/A";

    if (n > 0) {
        Match** matches = historico.paraArray(n);

        int contadores[1000] = {0};
        std::string nomes[1000];
        int maxContador = 0;
        int idxMaior    = -1;

        for (int i = 0; i < n; i++) {
            float compat = matches[i]->compatibilidade;
            if (compat > melhorAvaliacao) {
                melhorAvaliacao = compat;
            }

            for (int j = 0; j < 1000; j++) {
                if (nomes[j] == matches[i]->mentor->getNome()) {
                    contadores[j]++;
                    if (contadores[j] > maxContador) {
                        maxContador = contadores[j];
                        idxMaior    = j;
                    }
                    break;
                }
                if (nomes[j].empty()) {
                    nomes[j] = matches[i]->mentor->getNome();
                    contadores[j]++;
                    if (contadores[j] > maxContador) {
                        maxContador = contadores[j];
                        idxMaior    = j;
                    }
                    break;
                }
            }
        }

        if (idxMaior >= 0) {
            mentorMaisRequisitado = nomes[idxMaior];
        }

        delete[] matches;
    }

    std::cout << "\n╔══════════════════════════════════╗\n";
    std::cout << "║           RELATORIOS             ║\n";
    std::cout << "╚══════════════════════════════════╝\n\n";
    std::cout << "Mentorias realizadas     : " << totalMatches << "\n";
    std::cout << "Mentor mais requisitado  : " << mentorMaisRequisitado << "\n";
    std::cout << "Melhor compatibilidade   : " << std::fixed << std::setprecision(1) << (melhorAvaliacao * 100) << "%\n\n";
}
