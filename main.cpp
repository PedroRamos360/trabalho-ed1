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
};

struct Professor {
    string codigo;
    string nome;
};

struct Disciplina {
    string codigo;
    string curso;
    string nome;
    int carga_horaria;
};

struct Turma {
    string codigo;
    list<Aluno> alunos;
    Professor professor;
    Disciplina disciplina;
};

Aluno buscar_aluno(list<Aluno>* alunos, string matricula) {
    for (auto aluno : *alunos) {
        if (aluno.matricula == matricula) {
            return aluno;
        }
    }
    return Aluno();
}

Professor buscar_professor(list<Professor>* professores, string codigo) {
    for (auto professor : *professores) {
        if (professor.codigo == codigo) {
            return professor;
        }
    }
    return Professor();
}

Disciplina buscar_disciplina(list<Disciplina>* disciplinas, string codigo) {
    for (auto disciplina : *disciplinas) {
        if (disciplina.codigo == codigo) {
            return disciplina;
        }
    }
    return Disciplina();
}

Turma buscar_turma(list<Turma>* turmas, string codigo) {
    for (auto turma : *turmas) {
        if (turma.codigo == codigo) {
            return turma;
        }
    }
    return Turma();
}

void inserir_aluno(list<Aluno>* alunos) {
    Aluno novo_aluno;
    cout << "Matricula: ";
    cin >> novo_aluno.matricula;

    cout << "Nome: ";
    cin.ignore();
    getline(cin, novo_aluno.nome);

    cout << "Curso: ";
    getline(cin, novo_aluno.curso);

    alunos->push_back(novo_aluno);
    cout << "Aluno inserido com sucesso!" << endl;
}

void inserir_professor(list<Professor>* professores) {
    Professor novo_professor;
    cout << "Codigo: ";
    cin >> novo_professor.codigo;

    cout << "Nome: ";
    cin.ignore();
    getline(cin, novo_professor.nome);

    professores->push_back(novo_professor);
    cout << "Professor inserido com sucesso!" << endl;
}

void inserir_disciplina(list<Disciplina>* disciplinas) {
    Disciplina nova_disciplina;
    cout << "Codigo: ";
    cin >> nova_disciplina.codigo;

    cout << "Curso: ";
    cin.ignore();
    getline(cin, nova_disciplina.curso);

    cout << "Nome: ";
    getline(cin, nova_disciplina.nome);

    cout << "Carga horaria: ";
    cin >> nova_disciplina.carga_horaria;

    disciplinas->push_back(nova_disciplina);
    cout << "Disciplina inserida com sucesso!" << endl;
}

void inserir_turma(list<Turma>* turmas, list<Disciplina>* disciplinas) {
    Turma nova_turma;
    list<Aluno> alunos;
    Professor professor;

    string codigo_disciplina;

    cout << "Codigo da turma: ";
    cin >> nova_turma.codigo;

    cout << "Codigo da disciplina: ";
    cin >> codigo_disciplina;

    nova_turma.disciplina = buscar_disciplina(disciplinas, codigo_disciplina);
    nova_turma.alunos = alunos;
    nova_turma.professor = professor;

    turmas->push_back(nova_turma);
    cout << "Turma inserida com sucesso!" << endl;
}

void excluir_aluno(list<Aluno>* alunos) {
    string matricula;
    cout << "Matricula: ";
    cin >> matricula;

    for (auto it = alunos->begin(); it != alunos->end(); it++) {
        if (it->matricula == matricula) {
            alunos->erase(it);
            cout << "Aluno deletado com sucesso!" << endl;
            return;
        }
    }

    cout << "Aluno nao encontrado!" << endl;
}

void excluir_professor(list<Professor>* professores) {
    string codigo;
    cout << "Codigo: ";
    cin >> codigo;

    for (auto it = professores->begin(); it != professores->end(); it++) {
        if (it->codigo == codigo) {
            professores->erase(it);
            cout << "Professor deletado com sucesso!" << endl;
            return;
        }
    }

    cout << "Professor nao encontrado!" << endl;
}

void excluir_disciplina(list<Disciplina>* disciplinas) {
    string codigo;
    cout << "Codigo: ";
    cin >> codigo;

    for (auto it = disciplinas->begin(); it != disciplinas->end(); it++) {
        if (it->codigo == codigo) {
            disciplinas->erase(it);
            cout << "Disciplina deletada com sucesso!" << endl;
            return;
        }
    }

    cout << "Disciplina nao encontrada!" << endl;
}

void excluir_turma(list<Turma>* turmas) {
    string codigo;
    cout << "Codigo: ";
    cin >> codigo;

    for (auto it = turmas->begin(); it != turmas->end(); it++) {
        if (it->codigo == codigo) {
            turmas->erase(it);
            cout << "Turma deletada com sucesso!" << endl;
            return;
        }
    }

    cout << "Turma nao encontrada!" << endl;
}

void visualizar_aluno(list<Aluno>* alunos) {
    string matricula;
    cout << "Matricula: ";
    cin >> matricula;

    Aluno aluno = buscar_aluno(alunos, matricula);

    if (aluno.matricula.empty()) {
        cout << "Aluno nao encontrado!" << endl;
        return;
    }

    cout << "Matricula: " << aluno.matricula << endl;
    cout << "Nome: " << aluno.nome << endl;
    cout << "Curso: " << aluno.curso << endl;
}

