#include <iostream>
#include <string>
#include <vector>
#include <cmath>

const char letter_sub = 55;
const char numerical_sub = 48;

using namespace std;

unsigned int charTOint(char ex)
{
  if (ex >= 'A' && ex <= 'Z')
    return ex - letter_sub;
  else
    return ex - numerical_sub;
}

int main()
{
  string s1,s2,s3,s4;
  unsigned int base=2,n1,n2,n3,n4;

  cin >> s1 >> s2 >> s3 >> s4;

  for (size_t i=0; i < s1.size(); i++)
  {
    if (charTOint(s1[i]) + 1 > base)
      base = charTOint(s1[i]) + 1;
  }

  for (size_t i=0; i < s2.size(); i++)
  {
    if (charTOint(s2[i]) + 1 > base)
      base = charTOint(s2[i]) + 1;
  }

  for (size_t i=0; i < s3.size(); i++)
  {
    if (charTOint(s3[i]) + 1 > base)
      base = charTOint(s3[i]) + 1;
  }

  for (size_t i=0; i < s4.size(); i++)
  {
    if (charTOint(s4[i]) + 1 > base)
      base = charTOint(s4[i]) + 1;
  }

  bool baseCorrect = false;

  while (!baseCorrect)
  {
    n1 = 0; n2 = 0; n3 = 0; n4 = 0;

    for(int i=s1.size()-1; i >= 0; i--)
      n1 += charTOint(s1[s1.size()-1 - i]) * (unsigned int) pow((double) base,i);

    for(int i=s2.size()-1; i >= 0; i--)
      n2 += charTOint(s2[s2.size()-1 - i]) * (unsigned int) pow((double) base,i);

    for(int i=s3.size()-1; i >= 0; i--)
      n3 += charTOint(s3[s3.size()-1 - i]) * (unsigned int) pow((double) base,i);

    for(int i=s4.size()-1; i >= 0; i--)
      n4 += charTOint(s4[s4.size()-1 - i]) * (unsigned int) pow((double) base,i);

    if ((n1+n2) == (n3*n4))
      baseCorrect = true;
    else
      base++;
  }
  cout << base << endl;
  return 0;
}
