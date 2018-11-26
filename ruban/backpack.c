#include <stdio.h>
#include <stdlib.h>

#define WEIGHT_PACK 221
#define NUM_PRODUCT 3

struct product {
    int name;
    int weight;
    int price;
};

int max(int, int);
void show(int[]);
void path(int[], struct product[]);

int main(int argc, char const *argv[]) {
    struct product array[NUM_PRODUCT];
    printf("N->Price - Weight\n");
    for(int i = 0; i < NUM_PRODUCT; i++) {
        array[i].name = i + 1;
        array[i].price = 5 + i * 2;
        array[i].weight = i + 3;
        printf("%d->%5d - %6d\n", array[i].name, array[i].price, array[i].weight);
    }

    int try_my[WEIGHT_PACK + 1];
    try_my[0] = 0;
    for(int weight = 1; weight < WEIGHT_PACK; weight++) {
        try_my[weight] = try_my[weight - 1];
        for(int i = 0; i < NUM_PRODUCT; i++) {
            if(array[i].weight <= weight)
                try_my[weight] = max(try_my[weight], try_my[weight - array[i].weight] + array[i].price);
        }
    }
    show(try_my);
    path(try_my,array);
}

int max(int a, int b) {
    if(a < b)
        return b;
    else return a;
}

void show(int try_my[]) {
    printf("     W -> Price\n");
    for(int i = 0; i < WEIGHT_PACK; i++) {
        printf("%6d -> %5d\n", i, try_my[i]);
    }
}   

void path(int my[], struct product prod[]) {
    int index = WEIGHT_PACK - 1;
    int new_index = index - 1;
    printf("\nPath\nProd->Price\n");
    while(new_index >= 0) {
        for(int i = NUM_PRODUCT - 1; i >= 0; i--) {
            if((my[index] - prod[i].price) == my[new_index]) {
                printf("%4d->%5d\n", prod[i].name, prod[i].price);
                index = new_index;
                new_index--;
            }
        }
        new_index--;
    }
    
}
