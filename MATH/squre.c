#include <math.h>
#include <stdio.h>
#include <stdlib.h>// has library for sort
#include <string.h>

#define GRIDSIZE 50
#define NUMWORDS 4
#define MAXPAIRS 200
#define MAXWORDLENGTH 20
#define MAXLEN = 20
struct pair {
  char x;
  int xloc;
  char y;
  int yloc;
  int validFlag;
};

struct word {
  struct pair *p;// pair of letters 
  char *w;
};

struct coordinate {
  int x;
  int y;
};
// pairs genereated
struct pair *generatePairs(char *word, int distance) {
  // printf("%s : %i\n", word, distance);
  struct pair *p = malloc(sizeof(struct pair) * MAXPAIRS);//allocate space for pairs, enough for 200 pairs
  int pairCount = 0;
  for (int i = 0; i < strlen(word); i++) {
    if (i + distance < strlen(word)) {
      p[pairCount].x = word[i];
      p[pairCount].xloc = i;
      p[pairCount].y = word[i + distance];
      p[pairCount].yloc = i + distance;
      p[pairCount].validFlag = 1;
      // printf("[%c, %c]\n", word[i], word[i+distance]);
      pairCount++;
    }
  }

  return p;
}
//
int solution[128];

void clearSolution() {
  for (int i = 0; i < sizeof(solution) / sizeof(solution[0]); i++)
    solution[i] = 0;
}


   

