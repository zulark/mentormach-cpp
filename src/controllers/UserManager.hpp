#ifndef USERMANAGER_HPP
#define USERMANAGER_HPP

#include "../models/Aluno.hpp"
#include "../models/Mentor.hpp"
#include "../core/ListaEncadeada.hpp"
#include <algorithm>

class GerenciadorUsuarios {
private:
    ListaEncadeada<Aluno>  alunos;
    ListaEncadeada<Mentor> mentores;
    int proximoIdAluno;
    int proximoIdMentor;

public:
    GerenciadorUsuarios() : proximoIdAluno(1), proximoIdMentor(1) {}

    int cadastrarAluno(std::string nome, std::string area, int nivel);
    int cadastrarMentor(std::string nome, std::string area, float avaliacao, int nivel);

    Aluno*  buscarAluno(int id);
    Mentor* buscarMentor(int id);

    ListaEncadeada<Aluno>&  obterListaAlunos();
    ListaEncadeada<Mentor>& obterListaMentores();
};

#endif // USERMANAGER_HPP
