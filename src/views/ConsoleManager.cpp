#include "ConsoleManager.hpp"
#include <iostream>
#include <iomanip>

void GerenciadorConsole::exibirCabecalho(const std::string& titulo) {
    std::cout << "\n╔══════════════════════════════════╗\n";
    std::cout << "║ " << std::setw(31) << std::left << titulo << "║\n";
    std::cout << "╚══════════════════════════════════╝\n\n";
}

int GerenciadorConsole::exibirMenuPrincipal() {
    limparTela();
    exibirCabecalho("MENTORMATCH");
    std::cout << "1 - Cadastrar aluno\n";
    std::cout << "2 - Cadastrar mentor\n";
    std::cout << "3 - Entrar na fila\n";
    std::cout << "4 - Processar match\n";
    std::cout << "5 - Ver ranking\n";
    std::cout << "6 - Relatorios\n";
    std::cout << "7 - Sair\n\n";
    std::cout << "Escolha uma opcao: ";

    int opcao;
    std::cin >> opcao;
    std::cin.ignore(10000, '\n');
    return opcao;
}

void GerenciadorConsole::exibirTelaDaFila(Fila<Aluno>& fila) {
    exibirCabecalho("FILA DE MENTORIA");
    std::cout << "Alunos aguardando: " << fila.getTamanho() << "\n\n";

    int n = fila.getTamanho();
    if (n > 0) {
        Aluno** arr = fila.paraArray(n);
        for (int i = 0; i < n; i++) {
            std::cout << (i + 1) << ". " << arr[i]->getNome() << " -> " << arr[i]->getAreaInteresse() << "\n";
        }
        delete[] arr;
    } else {
        std::cout << "Fila vazia.\n";
    }
    std::cout << "\nPressione ENTER para continuar...";
    std::cin.get();
}

void GerenciadorConsole::exibirMatchRealizado(Match* match) {
    exibirCabecalho("MATCH REALIZADO");
    if (match) {
        std::cout << "Aluno          : " << match->aluno->getNome() << "\n";
        std::cout << "Mentor         : " << match->mentor->getNome() << "\n";
        std::cout << "Area           : " << match->aluno->getAreaInteresse() << "\n";
        std::cout << "Compatibilidade: " << std::fixed << std::setprecision(1) << (match->compatibilidade * 100) << "%\n\n";
        std::cout << "Sessao iniciada com sucesso.\n";
    } else {
        std::cout << "Nenhum match encontrado (compatibilidade minima nao atingida).\n";
    }
    std::cout << "\nPressione ENTER para continuar...";
    std::cin.get();
}

void GerenciadorConsole::exibirRelatorios(Mentor** ranking, int tamanho, Pilha<Match>& [[maybe_unused]] historico) {
    exibirCabecalho("RANKING DE MENTORES");
    if (tamanho > 0 && ranking) {
        std::cout << "Pos. Nome                    Avaliacao  Sessoes\n";
        std::cout << "─────────────────────────────────────────────\n";
        for (int i = 0; i < tamanho && i < 10; i++) {
            std::cout << std::setw(2) << (i + 1) << ".  " 
                      << std::setw(20) << std::left << ranking[i]->getNome() 
                      << std::setw(10) << std::right << std::fixed << std::setprecision(1) << ranking[i]->getAvaliacao() 
                      << "\n";
        }
    } else {
        std::cout << "Sem mentores cadastrados.\n";
    }
    std::cout << "\nPressione ENTER para continuar...";
    std::cin.get();
}

void GerenciadorConsole::capturarDadosAluno(int& id, std::string& nome, std::string& area, int& nivel) {
    std::cout << "ID: ";
    std::cin >> id;
    std::cin.ignore(10000, '\n');
    std::cout << "Nome: ";
    std::getline(std::cin, nome);
    std::cout << "Area de interesse: ";
    std::getline(std::cin, area);
    std::cout << "Nivel de aprendizado (1-4): ";
    std::cin >> nivel;
    std::cin.ignore(10000, '\n');
}

void GerenciadorConsole::capturarDadosMentor(int& id, std::string& nome, std::string& area, float& avaliacao, int& nivel) {
    std::cout << "ID: ";
    std::cin >> id;
    std::cin.ignore(10000, '\n');
    std::cout << "Nome: ";
    std::getline(std::cin, nome);
    std::cout << "Area de expertise: ";
    std::getline(std::cin, area);
    std::cout << "Avaliacao (0.0-5.0): ";
    std::cin >> avaliacao;
    std::cin.ignore(10000, '\n');
    std::cout << "Nivel de ensino (1-4): ";
    std::cin >> nivel;
    std::cin.ignore(10000, '\n');
}

int GerenciadorConsole::capturarId() {
    int id;
    std::cout << "ID do aluno: ";
    std::cin >> id;
    std::cin.ignore(10000, '\n');
    return id;
}

void GerenciadorConsole::limparTela() {
    std::cout << "\033[2J\033[1;1H";
}
