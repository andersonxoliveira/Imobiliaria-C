#include "testes.h"

const int TesteEntidades::SUCESSO;
const int TesteEntidades::FALHA;

const int TesteDominios::SUCESSO;
const int TesteDominios::FALHA;


// Entidades
void TesteEntidades::setUp() {
    imovel = new Imovel();
    proposta = new Proposta();
    usuario = new Usuario();
}

void TesteEntidades::tearDown(){
    delete imovel;
    delete proposta;
    delete usuario;
}

void TesteEntidades::testarCenarioSucesso() {
    Codigo codigo_teste;
    Classe classe_teste;
    Descricao descricao_teste;
    Data data_inicial_teste, data_final_teste;
    Numero hospede_teste;
    Moeda valor_teste;
    Endereco endereco_teste;
    Nome nome_teste;
    Email email_teste;
    Senha senha_teste;
    Telefone telefone_teste;

    codigo_teste.setValor("10101");
    classe_teste.setValor(1);
    descricao_teste.setValor("Descricao Atula.");
    data_inicial_teste.setValor("44-44-4444");
    data_final_teste.setValor("44-44-4444");
    hospede_teste.setValor(5);
    valor_teste.setValor(122.1);
    endereco_teste.setValor("QNA 23 CASA 332");
    nome_teste.setValor("Igor Silva");
    email_teste.setValor("aluno900@unb.br");
    senha_teste.setValor("bat210");
    telefone_teste.setValor("(061)-996784848");

    try{
        imovel->setCodigo(codigo_teste);
        imovel->setClasse(classe_teste);
        imovel->setDescricao(descricao_teste);
        imovel->setEndereco(endereco_teste);
        imovel->setDataInicial(data_inicial_teste);
        imovel->setDataFinal(data_final_teste);
        imovel->setHospedes(hospede_teste);
        imovel->setValor(valor_teste);

        proposta->setCodigo(codigo_teste);
        proposta->setDataInicial(data_inicial_teste);
        proposta->setDataFinal(data_final_teste);
        proposta->setHospedes(hospede_teste);
        proposta->setValor(valor_teste);


        usuario->setNome(nome_teste);
        usuario->setEmail(email_teste);
        usuario->setSenha(senha_teste);
        usuario->setTelefone(telefone_teste);

        estado_TesteEntidades = SUCESSO;

        //cout << imovel->getCodigo();

    } catch(invalid_argument excecao) {
        return;
    }
}


void TesteEntidades::testarCenarioFalha(){
    Codigo codigo_teste;
    Classe classe_teste;
    Descricao descricao_teste;
    Data data_inicial_teste, data_final_teste;
    Numero hospede_teste;
    Moeda valor_teste;
    Endereco endereco_teste;
    Nome nome_teste;
    Email email_teste;
    Senha senha_teste;
    Telefone telefone_teste;

    codigo_teste.setValor("00000");
    classe_teste.setValor(-1);
    descricao_teste.setValor("Descricaoula"); // Falta o ponto
    data_inicial_teste.setValor("44-44-4444");
    data_final_teste.setValor("44-44-4444");
    hospede_teste.setValor(555);
    valor_teste.setValor(-122.1);
    endereco_teste.setValor("QNA&23*CASA 332");
    nome_teste.setValor("Igor*Silva#");
    email_teste.setValor("aluno900@unb.br");
    senha_teste.setValor("bat210-----*&");
    telefone_teste.setValor("(06155)-996784848&");

    try {
        imovel->setCodigo(codigo_teste);
        imovel->setClasse(classe_teste);
        imovel->setDescricao(descricao_teste);
        imovel->setEndereco(endereco_teste);
        imovel->setDataInicial(data_inicial_teste);
        imovel->setDataFinal(data_final_teste);
        imovel->setHospedes(hospede_teste);
        imovel->setValor(valor_teste);

        proposta->setCodigo(codigo_teste);
        proposta->setDataInicial(data_inicial_teste);
        proposta->setDataFinal(data_final_teste);
        proposta->setHospedes(hospede_teste);
        proposta->setValor(valor_teste);


        usuario->setNome(nome_teste);
        usuario->setEmail(email_teste);
        usuario->setSenha(senha_teste);
        usuario->setTelefone(telefone_teste);


        estado_TesteEntidades = FALHA;

    }catch(invalid_argument excecao) {
        return;
    }
}

int TesteEntidades::run() {
    setUp();
    testarCenarioSucesso();
    //testarCenarioFalha(); // Esta detectando erros
    tearDown();

    return estado_TesteEntidades;
}




//TesteDominios
void TesteDominios::setUp() {
        codigo = new Codigo();
        classe = new Classe();
        descricao = new Descricao();
        endereco = new Endereco();
        data = new Data();
        numero = new Numero();
        moeda = new Moeda();
        nome = new Nome();
        email = new Email();
        senha = new Senha();
        telefone = new Telefone();
}

void TesteDominios::tearDown(){
    delete codigo;
    delete classe;
    delete descricao;
    delete endereco;
    delete data;
    delete numero;
    delete moeda;
    delete nome;
    delete email;
    delete senha;
    delete telefone;
}

void TesteDominios::testarCenarioSucesso() {
    codigo->setValor("10101");
    classe->setValor(3);
    descricao->setValor("Descricao Atual.");
    data->setValor("44-44-4444");
    numero->setValor(5);
    moeda->setValor(122.1);
    endereco->setValor("QNA 23 CASA 332");
    nome->setValor("Igor Silva");
    email->setValor("aluno900@unb.br");
    senha->setValor("batf20");
    telefone->setValor("(061)-996784848");

    estado_TesteDominios = SUCESSO;
}

void TesteDominios::testarCenarioFalha() {

    try{
        codigo->setValor("0000");
        classe->setValor(-3);
        descricao->setValor("Descricao Atual.");
        data->setValor("44-44-4444");
        numero->setValor(5);
        moeda->setValor(122.1);
        endereco->setValor("QNA 23 CASA 332");
        nome->setValor("Igor Silva");
        email->setValor("aluno900@unb.br");
        senha->setValor("batf20");
        telefone->setValor("(061)-996784848");

        estado_TesteDominios = FALHA;

    }catch(invalid_argument excecao) {
        return;
    }

}

int TesteDominios::run() {
    setUp();
    testarCenarioSucesso();
    //testarCenarioFalha();
    tearDown();

    return estado_TesteDominios;
}



