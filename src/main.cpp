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
                std::string nome, area;
                int nivel;
                console.capturarDadosAluno(nome, area, nivel);
                int idAluno = usuario.cadastrarAluno(nome, area, nivel);
                std::cout << "Aluno cadastrado com sucesso! ID: " << idAluno << "\n";
                std::cout << "Pressione ENTER para continuar...";
                std::cin.get();
                break;
            }
            case 2: {
                std::string nome, area;
                float avaliacao;
                int nivel;
                console.capturarDadosMentor(nome, area, avaliacao, nivel);
                int idMentor = usuario.cadastrarMentor(nome, area, avaliacao, nivel);
                std::cout << "Mentor cadastrado com sucesso! ID: " << idMentor << "\n";
                std::cout << "Pressione ENTER para continuar...";
                std::cin.get();
                break;
            }
            case 3: {
                console.exibirListaAlunos(usuario.obterListaAlunos());
                int id = console.capturarId();
                Aluno* aluno = usuario.buscarAluno(id);
                if (aluno) {
                    matching.adicionarNaFila(aluno);
                    std::cout << "Aluno adicionado a fila!\n";
                } else {
                    std::cout << "Aluno nao encontrado!\n";
                }
                std::cout << "Pressione ENTER para continuar...";
                std::cin.get();
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
                std::cout << "Pressione ENTER para continuar...";
                std::cin.get();
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
