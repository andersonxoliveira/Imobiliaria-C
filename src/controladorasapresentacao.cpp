#include "controladorasapresentacao.h"

//using namespace std;

void ControladoraApresentacaoControle::executar(void) {
    int opcao_escolhida;
    bool apresentacao = true, aut = false;

    while(apresentacao) {
        CLR_SCR;
        cout << "\n  Servicos disponiveis: " << endl;
        cout << "\t1 - Acessar Lista de Imoveis Disponiveis." << endl;
        cout << "\t2 - Autenticar" << endl;
        cout << "\t3 - Cadastrar usuario." << endl;
        cout << "\t4 - Encerrar sessao." << endl;

        cout << "\n\tEscolha uma opcao: ";
        cin >> opcao_escolhida;


        switch(opcao_escolhida) {
            case 1:
                contrInterfaceApresentacaoImoveis->mostrarImoveis();

                break;

            case 2:

                aut = contrApresentacaoAutenticacao->autenticar(&email);
                if(aut == true) { // Usuario j� cadastrado
                    bool apresentacao_case2 = true;
                    while(apresentacao_case2) {
                        CLR_SCR;
                        cout << "\n  Selecione um dos servicos : " << endl;
                        cout << "\t1 - Descadastrar conta." << endl;
                        cout << "\t2 - Editar dados da conta." << endl;
                        cout << "\t3 - Cadastrar imovel." << endl;
                        cout << "\t4 - Descadastrar seu imovel." << endl;
                        cout << "\t5 - Editar dados do seu imovel." << endl;
                        cout << "\t6 - Cadastrar proposta de aluguel." << endl;
                        cout << "\t7 - Listar suas propostas de aluguel." << endl;
                        cout << "\t8 - Dados da(s) sua(s) proposta(s) de aluguel." << endl;
                        cout << "\t9 - Descadastrar proposta de aluguel." << endl;
                        cout << "\t10 - Propostas de aluguel associadas ao im�vel." << endl;
                        cout << "\t11 - Voltar para pagina inicial" << endl;
                        cout << "\t12 - Encerrar sessao.\n";

                        cout << "\n\tEscolha uma opcao: ";
                        cin >> opcao_escolhida;

                        switch(opcao_escolhida) {
                            case 1:
                                cout << "Descadastrar conta nao foi implementado ainda.";
                                break;

                            case 2:
                                cout << "Editar dados da conta nao foi implementado ainda.";
                                break;

                            case 3: // Cadastrar imovel
                                CLR_SCR;
                                contrInterfaceApresentacaoImoveis->cadastrar(&email);
                                break;

                            case 4:
                                cout << "\tDescadastrar seu imovel nao foi implementado ainda." << endl;
                                break;

                            case 5:
                                cout << "\tEditar dados do seu imovel nao foi implementado ainda." << endl;
                                break;

                            case 6:// Cadastrar proposta
                                CLR_SCR;
                                contrInterfaceApresentacaoImoveis->cadastrarPropostaApresentacao();
                                break;

                            case 7:
                                cout << "\tListar suas propostas de aluguel nao foi implementado ainda." << endl;
                                break;

                            case 8:
                                cout << "\tDados da(s) sua(s) proposta(s) de aluguel nao foi implementado ainda." << endl;
                                break;

                            case 9:
                                cout << "\tDescadastrar proposta de aluguel nao foi implementado ainda." << endl;
                                break;

                            case 10:
                                cout << "\tPropostas de aluguel associadas ao im�vel nao foi implementado ainda." << endl;
                                break;

                            case 11:
                                apresentacao_case2 = false;
                                break;

                            case 12:
                                CLR_SCR;
                                cout << "\n\t#####################" << endl;
                                cout << "\t###### Goodbya ######" << endl;
                                cout << "\t#####################" << endl;
                                apresentacao = false;
                                apresentacao_case2 = false;
                                break;

                            default:
                                cout << "\n\tOpcao invalida!\n\tEntre para continuar :)" << endl;
                                //system("pause");
                                getch();
                                break;
                        }
                    }
                }else {
                    cout << "\n\tUsuario nao cadastro!" << endl;
                    getch();
                }
                break;

            case 3:
                CLR_SCR;
                contrInterfaceApresentacaoUsuario->cadastrar();
                break;

            case 4:
                CLR_SCR;
                cout << "\n\t#####################" << endl;
                cout << "\t###### Goodbya ######" << endl;
                cout << "\t#####################" << endl;
                apresentacao = false;
                break;

            default:
                cout << "\n\tOpcao invalida!\n\tEntrer para continuar :)" << endl;
                //system("pause");
                getch();
                break;
        }
    }

    return;
}





bool ControladoraApresentacaoAutenticacao::autenticar(Email *email) {
    Senha senha;
    char linha1[80], linha2[80];

    while(true) {
        CLR_SCR;

        cout << "\tDigite o e-mail  : ";
        cin >> linha1;
        cout << "\tDigite a senha  : ";
        cin >> linha2;

        try {
            email->setValor(string(linha1));
            senha.setValor(string(linha2));
            break;
        }catch(invalid_argument &exp) {
            CLR_SCR;
            cout << "\n\tDado em formato incorreto. \n\tEntrer para continuar :)";
            getch();
        }
    }

    return (contrInterfaceServicoAutenticacao->autenticar(*email, senha)); // Consultar na base de dados
}

// ------------------------- ControladoraApresentacaoUsuario ---------------------------


