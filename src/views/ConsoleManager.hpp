#ifndef CONSOLEMANAGER_HPP
#define CONSOLEMANAGER_HPP

#include "../models/Aluno.hpp"
#include "../models/Mentor.hpp"
#include "../models/Match.hpp"
#include "../core/Fila.hpp"
#include "../core/Pilha.hpp"
#include <string>

class GerenciadorConsole {
private:
    void exibirCabecalho(const std::string& titulo);

public:
    int exibirMenuPrincipal();
    void exibirTelaDaFila(Fila<Aluno>& fila);
    void exibirMatchRealizado(Match* match);
    void exibirRelatorios(Mentor** ranking, int tamanho, Pilha<Match>& historico);

    void capturarDadosAluno(int& id, std::string& nome, std::string& area, int& nivel);
    void capturarDadosMentor(int& id, std::string& nome, std::string& area, float& avaliacao, int& nivel);
    int  capturarId();

    void limparTela();
};

#endif // CONSOLEMANAGER_HPP
