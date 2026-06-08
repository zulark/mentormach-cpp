#ifndef MATCHENGINE_HPP
#define MATCHENGINE_HPP

#include "../models/Match.hpp"
#include "../core/Fila.hpp"
#include "../core/Pilha.hpp"
#include "../core/ListaEncadeada.hpp"

class MecanismoMatch {
private:
    Fila<Aluno>    filaEspera;
    Pilha<Match>   historico;

    float calcularCompatibilidade(Aluno* aluno, Mentor* mentor);

public:
    void adicionarNaFila(Aluno* aluno);
    Match* processarProximoMatch(ListaEncadeada<Mentor>& mentores);

    Fila<Aluno>&  obterFila();
    Pilha<Match>& obterHistorico();
};

#endif // MATCHENGINE_HPP
