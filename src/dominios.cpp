#include <string>
#include <stdexcept>
#include <ctype.h>

#include "dominios.h"

using namespace std;


// Defini��es de Codigo
bool Codigo::validarValor(string cod){
    if(cod == "00000"){
        throw invalid_argument("Erro parametro da classe Codigo.");
        return false;
    }else {
        return true;
    }
}

void Codigo::setValor(string cod) {
	validarValor(cod);
	this->codigo = cod;
}


// Defini��es de Classe
bool Classe::validarValor(int opc) {
    if(opc != 1 && opc != 2 && opc != 3) {
        throw invalid_argument("Erro parametro da classe Classe.");
    }else{
        return true;
    }
}

void Classe::setValor(int opc) {
    validarValor(opc);
    this->opcao = opc;
}


// Defini��es de Descricao
bool Descricao::validarValor(string desc) {
    int tamanho = desc.length();

    if((tamanho < 5 || tamanho > 30) && desc[tamanho-1] == '.') {
        throw invalid_argument("Erro parametro do classe Descricao.");
    }else {
        return true;
    }
}

void Descricao::setValor(string desc) {
    validarValor(desc);
    this->descricao = desc;
}



// Defini��es de Endere�o
bool Endereco::validarValor(string ender) {
    int tamanho = ender.length();

    if(tamanho < 5 || tamanho > 20) {
        throw invalid_argument("Erro parametro da classe Endereco.");
    }else {
        return true;
    }
}
void Endereco::setValor(string ender) {
    this->endereco = ender;
}



// Defini��es de Data
bool Data::validarValor(string dat) {
    // FAZER
    return true;
}

void Data::setValor(string dat) {
    validarValor(dat);
    this->data = dat;
}




// Defini��es de Numero
bool Numero::validarValor(int num) {
    if(num < VALOR_MINIMO || num > VALOR_MAXIMO) {
        throw invalid_argument("Erro parametro da classe Numero");
    }else {
        return true;
    }
}

void Numero::setValor(int num) {
    validarValor(num);
    this->numero = num;
}



// Defini��es de Moeda
bool Moeda::validarValor(float moed) {
    if(moed < VALOR_MINIMO || moed > VALOR_MAXIMO) {
        throw invalid_argument("Erro parametro da classe Moeda");
    }else {
        return true;
    }
}

void Moeda::setValor(float moed) {
    validarValor(moed);
    this->moeda = moed;
}



// Defini��es de Nome
bool Nome::validarValor(string nom) { // Terminar
    int tamanho = nom.length();

    if(tamanho < 5 || tamanho > 25) {
        throw invalid_argument("Erro parametro da classe Nome.");
    }else {
        return true;
    }
}

void Nome::setValor(string nom) {
    validarValor(nom);
    this->nome = nom;
}


// Defini��es de Email
bool Email::validarValor(string ema) {
    int tamanho = ema.length(), i;
    int nome = 0, flag = 0;

    for(i = 0; i < tamanho; i++) {
        if(ema[i] != '@')
            nome++;

        if(ema[i] == '@')
            break;
    }

    if(nome > 10 || ((tamanho-nome)-1) > 20) {
        throw invalid_argument("Erro parametro da classe Email");
        return false;
    }

    return true;
}

void Email::setValor(string ema) {
    validarValor(ema);
    this->email = ema;
}


// Defini��es de Senha
bool Senha::validarValor(string sen) {
    int tamanho = sen.length();

    if(tamanho < 6){ // Verifica o tamanho da senha
        throw invalid_argument("Erro parametro da classe Senha");
        return false;
    }

    int sen_vet[tamanho], i, j;
    int maiuscula=0, flag_digito=0, flag_minuscula=0;

    for(i = 0; i < tamanho; i++) {
        for(j = 0; j < tamanho; j++) {
            if(sen[j] == sen[i] && j != i){ // Nesse caso ah caracteres repetidos
                throw invalid_argument("Erro parametro da classe Senha");
                return false;
            }
        }

        if(isupper(sen[i])) { // Conta a quantidade de letra maiuscula
            maiuscula++;
        }

        else if(isdigit(sen[i])) flag_digito = 1;

        else if(islower(sen[i])) flag_minuscula = 1;

        else if(!(isalnum(sen[i]))) { // Verifica se nao e letra ou numeo
            throw invalid_argument("Erro parametro da classe Senha");
            return false;
        }
    }

    if((maiuscula > 0 && maiuscula <= (tamanho-2)) ||
       flag_digito == 0 || flag_minuscula == 0) {
        throw invalid_argument("Erro parametro da classe Senha");
        return false;
    }


    return true;
}

void Senha::setValor(string sen) {
    validarValor(sen);
    this->senha = sen;
}


// Defini��es de Telefone
bool Telefone::validarValor(string tel) {
    if(tel == "(000)-000000000" || tel.length() < 15) {
        throw invalid_argument("Erro parametro da classe Telefone");
        return false;
    }else {
        return true;
    }
}

void Telefone::setValor(string tel) {
    validarValor(tel);
    this->telefone = tel;
}


