#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cinema.h"

// ========================
// Implementação das Funções
// ========================

// ------------------------
// Funções de Salas
// ------------------------

void listarSalas(Sala* salas, int total_salas) {
    for (int i = 0; i < total_salas; i++) {
        printf("Código: %d\nNome: %s\nCapacidade: %d\nTipo de Exibição: %s\nAcessível: %s\n\n",
               salas[i].codigo, salas[i].nome, salas[i].capacidade,
               salas[i].tipoExibicao, salas[i].acessivel ? "Sim" : "Não");
    }
}

void listarSalaEspecifica(Sala* salas, int total_salas, int codigo) {
    for (int i = 0; i < total_salas; i++) {
        if (salas[i].codigo == codigo) {
            printf("Código: %d\n", salas[i].codigo);
            printf("Nome: %s\n", salas[i].nome);
            printf("Capacidade: %d\n", salas[i].capacidade);
            printf("Tipo de Exibição: %s\n", salas[i].tipoExibicao);
            printf("Acessível: %s\n\n", salas[i].acessivel ? "Sim" : "Não");
            return;
        }
    }
    printf("Sala com o código %d não encontrada.\n", codigo);
}

void incluirSala(Sala** salas, int* total_salas) {
    (*total_salas)++;
    *salas = realloc(*salas, (*total_salas) * sizeof(Sala));
    if (*salas == NULL) {
        perror("Erro ao alocar memória para novas salas.");
        exit(1);
    }

    // Solicitar dados da nova sala e preenchê-los
    printf("Digite o código da nova sala: ");
    scanf("%d", &(*salas)[*total_salas - 1].codigo);
    getchar();  // Limpa o buffer

    printf("Digite o nome da sala: ");
    fgets((*salas)[*total_salas - 1].nome, sizeof((*salas)[*total_salas - 1].nome), stdin);
    (*salas)[*total_salas - 1].nome[strcspn((*salas)[*total_salas - 1].nome, "\n")] = '\0';

    printf("Digite a capacidade da sala: ");
    scanf("%d", &(*salas)[*total_salas - 1].capacidade);
    getchar();

    printf("Digite o tipo de exibição da sala: ");
    fgets((*salas)[*total_salas - 1].tipoExibicao, sizeof((*salas)[*total_salas - 1].tipoExibicao), stdin);
    (*salas)[*total_salas - 1].tipoExibicao[strcspn((*salas)[*total_salas - 1].tipoExibicao, "\n")] = '\0';

    int acessivel_temp;
    printf("A sala é acessível? (1 para Sim, 0 para Não): ");
    scanf("%d", &acessivel_temp);
    (*salas)[*total_salas - 1].acessivel = (acessivel_temp != 0); // Converte para booleano

    printf("Sala adicionada com sucesso!\n");
}
void alterarSala(Sala* salas, int total_salas, int codigo) {
    for (int i = 0; i < total_salas; i++) {
        if (salas[i].codigo == codigo) {
            printf("Alterando informações da sala com código %d:\n", codigo);
            
            printf("Digite o novo nome da sala: ");
            getchar(); // Limpa o buffer de entrada
            fgets(salas[i].nome, sizeof(salas[i].nome), stdin);
            salas[i].nome[strcspn(salas[i].nome, "\n")] = '\0'; // Remove newline

            printf("Digite a nova capacidade: ");
            scanf("%d", &salas[i].capacidade);

            printf("Digite o novo tipo de exibição: ");
            getchar();
            fgets(salas[i].tipoExibicao, sizeof(salas[i].tipoExibicao), stdin);
            salas[i].tipoExibicao[strcspn(salas[i].tipoExibicao, "\n")] = '\0';

            int acessivel_temp;
            printf("Acessível (1 = Sim, 0 = Não): ");
            scanf("%d", &acessivel_temp);
            salas[i].acessivel = (acessivel_temp != 0);

            printf("Sala alterada com sucesso.\n");
            return;
        }
    }
    printf("Sala com o código %d não encontrada.\n", codigo);
}

void excluirSala(Sala* salas, int* total_salas, int codigo) {
    int found = 0;
    for (int i = 0; i < *total_salas; i++) {
        if (salas[i].codigo == codigo) {
            found = 1;
            for (int j = i; j < *total_salas - 1; j++) {
                salas[j] = salas[j + 1];
            }
            (*total_salas)--;
            break;
        }
    }
    if (!found) {
        printf("Sala com o código %d não encontrada.\n", codigo);
    }
}

