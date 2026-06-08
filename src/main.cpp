#include <iostream>
#include "controllers/UserManager.hpp"
#include "controllers/MatchEngine.hpp"
#include "controllers/RankingManager.hpp"
#include "views/ConsoleManager.hpp"

int main() {
    GerenciadorUsuarios usuario;
    MecanismoMatch matching;
    GerenciadorRanking rank;
    GerenciadorConsole console;

    bool executando = true;
    while (executando) {
        int opcao = console.exibirMenuPrincipal();

        switch (opcao) {
            case 1: {
                int id, nivel;
                std::string nome, area;
                console.capturarDadosAluno(id, nome, area, nivel);
                usuario.cadastrarAluno(id, nome, area, nivel);
                std::cout << "Aluno cadastrado com sucesso!\n";
                break;
            }
            case 2: {
                int id, nivel;
                float avaliacao;
                std::string nome, area;
                console.capturarDadosMentor(id, nome, area, avaliacao, nivel);
                usuario.cadastrarMentor(id, nome, area, avaliacao, nivel);
                std::cout << "Mentor cadastrado com sucesso!\n";
                break;
            }
            case 3: {
                int id = console.capturarId();
                Aluno* aluno = usuario.buscarAluno(id);
                if (aluno) {
                    matching.adicionarNaFila(aluno);
                    std::cout << "Aluno adicionado a fila!\n";
                } else {
                    std::cout << "Aluno nao encontrado!\n";
                }
                break;
            }
            case 4: {
                Match* match = matching.processarProximoMatch(usuario.obterListaMentores());
                console.exibirMatchRealizado(match);
                break;
            }
            case 5: {
                int tamanho;
                Mentor** ranking = rank.gerarRankingMentores(usuario.obterListaMentores(), tamanho);
                console.exibirRelatorios(ranking, tamanho, matching.obterHistorico());
                if (ranking) delete[] ranking;
                break;
            }
            case 6: {
                rank.exibirEstatisticas(matching.obterHistorico());
                break;
            }
            case 7: {
                executando = false;
                std::cout << "Saindo...\n";
                break;
            }
            default: {
                std::cout << "Opcao invalida!\n";
                break;
            }
        }
    }

    return 0;
}