void ControladoraApresentacaoUsuario::cadastrar() {
    string campo1, campo2, campo3, campo4;
    Usuario usuario;
    Nome nome;
    Email email;
    Senha senha;
    Telefone telefone;


    cout << "\nPreencha os seguintes campos \n";
    cout << "\tNome: ";
    //cin >> campo1;
    cin.ignore();
    getline(cin, campo1);

    cout << "\tE-mail: ";
    cin >> campo2;
    //cin.ignore();
    //getline(cin, campo2);

    cout << "\tSenha: ";
    cin >> campo3;
    //cin.ignore();
    //getline(cin, campo3);

    cout << "\tTelefone: ";
    cin >> campo4;
    //cin.ignore();
    //getline(cin, campo4);


    try{
        nome.setValor(string(campo1));
        email.setValor(string(campo2));
        senha.setValor(string(campo3));
        telefone.setValor(string(campo4));
    }
    catch(invalid_argument &exp){
        CLR_SCR;
        cout << "\n\tDado em formato incorreto. \n\tEntrer para continuar :)\n";
        getch();
        return;
    }

    usuario.setNome(nome);
    usuario.setEmail(email);
    usuario.setSenha(senha);
    usuario.setTelefone(telefone);


    if(contrInterfaceServicoUsuario->cadastrarUsuario(usuario)) {
        cout << "\n\tUsuario cadastrado com sucesso!\n\tEntrer para continuar :)\n";
        getch();
    }

}

// ------------------- ControladoraApresentacaoImoveis ---------------------------

void ControladoraApresentacaoImoveis::mostrarImoveis() {
    CLR_SCR;
    cout << "\nImoveis disponiveis: ";

    contrInterfaceServicoImoveis->mostrarImoveisD();

    cout << "\n\tEntrer para voltar a pagina inicial....";
    getch();
}


void ControladoraApresentacaoImoveis::cadastrarPropostaApresentacao() {
    string campo1, campo2;
    int campo3;
    float campo4;

    Proposta proposta;

    Numero hospedes;
    Data data_inicial;
    Data data_final;
    Moeda valor;

    cout << "\nPreencha os seguintes campos \n";
    cout << "\tData de Inicio: ";
    cin.ignore();
    getline(cin, campo1);

    cout << "\tData de Final: ";
    cin.ignore();
    getline(cin, campo2);

    cout << "\tNumero de hospedes: ";
    cin >> campo3;

    cout << "\tValor de diaria proposto: ";
    cin >> campo4;


    try {
        data_inicial.setValor(campo1);
        data_final.setValor(campo2);
        hospedes.setValor(campo3);
        valor.setValor(campo4);
    }catch(invalid_argument &exp){
        CLR_SCR;
        cout << "\n\tDado em formato incorreto. \n\tEntrer para continuar :)";
        getch();
        return;
    }

    proposta.setDataInicial(data_inicial);
    proposta.setDataFinal(data_final);
    proposta.setHospedes(hospedes);
    proposta.setValor(valor);

    if(contrInterfaceServicoImoveis->cadastrarProposta(proposta)) {
        cout << "\n\tProposta cadastrada com sucesso! \n\tEntrer para continuar";
        getch();
    }
}



void ControladoraApresentacaoImoveis::cadastrar(Email *email) {
    string campo2, campo3, campo4, campo5;
    int campo6, campo1;
    float campo7;

    Imovel imovel;

    Codigo codigo;
    Classe classe;
    Descricao descricao;
    Endereco endereco;
    Numero hospedes;
    Data data_inicial;
    Data data_final;
    Moeda valor;
    Email email_cad;

    cout << "\nPreencha os seguintes campos \n";
    cout << "\tClasse do imovel (1, 2 ou 3): ";
    cin >> campo1;

    cout << "\tDescricao do imovel: ";
    cin.ignore();
    getline(cin, campo2);

    cout << "\tEndereco do imovel: ";
    cin.ignore();
    getline(cin, campo3);

    cout << "\tNumero maximo de hospedes: ";
    cin >> campo6;

    cout << "\tData inicial de disponibilidade: ";
    cin.ignore();
    getline(cin, campo4);

    cout << "\tData final de disponibilidade: ";
    cin.ignore();
    getline(cin, campo5);

    cout << "\tValor de diaria m�nimo: ";
    cin >> campo7;

    srand(21112);
    string codigo_aleatorio = to_string(rand());
    //string codigo =

    try {
        classe.setValor(campo1);
        descricao.setValor(string(campo2));
        endereco.setValor(string(campo3));
        hospedes.setValor(campo6);
        data_inicial.setValor(string(campo4));
        data_final.setValor(string(campo5));
        valor.setValor(campo7);
        codigo.setValor(codigo_aleatorio);
        email_cad.setValor(email->getValor());
    }catch(invalid_argument &exp){
        CLR_SCR;
        cout << "\n\tDado em formato incorreto. \n\tEntrer para continuar :)";
        getch();
        return;
    }

    imovel.setClasse(classe);
    imovel.setDescricao(descricao);
    imovel.setEndereco(endereco);
    imovel.setHospedes(hospedes);
    imovel.setDataInicial(data_inicial);
    imovel.setDataFinal(data_final);
    imovel.setValor(valor);
    imovel.setCodigo(codigo);
    imovel.setEmail(email_cad);


    if(contrInterfaceServicoImoveis->cadastrarImovel(imovel)) {
        cout << "\n\tImovel Cadatrado com Sucesso!\n\tEntrer para continuar :)";
        getch();
    }
}