void carregarSalas(Sala** salas, int* total_salas, int* capacidade_salas, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        return;
    }

    Sala nova_sala;
    int acessivel_temp;
    while (fscanf(file, "%d %[^\n] %d %[^\n] %d ",
              &nova_sala.codigo, nova_sala.nome,
              &nova_sala.capacidade, nova_sala.tipoExibicao,
              &acessivel_temp) == 5) {
                 nova_sala.acessivel = (acessivel_temp != 0); // Converte para booleano
    
    if (*total_salas >= *capacidade_salas) {
        *capacidade_salas *= 2;
        *salas = realloc(*salas, sizeof(Sala) * (*capacidade_salas));
        if (*salas == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(file);
            exit(1);
        }
    }
    (*salas)[*total_salas] = nova_sala;
    (*total_salas)++;
}
fclose(file);
}

void salvarSalas(Sala* salas, int total_salas, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        return;
    }

    for (int i = 0; i < total_salas; i++) {
        fprintf(file, "%d %s %d %s %d\n",
                salas[i].codigo, salas[i].nome,
                salas[i].capacidade, salas[i].tipoExibicao,
                salas[i].acessivel);
    }
    fclose(file);
}


// ------------------------
// Funções de Filmes
// ------------------------

void listarFilmes(Filme* filmes, int total_filmes) {
    if (total_filmes == 0) {
        printf("Nenhum filme cadastrado.\n");
        return;
    }

    printf("Lista de Filmes:\n");
    for (int i = 0; i < total_filmes; i++) {
        printf("Código: %d, Nome: %s, Ano: %d, Diretor: %s, Atores: %s\n",
               filmes[i].codigo, filmes[i].nome, filmes[i].anoLancamento,
               filmes[i].diretor, filmes[i].atores);
    }
}

void listarFilmeEspecifico(Filme* filmes, int total_filmes, int codigo) {
    for (int i = 0; i < total_filmes; i++) {
        if (filmes[i].codigo == codigo) {
            printf("Filme encontrado:\nCódigo: %d, Nome: %s, Ano: %d, Diretor: %s, Atores: %s\n",
                   filmes[i].codigo, filmes[i].nome, filmes[i].anoLancamento,
                   filmes[i].diretor, filmes[i].atores);
            return;
        }
    }
    printf("Filme com código %d não encontrado.\n", codigo);
}

