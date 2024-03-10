// Dynamically Allocate Memory For An Array Of Strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
  {
    char **strings;
    int len_strings = 0;

    printf("Enter the number of strings: ");
    scanf("%d", &len_strings);
    printf("len_strings: %d\n", len_strings);

    strings = malloc(len_strings * sizeof(char *));

    for(int i = 0; i < len_strings; i++)
    {
      char *buffer = malloc(100 * sizeof(char));
      printf("Enter string %d: ", i);
      scanf("%s", buffer);
      strings[i] = malloc(sizeof(char) * (strlen(buffer) + 1));
      strings[i] = buffer;
    }

    for(int i = 0; i < len_strings; i++)
    {
      printf("String %d: %s\n", i, strings[i]);
    }

    free(strings);
    return 0;
  }