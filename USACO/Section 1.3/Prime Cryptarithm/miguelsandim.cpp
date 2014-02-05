/*
ID: migueel1
PROG: crypt1
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int numbers[9];
int subset_number;
unsigned int solution_number;

bool existsInSubSet(int num)
{
  for (int i=0; i < subset_number; i++)
    if (numbers[i] == num)
      return true;

  return false;
}

bool validSolution(int top[], int bottom[])
{
  //printf("Vou testar com os valores\nTop: %d,%d,%d;\nBot: %d,%d\n\n",top[2],top[1],top[0],
  //bottom[1],bottom[0]); getchar();

  int partial1[3], partial2[3], sum, carry=0;

  for (unsigned int i=0; i < 2; i++)
  {
    for (unsigned int j=0; j < 3; j++)
    {
      int mul = bottom[i]*top[j];

      //printf("Mul deu %d\n",mul); getchar();

      if (carry)
      {mul+= carry; carry = 0;}

      if (mul >= 10)
        carry = mul/10;

      //printf("Mul com carry %d\n",mul); getchar();

      mul = mul%10;

      //printf("Mul final %d\n",mul); getchar();

      if (!existsInSubSet(mul))
        return false;
      //else printf("passou\n");

      if (i==0)
        partial1[j] = mul;
      else
        partial2[j] = mul;

      if (j == 2 && carry) // se sobrou carry, não pode
        return false;
      //else printf("passou\n");
    }
  }

  //printf("Agora as somas\npartial1:   %d,%d,%d;\npartial2: %d,%d,%d\n\n",partial1[2],partial1[1],partial1[0],
  //partial2[2],partial2[1],partial2[0]); getchar();

  sum = partial1[1] + partial2[0];

  //printf("Soma deu %d\n",sum); getchar();

  if (sum >= 10)
    carry = 1;

  sum = sum%10;

  //printf("Soma final deu %d\n",sum); getchar();

  if (!existsInSubSet(sum))
    return false;
  //else printf("passou\n");

  sum = partial1[2] + partial2[1];
  //printf("Soma deu %d\n",sum); getchar();

  if (carry)
  {sum+= carry; carry=0;}

  //printf("Soma com carry %d\n",sum); getchar();

  if (sum >= 10)
    carry = sum/10;

  sum = sum%10;

  //printf("Soma final deu %d\n",sum); getchar();

  if (!existsInSubSet(sum))
    return false;
  //else printf("passou\n");

  sum = partial2[2];
  //printf("Soma deu %d\n",sum); getchar();

  if (carry)
  {sum+= carry; carry=0;}
  //printf("Soma com carry %d\n",sum); getchar();

  if (sum >= 10)
    carry = sum/10;

  sum = sum%10;
  //printf("Soma final deu %d\n",sum); getchar();

  if (!existsInSubSet(sum))
    return false;
  //else printf("passou\n");

  return carry==0;
}

int main()
{
  // receive input
  ifstream input("crypt1.in");
  input >> subset_number;

  for(int i=0; i < subset_number; i++)
    input >> numbers[i];

  input.close();

  // VARIABLE DECLARATION
  int top[3], bottom[2], solution_number=0;

  for(int i=0; i < subset_number; i++)
    for(int j=0; j < subset_number; j++)
      for(int k=0; k < subset_number; k++)
        for(int l=0; l < subset_number; l++)
          for(int m=0; m < subset_number; m++)
          {
            top[0] = numbers[i]; top[1] = numbers[j]; top[2] = numbers[k];
            bottom[0] = numbers[l]; bottom[1] = numbers[m];

            //top[0] = 9; top[1] = 7; top[2] = 2;
            //bottom[0] = 8; bottom[1] = 7;

            if (validSolution(top,bottom))
              solution_number++;
          }

  //SAVE OUTPUT
  ofstream output("crypt1.out");
  output << solution_number << endl;
  output.close();

  return 0;
}
