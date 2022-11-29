#include <stdio.h>
#include "my_mat.h"

int main() {

    char x;
    scanf("%s", &x);
    while (x != 'D') {
        if (x == 'A') initMatrix();
        else if (x == 'B') {
            size_t i, j;
            scanf("%zd", &i);
            scanf("%zd", &j);
            int flag = isPathAvailable(i, j);
            if (flag) printf("True");
            else printf("False");
        } else if (x == 'C') {
            size_t i, j;
            scanf("%zd", &i);
            scanf("%zd", &j);
            int shortest = findShortest(i,j);
            printf("%d", shortest);
        }
        scanf("%s", &x);
    }
    return 0;
}
