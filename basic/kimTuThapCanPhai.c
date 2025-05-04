#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Type a number: ");
    scanf("%d", &x);
    printf("%d\n", x);
    for (int i = 0; i < x; i++) {
      for (int j = 1; j < x-i; j++){
        printf("%c", ' ');
      }
      for (int j = 0; j <= i; j++){
        printf("%c", '*');
      }
      printf("\n");
    }

    return 0;
}
