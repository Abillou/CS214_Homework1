/**
 * Author: Rahul Hegde
 * Description: I wrote this script in C# as it's what I'm comfortable with.
 * We still need to convert it to pure C.
 */
using System;
using System.Text;

public class Monster {
  public static void PrintGrid(
    int boardX, int boardY, int plrX, int plrY, 
    int goalX, int goalY, int monX, int monY
    ) {

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < boardY; i++) {
      for (int j = 0; j < boardX; j++) {
        if(i == boardY - 1 - plrY && j == plrX) {
          sb.Append("P ");
        } else if(i == boardY - 1 - goalY && j == goalX) {
          sb.Append("G ");
        } else if(i == boardY - 1 - monY && j == monX) {
          sb.Append("M ");
        } else {
          sb.Append(". ");
        }
      }
      sb.AppendLine();
    }
    Console.WriteLine(sb.ToString());
  }
  public static void MoveCloserVertically(
    int plrX, int plrY, ref int monX, ref int monY, int goalX, int goalY
    ) {

    // No need to bound check on monster if we're bound checking on player
    if (plrY > monY && !(monY + 1 == goalY && monX == goalX)) {
      monY++;
      Console.WriteLine("monster moves N");
    } else if(!(monY - 1 == goalY && monX == goalX)) {
      monY--;
      Console.WriteLine("monster moves S");
    } else {
      Console.WriteLine("monster forefits move");
    }
  }
  public static void MoveCloserHorizontally(int plrX, int plrY, 
    ref int monX, ref int monY, int goalX, int goalY) {

    // No need to bound check on monster if we're bound checking on player
    if (plrX > monX && !(monX + 1 == goalX && monY == goalY)) {
      monX++;
      Console.WriteLine("monster moves E");
    } else if(!(monX - 1 == goalX && monY == goalY)) {
      monX--;
      Console.WriteLine("monster moves W");
    } else {
      Console.WriteLine("monster forefits move");
    }
  }
  public static void PlayGame(int boardX, int boardY, int plrX, 
    int plrY, int goalX, int goalY, int monX, int monY) {
      
    Random rand = new Random();
    bool gameWon = false;
    bool gameLost = false;

    // Game loop
    while (!gameWon && !gameLost) {
      // Print grid
      PrintGrid(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);

      // Get player input
      getPlayerInput:
      Console.WriteLine("Enter a direction (N, S, W, E): ");
      char input = Console.ReadLine()[0];

      // Move player
      switch (input) {
        case 'W':
          if (plrX > 0) {
            plrX--;
          }
          else {
            Console.WriteLine("invalid move");
            goto getPlayerInput;
          }
          break;
        case 'S':
          if (plrY > 0) {
            plrY--;
          }
          else {
            Console.WriteLine("invalid move");
            goto getPlayerInput;
          }
          break;
        case 'E':
          if (plrX < boardX - 1) {
            plrX++;
          }
          else {
            Console.WriteLine("invalid move");
            goto getPlayerInput;
          }
          break;
        case 'N':
          if (plrY < boardY - 1) {
            plrY++;
          }
          else {
            Console.WriteLine("invalid move");
            goto getPlayerInput;
          }
          break;
      }

      if(plrX == goalX && plrY == goalY) {
        gameWon = true;
        break;
      }

      if(plrX == monX && plrY == monY) {
        gameLost = true;
        break;
      }

      // Move monster
      int xDist = plrX - monX;
      int yDist = plrY - monY;

      if(Math.Abs(xDist) > Math.Abs(yDist)) { // Move horizontally
        MoveCloserHorizontally(plrX, plrY, ref monX, ref monY, goalX, goalY);
      } 
      else if(Math.Abs(xDist) < Math.Abs(yDist)) { // Move vertically
        MoveCloserVertically(plrX, plrY, ref monX, ref monY, goalX, goalY);
      }
      else { // Move randomly
        int randNum = rand.Next(0, 2);
        switch (randNum) {
          case 0:
            MoveCloserHorizontally(plrX, plrY, ref monX, ref monY, goalX, goalY);
            break;
          case 1:
            MoveCloserVertically(plrX, plrY, ref monX, ref monY, goalX, goalY);
            break;
        }
      }

      if(plrX == monX && plrY == monY) {
        gameLost = true;
        break;
      }
    }

    if(gameWon) {
      Console.WriteLine("player wins!");
    }
    else if(gameLost) {
      Console.WriteLine("monster wins!");
    }
  }
  public static void Main(String[] args) {
    int boardX = 5;
    int boardY = 5; 
    int plrX = 0; 
    int plrY = 0; 
    int goalX = 1; 
    int goalY = 1;   
    int monX = 3; 
    int monY = 4;

    PlayGame(boardX, boardY, plrX, plrY, goalX, goalY, monX, monY);
  }
}