void printSolution(int squareSize, char *w1, struct pair *p1, char *w2,
                   struct pair *p2, char *w3, struct pair *p3, char *w4,
                   struct pair *p4) {// p1,p2,p3,p4 are 4 corners
  char grid[GRIDSIZE][GRIDSIZE];
    // initialize grid to white space
    for (int i = 0; i < GRIDSIZE; i++) {
        for (int j = 0; j < GRIDSIZE; j++) {
        grid[i][j] = ' ';
        }
    }


    char *words[NUMWORDS] = {w1, w2, w3, w4};
    struct pair *pairs[NUMWORDS] = {p1,p2,p3,p4}; // pair for different side len
    struct coordinate coordinates[NUMWORDS];
    int wordUsed[NUMWORDS] = {0, 0, 0, 0};// mark for placed word

    // place the first word in the center
    for (int i = 0; i < strlen(w1); i++) {
        grid[GRIDSIZE / 2 + i][GRIDSIZE / 2] = w1[i];
        }
    coordinates[0].x = GRIDSIZE / 2;
    coordinates[0].y = GRIDSIZE / 2;
    wordUsed[0] = 1;

  // find words perpendicular to the first
  for (int i = 1; i < NUMWORDS; i++) {
    if (pairs[0]->x == pairs[i]->x) {
      coordinates[i].x = GRIDSIZE / 2 + pairs[0]->xloc;
      coordinates[i].y = GRIDSIZE / 2 - pairs[i]->xloc;
      for (int j = 0; j < strlen(words[i]); j++) {
        grid[coordinates[i].x][coordinates[i].y + j] = words[i][j];
      }
      wordUsed[i] = 1;
    } else if (pairs[0]->x == pairs[i]->y) {
      coordinates[i].x = GRIDSIZE / 2 + pairs[0]->xloc;
      coordinates[i].y = GRIDSIZE / 2 - pairs[i]->yloc;
      for (int j = 0; j < strlen(words[i]); j++) {
        grid[coordinates[i].x][coordinates[i].y + j] = words[i][j];
      }
      wordUsed[i] = 1;

    } else if (pairs[0]->y == pairs[i]->x) {
      coordinates[i].x = GRIDSIZE / 2 + pairs[0]->yloc;
      coordinates[i].y = GRIDSIZE / 2 - pairs[i]->xloc;
      for (int j = 0; j < strlen(words[i]); j++) {
        grid[coordinates[i].x][coordinates[i].y + j] = words[i][j];
      }
      wordUsed[i] = 1;
    } else if (pairs[0]->y == pairs[i]->y) {
      coordinates[i].x = GRIDSIZE / 2 + pairs[0]->yloc;
      coordinates[i].y = GRIDSIZE / 2 - pairs[i]->yloc;
      for (int j = 0; j < strlen(words[i]); j++) {
        grid[coordinates[i].x][coordinates[i].y + j] = words[i][j];
      }
      wordUsed[i] = 1;
    }
  }

  // which is the last word?
  int lastWord;
  for (int i = 0; i < NUMWORDS; i++) {
    if (!wordUsed[i]) {
      lastWord = i;
    }
    // printf("%s [%i, %i]\n",words[i],coordinates[i].x,coordinates[i].y);
  }

  // write last word
  int backwardsFlag = 0;
  for (int i = 0; i < NUMWORDS; i++) {
    if (!(lastWord == i) && wordUsed[lastWord] == 0) {
      if (pairs[lastWord]->x == pairs[i]->x) {
        coordinates[lastWord].x = coordinates[i].x - pairs[lastWord]->xloc;
        coordinates[lastWord].y = coordinates[i].y + pairs[i]->xloc;
        // printf("coordinates for %s are: [%i, %i]",words[lastWord],
        // coordinates[lastWord].x, coordinates[lastWord].y);

        for (int j = 0; j < strlen(words[lastWord]); j++) {
          if ((grid[coordinates[lastWord].x + j][coordinates[lastWord].y] !=
                   ' ' &&
               grid[coordinates[lastWord].x + j][coordinates[lastWord].y] !=
                   words[lastWord][j]) ||
              (grid[coordinates[lastWord].x + j][coordinates[lastWord].y] ==
                   ' ' &&
               (j == pairs[lastWord]->xloc || j == pairs[lastWord]->yloc))) {
            backwardsFlag = 1;
          }
          grid[coordinates[lastWord].x + j][coordinates[lastWord].y] =
              words[lastWord][j];
        }
        wordUsed[lastWord] = 1;
      } else if (pairs[lastWord]->x == pairs[i]->y) {
        coordinates[lastWord].x = coordinates[i].x - pairs[lastWord]->xloc;
        coordinates[lastWord].y = coordinates[i].y + pairs[i]->yloc;
        // printf("coordinates for %s are: [%i, %i]",words[lastWord],
        // coordinates[lastWord].x, coordinates[lastWord].y);
        for (int j = 0; j < strlen(words[lastWord]); j++) {
          if ((grid[coordinates[lastWord].x + j][coordinates[lastWord].y] !=
                   ' ' &&
               grid[coordinates[lastWord].x + j][coordinates[lastWord].y] !=
                   words[lastWord][j]) ||
              (grid[coordinates[lastWord].x + j][coordinates[lastWord].y] ==
                   ' ' &&
               (j == pairs[lastWord]->xloc || j == pairs[lastWord]->yloc))) {
            backwardsFlag = 1;
          }
          grid[coordinates[lastWord].x + j][coordinates[lastWord].y] =
              words[lastWord][j];
        }
        wordUsed[lastWord] = 1;

      } else if (pairs[lastWord]->y == pairs[i]->x) {
        coordinates[lastWord].x = coordinates[i].x - pairs[lastWord]->yloc;
        coordinates[lastWord].y = coordinates[i].y + pairs[i]->xloc;
        // printf("coordinates for %s are: [%i, %i]",words[lastWord],
        // coordinates[lastWord].x, coordinates[lastWord].y);
        for (int j = 0; j < strlen(words[lastWord]); j++) {
          if ((grid[coordinates[lastWord].x + j][coordinates[lastWord].y] !=
                   ' ' &&
               grid[coordinates[lastWord].x + j][coordinates[lastWord].y] !=
                   words[lastWord][j]) ||
              (grid[coordinates[lastWord].x + j][coordinates[lastWord].y] ==
                   ' ' &&
               (j == pairs[lastWord]->xloc || j == pairs[lastWord]->yloc))) {
            backwardsFlag = 1;
          }
          grid[coordinates[lastWord].x + j][coordinates[lastWord].y] =
              words[lastWord][j];
        }
        wordUsed[lastWord] = 1;
      } else if (pairs[lastWord]->y == pairs[i]->y) {
        coordinates[lastWord].x = coordinates[i].x - pairs[lastWord]->yloc;
        coordinates[lastWord].y = coordinates[i].y + pairs[i]->yloc;
        // printf("coordinates for %s are: [%i, %i]",words[lastWord],
        // coordinates[lastWord].x, coordinates[lastWord].y);
        for (int j = 0; j < strlen(words[lastWord]); j++) {
          if ((grid[coordinates[lastWord].x + j][coordinates[lastWord].y] !=
                   ' ' &&
               grid[coordinates[lastWord].x + j][coordinates[lastWord].y] !=
                   words[lastWord][j]) ||
              (grid[coordinates[lastWord].x + j][coordinates[lastWord].y] ==
                   ' ' &&
               (j == pairs[lastWord]->xloc || j == pairs[lastWord]->yloc))) {
            backwardsFlag = 1;
          }
          grid[coordinates[lastWord].x + j][coordinates[lastWord].y] =
              words[lastWord][j];
        }
        wordUsed[lastWord] = 1;
      }
    }
  }

  // print grid
  if (!backwardsFlag) {
    for (int i = 0; i < GRIDSIZE; i++) {
      for (int j = 0; j < GRIDSIZE; j++) {
        printf("%c", grid[i][j]);
      }
      printf("\n");
    }
  }
}

