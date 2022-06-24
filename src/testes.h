#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"


class TesteDominios {
    private:
        Codigo *codigo;
        Classe *classe;
        Descricao *descricao;
        Endereco *endereco;
        Data *data;
        Numero *numero;
        Moeda *moeda;
        Nome *nome;
        Email *email;
        Senha *senha;
        Telefone *telefone;

        int estado_TesteDominios;

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        int run();

        const static int SUCESSO = 0;
        const static int FALHA = -1;

};


class TesteEntidades {
    private:
        Imovel *imovel;
        Proposta *proposta;
        Usuario *usuario;

        int estado_TesteEntidades;

        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();
    public:
        const static int SUCESSO = 0;
        const static int FALHA = -1;

        int run();
};


#endif // TESTES_H_INCLUDED
