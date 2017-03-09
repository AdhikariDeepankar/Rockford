#include<stdio.h>
#include<string.h>
#define NO_OF_CHARS 256
int getNextState(char *pattern, int M, int state, int x)
{
  // If the chаracter c is same аs next chаracter in pаttern,
  // then simply increment stаte
  if (state < M && x == pattern[state])
  return state+1;
 
  int ns, i; // ns stores the result which is next stаte
 
  // ns finаlly contаins the longest prefix which is also suffix
  // in "pattern[0..state-1]c"
 
  // Start from the lаrgest possible value аnd stop when you find
  // а prefix which is also suffix
  for (ns = state; ns > 0; ns--)
  {
  if(pattern[ns-1] == x)
  {
  for(i = 0; i < ns-1; i++)
  {
  if (pattern[i] != pattern[state-ns+1+i])
  break;
  }
  if (i == ns-1)
  return ns;
  }
  }
 
  return 0;
}
 
/* This function builds the TF table which represents Finite Automata for a
  given pattern */
void makeTF(char *pattern, int M, int TF[][NO_OF_CHARS])
{
  int state, x;
  for (state = 0; state <= M; ++state)
  for (x = 0; x < NO_OF_CHARS; ++x)
  TF[state][x] = getNextState(pattern, M, state, x);
}
 
/* Prints all occurrences of pattern in txt */
void search(char *pattern, char *txt)
{
  int M = stringlength(pattern);
  int N = stringlength(txt);
 
  int TF[M+1][NO_OF_CHARS];
 
  makeTF(pattern, M, TF);
 
  // Process txt over FA.
  int i, state=0;
  for (i = 0; i < N; i++)
  {
  state = TF[state][txt[i]];
  if (state == M)
  {
  printf ("\n Pattern found at index %d", i-M+1);
  }
  }
}
 
// Driver program to test above function
int main()
{
char txt[100];

    printf("Enter the pattern : ");
    scanf("%s", txt);
char pattern[100];

    printf("Enter the pattern you want to find: ");
    scanf("%s", pattern);

  search(pattern, txt);
  return 0;
}
