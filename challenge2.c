//Counting Occurrences Of A Word In A String

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char **words;
  int size;
} Array;

Array *new_array() {
  Array *array = malloc(sizeof(Array));
  array->words = malloc(5 * sizeof(char *));
  array->size = 0;

  return array;
}

Array *add_word(Array *array, char *word) {
  if(array->size == 5) {
    array->words = realloc(array->words, array->size * 2 * sizeof(char *));
  }

  array->size++;
  array->words[array->size - 1] = word;

  return array;
}

Array *split(char *string) {
  char *word = malloc(100 * sizeof(char));
  Array *result = new_array();
  int i = 0;
  int word_index = 0;

  while(string[i] != '\0') {
    if(string[i] == ' ') {
      word[word_index] = '\0';
      add_word(result, word);
      word = malloc(100 * sizeof(char));
      word_index = 0;
    }
    else {
      word[word_index] = string[i];
      word_index++;
    }
    
    i++;
  }

  if(word_index > 0) {
    word[word_index] = '\0';
    add_word(result, word);
  }

  return result;
}

int count_occurrences(char *string, char *word) {
  int count = 0;
  Array *splitted_str = split(string);
  for(int i = 0; i < splitted_str->size; i++) {
    if(strcmp(splitted_str->words[i], word) == 0) {
      count++;
    }
  }

  return count;
}

int main() {
  int result = count_occurrences("abc def ghi jkl mno pqr stu vwx yz abc", "jkl");
  printf("The word abc occurs %d times \n", result);

  return 0;
}