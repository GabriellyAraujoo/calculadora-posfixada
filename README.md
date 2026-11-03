# Calculadora Pós-fixada (RPN)

Avaliador de expressões matemáticas em **notação polonesa reversa**, escrito em C.

Na notação pós-fixada o operador vem depois dos operandos, o que dispensa parênteses:
`(3 + 4) * 5` vira `3 4 + 5 *`.

## O que este projeto demonstra

- **Avaliação por pilha.** A expressão é lida da esquerda para a direita; números são
  empilhados, e ao encontrar um operador desempilham-se dois valores, aplica-se a
  operação e o resultado volta para a pilha.
- **Tokenização com `strtok`**, separando a expressão por espaços.
- **Tratamento de operador inválido**, com mensagem ao usuário e encerramento limpo.
- **Funções transcendentais** além dos operadores aritméticos: `ln`, `log`, `sen`, `cos`
  e `tg`.

## Como executar

```bash
cc -o calculadora calculadora.c -lm
./calculadora
```

Exemplo de uso:

```
Escreva a operação posfixa: 3 4 2 * 1 5 - 2 3 ^ ^ / +
Resultado: 3.00
```

## O documento do trabalho

O arquivo `TP06-Notacao-Posfixada.docx` traz a derivação completa da conversão de
infixada para pós-fixada, com a pilha rastreada item a item:

```
3 + 4 * 2 / (1 − 5) ^ 2 ^ 3   →   3 4 2 * 1 5 - 2 3 ^ ^ / +
```

| Passo | Token | Pilha |
|---|---|---|
| 1 | `3` | `[3]` |
| 2 | `4` | `[3, 4]` |
| 3 | `2` | `[3, 4, 2]` |
| 4 | `*` | `[3, 8]` |
| 5 | `1` | `[3, 8, 1]` |
| 6 | `5` | `[3, 8, 1, 5]` |
| 7 | `-` | `[3, 8, -4]` |
| 8 | `2` | `[3, 8, -4, 2]` |
| 9 | `3` | `[3, 8, -4, 2, 3]` |
| 10 | `^` | `[3, 8, -4, 8]` |
| 11 | `^` | `[3, 8, -4, 65536]` |
| 12 | `/` | `[3, 0.00012207]` |
| 13 | `+` | `[3.00012207]` |

## Operadores aceitos

| Token | Operação |
|---|---|
| `+` `-` `*` `/` | aritmética básica |
| `^` | potência |
| `ln` | logaritmo natural |
| `log` | logaritmo base 10 |
| `sen` `cos` `tg` | trigonometria em graus |

## Estrutura

```
calculadora.c                     # avaliação pós-fixada com pilha
TP06-Notacao-Posfixada.docx       # derivação da conversão, com a pilha rastreada
```
