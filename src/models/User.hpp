#ifndef USER_HPP
#define USER_HPP

#include <string>

class User{
    protected:
        int id;
        std::string nome;
        std::string area_de_interesse;

    public:
        User(int id, std::string nome, std::string area)
            :   id(id), nome(nome), area_de_interesse(area) {}

        virtual ~User() = default;

        int getId() const { return id; }
        std::string getNome() const { return nome; }
        std::string getAreaInteresse() const { return area_de_interesse; }
};

#endif // USER_HPP
