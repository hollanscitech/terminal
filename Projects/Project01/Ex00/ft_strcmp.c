#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Function 1 = starts pointer at first number or alphabet char. returns int.
Function 2 = ends pointer at last num or alph char. returns int.
Function 3 = formats a string by getting rid of spaces. returns a string.
Function 4 = (strcmp) finds out two strings are identical. returns int.
*/

//Ft 1
int ft_start(char *str)
{
  int i = 0;
  while(str[i] != '\0' && str[i] == ' ')
    {
      i++;
    }
  return i;
}

//Ft 2
int ft_end(char *str)
{
  int i = strlen(str);
  while(str[i - 1] == ' ')
    {
      i--;
    }
  return i;
}

//Ft3
char* format_str(char *str)
{
  int i = 0;
  int start = ft_start(str);
  int end = ft_end(str);
  char *formatted_str;
  formatted_str = malloc(sizeof(char) * ((end - start) + 1));
  while(start <= end)
    {
      formatted_str[i] = str[start];
      i++;
      start++;
    }
  formatted_str[i] = '\0';
  return formatted_str;
}

//Ft 4
int match(char *s1, char *s2)
{
  int i = 0;
  char *str1 = format_str(s1); 
  char *str2 = format_str(s2);
  while((str1[i] != '\0') || (str2[i] != '\0'))
    {
      if(str1[i] > str2[i])
	{
	  return 0;
	}
      if(str1[i] < str2[i])
	{
	  return 0;
	}
      i++;
    }
  return 1;
}

int main(void)
{
  char *s1;
  char *s2;
  s1 = "   main.c ";
  s2 = "main.c    ";
  int returned = match(s1, s2);
  printf("%d\n", returned);
  return 0;
}


    
