#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "entidades.h"
#include "dominios.h"
#include <list>

using namespace std;

class ContainerUsuario {
    private:
        list<Usuario> container;
        static ContainerUsuario *instancia;
        ContainerUsuario(){};

    public:
        static ContainerUsuario* getInstancia();       // M�todo para instanciar a classe.
        bool incluir(Usuario);                         // M�todos respons�veis por presta��o de servi�o.
        //bool remover(Email);
        bool pesquisar(Email, Senha);
        //bool atualizar(Usuario);
};


class ContainerImovel {
    private:
        list<Imovel> container;
        static ContainerImovel *instancia;
        ContainerImovel(){};

    public:
        static ContainerImovel* getInstancia();
        bool incluir(Imovel);
        void mostrarImoveis();
};

/*
class ContainerProposta {

};
*/


#endif // CONTAINERS_H_INCLUDED
