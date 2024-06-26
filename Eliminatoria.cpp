#include "Eliminatoria.hpp"
#include "Time.hpp"
#include "Competicao.hpp"
#include <iomanip> // Include the <iomanip> header to access setw
#include <string>
#include <iostream>
#include <memory>   
#include <vector>
#include "Selecao.hpp"

using namespace std;

Eliminatoria::Eliminatoria() : selecoes() {
    // inicialize outros membros, se necessário
}


Eliminatoria::~Eliminatoria() {
    // Não é necessário implementar o destrutor, pois não há recursos a serem liberados explicitamente
};

void Eliminatoria::ordenarTimes() {
    // Ordena o vetor de selecoes de acordo com os critérios de desempate
    sort(selecoes.begin(), selecoes.end(), [](const shared_ptr<Selecao>& selecao1, const shared_ptr<Selecao>& selecao2) {
        if (selecao1->calcularPontos() != selecao2->calcularPontos()) {
            return selecao1->calcularPontos() > selecao2->calcularPontos();
        } else if (selecao1->getVitorias() != selecao2->getVitorias()) {
            return selecao1->getVitorias() > selecao2->getVitorias();
        } else if (selecao1->calcularSaldoGols() != selecao2->calcularSaldoGols()) {
            return selecao1->calcularSaldoGols() > selecao2->calcularSaldoGols();
        } else if (selecao1->getGolsMarcados() != selecao2->getGolsMarcados()) {
            return selecao1->getGolsMarcados() > selecao2->getGolsMarcados();
        } else {
            return selecao1->getNome() < selecao2->getNome();
        }
    });
};

void Eliminatoria::melhor() {

    cout << "Melhor da Eliminatoria:" << endl;
    cout << "Pais: " << selecoes.front()->getNome() << endl;
}

void Eliminatoria::lerTimes() {

    string nome1, nome2;
    int _gols1, _gols2;

    char x;

    cin >> nome1 >> _gols1;
    cin >> x;
    cin >> _gols2 >> nome2;

    procurarInsertarTime(nome1, _gols1, _gols2);
    procurarInsertarTime(nome2, _gols2, _gols1);


}

void Eliminatoria::procurarInsertarTime(string nome, int gol1, int gol2) {
    bool encontrado = false;
    for (auto it = selecoes.begin(); it != selecoes.end(); ++it) {
        auto selecao = *it;
        if (selecao->getNome() == nome) {
            selecao->atualizarTime(gol1, gol2);
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        shared_ptr<Selecao> novaSelecao(new Selecao(nome, gol1, gol2));
        selecoes.push_back(novaSelecao); // Adiciona no final do vetor
    }
}

/*void Eliminatoria::imprimirTabela() {
    cout << "Eliminatoria" << endl;
    cout << setw(20) << "TIME" << "\tP\tJ\tV\tE\tD\tGP\tGC\tSG" << endl;
    for (const auto& selecao : selecoes) {
        cout << setw(20) << selecao->getNome() << "\t" << selecao->calcularPontos() << "\t"
                  << setw(2) << (selecao->getVitorias() + selecao->getEmpates() + selecao->getDerrotas()) << "\t"
                  << setw(2) << selecao->getVitorias() << "\t" << setw(2) << selecao->getEmpates() << "\t" 
                  << setw(2) << selecao->getDerrotas() << "\t"
                  << setw(2) << selecao->getGolsMarcados() << "\t" << setw(2) << selecao->getGolsSofridos() << "\t" 
                  << setw(2) << selecao->calcularSaldoGols() << endl;
    }
}*/

void Eliminatoria::imprimirTabela(){
    printf("Eliminatoria:\n");
	printf("                TIME");
	printf("\t P\t J\t V\t E\t D\t GP\t GC\t SG\n");

	for (unsigned int i = 0; i < selecoes.size(); i++) {
		selecoes[i]->imprime();
	}

	printf("\n");
}




