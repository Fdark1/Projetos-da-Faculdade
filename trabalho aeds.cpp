/*
Alunos:

Felipe de Melo Lemos
Patrick Alves Ferreira
Fernanda Dark Moreira
Augusto Tobias de Paula Reis

*/


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

//Declaração de variáveis constantes.

const int MAX_STUDENTS = 999;
const int MAX_EVENTS = 999;
const int MAX_INSCRIPTIONS = 999;

// Criação das Structures

struct Student {
    string cpf;
    string name;
    string curso;
    string periodo;
    string cel;
    string email;
};

struct Event {
	double cod;
	string nome;
	string tipo;
	string data;
	string hora;
	string local;
	int nvagas;
	string palestrante;
};

struct Inscription {
	string cpf;
	string data;
};

//Declaração das variáveis comuns das funções.

int num_students = 0;
int num_events = 0;
int num_inscription = 0;

Student students[MAX_STUDENTS];
Event events[MAX_EVENTS];
Inscription inscriptions[MAX_INSCRIPTIONS];

// Função Cadastro de Alunos

void add_student() {

    system("cls");

	if (num_students == MAX_STUDENTS) {
        cout << "Não é possível adicionar mais alunos, pois o limite máximo foi atingido." << endl;
        system("pause");
        return;
    }


    for(int i =0; i<8; i++)
	{

		if (i==0)
		{
		cout<< "+=====================================+"<<endl;
		}
		else
		{
		cout<< "|                                     |"<<endl;
		cout<< "+-------------------------------------+"<<endl;
		}


	}



	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,3});
    cin.ignore();
	cout << "|CPF:     |\n"<<endl;
    cout << "|Nome:    |\n"<<endl;
    cout << "|Curso:   |\n"<<endl;
    cout << "|Período: |\n"<<endl;
    cout << "|Celular: |\n"<<endl;
    cout << "|E-mail:  |\n";
    cout << "+-------------------------------------+"<<endl;

   	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,1});
	cout << "|\tInserindo novo aluno..." << endl;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){12,3});
    getline(cin,students[num_students].cpf);

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){12,5});
    getline(cin,students[num_students].name);

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){12,7});
    getline(cin,students[num_students].curso);

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){12,9});
    getline(cin,students[num_students].periodo);

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){12,11});
    getline(cin,students[num_students].cel);

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){12,13});
    getline(cin,students[num_students].email);;

	cout<<endl;
    num_students++;
 	system ("cls");
 	cout<< "Aluno cadastrado com sucesso!"<<endl<<endl;
 	cout<< "Retornando ao menu principal..."<<endl;
 	system("pause");
 	system ("cls");
}

// Função Atualizar Dados de Aluno

void update_student() {


	system ("cls");
	string cpf;
    cout << "Digite o CPF do aluno que deseja atualizar: "<<endl;
    cin >> cpf;
	cin.ignore();


    for (int i = 0; i < num_students; i++) {

        if (students[i].cpf == cpf) {
            system ("cls");

   		 for(int i =0; i<8; i++)
		   	{

			   	if (i==0)
			   	{
		   	cout<< "+=====================================+"<<endl;
		   	}
			   	else
			   	{
		   	cout<< "|                                     |"<<endl;
		   	cout<< "+-------------------------------------+"<<endl;
		   	}

	   	   	}

	   	   	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,2});
            cout<<endl;

            cout << "|Novo CPF:     |\n"<<endl;
            cout << "|Novo nome:    |\n"<<endl;
            cout << "|Novo Curso:   |\n"<<endl;
            cout << "|Novo Período: |\n"<<endl;
            cout << "|Novo Celular: |\n"<<endl;
            cout << "|Novo E-mail:  |\n"<<endl;

   	   		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,1});
			cout << "|\tAtualizando aluno..." << endl;

	   	   	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){17,3});
  	    	getline(cin, students[i].cpf);

        	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){17,5});
  	    	getline(cin, students[i].name);

  	    	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){17,7});
   	    	getline(cin, students[i].curso);

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){17,9});
			getline(cin,students[i].periodo);

   	    	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){17,11});
   	    	getline(cin,students[i].cel);

    		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){17,13});
    		getline(cin,students[i].email);;

			system ("cls");
            cout << "Aluno atualizado com sucesso!" << endl;
            cout << "Retornando ao menu principal..."<<endl;
            system ("pause");
   			system ("cls");
            return;
        }
        else
		{
  	    if (num_students==0)
		   	{
			  		system ("cls");
			  		cout<<endl;
			  		cout<<"\t NENHUM ALUNO CADASTRADO"<<endl;
			  		cout<< "Retornando ao menu principal..."<<endl;
			  		system ("pause");
			  		system ("cls");
		}
		else
		{
				system("cls");
		       	cout << "Não foi possível encontrar o aluno com o CPF fornecido." << endl;
		       	cout<< "Retornando ao menu principal..."<<endl;
		       	system ("pause");
		       	system ("cls");
	  			}
		}
    }


}

