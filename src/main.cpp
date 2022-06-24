#include <iostream>
#include <string.h>

#include "dominios.h"
#include "entidades.h"
//#include "testes.h"

#include "interface.h"
#include "controladorasapresentacao.h"
#include "controladorasservico.h"

using namespace std;

int main(void) {
    // Instancia as controladoras de apresenta��o.
    ControladoraApresentacaoControle *contrApresentacaoControle = new ControladoraApresentacaoControle();
    InterfaceApresentacaoAutenticacao *contrApresentacaoAutenticacao = new ControladoraApresentacaoAutenticacao();
    InterfaceApresentacaoUsuario *contrApresentacaoUsuario = new ControladoraApresentacaoUsuario();
    InterfaceApresentacaoImoveis *contrApresentacaoImovei = new ControladoraApresentacaoImoveis();


    // Instancia os controles do servi�o.

    InterfaceServicoAutenticacao *contServicoAutenticacao = new ControladoraServicoAutenticacao();
    InterfaceServicoUsuario *contrServicoUsuario = new ControladoraInterfaceServicoUsuario();
    InterfaceServicoImoveis *contrServicoImoveis = new ControladoraInterfaceServicoImoveis();


    // Interliga as controladoras aos servi�os.
    contrApresentacaoControle->setContrApresentacaoAutenticacao(contrApresentacaoAutenticacao);
    contrApresentacaoControle->setContrInterfaceApresentacaoUsuario(contrApresentacaoUsuario);
    contrApresentacaoControle->setContrInterfaceApresentacaoImoveis(contrApresentacaoImovei);

    contrApresentacaoAutenticacao->setControladoraServicoAutenticacao(contServicoAutenticacao);


    contrApresentacaoUsuario->setContrInterfaceServicoUsuario(contrServicoUsuario); // Interliga para fazer cadastro
    contrApresentacaoUsuario->setContrInterfaceApresentacaoImoveis(contrServicoImoveis);


    contrApresentacaoImovei->setContrInterfaceServicoImoveis(contrServicoImoveis);

    //contrApresentacaoImovei->setContrInterfaceServicoImoveis(contrServicoImoveis);


    contrApresentacaoControle->executar();

    delete(contrApresentacaoControle);
    delete(contrApresentacaoAutenticacao);
    delete(contrApresentacaoUsuario);
    delete(contrApresentacaoImovei);
    delete(contrServicoUsuario);
    delete(contrServicoImoveis);
    delete(contServicoAutenticacao);



    /*
    int teste_ent=1, teste_dom=1;
    TesteEntidades teste_entidades;
    TesteDominios teste_dominios;

    teste_ent = teste_entidades.run();

    if(teste_ent == 0)
            cout << "\n\nTestes das entidades realizados com cusseso!\n\n";

    teste_dom = teste_dominios.run();

    if(teste_dom == 0)
            cout << "\n\nTestes dos dominios realizados com cusseso!\n\n";
    */
    return 0;
}
