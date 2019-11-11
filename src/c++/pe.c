#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  if(argc < 4)
    {
      printf("need 3 param\n");
      return;
    }

  float pe = strtof(argv[1], NULL);
  float pb = strtof(argv[2], NULL);
  float ratio = strtof(argv[3], NULL);
  printf("pe: %f pb: %f ratio: %f\n", pe, pb, ratio);
  int num = 0;
  
  if(pe / pb + (1 + ratio) > pe)
    {
      num = 1;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) > pe)
    {
      num = 2;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) > pe)
    {
      num = 3;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) > pe)
    {
      num = 4;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) > pe)
    {
      num = 5;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) > pe)
    {
      num = 6;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) > pe)
    {
      num = 7;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) > pe)
    {
      num = 8;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) > pe)
    {
      num = 9;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) > pe)
    {
      num = 10;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) > pe)
    {
      num = 11;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) > pe)
    {
      num = 12;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) > pe)
    {
      num = 13;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) > pe)
    {
      num = 14;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) > pe)
    {
      num = 15;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) > pe)
    {
      num = 16;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) > pe)
    {
      num = 17;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) > pe)
    {
      num = 18;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) > pe)
    {
      num = 19;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) > pe)
    {
      num = 20;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) > pe)
    {
      num = 21;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) > pe)
    {
      num = 22;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) > pe)
    {
      num = 23;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) > pe)
    {
      num = 24;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) > pe)
    {
      num = 25;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) > pe)
    {
      num = 26;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) > pe)
    {
      num = 27;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) > pe)
    {
      num = 28;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) > pe)
    {
      num = 29;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) > pe)
    {
      num = 30;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) > pe)
    {
      num = 31;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) > pe)
    {
      num = 32;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) > pe)
    {
      num = 33;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) > pe)
    {
      num = 34;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) > pe)
    {
      num = 35;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) > pe)
    {
      num = 36;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) > pe)
    {
      num = 37;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) > pe)
    {
      num = 38;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) > pe)
    {
      num = 39;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) + pow(1 + ratio, 40) > pe)
    {
      num = 40;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) + pow(1 + ratio, 40) + pow(1 + ratio, 41) > pe)
    {
      num = 41;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) + pow(1 + ratio, 40) + pow(1 + ratio, 41) + pow(1 + ratio, 42) > pe)
    {
      num = 42;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) + pow(1 + ratio, 40) + pow(1 + ratio, 41) + pow(1 + ratio, 42) + pow(1 + ratio, 43) > pe)
    {
      num = 43;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) + pow(1 + ratio, 40) + pow(1 + ratio, 41) + pow(1 + ratio, 42) + pow(1 + ratio, 43) + pow(1 + ratio, 44) > pe)
    {
      num = 44;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) + pow(1 + ratio, 40) + pow(1 + ratio, 41) + pow(1 + ratio, 42) + pow(1 + ratio, 43) + pow(1 + ratio, 44) + pow(1 + ratio, 45) > pe)
    {
      num = 45;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) + pow(1 + ratio, 40) + pow(1 + ratio, 41) + pow(1 + ratio, 42) + pow(1 + ratio, 43) + pow(1 + ratio, 44) + pow(1 + ratio, 45) + pow(1 + ratio, 46) > pe)
    {
      num = 46;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) + pow(1 + ratio, 40) + pow(1 + ratio, 41) + pow(1 + ratio, 42) + pow(1 + ratio, 43) + pow(1 + ratio, 44) + pow(1 + ratio, 45) + pow(1 + ratio, 46) + pow(1 + ratio, 47) > pe)
    {
      num = 47;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) + pow(1 + ratio, 40) + pow(1 + ratio, 41) + pow(1 + ratio, 42) + pow(1 + ratio, 43) + pow(1 + ratio, 44) + pow(1 + ratio, 45) + pow(1 + ratio, 46) + pow(1 + ratio, 47) + pow(1 + ratio, 48) > pe)
    {
      num = 48;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) + pow(1 + ratio, 40) + pow(1 + ratio, 41) + pow(1 + ratio, 42) + pow(1 + ratio, 43) + pow(1 + ratio, 44) + pow(1 + ratio, 45) + pow(1 + ratio, 46) + pow(1 + ratio, 47) + pow(1 + ratio, 48) + pow(1 + ratio, 49) > pe)
    {
      num = 49;
    }
  else if(pe / pb + (1 + ratio) + pow(1 + ratio, 2) + pow(1 + ratio, 3) + pow(1 + ratio, 4) + pow(1 + ratio, 5) + pow(1 + ratio, 6) + pow(1 + ratio, 7) + pow(1 + ratio, 8) + pow(1 + ratio, 9) + pow(1 + ratio, 10) + pow(1 + ratio, 11) + pow(1 + ratio, 12) + pow(1 + ratio, 13) + pow(1 + ratio, 14) + pow(1 + ratio, 15) + pow(1 + ratio, 16) + pow(1 + ratio, 17) + pow(1 + ratio, 18) + pow(1 + ratio, 19) + pow(1 + ratio, 20) + pow(1 + ratio, 21) + pow(1 + ratio, 22) + pow(1 + ratio, 23) + pow(1 + ratio, 24) + pow(1 + ratio, 25) + pow(1 + ratio, 26) + pow(1 + ratio, 27) + pow(1 + ratio, 28) + pow(1 + ratio, 29) + pow(1 + ratio, 30) + pow(1 + ratio, 31) + pow(1 + ratio, 32) + pow(1 + ratio, 33) + pow(1 + ratio, 34) + pow(1 + ratio, 35) + pow(1 + ratio, 36) + pow(1 + ratio, 37) + pow(1 + ratio, 38) + pow(1 + ratio, 39) + pow(1 + ratio, 40) + pow(1 + ratio, 41) + pow(1 + ratio, 42) + pow(1 + ratio, 43) + pow(1 + ratio, 44) + pow(1 + ratio, 45) + pow(1 + ratio, 46) + pow(1 + ratio, 47) + pow(1 + ratio, 48) + pow(1 + ratio, 49) + pow(1 + ratio, 50) > pe)
    {
      num = 50;
    }
  else
    {
      num = 51;
    }

  if(num > 50)
    {
      printf("To earn the same money as pe, need more than 50 years\n");
    }
  else
    {
      printf("To earn the same money as pe, need %d years\n", num);
    }
}

