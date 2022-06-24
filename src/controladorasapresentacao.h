#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#define CLR_SCR system("cls || clear");

#include <conio.h>
#include <iostream>
#include <string.h>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

#include "interface.h"
#include "dominios.h"
#include "entidades.h"

using namespace std;



//------------- Classe controladora de apresenta��o controle -------------
class ControladoraApresentacaoControle {
    private:
        Email email;
        // Ponteiros Necessarios para Interface
        InterfaceApresentacaoAutenticacao *contrApresentacaoAutenticacao;
        InterfaceApresentacaoUsuario *contrInterfaceApresentacaoUsuario;
        InterfaceApresentacaoImoveis *contrInterfaceApresentacaoImoveis;

    public:
        void executar();
        // M�todos set para atribuir valores ao ponteiros declarados
        void setContrApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao*);
        void setContrInterfaceApresentacaoUsuario(InterfaceApresentacaoUsuario*);
        void setContrInterfaceApresentacaoImoveis(InterfaceApresentacaoImoveis*);
};

inline void ControladoraApresentacaoControle::setContrApresentacaoAutenticacao(InterfaceApresentacaoAutenticacao* cntr) {
    contrApresentacaoAutenticacao = cntr;
}
inline void ControladoraApresentacaoControle::setContrInterfaceApresentacaoUsuario(InterfaceApresentacaoUsuario* cntr) {
    contrInterfaceApresentacaoUsuario = cntr;
}
inline void ControladoraApresentacaoControle::setContrInterfaceApresentacaoImoveis(InterfaceApresentacaoImoveis* cntr) {
    contrInterfaceApresentacaoImoveis = cntr;
}


//------------- Classe controladora de apresenta��o autentica��o -------------
                                           // Herda a classe abstrata
class ControladoraApresentacaoAutenticacao:public InterfaceApresentacaoAutenticacao {
    private:
        // Ponteiros para Interface
        InterfaceServicoAutenticacao *contrInterfaceServicoAutenticacao;

    public:
        bool autenticar(Email*);
        void setControladoraServicoAutenticacao(InterfaceServicoAutenticacao*);
};

inline void ControladoraApresentacaoAutenticacao::setControladoraServicoAutenticacao(InterfaceServicoAutenticacao* cntr) {
    contrInterfaceServicoAutenticacao = cntr;
}



//------------- Classe controladora de apresenta��o usu�rio -------------
                                               // Herda a classe abstrata
class ControladoraApresentacaoUsuario:public InterfaceApresentacaoUsuario {
    private:
        InterfaceServicoUsuario *contrInterfaceServicoUsuario;
        InterfaceServicoImoveis *contrInterfaceApresentacaoImoveis;

    public:
        void cadastrar();
        //bool descadastrar(Email);
        void setContrInterfaceServicoUsuario(InterfaceServicoUsuario*);
        void setContrInterfaceApresentacaoImoveis(InterfaceServicoImoveis*);
};

inline void ControladoraApresentacaoUsuario::setContrInterfaceServicoUsuario(InterfaceServicoUsuario *cntr) {
    contrInterfaceServicoUsuario = cntr;
}

inline void ControladoraApresentacaoUsuario::setContrInterfaceApresentacaoImoveis(InterfaceServicoImoveis *cntr) {
    contrInterfaceApresentacaoImoveis = cntr;
}




// ------------- Classe controladora de apresenta��o produtos financeiros -------------
                                                // Herda a classe abstrata
class ControladoraApresentacaoImoveis:public InterfaceApresentacaoImoveis {
    private:
        InterfaceServicoImoveis *contrInterfaceServicoImoveis;
    public:
        void cadastrar(Email*);
        void mostrarImoveis();
        void cadastrarPropostaApresentacao();
        //void cadastrarProposta();
        void setContrInterfaceServicoImoveis(InterfaceServicoImoveis*);
};

inline void ControladoraApresentacaoImoveis::setContrInterfaceServicoImoveis(InterfaceServicoImoveis* cntr) {
    contrInterfaceServicoImoveis = cntr;
}


#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
