#ifndef CLUBE_HPP
#define CLUBE_HPP

#include <string>
#include <vector>

#include "Time.hpp"

using namespace std;


class Clube : public Time {

    protected:

    string cidade;

    public:

    Clube(string nome, string cidade, int golsMarcados, int golsSofridos);
    Clube();

    string getCidade() const;

    void setCidade(string cidade);

    vector<Clube> getClubes();

    ~Clube();

};

#endif /* CLUBE_HPP*/