// Função Excluir Aluno

void delete_student() {

	string cpf;
    system ("cls");
    cout<<endl;
	cout << "Digite o CPF do aluno que deseja excluir: ";
    cin >> cpf;

    for (int i = 0; i < num_students; i++) {
        if (students[i].cpf == cpf) {
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            system ("cls");
			cout<<endl;
			cout << "Aluno de CPF: "<<cpf<<" excluído com sucesso!" << endl;
			cout<< "Retornando ao menu principal..."<<endl;
			system ("pause");
			system ("cls");
            return;
        }
    }

   if (num_students==0)
	{
		system ("cls");
		cout<<endl;
		cout<<"\t NENHUM ALUNO CADASTRADO"<<endl;
		cout<< "Retornando ao menu principal..."<<endl;
		system ("pause");
		system ("cls");
	}
	else
	{
		system("cls");
    	cout << "Não foi possível encontrar o aluno com o CPF fornecido." << endl;
    	cout<< "Retornando ao menu principal..."<<endl;
    	system ("pause");
    	system ("cls");
	  }





}

// Função Listar Alunos

void list_students() {

	system("cls");
	if (num_students==0)
	{
		system ("cls");
		cout<<endl;
		cout<<"NENHUM ALUNO CADASTRADO"<<endl;
		cout<< "Retornando ao menu principal..."<<endl;
		system ("pause");
		system ("cls");

	}
	system ("cls");
	cout << "\tListagem de alunos..." << endl;
	cout<<endl;

    for (int i = 0; i < num_students; i++) {

    	cout << "+==============================+"<<endl;
        cout << "|ALUNO " << i + 1 <<endl;
        cout << "+---------+--------------------+"<<endl;
        cout << "|CPF:     |" << students[i].cpf << endl;
  		cout << "+---------+--------------------+"<<endl;
        cout << "|Nome:    |" << students[i].name << endl;
        cout << "+---------+--------------------+"<<endl;
        cout << "|Curso:   |" << students[i].curso << endl;
        cout << "+---------+--------------------+"<<endl;
        cout << "|Período: |" << students[i].periodo << endl;
        cout << "+---------+--------------------+"<<endl;
        cout << "|Celular: |" << students[i].cel << endl;
        cout << "+---------+--------------------+"<<endl;
        cout << "|E-mail:  |" << students[i].email << endl;
        cout << "+==============================+\n\n"<<endl;
        cout<<endl;
    }
    system("pause");
    system("cls");
}

// Função Salvar dados de Alunos em Arquivo

void save_to_file () {

	ofstream file("alunos.txt");
	if (!file.is_open()) {

		system ("cls");
		cout << "Não foi possível abrir o arquivo para escrita." << endl;
		cout<< "Retornando ao menu principal..."<<endl;
		system ("Pause");
		system ("cls");
		return;
}

	file << num_students << endl;
	for (int i = 0; i < num_students; i++) {
	    file << students[i].cpf << endl;
	    file << students[i].name << endl;
	    file << students[i].curso << endl;
	    file << students[i].periodo << endl;
	    file << students[i].cel << endl;
	    file << students[i].email << endl;
	    file<<endl;
	}

	file.close();
	system ("cls");
	cout<<endl;
	cout << "Dados dos alunos salvos com sucesso no arquivo alunos.txt." << endl;
	cout << "Retornando ao menu principal..."<<endl;
	cout<<endl;
	system ("pause");
	system ("cls");
}

// Função Carregar Dados de Aluno de Arquivo

void load_from_file() {

	ifstream file("alunos.txt");
	if (!file.is_open()) {
	system ("cls");
	cout << "Não foi possível abrir o arquivo para escrita." << endl;
	cout << "Retornando ao menu principal..."<<endl;
	cout<<endl;
	system ("pause");
	system ("cls");
	return;
}

file >> num_students;
	for (int i = 0; i < num_students; i++) {
    	file >> students[i].cpf;
	    file >> students[i].name;
	    file >> students[i].curso;
	    file >> students[i].periodo;
	    file >> students[i].cel;
	    file >> students[i].email;

}

	file.close();
	cout<<endl;
	system ("cls");
	cout << "Dados dos alunos carregados com sucesso do arquivo alunos.txt." << endl;
	cout << "Retornando ao menu principal..."<<endl;
	cout<<endl;
	system ("pause");
	system ("cls");
	cout<<endl;
}

