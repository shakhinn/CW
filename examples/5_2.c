#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int func1(const void* a, const void* b){
    char aa = *(char*)a;
    char bb = *(char*)b;
    if(aa > bb){
        return 1;
    } if(aa < bb) return -1;
    return 0;
}

int func2(const void* a, const void* b){
    int aa = *(int*)a;
    int bb = *(int*)b;
    if(aa > bb){
        return 1;
    } if(aa < bb) return -1;
    return 0;
}

int func3(const void* a, const void* b){
    double aa = *(double*)a;
    double bb = *(double*)b;
    if(aa - bb > 0)
        return 1;
    if(fabs(aa - bb) <= 0.0001)
        return 0;
    if(aa - bb < 0)
        return -1;

}

int universalMax(void* arr, int array_length, int size_of_element, int (*func)(const void*, const void*)){
    int res = 0;
    void* min = arr;
    for(int i = 0; i < array_length; i++){
        if(func(arr + i*size_of_element, min) > 0){
            res = i;
            min = arr + i*size_of_element;
        }
    }
    return res;
}

int main(){
    int c;
    char* arrc = malloc(20* sizeof(char));
    int* arrint =  malloc(20* sizeof(int));
    double * arrd = malloc(20* sizeof(double));
    scanf("%d", &c);
    switch (c){
        case 1:
            for (int i = 0; i < 20; i++) {
                scanf(" %c", &arrc[i]);
            }
            int ans = universalMax(arrc, 20, 1, func1);
            printf("%d", ans);
            return 0;
        case 4:
            for (int i = 0; i < 20; i++){
                scanf("%d", &arrint[i]);
            }
            int ans1 = universalMax(arrint, 20, 4, func2);
            printf("%d", ans1);
            return 0;
        case 8:
            for (int i = 0; i < 20; i++){
                scanf("%lf", &arrd[i]);
            }
            int ans2 = universalMax(arrc, 20, 8, func3);
            printf("%d", ans2);
            return 0;

    }
    free(arrc);
    free(arrd);
    free(arrint);
    return 0;
}
