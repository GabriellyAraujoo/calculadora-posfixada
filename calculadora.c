#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h> 
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define MAX 100

typedef struct {
    double data[MAX];
    int top;
} Stack;

void fazPilha(Stack *stack) {
    stack->top = -1;
}

int PilhaCheia(Stack *stack) {
    return stack->top == MAX - 1;
}

int PilhaVazia(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, double value) {
    if (PilhaCheia(stack)) {
        printf("Elemento empilhado\n");
        exit(1);
    } else {
        stack->data[++stack->top] = value;
    }
}

double pop(Stack *stack) {
    if (PilhaVazia(stack)) {
        printf("Elemento desempilhado\n");
        exit(1);
    } else {
        return stack->data[stack->top--];
    }
}

double Posfixa(char* expression) {
    Stack stack;
    fazPilha(&stack);
    char *token = strtok(expression, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atof(token));
        } else if (strcmp(token, "ln") == 0) {
            double val = pop(&stack);
            push(&stack, log(val));
        } else if (strcmp(token, "log") == 0) {
            double val = pop(&stack);
            push(&stack, log10(val));
        }else if (strcmp(token, "sen") == 0) {
        double val = pop(&stack);
        push(&stack, sin(val * M_PI / 180));
        } else if (strcmp(token, "cos") == 0) {
    double val = pop(&stack);
    push(&stack, cos(val * M_PI / 180));
        } else if (strcmp(token, "tg") == 0) {
    double val = pop(&stack);
    push(&stack, tan(val * M_PI / 180));
        } else {
            double val1 = pop(&stack);
            double val2 = pop(&stack);

            switch (token[0]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
                case '^': push(&stack, pow(val2, val1)); break;
                default:
                    printf("Operador invalido\n");
                    exit(1);
            }
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

int main() {
    char expression[MAX];
    char choice;

    do {
        printf("Escreva a operação posfixa: ");
        fgets(expression, MAX, stdin);

        expression[strcspn(expression, "\n")] = 0;

        printf("Resultado: %.2f\n", Posfixa(expression));

        printf("Deseja fazer outra operação? (s/n) : ");
        choice = getchar();
        getchar();
    } while (choice == 's' || choice == 'S');

    return 0;
}