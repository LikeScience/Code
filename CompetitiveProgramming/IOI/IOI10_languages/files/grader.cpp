#include "grader.h"
#include "lang.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 100

static char lang[20], lan[100][20];
static int lnum, i, n, nl, uni[N], right, tot;
static int called = 0;
int language(int L) {
  if (called) {
    printf("Duplicate language call\n");
    exit(0);
  }
  if (L < 0 || L >= 56) {
    printf("Invalid language code: %d\n", L);
    exit(0);
  }
  called = 1;
  right += (L == lnum);
  tot++;
  return lnum;
}

int main() {
  for (n = 0; 1 == scanf("%s", lang); n++) {
    if (!strcmp(lang, "??"))
      break;
    for (i = 0; i < nl && strcmp(lang, lan[i]); i++) {
    }
    strcpy(lan[i], lang);
    if (i == nl) {
      nl++;
    }
    lnum = i;
    for (i = 0; i < N; i++)
      scanf("%d,", &uni[i]);
    scanf("%*[^\n]");
    called = 0;
    excerpt(uni);
    if (!called) {
      printf("NO language call\n");
      exit(0);
    }
  }
  printf("OK\n%0.2lf\n", 100.0 * right / tot);
  return 0;
}
