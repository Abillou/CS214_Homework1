#include<stdio.h>
#include<stdlib.h>

void printGrid(
  int boardX, int boardY, int plrX, int plrY, 
  int goalX, int goalY, int monX, int monY
) {
  int i, j, k = 0;
  // allocate enough space for every character and space padding and \n at end of line
  /*
  . . . P . \n
  . . . . . \n
  . G . . . \n
  . . . M . \n
  */
  char* dispString = (char*)calloc(((boardX * boardY * 2) + boardY), sizeof(char));

  for (i = 0; i < boardY; i++) {
    for (j = 0; j < boardX; j++) {
      if(i == boardY - 1 - plrY && j == plrX) {
        dispString[k] = 'P';
        // sb.Append("P ");
      } else if(i == boardY - 1 - goalY && j == goalX) {
        dispString[k] = 'G';
        // sb.Append("G ");
      } else if(i == boardY - 1 - monY && j == monX) {
        dispString[k] = 'M';
        // sb.Append("M ");
      } else {
        dispString[k] = '.';
        // sb.Append(". ");
      }
      k++;
      dispString[k] = ' ';
      k++;
    }
    dispString[k] = '\n';
    k++;
  }
  printf("%s", dispString);
}

void moveCloserVertically(
  int plrX, int plrY, int* monX, int* monY, int goalX, int goalY
) {
  if (plrY > *monY && !(*monY + 1 == goalY && *monX == goalX)) {
    *monY = *monY + 1;
    printf("\nmonster moves N\n");
  } else if (!(*monY - 1 == goalY && *monX == goalX)) {
    *monY = *monY - 1;
    printf("\nmonster moves S\n");
  } else {
    printf("\nmonster forefits move\n");
  }
}

void moveCloserHorizontally(
  int plrX, int plrY, int* monX, int* monY, int goalX, int goalY
) {
  if (plrX > *monX && !(*monY == goalY && *monX + 1 == goalX)) {
    *monX = *monX + 1;
    printf("\nmonster moves E\n");
  } else if (!(*monY == goalY && *monX - 1 == goalX)) {
    *monX = *monX - 1;
    printf("\nmonster moves W\n");
  } else {
    printf("\nmonster forefits move\n");
  }
}
void playGame(
  int boardX, int boardY, int plrX, int plrY, 
  int goalX, int goalY, int monX, int monY
) {
  int gameWon = 0;
  int gameLost = 0;
  int notFirstMove = 0;

  // Game loop
  while (!gameWon && !gameLost) {
    // Print grid
    printGrid(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);

    // Get player input
  getPlayerInput:
    if(notFirstMove == 1) {
      getchar();
    }
    printf("Enter a direction (N, S, E, W): ");
    char input = '\n';
    while(input != 'N' && input != 'S' && input != 'E' && input != 'W') {
      input = getchar();
      if(input != 'N' && input != 'S' && input != 'E' && input != 'W') {
        printf("\ninvalid input.\n");
        printf("\nEnter a direction (N, S, E, W): ");
      }
    }

    // Move player
    switch (input) {
      case 'W':
        if (plrX > 0) {
          plrX--;
        }
        else {
          printf("invalid move\n");
          goto getPlayerInput;
        }
        break;
      case 'S':
        if (plrY > 0) {
          plrY--;
        }
        else {
          printf("invalid move\n");
          goto getPlayerInput;
        }
        break;
      case 'E':
        if (plrX < boardX - 1) {
          plrX++;
        }
        else {
          printf("invalid move\n");
          goto getPlayerInput;
        }
        break;
      case 'N':
        if (plrY < boardY - 1) {
          plrY++;
        }
        else {
          printf("invalid move\n");
          goto getPlayerInput;
        }
        break;
      default:
        printf("invalid move\n");
        goto getPlayerInput;
    }

    notFirstMove = 1;

    if(plrX == goalX && plrY == goalY) {
      gameWon = 1;
      break;
    }

    if(plrX == monX && plrY == monY) {
      gameLost = 1;
      break;
    }

    // Move monster
    int xDist = plrX - monX;
    int yDist = plrY - monY;

    if(abs(xDist) > abs(yDist)) { // Move horizontally
      moveCloserHorizontally(plrX, plrY, &monX, &monY, goalX, goalY);
    } 
    else if(abs(xDist) < abs(yDist)) { // Move vertically
      moveCloserVertically(plrX, plrY, &monX, &monY, goalX, goalY);
    }
    else { // Move randomly
      // generate random number beteen 0 and 2
      int randNum = rand() % 2;
      switch (randNum) {
        case 0:
          moveCloserHorizontally(plrX, plrY, &monX, &monY, goalX, goalY);
          break;
        case 1:
          moveCloserVertically(plrX, plrY, &monX, &monY, goalX, goalY);
          break;
      }
    }

    if(plrX == monX && plrY == monY) {
      gameLost = 1;
      break;
    }
  }

  if(gameWon) {
    printf("player wins!");
  }
  else if(gameLost) {
    printf("monster wins!");
  }
}

int main(int argc, char** argv) {
  // get input integers from command line
  int boardX = atoi(argv[1]);
  int boardY = atoi(argv[2]);
  int plrX = atoi(argv[3]);
  int plrY = atoi(argv[4]);
  int goalX = atoi(argv[5]);
  int goalY = atoi(argv[6]);
  int monX = atoi(argv[7]);
  int monY = atoi(argv[8]);

  playGame(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);
}