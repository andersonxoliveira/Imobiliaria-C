#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interface.h"
#include "containers.h"

//------------- Implementar as controladoras de servi�o -------------


//------------- Classe controladora de servi�o autentica��o -------------
// N�o depedem de servi�os, elas realizam servi�o
class ControladoraServicoAutenticacao:public InterfaceServicoAutenticacao {
    public:
        bool autenticar(Email, Senha);
};


//------------- Classe controladora de servi�o autentica��o -------------
class ControladoraInterfaceServicoUsuario:public InterfaceServicoUsuario {
    public:
        bool cadastrarUsuario(Usuario);
};


//------------- Classe controladora de servi�o autentica��o -------------
class ControladoraInterfaceServicoImoveis:public InterfaceServicoImoveis {
    public:
        void mostrarImoveisD();
        bool cadastrarImovel(Imovel);
        bool cadastrarProposta(Proposta);
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
