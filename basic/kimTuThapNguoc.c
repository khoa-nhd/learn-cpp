#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("Type a number: ");
    scanf("%d", &x);
    x = x*2;
    for (int i = 0; i < x; i=i+2) {
      // for (int j = 1; j < x-i; j=j+2){
      //   printf("%c", ' ');
      // }
      printf("%*c", (x - i)/2, " ");
      for (int j = 0; j <= i; j++){
        printf("%c", '*');
      }
      printf("\n");
    }

    return 0;
}

