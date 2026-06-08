#include "UserManager.hpp"

void GerenciadorUsuarios::cadastrarAluno(int id, std::string nome, std::string area, int nivel) {
    Aluno* aluno = new Aluno(id, nome, area, nivel);
    alunos.inserir(aluno);
}

void GerenciadorUsuarios::cadastrarMentor(int id, std::string nome, std::string area, float avaliacao, int nivel) {
    Mentor* mentor = new Mentor(id, nome, area, avaliacao, nivel);
    mentores.inserir(mentor);
}

Aluno* GerenciadorUsuarios::buscarAluno(int id) {
    return alunos.buscar(id);
}

Mentor* GerenciadorUsuarios::buscarMentor(int id) {
    return mentores.buscar(id);
}

ListaEncadeada<Aluno>& GerenciadorUsuarios::obterListaAlunos() {
    return alunos;
}

ListaEncadeada<Mentor>& GerenciadorUsuarios::obterListaMentores() {
    return mentores;
}
