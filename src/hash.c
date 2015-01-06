#include "hash.h"
enum { starting_size = 7};

unsigned int hash(char *key, int size);
HashElement *make_element(char *key, int value);

unsigned int hash(char *key, int size)
{
  unsigned int h;
  unsigned char *p;
  h = 0;
  for (p = (unsigned char *)str; *p != '\0'; p++)
    h = 37 * h + *p;
  return h % size;
}

HashElement *lookup(Hash *table, char *key) {
  HashElement *element;

  int i = hash(key, table->size);
  element = table->elements[i];
  while (element != NULL) {
    if (strcmp(key, element->key) == 0)
      return element;
    element = element->next;
  }

  return NULL;
}

// this assumes that key has been allocated!
void insert(Hash *table, char *key, int value) {
  HashElement *element;
  int i = hash(key, table->size);
  element = table->elements[i];
  if (element == NULL) {
    element = make_element(key, value);
    table->elements[i] = element;
  } else {
    do {
      if (strcmp(element->key, key) == 0)
        element->value = value;
    } while ((element = element->next) != NULL);
  }
}

HashElement *make_element(char *key, int value)
{
  HashElement *element;

  element = (HashElement *)malloc(sizeof(HashElement));
  element->key = key;
  element->value = value;
  
  return element;
}

Hash *init_hash()
{
  Hash *table;
  table = (Hash *)malloc(sizeof(Hash));
  table->elements = malloc(sizeof(HashElement *) * starting_size);
  table->size = 7;
  return table;
}

void free_hash(Hash *table)
{
  // walk all elements and free
  HashElement *element;
  for (int i = 0; i < table->size; i++) {
    element = table->elements[i];
    while (element != NULL) {
      HashElement *temp = element;
      element = element->next;
      free_element(temp);
    }
  }
  // free elements array and table
  free(table->elements);
  free(table);
}

void free_element(HashElement *element)
{
  free(element->key);
  free(element);
}
