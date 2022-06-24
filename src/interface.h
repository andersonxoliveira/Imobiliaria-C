#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

class InterfaceServicoAutenticacao;
class InterfaceServicoUsuario;
class InterfaceServicoImoveis;



//--------------------------------------------------------------------
// Declara��es das interfaces da camada de apresenta��o.
class InterfaceApresentacaoAutenticacao { // Classe abstrata
    public:
        virtual bool autenticar(Email*) = 0;
        virtual void setControladoraServicoAutenticacao(InterfaceServicoAutenticacao*) = 0;
        virtual ~InterfaceApresentacaoAutenticacao(){}
};


class InterfaceApresentacaoUsuario { // Resposavel por cadastrar usuario
    public:
        //virtual void executar(Email) = 0;
        virtual void cadastrar() = 0;
        //virtual bool descadastrar() = 0;
        virtual void setContrInterfaceServicoUsuario(InterfaceServicoUsuario*) = 0;
        virtual void setContrInterfaceApresentacaoImoveis(InterfaceServicoImoveis*) = 0;
        virtual ~InterfaceApresentacaoUsuario(){}
};

class InterfaceApresentacaoImoveis { // Mostra imoveis ao usuario
    public:
        //virtual void executar() = 0; // Mostrar imoveis
        //virtual void executar(Email) = 0; // Mostrar imoveis
        virtual void cadastrar(Email*) = 0;
        virtual void mostrarImoveis() = 0;
        virtual void cadastrarPropostaApresentacao() = 0;
        virtual void setContrInterfaceServicoImoveis(InterfaceServicoImoveis*) = 0;
        virtual ~InterfaceApresentacaoImoveis(){}
};



//--------------------------------------------------------------------
// Declara��es das interfaces da camada de servi�o.
class InterfaceServicoAutenticacao {
    public:
        virtual bool autenticar(Email, Senha) = 0;
        virtual ~InterfaceServicoAutenticacao(){}
};


class InterfaceServicoUsuario {
    public:
        virtual bool cadastrarUsuario(Usuario) = 0;
        //virtual bool descadrarUsuario(Usuario) = 0;
        virtual ~InterfaceServicoUsuario(){}
};

class InterfaceServicoImoveis {
    public:
        virtual void mostrarImoveisD() = 0;
        virtual bool cadastrarImovel(Imovel) = 0;
        //virtual bool descadastrarImovel(Imovel) = 0;
        //virtual bool editarDadosImovel(Imovel) = 0;
        virtual bool cadastrarProposta(Proposta) = 0;
        //virtual bool descadastrarProposta(Proposta)= 0;
        virtual ~InterfaceServicoImoveis(){}

};






















#endif // INTERFACE_H_INCLUDED
