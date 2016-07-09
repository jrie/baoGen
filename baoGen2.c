#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int startPieces = 32;
  int fields = 16;
  int playboardsToCreate = 10;

  // Command parsing
  if (argc > 1) {
    for (int i = 1; i < argc; ++i) {
      char *data[255];
      if (argv[i][0] == 'p') {
        startPieces = strtol(argv[i]+1, data, 10);
      } else if (argv[i][0] == 'b') {
        playboardsToCreate = strtol(argv[i]+1, data, 10);
      } else if (argv[i][0] == 'f') {
        fields = strtol(argv[i]+1, data, 10);
      } else {
        printf("[ERROR] Unknown command: '%s'\nUse the switches 'p', 'b' or 'f' in combinations.\n\nLike\n'p12': 12 Game pieces\n'b10': 10 Playboards\n'f16': 16 fields.\n\n", argv[i]);
        return 1;
      }
    }
  }

  // Error messages
  if (fields % 2 != 0) {
    printf("[ERROR] Fields dont align by 2.\n");
    return 1;
  } else if (fields < 4) {
    printf("[ERROR] Cant create playboards with less than 4 fields.\n");
    return 1;
  } else if (fields > 32) {
    printf("[ERROR] Dont want to create playboards with more than 32 fields. Buy the full edition to continue!\n");
    return 1;
  }

  if (startPieces < 4) {
    printf("[ERROR] Need at least 4 gaming pieces to operate\n");
    return 1;
  } else if (startPieces > fields * 3) {
    printf("[ERROR] Too many gaming pieces, cannot be more than 3 times the fields.\n");
    return 1;
  }

  if (playboardsToCreate < 0) {
    printf("[ERROR] Need at one playboard to generate, canceling.\n");
    return 1;
  } else if (playboardsToCreate > 100) {
    printf("[ERROR] Too many playboards, in shareware, I generate only 100 a time! We are sorry.\n");
    return 1;
  }

  // Generate the playboards
  FILE *playboardStore = fopen("playboard.csv", "w");
  if (playboardStore == NULL) {
    printf("[ERROR] Cannot open 'playboard.csv' for writing playboard data.\n");
    return 1;
  }

  // Init after errors
  int generatedPlayboards = 0;
  char data[64];

  int rows = fields / 2;
  int playboard[2][fields];
  int pieces[2];

  srand(time(NULL) + clock());

  // Playboard setup, filling and output
  while (playboardsToCreate--) {
    generatedPlayboards++;

    // Generate the playboard
    printf("\nPlayboard #%d\n\n", generatedPlayboards);

    for (int player = 0; player < 2; ++player) {
      memset(playboard[player], 0, sizeof(int) * fields);
      pieces[player] = startPieces;

      for (int j = 0; j < startPieces; j++) {
        int field = rand() % fields;
        ++playboard[player][field];
        --pieces[player];
      }

      for (int i = 1, j = 0; j < fields; ++j) {
        if ((j+1) < (i*rows)) {
          printf("%d;", playboard[player][j]);
          sprintf(data, "%d;", playboard[player][j]);
          fputs(data, playboardStore);
        } else {
          printf("%d", playboard[player][j]);
          sprintf(data, "%d", playboard[player][j]);
          fputs(data, playboardStore);

          printf("\n");
          fputc('\n', playboardStore);
          ++i;
        }
      }

      printf("Pieces left: %d left of %d\n\n", pieces[player], startPieces);
    }

    fputc('\n', playboardStore);
  }

  fclose(playboardStore);
}
