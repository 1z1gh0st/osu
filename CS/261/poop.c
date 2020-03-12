#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct poop {
    int value;
};

struct poop* allocate(int n) {
    struct poop *result = (struct poop*) malloc(n * sizeof(struct poop));
    return result;
}

void generate(struct poop *p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        p[i].value = i * i;
    }
}

void print_em(struct poop *p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\n", p[i].value);
    }
}

void access_poop(struct poop **p, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d", i);
        p[i]->value = 0;
    }
}

int main() {
    struct poop *poop_ptr = allocate(10);
    generate(poop_ptr, 10);
    print_em(poop_ptr, 10);
    printf("meow\n");
    struct poop **ptr_ptr = &poop_ptr;
    printf("woof\n");
    print_em(poop_ptr, 10);
    access_poop(&poop_ptr, 10);
    
}