// Função Adicionar Eventos e Inscrições

void add_event() {

	int op, contin;

    if (num_events == MAX_EVENTS) {
        system ("cls");
		cout << "Não é possível adicionar mais eventos, pois o limite máximo foi atingido." << endl;
	   	cout << "Retornando ao menu principal..."<<endl;
	   	cout<<endl;
	   	system ("pause");
	   	system ("cls");
        return;
    }
    system ("cls");

  		 for(int i =0; i<10; i++)
	   	{

		   	if (i==0)
		   	{
	   	   	   	cout<< "+=====================================+"<<endl;
	   		}
		   	else
		   	{
  	   		cout<< "|                                     |"<<endl;
  	   		cout<< "+-------------------------------------+"<<endl;
	   		}
		}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){0,0});
	cout<<endl;
	cin.ignore();


	cout << "|\tInserindo novo evento..." << endl;
	cout<<endl;
    cout << "|Código:          |\n"<<endl;
	cout << "|Nome do Evento:  |\n"<<endl;
    cout << "|Tipo do Evento:  |\n"<<endl;
    cout << "|Data (DD/MM/AA): |\n"<<endl;
    cout << "|Horário (HH:MM): |\n"<<endl;
    cout << "|Local:           |\n"<<endl;
    cout << "|Número de Vagas: |\n"<<endl;
    cout << "|Palestrante:     |\n"<<endl;


	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){19,3});
	cin>>events[num_events].cod;
	cin.ignore();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){19,5});
    getline(cin,events[num_events].nome);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){19,7});
    getline(cin,events[num_events].tipo);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){19,9});
    getline(cin,events[num_events].data);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){19,11});
	getline(cin,events[num_events].hora);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){19,13});
	getline(cin,events[num_events].local);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){19,15});
	cin>>events[num_events].nvagas;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){19,17});
	cin.ignore();
	getline(cin,events[num_events].palestrante);

	system ("cls");
	cout<< "Evento cadastrado com sucesso..."<<endl;
	system("pause");
	system("cls");

    cout<< "Deseja realizar inscrição neste evento? 1= Sim /0- Não"<<endl;
    cin>> op;
    system ("cls");

    if (op==1) {
    int j = events[num_events].nvagas;
    int i = 1;
    while (i <= j) {
        cout << endl;
        cout << "Inserindo novo inscrito..." << endl;
        cout << endl;
        cout << "CPF do Aluno: ";
        cin >> inscriptions[i].cpf;
        cout << "Data da Inscrição(DD/MM/AA): ";
        cin >> inscriptions[i].data;

        cout<<endl;
		cout<< "Deseja continuar o cadastro? 1= Sim /0- Não "<<endl;
        cin >> contin;
        if (contin == 0) {
            break;
        }

        i++;
    }
       if (contin == 1 && i>j)
		{
			system ("cls");
			cout<<endl;
			cout<<"EVENTO COM VAGAS ESGOTADAS!"<<endl;
	   		cout << "Retornando ao menu principal..."<<endl;
	   		cout<<endl;
	   		system ("pause");
	   		system ("cls");
			cout<<endl;
		}
}

num_events++;

    system ("cls");
}

// Função Listar Eventos

void list_events() {

	if (num_events==0)
	{
		system ("cls");
		cout<<endl;
		cout<<"NENHUM EVENTO CADASTRADO"<<endl;
		cout<< "Retornando ao menu principal..."<<endl;
		system ("pause");
		system ("cls");

	}

	system ("cls");
	cout << "\tListagem de EVENTOS..." << endl;
	cout<<endl;

    	for (int i = 0; i < num_events; i++) {

    	cout << "+==============================+"<<endl;
        cout << "|EVENTO " << i + 1 <<endl;
        cout << "+---------+--------------------+"<<endl;
        cout << "|CODIGO:     |" << events[i].cod << endl;
  		cout << "+---------+--------------------+"<<endl;
        cout << "|Nome:       |" << events[i].nome << endl;
        cout << "+---------+--------------------+"<<endl;
        cout << "|TIPO:       |" << events[i].tipo << endl;
        cout << "+---------+--------------------+"<<endl;
        cout << "|DATA:       |" << events[i].data << endl;
        cout << "+---------+--------------------+"<<endl;
        cout << "|HORÁRIO:    |" << events[i].hora << endl;
        cout << "+---------+--------------------+"<<endl;
        cout << "|LOCAL:      |" << events[i].local << endl;
		cout << "+---------+--------------------+"<<endl;
        cout << "|VAGAS:      |" << events[i].nvagas << endl;
        cout << "+---------+--------------------+"<<endl;
        cout << "|PALESTRANTE:|" << events[i].palestrante << endl;
        cout << "+==============================+\n\n"<<endl;
        cout<<endl;


		}
         system ("pause");
		 system ("cls");
}

