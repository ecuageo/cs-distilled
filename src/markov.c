enum {
  NPREF = 2,       /* number of prefix words */
  NHASH = 4093,    /* size of state hash table array */
  MAXGEN = 10000   /* maximum words generated */
};

typedef struct State State;
typedef struct Suffix Suffix;

struct State {
  char *pref[NPREF];
  Suffix *suf;
  State *next;
};

struct Suffix {
  char *word;
  Suffix *next;
}

const int MULTIPLIER = 31;  /* for hash() */

unsigned int hash(char *s[NPREF])
{
  unsigned int h;
  unsigned char *p;

  h = 0;
  for (int i = 0; i < NPREF; i++)
    for (p = (unsigned char *)s[i]; *p != '\0'; p++)
      h = MULTIPLIER * h + *p;
  return h % MULTIPLIER;
}

/* lookup: search for prefix; create if requested. */
/* returns pointer if present or created; NULL if not. */
/* creation doesn't strdup so strings mustn't change later. */
State *lookup(char *prefix[NPREF], int create)
{
  int i;
  State *sp;

  int h = hash(prefix);
  for (sp = statetab[h]; sp != NULL; sp = sp->next) {
    for (i = 0; i < NPREF; i++)
      if (strcmp(prefix[i], sp->pref[i]) != 0)
        break;
    if (i == NPREF)
      return sp;
  }

  if (create) {
    sp = (State *)malloc(sizeof(State));
    for (i = 0; i < NPREF; i++)
      sp->pref[i] = prefix[i];
    sp->suf = NULL;
    sp->next = statetab[h];
    statetab[h] = sp;
  }
  return sp;
}

/* build: read input, build prefix table */
void build(char *prefix[NPREF], FILE *f)
{
  char buf[100], fmt[10];

  /* create a format string; %s could overflow but */
  sprintf(fmt, "%%%ds", sizeof(buf)-1);
  while (fscanf(f, fmt, buf) != EOF)
    add(prefix, estrdup(buf));
}

/* add: add word to suffix list, update prefix */
void add(char *prefix[NPREF], char *suffix)
{
  State *sp;

  sp = lookup(prefix, 1);
  addsuffix(sp, suffix);
  /* move the words down the prefix */
  memmove(prefix, prefix+1, (NPREF-1) * sizeof(prefix[0]));
  prefix[NPREF-1] = suffix;
}

/* addsuffix: add to state. suffix must not change later */
void addsuffix(State *sp, char *suffix)
{
  Suffix *suf;

  suf = (Suffix *)malloc(sizeof(Suffix));
  suf->word = suffix;
  suf->next = sp->suf;
  sp->suf = suf;
}
