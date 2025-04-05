# Tokenização para o Parser da Minishell

## Objetivo

A tokenização é a primeira etapa do parser da **minishell**. O objetivo é transformar a entrada do usuário (linha de comando) em uma sequência de **tokens estruturados**, que serão posteriormente analisados e executados pelo parser e executor da shell.

---

## Tarefas a Serem Implementadas

### 1. Leitura e Segmentação
- Capturar a entrada do usuário.
- Dividir a entrada em tokens com base em espaços e operadores especiais.

### 2. Identificação de Tokens
Diferenciar tipos de tokens, incluindo:
- **Palavras** (comandos, argumentos, variáveis de ambiente).
- **Operadores** (`|`, `>`, `>>`, `<`, `<<`).
- **Metacaracteres** (`"`, `'`, `\`).
- **Espaços e tabulações** (devem ser ignorados, exceto dentro de aspas).

### 3. Tratamento de Casos Especiais

#### Aspas Simples e Duplas:
- **Aspas simples (`'`)** devem preservar o conteúdo exatamente como está.
- **Aspas duplas (`"`)** permitem expansão de variáveis e tratamento especial de `\`.

#### Redirecionamentos:
- Diferenciar corretamente os tipos: `>`, `>>`, `<`, `<<`.

#### Pipe (`|`):
- Separar corretamente os comandos encadeados pelo operador pipe.

### 4. Criação da Estrutura de Tokens
- Criar uma estrutura para armazenar cada token identificado.
- Definir os atributos principais:
  - **Tipo** (comando, argumento, operador, etc.).
  - **Valor** (conteúdo do token).
  - **Flag indicando se está entre aspas**.

### 5. Construção da Lista de Tokens
- Armazenar tokens em uma **lista duplamente encadeada** para facilitar a manipulação.
- Garantir que a lista seja consistente para ser utilizada pelo parser.

---

## Estruturas Utilizadas

### `t_redirect`

```c
typedef struct s_redirect
{
    char    *type;
    char    *filename;
}   t_redirect;