Filme* incluirFilme(Filme* filmes, int* total_filmes) {
    filmes = realloc(filmes, (*total_filmes + 1) * sizeof(Filme));
    if (filmes == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    Filme* novo_filme = &filmes[*total_filmes];
    printf("Digite o código do filme: ");
    scanf("%d", &novo_filme->codigo);
    getchar(); // Limpa o buffer

    printf("Digite o nome do filme: ");
    fgets(novo_filme->nome, sizeof(novo_filme->nome), stdin);
    novo_filme->nome[strcspn(novo_filme->nome, "\n")] = '\0';

    printf("Digite o ano de lançamento: ");
    scanf("%d", &novo_filme->anoLancamento);
    getchar();

    printf("Digite o diretor: ");
    fgets(novo_filme->diretor, sizeof(novo_filme->diretor), stdin);
    novo_filme->diretor[strcspn(novo_filme->diretor, "\n")] = '\0';

    printf("Digite os atores (separados por vírgula): ");
    fgets(novo_filme->atores, sizeof(novo_filme->atores), stdin);
    novo_filme->atores[strcspn(novo_filme->atores, "\n")] = '\0';

    (*total_filmes)++;
    printf("Filme incluído com sucesso.\n");

    return filmes;
}

void alterarFilme(Filme* filmes, int total_filmes, int codigo) {
    for (int i = 0; i < total_filmes; i++) {
        if (filmes[i].codigo == codigo) {
            printf("Alterando informações do filme com código %d:\n", codigo);

            printf("Digite o novo nome do filme: ");
            getchar();
            fgets(filmes[i].nome, sizeof(filmes[i].nome), stdin);
            filmes[i].nome[strcspn(filmes[i].nome, "\n")] = '\0';

            printf("Digite o novo ano de lançamento: ");
            scanf("%d", &filmes[i].anoLancamento);

            printf("Digite o novo diretor: ");
            getchar();
            fgets(filmes[i].diretor, sizeof(filmes[i].diretor), stdin);
            filmes[i].diretor[strcspn(filmes[i].diretor, "\n")] = '\0';

            printf("Digite os novos atores (separados por vírgula): ");
            fgets(filmes[i].atores, sizeof(filmes[i].atores), stdin);
            filmes[i].atores[strcspn(filmes[i].atores, "\n")] = '\0';

            printf("Filme alterado com sucesso.\n");
            return;
        }
    }
    printf("Filme com o código %d não encontrado.\n", codigo);
}

Filme* excluirFilme(Filme* filmes, int* total_filmes, int codigo) {
    for (int i = 0; i < *total_filmes; i++) {
        if (filmes[i].codigo == codigo) {
            for (int j = i; j < *total_filmes - 1; j++) {
                filmes[j] = filmes[j + 1];
            }
            (*total_filmes)--;
            filmes = realloc(filmes, (*total_filmes) * sizeof(Filme));
            printf("Filme com código %d excluído.\n", codigo);
            return filmes;
        }
    }
    printf("Filme com código %d não encontrado.\n", codigo);
    return filmes;
}

Filme* carregarFilmes(int* total_filmes, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        return NULL;
    }

    Filme* filmes = NULL;
    *total_filmes = 0;

    while (!feof(file)) {
        filmes = realloc(filmes, (*total_filmes + 1) * sizeof(Filme));
        if (filmes == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(file);
            return NULL;
        }

        Filme* novo_filme = &filmes[*total_filmes];
        fscanf(file, "%d\n", &novo_filme->codigo);
        fgets(novo_filme->nome, sizeof(novo_filme->nome), file);
        novo_filme->nome[strcspn(novo_filme->nome, "\n")] = '\0';

        fscanf(file, "%d\n", &novo_filme->anoLancamento);
        fgets(novo_filme->diretor, sizeof(novo_filme->diretor), file);
        novo_filme->diretor[strcspn(novo_filme->diretor, "\n")] = '\0';

        fgets(novo_filme->atores, sizeof(novo_filme->atores), file);
        novo_filme->atores[strcspn(novo_filme->atores, "\n")] = '\0';

        (*total_filmes)++;
    }

    fclose(file);
    printf("Filmes carregados com sucesso.\n");
    return filmes;
}

void salvarFilmes(Filme* filmes, int total_filmes, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        return;
    }

    for (int i = 0; i < total_filmes; i++) {
        fprintf(file, "%d\n%s\n%d\n%s\n%s\n",
                filmes[i].codigo, filmes[i].nome, filmes[i].anoLancamento,
                filmes[i].diretor, filmes[i].atores);
    }

    fclose(file);
    printf("Filmes salvos com sucesso.\n");
}

// ------------------------
// Funções de Sessões
// ------------------------

// Função para listar todas as sessões
void listarSessoes(Sessao* sessoes, int total_sessoes) {
    for (int i = 0; i < total_sessoes; i++) {
        printf("Código do Filme: %d\nCódigo da Sala: %d\nData: %s\nHorário: %s\nPreço do Ingresso: %.2f\n\n",
               sessoes[i].codigoFilme, sessoes[i].codigoSala, sessoes[i].data, sessoes[i].horario, sessoes[i].precoIngresso);
    }
}

// Função para listar uma sessão específica
void listarSessaoEspecifica(Sessao* sessoes, int total_sessoes, int codigoFilme, int codigoSala) {
    for (int i = 0; i < total_sessoes; i++) {
        if (sessoes[i].codigoFilme == codigoFilme && sessoes[i].codigoSala == codigoSala) {
            printf("Código do Filme: %d\nCódigo da Sala: %d\nData: %s\nHorário: %s\nPreço do Ingresso: %.2f\n",
                   sessoes[i].codigoFilme, sessoes[i].codigoSala,
                   sessoes[i].data, sessoes[i].horario, sessoes[i].precoIngresso);
            return;
        }
    }
    printf("Sessão não encontrada.\n");
}