//Função Salvar Dados de Eventos em Arquivo

void save_events_to_file () {

ofstream file("events.txt");
if (!file.is_open()) {
system("cls");
cout << "Não foi possível abrir o arquivo para escrita." << endl;
cout << "Retornando ao menu principal..."<<endl;
cout<<endl;
system ("pause");
system ("cls");
return;
}

file << num_events << endl;
for (int i = 0; i < num_events; i++) {
    file << events[i].cod << endl;
	file << events[i].nome << endl;
    file << events[i].tipo << endl;
    file << events[i].data << endl;
    file << events[i].hora << endl;
    file << events[i].local << endl;
    file << events[i].nvagas << endl;
    file << events[i].palestrante << endl<<endl<<endl;

}

file.close();
system ("cls");
cout<<endl;
cout << "Dados dos eventos salvos com sucesso no arquivo events.txt." << endl;
cout<<endl;
cout << "Retornando ao menu principal..."<<endl;
cout<<endl;
system ("pause");
system ("cls");

}

//Função carregar dados de Eventos de Arquivo

void load_events_from_file() {

ifstream file("events.txt");
if (!file.is_open()) {
	system ("cls");
	cout << "Não foi possível abrir o arquivo para leitura." << endl;
	cout << "Retornando ao menu principal..."<<endl;
	cout<<endl;
	system ("pause");
	system ("cls");
	return;
}

file >> num_events;
for (int i = 0; i < num_events; i++) {
    file >> events[i].cod;
	file >> events[i].nome;
    file >> events[i].tipo;
    file >> events[i].data;
    file >> events[i].hora;
    file >> events[i].local;
    file >> events[i].nvagas;
    file >> events[i].palestrante;
}

file.close();
cout<<endl;
system ("cls");
cout << "Dados dos eventos carregados com sucesso do arquivo events.txt." << endl;
cout << "Retornando ao menu principal..."<<endl;
cout<<endl;
system ("pause");
system ("cls");
cout<<endl;
}

// Programa Principal

int main() {

setlocale (LC_ALL,"portuguese");


system ("cls");
int opcao;
do {
    cout << "+===================================================================================+"<< endl;
    cout << "|                          PROGRAMA SEMANA DA INFORMÁTICA                           |"<<endl;
    cout << "+===================================================================================+"<< endl;
	cout << "|                                       MENU                                        |" << endl;
    cout << "+===================================================================================+"<< endl;
	cout << "|                 ALUNOS                 ||                  EVENTO                 |"<<endl;
    cout << "+========================================++=========================================+"<< endl;
    cout << "|1. Adicionar Aluno                      ||7.  Cadastrar Evento / Nova Inscrição    |" << endl;
    cout << "|2. Atualizar Aluno                      ||8.  Listar Eventos                       |" << endl;
    cout << "|3. Excluir Aluno                        ||9.  Salvar dados dos Eventos em arquivo  |" << endl;
    cout << "|4. Listar Alunos                        ||10. Carregar dados dos Eventos de arquivo|" << endl;
    cout << "|5. Salvar dados dos Alunos em arquivo   ||0.  Encerrar programa                    |" << endl;
    cout << "|6. Carregar dados dos Alunos de arquivo ||                                         |" << endl;
    cout << "+========================================++=========================================+"<< endl;
    cout<<endl;
    cout << "Opção: ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            add_student();
            break;
        case 2:
            update_student();
            break;
        case 3:
            delete_student();
            break;
        case 4:
            list_students();
            break;
        case 5:
            save_to_file();
            break;
        case 6:
            load_from_file();
            break;
        case 7:
            add_event();
            break;
        case 8:
            list_events();
            break;
        case 9:
            save_events_to_file();
            break;
        case 10:
            load_events_from_file();
            break;
        case 0:
            break;
        default:
        	system ("cls");
            cout << "\t Opção inválida, escolha uma opção válida." << endl;
	   		cout << "Retornando ao menu principal..."<<endl;
	   		cout<<endl;
	   		system ("pause");
	   		system ("cls");
            break;
    }
} while (opcao != 0);


return 0;
}
