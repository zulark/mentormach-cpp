#ifndef MATCH_HPP
#define MATCH_HPP

#include "Aluno.hpp"
#include "Mentor.hpp"

struct Match {
    Aluno*  aluno;
    Mentor* mentor;
    float   compatibilidade;

    Match() : aluno(nullptr), mentor(nullptr), compatibilidade(0.0f) {}
    Match(Aluno* a, Mentor* m, float c) : aluno(a), mentor(m), compatibilidade(c) {}
};

#endif // MATCH_HPP
