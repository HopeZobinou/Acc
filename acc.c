#include <stdio.h>
#include <math.h>
#include <string.h>

char print_menu(void);
void print_acc(short acc, char mode);
short get_operand(char mode);

int main(void)
{
  
  char Mode = 'D';
  short acc = 0;
  char UserOption;
  
  print_acc(acc, Mode);
  UserOption = print_menu();

  while(UserOption != 'Q')
  {  
    if(UserOption == 'O')
    {
      Mode = UserOption;
      printf("Mode is Octal\n");
      print_acc(acc, Mode);
      UserOption = print_menu();
    }
    else if(UserOption == 'H')
    {  
      Mode = UserOption;
      printf("Mode is Hexadecimal\n");
      printf("\n");
      print_acc(acc, Mode);
      UserOption = print_menu();
    }
    else if(UserOption == 'D')
    {  
      Mode = UserOption;
      printf("Mode is Decimal\n");
      printf("\n");
      print_acc(acc, Mode);
      UserOption = print_menu();
    }
    else if(UserOption == 'C')
    {
      acc = 0;
      print_acc(acc, Mode);
      UserOption = print_menu();
    }
    else if(UserOption == 'S')
    {
      acc = get_operand(Mode);
      print_acc(acc, Mode);
      UserOption = print_menu();
    }
  }

}

void print_acc(short acc, char mode)
{
  printf("*****************************************\n");
  printf("* Accumulator:          Input Mode: ");
  printf("%c   *\n", mode);
  printf("*   Hex     :  %04hX                     *\n", acc);
  printf("*   Octal   :  %06ho                   *\n", acc);
  printf("*   Decimal :  %-10d               *\n", acc);
  printf("*****************************************\n");
  printf("\n");
}

char print_menu(void)
{
  char ValidOptions [7] ="OHDCSQ";
  short IsValidOption = 0;
  char UserOption;
  char UserString[10]; 
  
  while(IsValidOption == 0)
  {
    printf("Please select one of the following options: \n");
    printf("\n");
    printf("O Octal Mode\n");
    printf("H Hexadecimal Mode\n");
    printf("D Decimal Mode\n");
    printf("\n");
    printf("C Clear Accumulator\n");
    printf("S Set Accumulator\n");
    printf("\n");
    printf("Q Quit\n");
    printf("\n");
    printf("Option: ");
    scanf("%s", UserString);
    printf("\n");
    
    if(strlen(UserString) == 1)
    {
      UserOption = UserString[0];
      UserOption = toupper(UserOption);
    }
    if(!strchr(ValidOptions, UserOption) || strlen(UserString) != 1)
    {
      printf("Invald option: %s\n", UserString);
      printf("\n");
    }
    else
    {
      IsValidOption = 1;
    }
  }
  
  return UserOption;
}

short get_operand(char mode)
{
  short UserValue;

  switch(mode)
  {
  case 'D':
    printf("Enter decimal value: ");
    scanf("%hd", &UserValue);
    break;
  case 'O':
    printf("Enter octal value: ");
    scanf("%ho", &UserValue);
    break;
  case 'H':
    printf("Enter hex value: ");
    scanf("%hx", &UserValue);
    break;
  }

  return UserValue;
  
}
