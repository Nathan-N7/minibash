# Tokenização para o Parser da Minishell

## Objetivo
A tokenização é a primeira etapa do parser da minishell. O objetivo é transformar a entrada do usuário (linha de comando) em uma sequência de tokens estruturados, que serão posteriormente analisados e executados.

## Tarefas a serem implementadas

### 1. Leitura e Segmentação
- Capturar a entrada do usuário.
- Dividir a entrada em tokens com base em espaços e operadores especiais.

### 2. Identificação de Tokens
- Diferenciar tipos de tokens, incluindo:
  - **Palavras** (comandos, argumentos, variáveis de ambiente).
  - **Operadores** (`|`, `>`, `>>`, `<`, `<<`).
  - **Metacaracteres** (`"`, `'`, `\`).
  - **Espaços e tabulações** (devem ser ignorados exceto em casos específicos).

### 3. Tratamento de Casos Especiais
- **Aspas Simples e Duplas**:
  - Aspas simples (`'`) devem preservar o conteúdo exato.
  - Aspas duplas (`"`) permitem expansão de variáveis e tratamento de backslashes.
- **Redirecionamentos**:
  - Diferenciar `>`, `>>`, `<`, `<<` corretamente.
- **Pipe (`|`)**:
  - Separar comandos corretamente ao encontrar `|`.

### 4. Criação da Estrutura de Tokens
- Criar uma estrutura para armazenar cada token identificado.
- Definir os atributos principais do token:
  - Tipo (comando, argumento, operador, etc.).
  - Valor (conteúdo do token).
  - Indicação se está dentro de aspas ou não.

### 5. Construção da Lista de Tokens
- Armazenar tokens em uma estrutura de lista duplamente encadeada para facilitar a manipulação.
- Garantir a integridade da lista para que possa ser usada pelo parser.

## Próximos Passos
Após finalizar a tokenização, a próxima etapa será implementar o parser, que usará os tokens gerados para construir a estrutura de execução dos comandos da minishell.

