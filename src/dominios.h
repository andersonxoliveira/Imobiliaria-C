#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

//! Classe que codifica dominio Codigo.

//! Cada im�vel tem c�digo pr�prio no momento de registro. Sendo assim, c�digo tem o //!intuito de diferenciar e identificar todos os im�veis cadastrados no sistema.
//!
//! Cada proposta de aluguel tamb�m tem c�digo pr�prio no momento de registro. Sendo assim //! c�digo de proposta tem mesmo intuito que c�digo de aluguel.
//! Codigo consiste em cadeia de caracteres no formato : XXXXX .
//! X � letra maiuscula (A-Z) ou digito (0 � 9).
//! Codigo nao � 00000.
//! Caso c�digo inserido seja inv�lido mensagem de erro ser� mostrada e o im�vel n�o ser� //! cadastrado
//!
//! M�todo setValor recebe uma string e � empregado para alterar codigo presente.
//! M�todo getValor retorna a string armazenada em codigo.


class Codigo {
	private:
		string codigo;
		bool validarValor(string);
	public:
		//Codigo();
		//static string CODIGO_INVALIDO = "00000";
		void setValor(string);
		string getValor() const {
            return codigo;
		}
};

//! Classe que codifica dominio Classe.

//! Valor op��o presente na classe indica tipo de im�vel.
//! Op��o tem o valor 1 caso o im�vel seja um apartamento, 2 caso seja casa e 3 caso seja //! um quarto.
//! Caso op��o invalida seja inserida, registro do im�vel no sistema n�o ser� efetuado e //! mensagem de erro ocorrer�.
//! M�todo setValor recebe um inteiro e � empregado para alterar op��o presente.
//! M�todo getValor retorna o inteiro armazenada em op��o.


class Classe {
    private:
        int opcao;
        bool validarValor(int);
    public:
        void setValor(int);
        int getValor(void) const {
            return opcao;
        }
};


//! Classe que codifica dom�nio Descri��o

//! Descri��o tem como objetivo informar de maneira concisa as caracter�sticas mais       //! importantes a respeito do im�vel que est� sendo alugado.
//!
//! A descri��o deve conter entre 5 a 30 caracteres e deve ser terminada com ponto final.
//! Descri��o � uma cadeia de caracteres.
//! Existe m�todo privado que verifica validade da descri��o inserida.
//! M�todo setValor recebe uma string e � empregado para alterar a descri�ao presente.
//! M�todo getValor retorna a string armazenada em descri��o.


class Descricao {
    private:
        string descricao;
        bool validarValor(string);
    public:
        void setValor(string);
        string getValor(void) const {
            return descricao;
        }
};


//! Classe que codifica dom�nio Endere�o.

//! O endere�o do im�vel � informa��o essencial para quem deseja contratar o aluguel.
//! Endere�o � uma cadeia de caracteres que cont�m entre 5 e 20 caracteres.
//! Existe m�todo privado para validar o endere�o inserido no momento do registro.
//! M�todo setValor recebe uma string e � empregado para inicializar ou alterar endere�o
//! presente.
//! M�todo getValor retorna a string armazenada em Endere�o.


class Endereco {
    private:
        string endereco;
        bool validarValor(string);
    public:
        void setValor(string);
        string getValor(void) const {
            return endereco;
        }
};


//! Classe que codifica dom�nio Data.

//! Data � informa��o relevante
//! Data deve estar no formato  DD-MM-AA.
//! DD deve estar entre 01 e 31.
//! MM deve estar entre 01 e 12.
//! AA deve estar entre 21 e 99.
//! Data considera anos bissextos.
//! H� m�todo privado para verificar se data inserida corresponde aos requisitos.
//! M�todo setValor recebe uma string e � empregado para inicializar ou alterar data
//! presente.
//! M�todo getValor retorna a string armazenada em Data.


class Data {
    private:
        string data;
        bool validarValor(string);
    public:
        void setValor(string);
        string getValor(void) const {
            return data;
        }
};

//! Classe que codifica dom�nio N�mero

//! N�mero � informa��o relevante para saber quantos h�spedes cada im�vel pode receber
//! e quantos h�spedes se hospedar�o em cada proposta de aluguel.
//! N�mero deve estar entre 0 e 20.
//! H� m�todo privado para verificar validade de n�mero.
//! M�todo setValor recebe um inteiro e � empregado para inicializar ou alterar numero
//! presente.
//! M�todo getValor retorna o inteiro armazenada em Numero.

class Numero {
    private:
        int numero;
        bool validarValor(int);
    public:
        const static int VALOR_MAXIMO = 20;
        const static int VALOR_MINIMO = 0;

