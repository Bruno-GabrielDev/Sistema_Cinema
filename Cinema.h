#ifndef CINEMA_H
#define CINEMA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

// Estrutura para representar uma sala
typedef struct {
    int codigo;
    char tipoExibicao[20]; // Tipo de exibição (e.g., 2D, 3D, IMAX)
    int capacidade;
    char nome[50];         // Nome da sala
    int total_sessoes;     // Contador para o número de sessões associadas à sala
    bool acessivel;        // Indica se a sala é acessível
} Sala;

// Estrutura para representar um filme
typedef struct {
    int codigo;
    char nome[60];         // Nome do filme
    char titulo[100];      // Título do filme
    char diretor[50];      // Nome do diretor
    int duracao;           // Duração em minutos
    char genero[30];       // Gênero do filme
    int classificacao;     // Classificação indicativa
    int anoLancamento;     // Ano de lançamento do filme
    char atores[200];      // Lista de atores principais
    char tipoExibicao[20]; // Tipo de exibição (e.g., 2D, 3D, IMAX)
} Filme;

// Estrutura para representar uma sessão
typedef struct {
    int codigoSessao;
    int codigoFilme;
    int codigoSala;
    char data[11];         // Formato "dd/mm/aaaa"
    char horario[6];       // Formato "hh:mm"
    float precoIngresso;   // Preço do ingresso
    int assentosOcupados;  // Número de assentos ocupados na sessão
} Sessao;

// Funções de manipulação de salas
void listarSalas(Sala* salas, int total_salas);
void listarSalaEspecifica(Sala* salas, int total_salas, int codigo);
void incluirSala(Sala** salas, int* total_salas);
void alterarSala(Sala* salas, int total_salas, int codigo);
void excluirSala(Sala* salas, int* total_salas, int codigo);
void carregarSalas(Sala** salas, int* total_salas, int* capacidade_salas, const char* filename);
void salvarSalas(Sala* salas, int total_salas, const char* filename);

// Funções para manipulação de filmes com alocação dinâmica
void listarFilmes(Filme* filmes, int total_filmes);
void listarFilmeEspecifico(Filme* filmes, int total_filmes, int codigo);
Filme* incluirFilme(Filme* filmes, int* total_filmes);
void alterarFilme(Filme* filmes, int total_filmes, int codigo);
Filme* excluirFilme(Filme* filmes, int* total_filmes, int codigo);
Filme* carregarFilmes(int* total_filmes, const char* filename);
void salvarFilmes(Filme* filmes, int total_filmes, const char* filename);

// Funções para manipulação de sessões
void listarSessoes(Sessao* sessoes, int total_sessoes);
void listarSessaoEspecifica(Sessao* sessoes, int total_sessoes, int codigoFilme, int codigoSala);
Sessao* incluirSessao(Sessao* sessoes, int* total_sessoes);
void alterarSessao(Sessao* sessoes, int total_sessoes, int codigoFilme, int codigoSala);
Sessao* excluirSessao(Sessao* sessoes, int* total_sessoes, int codigoFilme, int codigoSala);
Sessao* carregarSessoes(int* total_sessoes, const char* filename);
void salvarSessoes(Sessao* sessoes, int total_sessoes, const char* filename);

// Declarações das funções de relatórios
int compararDatas(const char* data1, const char* data2);
void relatorioSalas(const Sala* salas, int total_salas);
void relatorioFilmes(const Filme* filmes, int total_filmes);
void relatorioSessoes(const Sessao* sessoes, int total_sessoes);

// Declarações das funções dos submenus
void submenuSalas(Sala** salas, int* total_salas);
void submenuFilmes(Filme** filmes, int* total_filmes);
void submenuSessoes(Sessao** sessoes, int* total_sessoes, const Filme* filmes, int total_filmes, const Sala* salas, int total_salas);


#endif // CINEMA_H
