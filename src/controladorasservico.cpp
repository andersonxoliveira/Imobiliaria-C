#include <conio.h>
#include "controladorasservico.h"
#include "dominios.h"

//----------------- Autenticar -----------------
bool ControladoraServicoAutenticacao::autenticar(Email email, Senha senha) { // Consulta a base de dados para autenticar
    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    return container->pesquisar(email, senha);
}


//----------------- Usu�rio -----------------
bool ControladoraInterfaceServicoUsuario::cadastrarUsuario(Usuario usuario) { // Armazena os dados em servidor ou lista
    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    return container->incluir(usuario); // Retorna um bool
}



//----------------- Imovel -----------------
void ControladoraInterfaceServicoImoveis::mostrarImoveisD() {
    ContainerImovel *container;

    container = ContainerImovel::getInstancia();

    container->mostrarImoveis();
}

bool ControladoraInterfaceServicoImoveis::cadastrarImovel(Imovel imovel) { // Armazena os dados em servidor ou lista
    ContainerImovel *container;

    container = ContainerImovel::getInstancia();

    return container->incluir(imovel);
}

bool ControladoraInterfaceServicoImoveis::cadastrarProposta(Proposta proposta) {
    return true;
}
