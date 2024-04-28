#include <stdio.h>


struct salesPerson {
    char initial[2];
    int salesAmount;
};


int main(void) {
  struct salesPerson danielle = {"D", 0};
  struct salesPerson edward = {"E", 0};
  struct salesPerson francis = {"F", 0};
  FILE *file = fopen("unit_test_1.txt", "r");
  char line[100];
  char initial;
  int grandTotal = 0;
  int sale;
  
  while (fgets(line, sizeof(line), file) != NULL) {
    sscanf(line, "%c %d", &initial, &sale);
    switch (initial) 
      {
        case 'D':
          {
            danielle.initial[0] = initial;
            danielle.initial[1] = '\0';
            danielle.salesAmount = sale;
            break;
          }
        case 'E':
          {
            edward.initial[0] = initial;
            edward.initial[1] = '\0';
            edward.salesAmount = sale;
            break;
          }
        case 'F':
          {
            francis.initial[0] = initial;
            francis.initial[1] = '\0';
            francis.salesAmount = sale;
            break;
          }
        default:
          {
            printf("intermediate output: Error, invalid salesperson selected, please try again\n");
          }
      }
  }
  
  fclose(file);
  
  grandTotal = danielle.salesAmount + edward.salesAmount + francis.salesAmount;
  printf("Grand Total: $%d\n", grandTotal);
  
  if (danielle.salesAmount > edward.salesAmount && danielle.salesAmount > francis.salesAmount)
    {
      printf("Highest Sale: D");
    } 
  else if (edward.salesAmount > danielle.salesAmount && edward.salesAmount > francis.salesAmount) 
    {
      printf("Highest Sale: E");
    } 
  else if (francis.salesAmount > danielle.salesAmount && francis.salesAmount > edward.salesAmount) 
    {
      printf("Highest Sale: F");
    }
  
  return 0;
}
