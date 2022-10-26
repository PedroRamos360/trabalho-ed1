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
            case 4: {
                Turma nova_turma;
                list<Aluno> alunos_turma;
                Professor professor_turma;

                cout << "Professor: ";
                cin >> professor_turma.codigo;

                nova_turma.criar(alunos_turma, professor_turma);

                turmas.push_back(nova_turma);

                break;
            }
            case 5: {
                string matricula;
                cout << "Matricula: ";
                cin >> matricula;

                for (list<Aluno>::iterator it = alunos.begin(); it != alunos.end(); it++) {
                    if (it->matricula == matricula) {
                        alunos.erase(it);
                        break;
                    }
                }

                break;
            }
            case 6: {
                string codigo;
                cout << "Codigo: ";
                cin >> codigo;

                for (list<Professor>::iterator it = professores.begin(); it != professores.end(); it++) {
                    if (it->codigo == codigo) {
                        professores.erase(it);
                        break;
                    }
                }

                break;
            }
            case 7: {
                string codigo;
                cout << "Codigo: ";
                cin >> codigo;

                for (list<Disciplina>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++) {
                    if (it->codigo == codigo) {
                        disciplinas.erase(it);
                        break;
                    }
                }

                break;
            }
            case 8: {
                string codigo;
                cout << "Codigo: ";
                cin >> codigo;

                for (list<Turma>::iterator it = turmas.begin(); it != turmas.end(); it++) {
                    if (it->professor.codigo == codigo) {
                        turmas.erase(it);
                        break;
                    }
                }

                break;
            }
            case 9: {
                string matricula;
                cout << "Matricula: ";
                cin >> matricula;

                for (list<Aluno>::iterator it = alunos.begin(); it != alunos.end(); it++) {
                    if (it->matricula == matricula) {
                        cout << "Matricula: " << it->matricula << endl;
                        cout << "Nome: " << it->nome << endl;
                        cout << "Curso: " << it->curso << endl;
                        break;
                    }
                }

                break;
            }
            case 10: {
                string codigo;
                cout << "Codigo: ";
                cin >> codigo;

                for (list<Professor>::iterator it = professores.begin(); it != professores.end(); it++) {
                    if (it->codigo == codigo) {
                        cout << "Codigo: " << it->codigo << endl;
                        cout << "Nome: " << it->nome << endl;
                        break;
                    }
                }

                break;
            }
            case 11: {
                string codigo;
                cout << "Codigo: ";
                cin >> codigo;

                for (list<Disciplina>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++) {
                    if (it->codigo == codigo) {
                        cout << "Codigo: " << it->codigo << endl;
                        cout << "Nome: " << it->nome << endl;
                        cout << "Curso: " << it->curso << endl;
                        cout << "Carga horária: " << it->carga_horaria << endl;
                        break;
                    }
                }

                break;
            }
            case 12: {
                string codigo;
                cout << "Codigo: ";
                cin >> codigo;

                for (list<Turma>::iterator it = turmas.begin(); it != turmas.end(); it++) {
                    if (it->professor.codigo == codigo) {
                        cout << "Professor: " << it->professor.codigo << endl;
                        cout << "Alunos: " << endl;
                        for (list<Aluno>::iterator it2 = it->alunos.begin(); it2 != it->alunos.end(); it2++) {
                            cout << it2->matricula << endl;
                        }
                        break;
                    }
                }

                break;
            }
            case 13: {
                string matricula;
                cout << "Matricula: ";
                cin >> matricula;

                for (list<Turma>::iterator it = turmas.begin(); it != turmas.end(); it++) {
                    for (list<Aluno>::iterator it2 = it->alunos.begin(); it2 != it->alunos.end(); it2++) {
                        if (it2->matricula == matricula) {
                            cout << "Professor: " << it->professor.codigo << endl;
                            cout << "Alunos: " << endl;
                            for (list<Aluno>::iterator it3 = it->alunos.begin(); it3 != it->alunos.end(); it3++) {
                                cout << it3->matricula << endl;
                            }
                            break;
                        }
                    }
                }

                break;
            }
            case 14: {
                string codigo;
                cout << "Codigo: ";
                cin >> codigo;

                for (list<Turma>::iterator it = turmas.begin(); it != turmas.end(); it++) {
                    if (it->professor.codigo == codigo) {
                        cout << "Professor: " << it->professor.codigo << endl;
                        cout << "Alunos: " << endl;
                        for (list<Aluno>::iterator it2 = it->alunos.begin(); it2 != it->alunos.end(); it2++) {
                            cout << it2->matricula << endl;
                        }
                        break;
                    }
                }

                break;
            }
            case 15: {
                string codigo;
                cout << "Codigo: ";
                cin >> codigo;

                for (list<Disciplina>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++) {
                    if (it->codigo == codigo) {
                        cout << "Codigo: " << it->codigo << endl;
                        cout << "Nome: " << it->nome << endl;
                        cout << "Curso: " << it->curso << endl;
                        cout << "Carga horária: " << it->carga_horaria << endl;
                        break;
                    }
                }

                break;
            }
            case 16: {
                string codigo;
                cout << "Codigo: ";
                cin >> codigo;

                for (list<Disciplina>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++) {
                    if (it->codigo == codigo) {
                        cout << "Codigo: " << it->codigo << endl;
                        cout << "Nome: " << it->nome << endl;
                        cout << "Curso: " << it->curso << endl;
                        cout << "Carga horária: " << it->carga_horaria << endl;
                        break;
                    }
                }

                break;
            }
            case 17: {
                string codigo;
                cout << "Codigo: ";
                cin >> codigo;

                for (list<Disciplina>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++) {
                    if (it->codigo == codigo) {
                        cout << "Codigo: " << it->codigo << endl;
                        cout << "Nome: " << it->nome << endl;
                        cout << "Curso: " << it->curso << endl;
                        cout << "Carga horária: " << it->carga_horaria << endl;
                        break;
                    }
                }

                break;
            }
            case 18: {
                string codigo;
                cout << "Codigo: ";
                cin >> codigo;

                for (list<Disciplina>::iterator it = disciplinas.begin(); it != disciplinas.end(); it++) {
                    if (it->codigo == codigo) {
                        cout << "Codigo: " << it->codigo << endl;
                        cout << "Nome: " << it->nome << endl;
                        cout << "Curso: " << it->curso << endl;
                        cout << "Carga horária: " << it->carga_horaria << endl;
                        break;
                    }
                }

                break;
            }
            
            default:
                loop = false;
                break;
        }
    }
    return 0;
}
