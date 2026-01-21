# 🎬 Sistema de Gerenciamento de Cinema

[![C](https://img.shields.io/badge/C-99+-blue.svg)](https://www.iso.org/standard/74528.html)
[![GCC](https://img.shields.io/badge/GCC-Compatible-green.svg)](https://gcc.gnu.org/)
[![Make](https://img.shields.io/badge/Make-Build%20System-orange.svg)](https://www.gnu.org/software/make/)
[![License](https://img.shields.io/badge/Licença-MIT-blue.svg)](LICENSE)

Sistema completo de gerenciamento de cinema desenvolvido em C, permitindo controle eficiente de filmes, salas de exibição e sessões cinematográficas através de interface de linha de comando intuitiva.

## 📋 Visão Geral

Este projeto foi desenvolvido para demonstrar conceitos fundamentais de programação em C, incluindo estruturas de dados, gerenciamento de memória, entrada/saída de dados e organização de código modular. O sistema oferece uma solução completa para administração de operações básicas de um cinema.

## ✨ Funcionalidades Principais

### 🎥 Gerenciamento de Filmes

- ✅ **CRUD Completo**
  - Cadastrar novos filmes
  - Alterar informações de filmes existentes
  - Excluir filmes do catálogo
  - Listar todos os filmes disponíveis

- 📝 **Informações Detalhadas**
  - Título do filme
  - Gênero
  - Duração
  - Classificação indicativa
  - Sinopse

### 🎭 Gerenciamento de Salas

- ✅ **Controle de Salas de Exibição**
  - Cadastrar novas salas
  - Modificar configurações
  - Remover salas
  - Visualizar todas as salas

- 🪑 **Características das Salas**
  - Número/nome da sala
  - Capacidade de assentos
  - Tipo de projeção (2D, 3D, IMAX)
  - Status (ativa/manutenção)

### 📅 Gerenciamento de Sessões

- ✅ **Programação de Sessões**
  - Criar novas sessões
  - Atualizar horários e informações
  - Cancelar sessões
  - Listar todas as sessões programadas

- 🕐 **Detalhes das Sessões**
  - Filme exibido
  - Sala designada
  - Horário de início
  - Data da exibição
  - Preço do ingresso
  - Ingressos disponíveis

## 🏗️ Estrutura do Projeto

```
projeto-cinema/
├── src/
│   ├── main.c              # Função principal e menu
│   ├── filme.c             # Operações de filmes
│   ├── filme.h             # Header de filmes
│   ├── sala.c              # Operações de salas
│   ├── sala.h              # Header de salas
│   ├── sessao.c            # Operações de sessões
│   ├── sessao.h            # Header de sessões
│   └── utils.c             # Funções auxiliares
│       └── utils.h
│
├── data/
│   ├── filmes.dat          # Dados persistidos de filmes
│   ├── salas.dat           # Dados persistidos de salas
│   └── sessoes.dat         # Dados persistidos de sessões
│
├── Makefile                # Script de compilação
├── README.md               # Documentação
└── LICENSE                 # Licença MIT
```

## 🚀 Pré-requisitos

Antes de começar, certifique-se de ter as seguintes ferramentas instaladas:

### Software Necessário

- **GCC (GNU Compiler Collection)** 4.8 ou superior
  - Windows: [MinGW](https://www.mingw-w64.org/) ou [TDM-GCC](https://jmeubank.github.io/tdm-gcc/)
  - Linux: `sudo apt-get install gcc` (Debian/Ubuntu)
  - macOS: Xcode Command Line Tools ou Homebrew

- **Make** 3.81 ou superior
  - Windows: Incluído no MinGW
  - Linux: `sudo apt-get install make`
  - macOS: Incluído no Xcode Command Line Tools

- **Git** (opcional, para clonar o repositório)
  - [Baixar Git](https://git-scm.com/downloads)

### Verificar Instalação

```bash
# Verificar GCC
gcc --version

# Verificar Make
make --version

# Verificar Git
git --version
```

## 📥 Instalação

### Método 1: Clonar com Git

```bash
# 1. Clone o repositório
git clone https://github.com/Bruno-GabrielDev/projeto-cinema.git

# 2. Navegue até a pasta do projeto
cd projeto-cinema

# 3. Compile o código
make

# 4. Execute o programa
./main
```

### Método 2: Download Manual

1. Baixe o ZIP do repositório
2. Extraia os arquivos
3. Abra o terminal na pasta extraída
4. Execute:
   ```bash
   make
   ./main
   ```

### Limpeza de Arquivos Compilados

```bash
# Remover arquivos objeto e executável
make clean
```

## 💻 Como Usar

### Menu Principal

Ao executar o programa, você verá o seguinte menu:

```
════════════════════════════════════════
     SISTEMA DE GERENCIAMENTO DE CINEMA
════════════════════════════════════════

1. Gerenciar Filmes
2. Gerenciar Salas
3. Gerenciar Sessões
4. Sair

Escolha uma opção: _
```

### 1️⃣ Gerenciar Filmes

```
────────────────────────────────────────
         GERENCIAMENTO DE FILMES
────────────────────────────────────────

1. Incluir Filme
2. Alterar Filme
3. Excluir Filme
4. Listar Todos os Filmes
5. Voltar ao Menu Principal

Escolha uma opção: _
```

**Exemplo de Cadastro:**
```
═══ Incluir Novo Filme ═══
Título: Avatar: O Caminho da Água
Gênero: Ficção Científica
Duração (minutos): 192
Classificação: 12 anos
Sinopse: Continuação da saga Avatar...

✓ Filme cadastrado com sucesso!
```

### 2️⃣ Gerenciar Salas

```
────────────────────────────────────────
         GERENCIAMENTO DE SALAS
────────────────────────────────────────

1. Incluir Sala
2. Alterar Sala
3. Excluir Sala
4. Listar Todas as Salas
5. Voltar ao Menu Principal

Escolha uma opção: _
```

**Exemplo de Cadastro:**
```
═══ Incluir Nova Sala ═══
Número da Sala: 1
Capacidade: 150
Tipo de Projeção: IMAX 3D
Status: Ativa

✓ Sala cadastrada com sucesso!
```

### 3️⃣ Gerenciar Sessões

```
────────────────────────────────────────
        GERENCIAMENTO DE SESSÕES
────────────────────────────────────────

1. Incluir Sessão
2. Alterar Sessão
3. Excluir Sessão
4. Listar Todas as Sessões
5. Voltar ao Menu Principal

Escolha uma opção: _
```

**Exemplo de Cadastro:**
```
═══ Incluir Nova Sessão ═══
Filme: [Selecionar da lista]
Sala: [Selecionar da lista]
Data: 25/01/2026
Horário: 19:30
Preço: R$ 35,00

✓ Sessão criada com sucesso!
```

## 📊 Estruturas de Dados

### Estrutura Filme

```c
typedef struct {
    int id;
    char titulo[100];
    char genero[50];
    int duracao;            // em minutos
    int classificacao;      // idade mínima
    char sinopse[500];
    int ativo;              // 1 = ativo, 0 = inativo
} Filme;
```

### Estrutura Sala

```c
typedef struct {
    int numero;
    int capacidade;
    char tipo_projecao[20]; // 2D, 3D, IMAX
    int status;             // 1 = ativa, 0 = manutenção
} Sala;
```

### Estrutura Sessão

```c
typedef struct {
    int id;
    int id_filme;
    int numero_sala;
    char data[11];          // formato: DD/MM/AAAA
    char horario[6];        // formato: HH:MM
    float preco;
    int ingressos_disponiveis;
} Sessao;
```

## 🔧 Makefile

O projeto inclui um Makefile para facilitar a compilação:

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = main
SOURCES = src/main.c src/filme.c src/sala.c src/sessao.c src/utils.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
```

### Comandos Make Disponíveis

```bash
make          # Compila o projeto
make clean    # Remove arquivos compilados
make run      # Compila e executa
make all      # Compila tudo (padrão)
```

## 💾 Persistência de Dados

Os dados são salvos em arquivos binários na pasta `data/`:

- **filmes.dat**: Armazena todos os filmes cadastrados
- **salas.dat**: Armazena todas as salas cadastradas
- **sessoes.dat**: Armazena todas as sessões programadas

### Funções de Persistência

```c
// Salvar dados
void salvar_filmes(Filme *filmes, int quantidade);
void salvar_salas(Sala *salas, int quantidade);
void salvar_sessoes(Sessao *sessoes, int quantidade);

// Carregar dados
int carregar_filmes(Filme *filmes);
int carregar_salas(Sala *salas);
int carregar_sessoes(Sessao *sessoes);
```

## 🎯 Exemplo de Fluxo Completo

### Cenário: Programar uma Sessão de Cinema

```bash
# 1. Executar o programa
./main

# 2. Cadastrar um filme
[Menu Principal] → 1. Gerenciar Filmes
[Filmes] → 1. Incluir Filme
Título: Oppenheimer
Gênero: Drama/Biografia
Duração: 180
Classificação: 14
✓ Filme cadastrado!

# 3. Cadastrar uma sala
[Menu Principal] → 2. Gerenciar Salas
[Salas] → 1. Incluir Sala
Número: 3
Capacidade: 200
Tipo: IMAX
✓ Sala cadastrada!

# 4. Criar sessão
[Menu Principal] → 3. Gerenciar Sessões
[Sessões] → 1. Incluir Sessão
Filme: Oppenheimer
Sala: 3
Data: 26/01/2026
Horário: 20:00
Preço: 45,00
✓ Sessão criada!

# 5. Listar sessões
[Sessões] → 4. Listar Todas as Sessões

═══ SESSÕES PROGRAMADAS ═══
ID: 001
Filme: Oppenheimer
Sala: 3 (IMAX - 200 lugares)
Data/Hora: 26/01/2026 às 20:00
Preço: R$ 45,00
Ingressos disponíveis: 200
```

## 🛡️ Tratamento de Erros

O sistema inclui validações para:

- ✅ Entrada de dados inválidos
- ✅ Capacidade de salas excedida
- ✅ Horários conflitantes de sessões
- ✅ IDs duplicados
- ✅ Arquivos de dados corrompidos
- ✅ Memória insuficiente

```c
// Exemplo de validação
if (filme.duracao <= 0) {
    printf("❌ Erro: Duração deve ser positiva!\n");
    return ERRO_VALIDACAO;
}

if (sala.capacidade > MAX_CAPACIDADE) {
    printf("❌ Erro: Capacidade excede o limite!\n");
    return ERRO_CAPACIDADE;
}
```

## 🤝 Contribuindo

Contribuições são bem-vindas! Siga estas etapas:

### 1. Fork do Repositório

```bash
# Clique em "Fork" no GitHub ou use:
gh repo fork Bruno-GabrielDev/projeto-cinema
```

### 2. Criar Branch de Feature

```bash
git checkout -b feature/minha-contribuicao
```

### 3. Fazer Alterações

- Siga o padrão de código existente
- Adicione comentários em português
- Teste suas alterações

### 4. Commit das Mudanças

```bash
git add .
git commit -m "feat: adiciona funcionalidade X"
```

**Padrão de Commits:**
- `feat:` Nova funcionalidade
- `fix:` Correção de bug
- `docs:` Atualização de documentação
- `refactor:` Refatoração de código
- `test:` Adição de testes

### 5. Push da Branch

```bash
git push origin feature/minha-contribuicao
```

### 6. Abrir Pull Request

1. Vá para o repositório original no GitHub
2. Clique em "New Pull Request"
3. Selecione sua branch
4. Descreva suas alterações
5. Aguarde revisão

## 📈 Melhorias Futuras

Possíveis expansões do sistema:

- [ ] Sistema de venda de ingressos
- [ ] Reserva online de assentos
- [ ] Relatórios de bilheteria
- [ ] Integração com APIs de filmes (TMDb)
- [ ] Sistema de descontos e promoções
- [ ] Múltiplos cinemas
- [ ] Histórico de sessões passadas
- [ ] Estatísticas de ocupação
- [ ] Interface gráfica (GTK/Qt)
- [ ] Versão web (CGI)
- [ ] Banco de dados SQL
- [ ] Sistema de login de funcionários

## 🐛 Problemas Conhecidos

- [ ] Limitação de 100 filmes simultâneos
- [ ] Sem validação de conflito de horários
- [ ] Arquivos binários não portáveis entre sistemas

## 📝 Licença

Este projeto está licenciado sob a **Licença MIT**.

```
MIT License

Copyright (c) 2024 Bruno Gabriel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## 👨‍💻 Autor

**Bruno Gabriel**
- Estudante de Engenharia de Software - IFSP São Carlos
- GitHub: [@Bruno-GabrielDev](https://github.com/Bruno-GabrielDev)


## 🙏 Agradecimentos

- Desenvolvido como projeto acadêmico de Algoritmos e Estruturas de Dados
- Inspirado em sistemas reais de gerenciamento de cinemas
- Agradecimentos aos professores e colegas por feedback e sugestões

## 📚 Referências

- **The C Programming Language** - Brian W. Kernighan, Dennis M. Ritchie
- **C: A Reference Manual** - Samuel P. Harbison, Guy L. Steele Jr.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)

---

<div align="center">
  
**Desenvolvido em C** | Sistema de Cinema © 2024

*Programação estruturada na prática!* 🎬🍿

</div>
