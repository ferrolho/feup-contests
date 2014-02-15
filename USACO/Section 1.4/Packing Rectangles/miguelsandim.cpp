/*
ID: migueel1
PROG: packrec
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Rect
{
  unsigned int c, l;
};

vector<Rect> rects, final_rects;
unsigned int final_area;

bool comp(const Rect &a, const Rect &b)
{ return a.c < b.c; }

bool larg(const Rect &a, const Rect &b)
{ return a.l < b.l; }

unsigned int max3(unsigned int a, unsigned int b, unsigned int c)
{
  if (a>b && a>c)
    return a;
  else if (b>a && b>c)
    return b;
  else if (c>a && c>b)
    return c;
  else if (a>b || a>c) // se nao ha nenhum maior absoluto
    return a;
  else if (b>a || b>c)
    return b;
  else
    return c;
}

bool rectPresent(Rect a)
{
  for(unsigned int i=0; i < final_rects.size(); i++)
    if (a.l == final_rects[i].l && a.c == final_rects[i].c)
      return true;

  return false;
}

void analyze(unsigned int comp, unsigned int larg)
{
  unsigned int area = comp*larg;

  if (area < final_area || area == final_area)
  {
    if (area < final_area)
    {
      final_area = area;
      final_rects.clear();
    }

    Rect r; r.c = comp; r.l = larg;
    if (r.l > r.c) swap(r.l,r.c);

    if (!rectPresent(r))
      final_rects.push_back(r);
  }
}

void search(int position)
{
  unsigned int cmp=0, lrg=0;

  for(int i=0; i <= 3; i++) // todas as permutações dos 4 rectângulos -> 4 ciclos
    for(int j=0; j <= 3; j++)
      for(int k=0; k <= 3; k++)
        for(int l=0; l <= 3; l++)
        {
          if (i==j || i==k || i==l || j==k || j==l || k==l)
            continue;

          for(int q=0; q < 2; q++) // todas as rotações possíveis -> 4 ciclos
          {
            for(int r=0; r < 2; r++)
            {
              for(int s=0; s < 2; s++)
              {
                for(int t=0; t < 2; t++)
                {
                  lrg = 0;
                  cmp = 0;

                  if (position == 1)
                  {
                    // contar area
                    for(unsigned int i=0; i < rects.size(); i++)
                      lrg += rects[i].l;

                    cmp = max_element(rects.begin(),rects.end(),comp)->c;

                    //printf("area: %d, comp: %d, larg: %d\n",cmp*lrg,cmp,lrg); getchar();

                    //if (cmp*lrg==0)
                    //{printf("foi na 1\n"); getchar();}

                    analyze(cmp,lrg);
                  }

                  // contagem da area
                  // contar casos -> i é o rectangulo por baixo
                  else if (position == 2)
                  {
                    cmp = rects[i].l + max3(rects[j].c, rects[k].c, rects[l].c);
                    lrg = max(rects[i].c, rects[j].l + rects[k].l  + rects[l].l);
                    analyze(cmp,lrg);

                    //if ((cmp == 8 && lrg == 9) || (cmp == 9 && lrg == 8))
                    //{printf("foi na 2\n"); getchar();}
                  }
                  // contar casos -> i é o rectangulo por baixo; j é o do lado direito
                  else if (position == 3)
                  {
                    cmp = max(rects[i].l + max(rects[k].c,rects[l].c), rects[j].c);
                    lrg = rects[j].l + max(rects[i].c, rects[k].l + rects[l].l);
                    analyze(cmp,lrg);

                    //if ((cmp == 8 && lrg == 9) || (cmp == 9 && lrg == 8))
                    //{printf("foi na 3\n"); getchar();}
                  }
                  // contar casos -> i é o rectangulo de cima; j é o de baixo
                  else if (position == 4) // 4,5 sao iguais
                  {
                    cmp = max3(rects[i].c + rects[j].c, rects[k].c, rects[l].c);
                    lrg = max(rects[i].l,rects[j].l) + rects[k].l + rects[l].l;
                    analyze(cmp,lrg);

                    //if ((cmp == 8 && lrg == 9) || (cmp == 9 && lrg == 8))
                    //{printf("foi na 4\n"); getchar();}
                  }
                  // contar casos ->
                  // i j
                  // k l
                  else if (position == 5) // caso 6
                  {
                    cmp = max(rects[l].c + rects[j].c, rects[k].c + rects[i].c);
                    lrg = rects[k].l + rects[l].l; // a partida supoe-se que os rectangulos mais largos estão na base..

                    // se o l é o mais alto da base, i pode bater no l e aumentar a largura
                    if(rects[k].c < rects[l].c)
                      lrg = max(lrg, rects[i].l + rects[l].l);

                    // se k é o mais alto da base, j pode bater no k e aumentar a largura
                    if(rects[l].c < rects[k].c)
                      lrg = max(lrg, rects[k].l + rects[j].l);

                    // caso em que i e j podem bater ->
                    if(rects[k].c + rects[i].c > rects[l].c || rects[l].c + rects[j].c > rects[k].c)
                      lrg = max(lrg, rects[i].l + rects[j].l);

                    analyze(cmp,lrg);

                    //if ((cmp == 8 && lrg == 9) || (cmp == 9 && lrg == 8))
                    //{printf("foi na 6\n"); getchar();}
                  }
                  swap(rects[l].c,rects[l].l);
                }
                swap(rects[k].c,rects[k].l);
              }
              swap(rects[j].c,rects[j].l);
            }
            swap(rects[i].c,rects[i].l);
          }
        }
}

int main()
{
  final_area = 60000;

  // READ INPUT
  ifstream input("packrec.in");
  for(int i=0; i < 4; i++)
  {
    Rect r; input >> r.c >> r.l;

    if (r.l > r.c) swap(r.l,r.c);
    rects.push_back(r);
  }
  input.close();

  for(int i=1; i <=5; i++)
    search(i);

  sort(final_rects.begin(),final_rects.end(),larg);

  //SAVE OUTPUT
  ofstream output("packrec.out");
  output << final_area << endl;

  for(unsigned int i=0; i < final_rects.size(); i++)
    output << final_rects[i].l << ' ' << final_rects[i].c << endl;

  output.close();

  return 0;
}