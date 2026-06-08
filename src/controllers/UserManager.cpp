#include "UserManager.hpp"

int GerenciadorUsuarios::cadastrarAluno(std::string nome, std::string area, int nivel) {
    int id = proximoIdAluno++;
    Aluno* aluno = new Aluno(id, nome, area, nivel);
    alunos.inserir(aluno);
    return id;
}

int GerenciadorUsuarios::cadastrarMentor(std::string nome, std::string area, float avaliacao, int nivel) {
    int id = proximoIdMentor++;
    Mentor* mentor = new Mentor(id, nome, area, avaliacao, nivel);
    mentores.inserir(mentor);
    return id;
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
