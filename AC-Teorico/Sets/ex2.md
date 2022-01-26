# Stacks

Stack é uma estrutura LIFO, last in, first out. E deve ser capaz de responder às operações `push` e `pop`.

## Código

```c
typedef struct stack {
    int N;
    int sp;
    int *arr;
} *Stack;

Stack stack_new(int N) {
    Stack s = malloc(sizeof(struct stack));

    s->N = N;
    s->arr = malloc(sizeof(int)*N);
    s->sp = 0;

    return s;
}

void stack_destroy(Stack s) {
    free(s->arr);
    free(s);
}

int stack_pop(Stack s, int *v) {
    // 0 se nao conseguiu dar pop
    // 1 se consegui
    //--- se consegue, elemento fica em *v.
    int contador = 1;

    if (s->sp == 0) 
        contador = 0;
    else {
        s->sp--;
        *v = s->arr[s->sp];
    }

    return contador;
}

int stack_push(Stack s, int x) {
    int contador = 1;
    
    if (s->sp == s->N) {
        contador = 0;
    }
    else {
        s->arr[s->sp] = x;
        s->sp++;
    }

    return contador;
}

```