        void setValor(int);
        int getValor(void) const {
            return numero;
        }
};

//! Classe que codifica dom�nio Moeda

//! Moeda � vari�vel relevante para saber o m�nimo de aluguel aceito por im�vel e
//! quanto cada proposta oferece de pagamento.
//!
//! Moeda � um valor de ponto flutuante entre 0,00 e 1.000.000,00.
//! H� m�todo que valida o valor inserido.
//! M�todo setValor recebe um float e � empregado para inicializar ou alterar valor
//! presente.
//! M�todo getValor retorna um numero em ponto flutuante armazenado em Moeda.

class Moeda {
    private:
        float moeda;
        bool validarValor(float);
    public:
        const static int VALOR_MINIMO = 0.0;
        const static int VALOR_MAXIMO = 1000000.0;

        void setValor(float);
        float getValor(void) const {
            return moeda;
        }
};


//! Classe que codifica dom�nio Nome.

//! Dom�nio Nome serve para identificar todos os usu�rios cadastrados no sistema no momento //! de registro de contas autenticadas.
//! Nome � uma string que deve conter entre 5 e 25 caracteres.
//! Cada caracter � letra (A-Z ou a-z), ponto ou espa�o.
//! Ponto � deve ser precedido por letra.
//! N�o deve haver esspa�os em sequ�ncia.
//! Primeira letra de cada termo � Mai�scula.
//!  H� m�todo que valida o nome inserido.
//! M�todo setValor recebe uma string e � empregado para inicializar ou alterar nome
//! presente.
//! M�todo getValor retorna a cadeia de caracteres armazenada em Nome.


class Nome {
    private:
        string nome;
        bool validarValor(string);
    public:
        const static int TAMANHO_MAXIMO = 25;
        const static int TAMANHO_MINIMO = 5;

        void setValor(string);
        string getValor(void) const {
            return nome;
        }
};



//! Classe que codifica dom�nio Email.

//! Email � informa��o essencial no momento de autentica��o e cadastro de Usu�rio.
//! Email � string no formato : nome@dom�nio .
//! nome deve ter no m�ximo 10 caracteres.
//! dom�nio deve ter no m�ximo 20 caracteres.
//! Cada caracter � letra (A-Z ou a-z), d�gito  (0 � 9) ou ponto "." .
//! N�o deve haver "." (ponto) em sequ�ncia.
//! H� m�todo que valida o nome e o dom�nio inserido.
//! M�todo setValor recebe uma string e � empregado para inicializar ou alterar Email
//! presente.
//! M�todo getValor retorna a string armazenada em Email.



class Email{
  private:
    string email;

    bool validarValor(string);

  public:
    const static int TAMANHO_MAXIMO_NOME = 10;
    const static int TAMANHO_MAXIMO_domino = 20;

    void setValor(string);
    string getValor(void) const {
      return email;
    }
};


//! Classe que codifica dom�nio Senha.

//! Senha � essencial na autentica��o de usu�rios do sistema junto com o E-mail.
//! Senha � criada no momento do registro de usu�rio.
//! Senha tem o formato XXXXXX onde cada X � letra (A-Z ou a-z) ou d�gito (0 � 9).
//! N�o deve existir caracter repetido
//! Deve existir  na senha pelo menos uma letra mai�scula, uma letra min�scula e um d�gito.
//! H� m�todo que verifica se a senha inserida � valida.
//! M�todo setValor recebe uma string e � empregado para inicializar ou alterar senha
//! presente.
//! M�todo getValor retorna a string armazenada em senha.


class Senha {
    private:
        string senha;

        bool validarValor(string);

    public:
        const static int TAMANHO_SENHA = 6;

        void setValor(string);
        string getValor(void) const {
            return senha;
        }
};


//! Classe que codifica dom�nio Telefone.

//! Telefone � inform��o relevante para contato entre as partes do contrato de aluguel.
//! string telefone deve estar no Formato : (XXX)-XXXXXXXXX onde cada X � d�gito (0 � 9).
//! telefone (000)-000000000 � considerado telefone inv�lido.
//! H� m�todo que valida o telefone inserido.
//! M�todo setValor recebe uma string e � empregado para inicializar ou alterar telefone
//! presente.
//! M�todo getValor retorna a string armazenada em Telefone.


class Telefone {
    private:
        string telefone;

        bool validarValor(string);

    public:
        //const static string DDD_INVALIDO = "000";
        //const static string NUMERO_INVALIDO = "000000000";

        void setValor(string);
        string getValor(void) const {
            return telefone;
        }

};

#endif // DOMINIOS_H_INCLUDED
