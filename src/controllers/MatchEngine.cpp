#include "MatchEngine.hpp"
#include <cmath>

void MecanismoMatch::adicionarNaFila(Aluno* aluno) {
    filaEspera.enfileirar(aluno);
}

float MecanismoMatch::calcularCompatibilidade(Aluno* aluno, Mentor* mentor) {
    float pontos = 0.0f;

    if (aluno->getAreaInteresse() == mentor->getAreaInteresse()) {
        pontos += 50.0f;
    }

    int difNivel = std::abs(aluno->getNivelAprendizado() - mentor->getNivelEnsino());
    float compNivel = std::max(0.0f, (4.0f - difNivel) / 4.0f) * 30.0f;
    pontos += compNivel;

    float avaliacaoNorm = (mentor->getAvaliacao() / 5.0f) * 20.0f;
    pontos += avaliacaoNorm;

    return pontos / 100.0f;
}

Match* MecanismoMatch::processarProximoMatch(ListaEncadeada<Mentor>& mentores) {
    if (filaEspera.estaVazia()) return nullptr;

    Aluno* aluno = filaEspera.frente();
    filaEspera.desenfileirar();

    Mentor* melhorMentor = nullptr;
    float   maiorCompatibilidade = 0.0f;

    Node<Mentor>* atual = mentores.getHead();
    while (atual) {
        float compatibilidade = calcularCompatibilidade(aluno, atual->data);
        if (compatibilidade > maiorCompatibilidade) {
            maiorCompatibilidade = compatibilidade;
            melhorMentor         = atual->data;
        }
        atual = atual->next;
    }

    if (maiorCompatibilidade >= 0.70f && melhorMentor) {
        Match* match = new Match(aluno, melhorMentor, maiorCompatibilidade);
        historico.empilhar(match);
        return match;
    }

    return nullptr;
}

Fila<Aluno>& MecanismoMatch::obterFila() {
    return filaEspera;
}

Pilha<Match>& MecanismoMatch::obterHistorico() {
    return historico;
}