int compare(string str1, string str2){
   if(str1.length() < str2.length())
   return 1;
   return 0;
}

int main(int argc, char **argv) {

    sort(argv, argv + 4, compare);
  // printf("You have entered %i arguments:\n",argc);

  struct word arr[argc - 1];

  // initialize words
  int maxWordLength = 0;
  for (int i = 1; i < argc; ++i) {
    // printf("%s\n",argv[i]);
    arr[i - 1].w = argv[i];
    if (strlen(argv[i]) > maxWordLength) {
      maxWordLength = strlen(argv[i]);
    }
  }

  // foreach distance
  for (int i = 1; i < maxWordLength; ++i) {
    for (int j = 0; j < NUMWORDS; j++) {
      arr[i - 1].p = generatePairs(argv[i], 1);
    }
  }
for( int squareSize = 0; squareSize < strlen( argv[0]); squareSize++){
  // distance of 1
  for (int i = 0; i < MAXPAIRS; i++) {
    for (int j = 0; j < MAXPAIRS; j++) {
      for (int k = 0; k < MAXPAIRS; k++) {
        for (int l = 0; l < MAXPAIRS; l++) {
          if (arr[0].p1[i].validFlag == 1 && arr[1].p1[j].validFlag == 1 &&
              arr[2].p1[k].validFlag == 1 && arr[3].p1[l].validFlag == 1) {
            /*printf("[%c, %c], [%c, %c], [%c, %c], [%c, %c]\n",
                arr[0].p1[i].x, arr[0].p1[i].y,
                arr[1].p1[j].x, arr[1].p1[j].y,
                arr[2].p1[k].x, arr[2].p1[k].y,
                arr[3].p1[l].x, arr[3].p1[l].y);
            */
            solution[(int)arr[0].p1[i].x] += 1;
            solution[(int)arr[0].p1[i].y] += 1;
            solution[(int)arr[1].p1[j].x] += 1;
            solution[(int)arr[1].p1[j].y] += 1;
            solution[(int)arr[2].p1[k].x] += 1;
            solution[(int)arr[2].p1[k].y] += 1;
            solution[(int)arr[3].p1[l].x] += 1;
            solution[(int)arr[3].p1[l].y] += 1;

            int solutionValidFlag = 0;
            for (int m = 0; m < 128; m++) {
              if (solution[m] > 0) {
                // printf("%c = %i, ",m,solution[m]);
                if (solution[m] % 2 == 0) {
                  solutionValidFlag = 1;
                } else {
                  solutionValidFlag = 0;
                  break;
                }
              }
            }
            if (solutionValidFlag) {
              // printf(" -- Eureka! Solution is valid! Square of Size 1:\n");
              /*printf("%s [%c, %c], %s [%c, %c], %s [%c, %c], %s [%c, %c]\n",
                  arr[0].w, arr[0].p1[i].x, arr[0].p1[i].y,
                  arr[1].w, arr[1].p1[j].x, arr[1].p1[j].y,
                  arr[2].w, arr[2].p1[k].x, arr[2].p1[k].y,
                  arr[3].w, arr[3].p1[l].x, arr[3].p1[l].y);*/
              printSolution(i, arr[0].w, &arr[0].p1[i], arr[1].w, &arr[1].p1[j],
                            arr[2].w, &arr[2].p1[k], arr[3].w, &arr[3].p1[l]);
            }
            // printf("\n");
            clearSolution();
          }
        }
      }
    }
  }

}
  return 0;
}
