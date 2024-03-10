// Implement a Set data structure
// Does not allow duplicates
// Does not matter order of elements
// Implements the following operations: 
// contains, is_empty, insert, remove, union, inter, print, is_subset.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *elements;
  int length;
  int capacity;
} Set;

Set *new_set(int capacity) {
  Set *set = malloc(sizeof(Set));
  set->capacity = capacity;
  set->elements = malloc(capacity * sizeof(int));
  set->length = 0;

  return set;
}

bool is_empty_set(Set *set) {
  return set->length == 0;
}

bool contains_set(Set *set, int element) {
  for(int i = 0; i< set->length; i++)
    if(set->elements[i] == element) return true;

  return false;
}

void print_set(Set *set) {
  printf("Set: {");
  for(int i = 0; i < set->length; i++) {
    printf("%d", set->elements[i]);
    if(i < set->length -1) printf(", ");
  }

  printf("}\n");
} 

Set *insert_set(Set *set, int element) {
  for(int i = 0; i < set->length; i++)
    if(set->elements[i] == element) return set;

  if(set->length == set->capacity) {
    set->capacity *= 2;
    set->elements = realloc(set->elements, set->capacity * sizeof(char*));
  }

  set->elements[set->length] = element;
  set->length++;

  return set;
}

Set *remove_set(Set *set, int element) {
  Set *set_copy = new_set(set->capacity);
  if(contains_set(set, element)) {
    for(int i = 0; i < set->length; i++) {
      if(set->elements[i] != element) insert_set(set_copy, set->elements[i]);
    }
  } else {
    return set;
  }

  *set = *set_copy;

  return set;
}

Set *union_set(Set *setA, Set *setB) {
  Set *set_copy = new_set(setA->capacity);
  for(int i = 0; i < setA->length; i++) insert_set(set_copy, setA->elements[i]);
  for(int i = 0; i < setB->length; i++) insert_set(set_copy, setB->elements[i]);
  
  return set_copy;
}

Set *inter_set(Set *setA, Set *setB) {
  Set *set_copy = new_set(setA->capacity);
  for(int i = 0; i < setA->length; i++) {
    for(int j = 0; j < setB->length; j++) {
      if(contains_set(setB, setA->elements[j])) insert_set(set_copy, setA->elements[j]);
    }
  }

  return set_copy;
}

bool is_subset(Set *setA, Set *setB) {
  if(setA->length > setB->length) return false;

  for(int i = 0; i < setA->length; i++) {
    if(!contains_set(setB, setA->elements[i])) return false;
  }

  return true;
}

int main() {
  Set *setA = new_set(5);
  printf("SetA is empty? %s\n", is_empty_set(setA) ? "true" : "false");
  insert_set(setA, 1);
  insert_set(setA, 2);
  insert_set(setA, 3);
  insert_set(setA, 4);
  insert_set(setA, 5);
  insert_set(setA, 6);
  insert_set(setA, 1);
  insert_set(setA, 6);
  printf("After insert:\n");
  print_set(setA);

  printf("SetA contains 1? %s\n", contains_set(setA, 1) ? "true" : "false");
  printf("SetA contains 5? %s\n", contains_set(setA, 5) ? "true" : "false");

  printf("After remove:\n");
  remove_set(setA, 1);
  remove_set(setA, 5);
  print_set(setA);

  printf("SetA contains 1? %s\n", contains_set(setA, 1) ? "true" : "false");
  printf("SetA contains 5? %s\n", contains_set(setA, 5) ? "true" : "false");

  printf("After union: \n");
  Set *setB = new_set(5);
  insert_set(setB, 1);
  insert_set(setB, 2);
  insert_set(setB, 3);
  insert_set(setB, 7);
  insert_set(setB, 8);
  printf("SetA: ");
  print_set(setA);
  printf("SetB: ");
  print_set(setB);
  printf("A Union B:");
  Set *unionAB = union_set(setA, setB);
  print_set(unionAB);

  printf("After intersection: \n");
  printf("SetA: ");
  print_set(setA);
  printf("SetB: ");
  print_set(setB);
  printf("A Intersection B:");
  Set *interAB = inter_set(setA, setB);
  print_set(interAB);

  printf("is_subset\n");
  printf("SetA: ");
  print_set(setA);
  printf("SetB: ");
  print_set(setB);
  printf("A is subset of B? %s\n", is_subset(setA, setB) ? "true" : "false");
  printf("A is subset of AB? %s\n", is_subset(setA, unionAB) ? "true" : "false");
  printf("B is subset of AB? %s\n", is_subset(setB, unionAB) ? "true" : "false");
}