#ifndef TIMES_HPP
#define TIMES_HPP

#include <string>
#include <iostream>

using namespace std;

class Time {

protected:
    int derrotas;
    int empates;
    string nome;
    int golsMarcados;
    int golsSofridos;
    int vitorias;

public:
    Time(string nome, int golsMarcados, int golsSofridos);
    Time(); // Construtor padrão
    void imprime() const; // Modificado para const
    int getDerrotas() const;
    void setDerrotas(int derrotas);
    int getEmpates() const;
    void setEmpates(int empates);
    int getGolsMarcados() const;
    void setGolsMarcados(int golsMarcados);
    int getGolsSofridos() const;
    std::string getNome() const; // Modificado para retornar const string&
    void setNome(const std::string &nome);
    int getVitorias() const;
    void setVitorias(int vitorias);
    int calcularPontos() const; // Modificado para const
    int calcularSaldoGols() const; // Modificado para const
   virtual void atualizarTime(int gols1, int gols2) =0;
    ~Time(); // Destrutor

};

#endif /* TIMES_HPP */

