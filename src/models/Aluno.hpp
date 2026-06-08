#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "User.hpp"

class Aluno : public User {
    private:
        int nivel_aprendizado;

    public:
        Aluno(int id, std::string nome, std::string area, int nivel)
            : User(id, nome, area), nivel_aprendizado(nivel) {}

        int getNivelAprendizado() const { return nivel_aprendizado; }
};


#endif // ALUNO_HPP