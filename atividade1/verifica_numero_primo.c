#include <stdio.h>
#include <stdlib.h>

int main() {
    int number;
    printf("Digite um numero: ");
    scanf("%d", &number);

    if (number <= 1) {
        printf("0 - O numero nao eh primo.\n");
        return 0;
    }

    int is_prime = 1;

    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            is_prime = 0;
            break;
        }
    }

    if (is_prime) {
        printf("1 - O numero eh primo.\n");
    } else {
        printf("0 - O numero nao eh primo.\n");
    }

    return 0;
}

