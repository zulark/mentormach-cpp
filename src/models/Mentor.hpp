#ifndef MENTOR_HPP
#define MENTOR_HPP

#include "User.hpp"

class Mentor : public User {
    private:
        float avaliacao;
        int nivel_ensino;

    public:
        Mentor(int id, std::string nome, std::string area, float avaliacao, int nivel)
            : User(id, nome, area), avaliacao(avaliacao), nivel_ensino(nivel) {}

        float getAvaliacao() const { return avaliacao; }
        int getNivelEnsino() const { return nivel_ensino; }
};

#endif // MENTOR_HPP