void visualizar_professor(list<Professor>* professores) {
    string codigo;
    cout << "Codigo: ";
    cin >> codigo;

    Professor professor = buscar_professor(professores, codigo);

    if (professor.codigo.empty()) {
        cout << "Professor nao encontrado!" << endl;
        return;
    }

    cout << "Codigo: " << professor.codigo << endl;
    cout << "Nome: " << professor.nome << endl;
}

void visualizar_disciplina(list<Disciplina>* disciplinas) {
    string codigo;
    cout << "Codigo: ";
    cin >> codigo;

    Disciplina disciplina = buscar_disciplina(disciplinas, codigo);

    if (disciplina.codigo.empty()) {
        cout << "Disciplina nao encontrada!" << endl;
        return;
    }

    cout << "Codigo: " << disciplina.codigo << endl;
    cout << "Nome: " << disciplina.nome << endl;
    cout << "Curso: " << disciplina.curso << endl;
    cout << "Carga horaria: " << disciplina.carga_horaria << endl;
}

void visualizar_turma(list<Turma>* turmas) {
    string codigo;
    cout << "Codigo: ";
    cin >> codigo;

    Turma turma = buscar_turma(turmas, codigo);

    if (turma.codigo.empty()) {
        cout << "Turma nao encontrada!" << endl;
        return;
    }

    cout << "Codigo: " << turma.codigo << endl;
    cout << "Disciplina: " << turma.disciplina.nome << endl;
    cout << "Professor: " << turma.professor.nome << endl;
    cout << "Alunos: " << endl;

    for (auto aluno : turma.alunos) {
        cout << "- " << aluno.nome << endl;
    }
}

void inserir_professor_turma(list<Turma>* turmas, list<Professor>* professores) {
    string codigo_turma;
    string codigo_professor;

    cout << "Codigo da turma: ";
    cin >> codigo_turma;

    cout << "Codigo do professor: ";
    cin >> codigo_professor;

    Turma turma = buscar_turma(turmas, codigo_turma);
    Professor professor = buscar_professor(professores, codigo_professor);

    if (turma.codigo.empty()) {
        cout << "Turma nao encontrada!" << endl;
        return;
    }

    if (professor.codigo.empty()) {
        cout << "Professor nao encontrado!" << endl;
        return;
    }

    turma.professor = professor;
    // excluir turma antiga
    for (auto it = turmas->begin(); it != turmas->end(); it++) {
        if (it->codigo == codigo_turma) {
            turmas->erase(it);
            break;
        }
    }
    // inserir turma nova
    turmas->push_back(turma);
}

void inserir_aluno_turma(list<Turma>* turmas, list<Aluno>* alunos) {
    string codigo_turma;
    string matricula_aluno;

    cout << "Codigo da turma: ";
    cin >> codigo_turma;

    cout << "Matricula do aluno: ";
    cin >> matricula_aluno;

    Turma turma = buscar_turma(turmas, codigo_turma);
    Aluno aluno = buscar_aluno(alunos, matricula_aluno);

    if (turma.codigo.empty()) {
        cout << "Turma nao encontrada!" << endl;
        return;
    }

    if (aluno.matricula.empty()) {
        cout << "Aluno nao encontrado!" << endl;
        return;
    }

    turma.alunos.push_back(aluno);
    // excluir turma antiga
    for (auto it = turmas->begin(); it != turmas->end(); it++) {
        if (it->codigo == codigo_turma) {
            turmas->erase(it);
            break;
        }
    }
    // inserir turma nova
    turmas->push_back(turma);
}

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
        cout << "9 - Visualizar aluno" << endl;
        cout << "10 - Visualizar professor" << endl;
        cout << "11 - Visualizar disciplina" << endl;
        cout << "12 - Visualizar turma" << endl;
        cout << "13 - Inserir professor em turma" << endl;
        cout << "14 - Inserir aluno em turma" << endl;
        cout << "15 - Sair" << endl;

        cin >> op;

        switch(op) {
            case 1: {
                inserir_aluno(&alunos);
                break;
            }
            case 2: {
                inserir_professor(&professores);
                break;
            }
            case 3: {
                inserir_disciplina(&disciplinas);
                break;
            }
            case 4: {
                inserir_turma(&turmas, &disciplinas);
                break;
            }
            case 5: {
                excluir_aluno(&alunos);
                break;
            }
            case 6: {
                excluir_professor(&professores);
                break;
            }
            case 7: {
                excluir_disciplina(&disciplinas);
                break;
            }
            case 8: {
                excluir_turma(&turmas);
                break;
            }
            case 9: {
                visualizar_aluno(&alunos);
                break;
            }
            case 10: {
                visualizar_professor(&professores);
                break;
            }
            case 11: {
                visualizar_disciplina(&disciplinas);
                break;
            }
            case 12: {
                visualizar_turma(&turmas);
                break;
            }
            case 13: {
                inserir_professor_turma(&turmas, &professores);
                break;
            }
            case 14: {
                inserir_aluno_turma(&turmas, &alunos);
                break;
            }
            default:
                loop = false;
                break;
        }
    }
    return 0;
}
