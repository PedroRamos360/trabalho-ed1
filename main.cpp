/*
    Criar um programa para controle acadêmico, que atenda aos seguintes requisitos mínimos:

        Os dados devem ser armazenados em listas em memória.

        Deve ser possível cadastrar alunos, professores, disciplinas e turmas (operações: incluir, excluir, buscar e visualizar). 

        Cada aluno deve ter os seguintes dados: matrícula, nome, curso.

        Cada professor deve ter os seguintes dados: código, nome.

        Cada disciplina deve ter os seguintes dados: código, curso, nome, carga horária.

        Deve ser possível matricular alunos em uma turma. Uma turma pode ter apenas um professor associado.
*/

#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Aluno {
    string matricula;
    string nome;
    string curso;

    void criar(string matricula1, string nome1) {
        matricula = matricula1;
        nome = nome1;
    }
};

struct Professor {
    string codigo;
    string nome;

    void criar(string codigo1, string nome1) {
        codigo = codigo1;
        nome = nome1;
    }
};

struct Disciplina {
    string codigo;
    string curso;
    string nome;
    int carga_horaria;

    void criar(string codigo1, string curso1, string nome1, int carga_horaria1) {
        codigo = codigo1;
        curso = curso1;
        nome = nome1;
        carga_horaria = carga_horaria1;
    }
};

struct Turma {
    list<Aluno> alunos;
    Professor professor;

    void criar(list<Aluno> alunos1, Professor professor1) {
        alunos = alunos1;
        professor = professor1;
    }

    void inserir_aluno(Aluno aluno) {
        alunos.push_back(aluno);
    }
};

int main() {
    list<Aluno> alunos;
    list<Professor> professores;
    list<Disciplina> disciplinas;
    list<Turma> turmas;
    bool loop = true;

    while (loop) {
        int op;

        cout << "Que operação você deseja fazer?" << endl;
        cout << "1 - Inserir aluno" << endl;
        cout << "2 - Inserir professor" << endl;
        cout << "3 - Inserir disciplina" << endl;
        cout << "4 - Inserir turma" << endl;
        cout << "5 - Excluir aluno" << endl;
        cout << "6 - Excluir professor" << endl;
        cout << "7 - Excluir disciplina" << endl;
        cout << "8 - Excluir turma" << endl;
        cout << "9 - Buscar aluno" << endl;
        cout << "10 - Buscar professor" << endl;
        cout << "11 - Buscar disciplina" << endl;
        cout << "12 - Buscar turma" << endl;
        cout << "13 - Visualizar aluno" << endl;
        cout << "14 - Visualizar professor" << endl;
        cout << "15 - Visualizar disciplina" << endl;
        cout << "16 - Visualizar turma" << endl;
        cout << "17 - Inserir professor em turma" << endl;
        cout << "18 - Inserir aluno em turma" << endl;
        cout << "19 - Sair" << endl;

        cin >> op;

        switch(op) {
            case 1: {
                Aluno novo_aluno;
                cout << "Matricula: ";
                cin >> novo_aluno.matricula;

                cout << "Nome: ";
                cin.ignore();
                getline(cin, novo_aluno.nome);

                cout << "Curso: ";
                cin.ignore();
                getline(cin, novo_aluno.curso);

                alunos.push_back(novo_aluno);

                break;
            }
            case 2: {
                Professor novo_professor;
                cout << "Codigo: ";
                cin >> novo_professor.codigo;

                cout << "Nome: ";
                cin.ignore();
                getline(cin, novo_professor.nome);

                professores.push_back(novo_professor);

                break;
            }
            case 3: {
                Disciplina nova_disciplina;
                cout << "Codigo: ";
                cin >> nova_disciplina.codigo;

                cout << "Curso: ";
                cin.ignore();
                getline(cin, nova_disciplina.curso);

                cout << "Nome: ";
                cin.ignore();
                getline(cin, nova_disciplina.nome);

                cout << "Carga horária: ";
                cin >> nova_disciplina.carga_horaria;

                disciplinas.push_back(nova_disciplina);

                break;
            }
            
            default:
                loop = false;
                break;
        }
    }
    return 0;
}
