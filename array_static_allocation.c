// Statically allocate memory for an array of strings that the user will input.

#include <stdio.h>
#include <stdlib.h>

int main() {
  char **strings;
  int len_strings;

  printf("Enter the number of strings: \n");
  scanf("%d", &len_strings);
  printf("len_strings: %d\n", len_strings);

  strings = malloc(len_strings * sizeof(char *));
  printf("The strings are: %p\n", strings);

  for(int i = 0; i < len_strings; i++)
  {
    printf("Enter string %d: ", i);
    scanf("%s", strings[i]);
  }

  free(strings);

  return 0;
}