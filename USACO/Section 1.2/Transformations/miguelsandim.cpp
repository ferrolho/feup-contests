/*
ID: migueel1
PROG: transform
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

unsigned int N, transf;

vector< vector <char> > matrix_or, matrix_tr, matrix_semi, matrix_temp;

void printMatrix(const vector<vector<char> > &a)
{
  for(unsigned int i = 0; i < N; i++)
  {
    printf("[");
    for (unsigned int j=0; j < N; j++)
      printf("%c ",a[i][j]);

    printf("]\n");
  }

  printf("-----\n");
}

bool equalMatrix(const vector<vector<char> > &a, const vector<vector<char> > &b)
{
  for(unsigned int i = 0; i < N; i++)
  {
    for (unsigned int j=0; j < N; j++)
    {
      if (a[i][j] != b[i][j])
        return false;
    }
  }
  return true;
}

void rotateSemi90()
{
  matrix_temp = matrix_semi;

  for(unsigned int i=0; i < N; i++)
    for(unsigned int j=0; j < N; j++)
      matrix_semi[i][j] = matrix_temp[N-1-j][i];
}

void mirrorEffectSemi()
{
  char temp;

  for(unsigned int i=0; i < N; i++)
    for(unsigned int j=0; j < N/2; j++)
    {
      temp = matrix_semi[i][N-1-j];
      matrix_semi[i][N-1-j] = matrix_semi[i][j];
      matrix_semi[i][j] = temp;
    }
}

int main()
{
  ifstream input("transform.in");
  input >> N;

  // original matrix
  for(unsigned int i = 0; i < N; i++)
  {
    vector<char> line(N);

    for(unsigned int j = 0; j < N; j++)
      input >> line[j];

    matrix_or.push_back(line);
  }

  // transformed matrix
  for(unsigned int i = 0; i < N; i++)
  {
    vector<char> line(N);

    for(unsigned int j = 0; j < N; j++)
      input >> line[j];

    matrix_tr.push_back(line);
  }

  input.close();

  // semi-transformed matrix
  matrix_semi = matrix_or;

  // check if the given transformation is one of the ones...
  while(true)
  {
    //printMatrix(matrix_semi);

    rotateSemi90();

    if(equalMatrix(matrix_tr,matrix_semi))
    {
      transf = 1; break;
    }

    rotateSemi90();

    if(equalMatrix(matrix_tr,matrix_semi))
    {
      transf = 2; break;
    }

    rotateSemi90();

    if(equalMatrix(matrix_tr,matrix_semi))
    {
      transf = 3; break;
    }

    rotateSemi90(); // back to normal

    mirrorEffectSemi();

    if(equalMatrix(matrix_tr,matrix_semi))
    {
      transf = 4; break;
    }

    rotateSemi90();

    if(equalMatrix(matrix_tr,matrix_semi))
    {
      transf = 5; break;
    }

    rotateSemi90();

    if(equalMatrix(matrix_tr,matrix_semi))
    {
      transf = 5; break;
    }

    rotateSemi90();

    if(equalMatrix(matrix_tr,matrix_semi))
    {
      transf = 5; break;
    }

    if (matrix_or == matrix_tr)
    {
      transf = 6; break;
    }

    transf = 7;
    break;
  }

  ofstream output("transform.out");

  output << transf << endl;

  return 0;
}