// Função para incluir uma nova sessão
Sessao* incluirSessao(Sessao* sessoes, int* total_sessoes) {
    *total_sessoes += 1;
    sessoes = realloc(sessoes, (*total_sessoes) * sizeof(Sessao));
    if (sessoes == NULL) {
        printf("Erro de memória.\n");
        exit(1);
    }
    printf("Digite o código do filme, da sala, data (dd/mm/yyyy), horário (hh:mm) e preço do ingresso: ");
    scanf("%d %d %s %s %f", &sessoes[*total_sessoes - 1].codigoFilme, &sessoes[*total_sessoes - 1].codigoSala,
          sessoes[*total_sessoes - 1].data, sessoes[*total_sessoes - 1].horario, &sessoes[*total_sessoes - 1].precoIngresso);
    return sessoes;
}

// Função para alterar uma sessão existente
void alterarSessao(Sessao* sessoes, int total_sessoes, int codigoFilme, int codigoSala) {
    for (int i = 0; i < total_sessoes; i++) {
        if (sessoes[i].codigoFilme == codigoFilme && sessoes[i].codigoSala == codigoSala) {
            printf("Digite a nova data (dd/mm/yyyy), horário (hh:mm) e preço do ingresso: ");
            scanf("%s %s %f", sessoes[i].data, sessoes[i].horario, &sessoes[i].precoIngresso);
            printf("Sessão alterada com sucesso.\n");
            return;
        }
    }
    printf("Sessão não encontrada.\n");
}

// Função para excluir uma sessão
Sessao* excluirSessao(Sessao* sessoes, int* total_sessoes, int codigoFilme, int codigoSala) {
    int index = -1;
    for (int i = 0; i < *total_sessoes; i++) {
        if (sessoes[i].codigoFilme == codigoFilme && sessoes[i].codigoSala == codigoSala) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Sessão não encontrada.\n");
        return sessoes;
    }

    for (int i = index; i < *total_sessoes - 1; i++) {
        sessoes[i] = sessoes[i + 1];
    }
    *total_sessoes -= 1;
    sessoes = realloc(sessoes, (*total_sessoes) * sizeof(Sessao));
    return sessoes;
}

// Função para carregar sessões de um arquivo
Sessao* carregarSessoes(int* total_sessoes, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        return NULL;
    }

    fscanf(file, "%d", total_sessoes);
    Sessao* sessoes = malloc(*total_sessoes * sizeof(Sessao));
    if (sessoes == NULL) {
        printf("Erro de memória.\n");
        exit(1);
    }

    for (int i = 0; i < *total_sessoes; i++) {
        fscanf(file, "%d %d %s %s %f", &sessoes[i].codigoFilme, &sessoes[i].codigoSala,
               sessoes[i].data, sessoes[i].horario, &sessoes[i].precoIngresso);
    }

    fclose(file);
    return sessoes;
}

// Função para salvar sessões em um arquivo
void salvarSessoes(Sessao* sessoes, int total_sessoes, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        return;
    }

    fprintf(file, "%d\n", total_sessoes);
    for (int i = 0; i < total_sessoes; i++) {
        fprintf(file, "%d %d %s %s %.2f\n", sessoes[i].codigoFilme, sessoes[i].codigoSala,
                sessoes[i].data, sessoes[i].horario, sessoes[i].precoIngresso);
    }

    fclose(file);
}

// ------------------------
// Funções de Relatórios
// ------------------------

