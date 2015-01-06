#ifndef _HASH
#define HASH

typedef struct HashElement {
  char *key;
  int value;
  HashElement *next;
} HashElement;

typedef struct Hash {
  int size;
  HashElement *elements;
};

HashElement *lookup(Hash *table, char *key); 
void insert(Hash *table, char *key, int value); 
Hash *init_hash();
void free_hash(Hash *table);
void free_element(HashElement *element);
#endif
