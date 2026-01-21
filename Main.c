#include <stdio.h>
#include <stdlib.h>
#include "Cinema.h"  // Inclua o arquivo de cabeçalho para acessar as funções e structs

int main() {
    // Inicialização das variáveis de controle e alocação dinâmica de memória
    Filme* filmes = NULL;
    Sala* salas = NULL;
    Sessao* sessoes = NULL;

    int total_filmes = 0;
    int total_salas = 0;
    int total_sessoes = 0;

    int opcao;

    // Menu principal
    do {
        printf("\nMenu Principal:\n");
        printf("1. Gerenciar Filmes\n");
        printf("2. Gerenciar Salas\n");
        printf("3. Gerenciar Sessões\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                submenuFilmes(&filmes, &total_filmes);  // Chamada ao submenu de filmes
                break;
            case 2:
                submenuSalas(&salas, &total_salas);  // Chamada ao submenu de salas
                break;
            case 3:
                submenuSessoes(&sessoes, &total_sessoes, filmes, total_filmes, salas, total_salas);  // Chamada ao submenu de sessões
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while(opcao != 4);

    // Liberação de memória alocada antes de encerrar o programa
    free(filmes);
    free(salas);
    free(sessoes);

    return 0;
}