// Função para comparar datas
int compararDatas(const char* data1, const char* data2) {
    // Aqui assumimos que as datas estão no formato "dd/mm/aaaa"
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;

    sscanf(data1, "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(data2, "%d/%d/%d", &dia2, &mes2, &ano2);

    if (ano1 != ano2) return ano1 - ano2;
    if (mes1 != mes2) return mes1 - mes2;
    return dia1 - dia2;
}

// Função de relatório para Salas
void relatorioSalas(const Sala* salas, int total_salas) {
    printf("\nRelatório de Salas:\n");
    for (int i = 0; i < total_salas; i++) {
        printf("Código: %d, Capacidade: %d\n", salas[i].codigo, salas[i].capacidade);
    }
}

// Função de relatório para Filmes
void relatorioFilmes(const Filme* filmes, int total_filmes) {
    printf("\nRelatório de Filmes:\n");
    for (int i = 0; i < total_filmes; i++) {
        printf("Código: %d, Título: %s, Duração: %d minutos\n", filmes[i].codigo, filmes[i].titulo, filmes[i].duracao);
    }
}

// Função de relatório para Sessões
void relatorioSessoes(const Sessao* sessoes, int total_sessoes) {
    printf("\nRelatório de Sessões:\n");
    for (int i = 0; i < total_sessoes; i++) {
        printf("Código do Filme: %d, Código da Sala: %d, Data: %s, Horário: %s, Preço do Ingresso: %.2f\n",
               sessoes[i].codigoFilme, sessoes[i].codigoSala,
               sessoes[i].data, sessoes[i].horario, sessoes[i].precoIngresso);
    }
}

// ------------------------
// SubMenus
// ------------------------

// Função submenu para Salas
void submenuSalas(Sala** salas, int* total_salas) {
    int opcao, codigo;

    do {
        printf("\nSubmenu de Salas:\n");
        printf("1. Listar Salas\n2. Listar Sala Específica\n3. Incluir Sala\n");
        printf("4. Alterar Sala\n5. Excluir Sala\n6. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                listarSalas(*salas, *total_salas);
                break;
            case 2:
                printf("Digite o código da sala: ");
                scanf("%d", &codigo);
                listarSalaEspecifica(*salas, *total_salas, codigo);
                break;
            case 3:
                incluirSala(salas, total_salas);  // Removido `&` extra
                break;
            case 4: 
                printf("Digite o código da sala a alterar: ");
                scanf("%d", &codigo);
                alterarSala(*salas, *total_salas, codigo);
                break;
            case 5:
                printf("Digite o código da sala a ser excluída: ");
                scanf("%d", &codigo);
                excluirSala(*salas, total_salas, codigo);  // Removido `int codigo` duplicado
                break;
            case 6:
                printf("Retornando ao Menu Principal...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(opcao != 6);
}


// Função submenu para Filmes
void submenuFilmes(Filme** filmes, int* total_filmes) {
    int opcao, codigo;

    do {
        printf("\nSubmenu de Filmes:\n");
        printf("1. Listar Filmes\n2. Listar Filme Específico\n3. Incluir Filme\n");
        printf("4. Alterar Filme\n5. Excluir Filme\n6. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                listarFilmes(*filmes, *total_filmes);
                break;
            case 2:
                printf("Digite o código do filme: ");
                scanf("%d", &codigo);
                listarFilmeEspecifico(*filmes, *total_filmes, codigo);
                break;
            case 3:
                *filmes = incluirFilme(*filmes, total_filmes);
                break;
            case 4:
                printf("Digite o código do filme a alterar: ");
                scanf("%d", &codigo);
                alterarFilme(*filmes, *total_filmes, codigo);
                break;
            case 5:
                printf("Digite o código do filme a excluir: ");
                scanf("%d", &codigo);
                *filmes = excluirFilme(*filmes, total_filmes, codigo);
                break;
        }
    } while(opcao != 6);
}

// Função submenu para Sessões
void submenuSessoes(Sessao** sessoes, int* total_sessoes, const Filme* filmes, int total_filmes, const Sala* salas, int total_salas) {
    (void) filmes;
    (void) total_filmes;
    (void) salas;
    (void) total_salas;
    int opcao, codigoFilme, codigoSala;

    do {
        printf("\nSubmenu de Sessões:\n");
        printf("1. Listar Sessões\n2. Listar Sessão Específica\n3. Incluir Sessão\n");
        printf("4. Alterar Sessão\n5. Excluir Sessão\n6. Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                listarSessoes(*sessoes, *total_sessoes);
                break;
            case 2:
                printf("Digite o código do filme e o código da sala da sessão: ");
                scanf("%d %d", &codigoFilme, &codigoSala);
                listarSessaoEspecifica(*sessoes, *total_sessoes, codigoFilme, codigoSala);
                break;
            case 3:
                *sessoes = incluirSessao(*sessoes, total_sessoes);
                break;
            case 4:
                printf("Digite o código do filme e o código da sala da sessão a alterar: ");
                scanf("%d %d", &codigoFilme, &codigoSala);
                alterarSessao(*sessoes, *total_sessoes, codigoFilme, codigoSala);
                break;
            case 5:
                printf("Digite o código do filme e o código da sala da sessão a excluir: ");
                scanf("%d %d", &codigoFilme, &codigoSala);
                *sessoes = excluirSessao(*sessoes, total_sessoes, codigoFilme, codigoSala);
                break;
        }
    } while(opcao != 6);
}

