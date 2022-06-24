#include "containers.h"

// --------------------------- Usu�rio ---------------------------

ContainerUsuario* ContainerUsuario::instancia = nullptr;

ContainerUsuario* ContainerUsuario::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerUsuario();
    return instancia;
}

bool ContainerUsuario::incluir(Usuario usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail() == usuario.getEmail()){
            return false;
        }
    }
    // Inclui objeto.
    container.push_back(usuario);
    return true;
}

/*
bool ContainerUsuario::remover(Email email){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail() == email.getValor()){
            // Remove objeto localizado.
            container.erase(elemento);
            return true;
        }
    }
    return false;
}
*/

bool ContainerUsuario::pesquisar(Email email, Senha senha){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getEmail() == email.getValor()){
            // Copia dados do objeto localizado.
            //usuario->setEndereco(elemento->getEndereco());
            //usuario->setCEP(elemento->getCEP());
            //usuario->setSenha(elemento->getSenha());
            if(elemento->getSenha() == senha.getValor()) {
                return true;
            }
        }
    }
    return false;
}

/*
bool ContainerUsuario::atualizar(Usuario usuario){
    for(list<Usuario>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCPF().getValor() == usuario.getCPF().getValor()){
            elemento->setEndereco(usuario.getEndereco());
            elemento->setCEP(usuario.getCEP());
            elemento->setSenha(usuario.getSenha());
            return true;
        }
    }
    return false;
}
*/


// --------------------------- Im�vel ---------------------------

ContainerImovel* ContainerImovel::instancia = nullptr;

ContainerImovel* ContainerImovel::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerImovel();
    return instancia;
}


bool ContainerImovel::incluir(Imovel imovel){
    for(list<Imovel>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo() == imovel.getCodigo()){
            return false;
        }
    }
    // Inclui objeto.
    container.push_back(imovel);
    return true;
}

void ContainerImovel::mostrarImoveis() {
    int cont = 1;

    for(list<Imovel>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        cout << "\n\n\tImovel " << cont << endl;
        cout << "\tCodigo: " << elemento->getCodigo() << endl;
        cout << "\tDescricao: " << elemento->getDescricao() << endl;
        cout << "\tEndereco: " << elemento->getEndereco() << endl;
        cout << "\tNumero maximo de hospedes: " << elemento->getHospedes() << endl;
        cout << "\tData Inicial de disponibilidade: " << elemento->getDataInicial() << endl;
        cout << "\tNumero maximo de hospedes: " << elemento->getDataFinal() << endl;
        cout << "\tValor: " << elemento->getValor() << endl;
        cout << "--------------------------------------------------\n";

        cont++;
    }
}

// --------------------------- Proposta ---------------------------








