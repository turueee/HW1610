#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int create_vector(int* count, int** vector)
{
  int i = 0;
  printf("Введите n - число измерений, в которых существует вектор: ");
  scanf("%d", count);
  if (*count < 0 || *count>500000000)
  {
    printf("Error sizer!!!");
    return -1;
  }
  *vector = (int*)malloc(*count * sizeof(int));
  for (i = 0; i < *count; i++)
  {
    (*vector)[i] = (int)rand() % 100;
    printf("%d ", (int)((*vector)[i]));
  }
  printf("\n");
  return 0;
}


void free_vector(int* vector)
{
  return free(vector);
}

int sum_vectors(int n1, int* vector_1, int n2, int* vector_2,int* n3,int** vector_3)
{
  int i,i1,nsum;
  if (n1 >= n2)
    *n3 = n1;
  else
    *n3 = n2;
  *vector_3 = (int*)malloc(*n3 * sizeof(int));
  if (n1 >= n2)
  {
    nsum = n2;
    for (i = 0; i < *n3; i++)
    {
      if (i < nsum)
      {
        i1 = i;
        (*vector_3)[i] = (int)vector_1[i] + (int)vector_2[i1];
        printf("%d", (int)((*vector_3)[i]));
      }
      else
      {
        (*vector_3)[i] = (int)vector_1[i];
        printf("%d", (int)((*vector_3)[i]));
      }
    }
  }
  else
  {
    nsum = n1;
    for (i = 0; i < *n3; i++)
    {
      if (i < nsum)
      {
        i1 = i;
        (*vector_3)[i] = (int)vector_1[i] + (int)vector_2[i1];
        printf("%d", (int)((*vector_3)[i]));
      }
      else
      {
        (*vector_3)[i] = (int)vector_2[i];
        printf("%d", (int)((*vector_3)[i]));
      }
    }
  }
  return 0;
}




int main()
{
  int* vector_1, vector_2, vector_3, errorCode_1 = 0, errorCode_2 = 0, errorCode_3 = 0;
  int n1 = 0, n2 = 0,n3 = 0;
  system("chcp 1251>nul");
  srand(time(0));
  errorCode_1 = create_vector(&n1, &vector_1);
  if (errorCode_1 != 0)
    return errorCode_1;
  errorCode_2 = create_vector(&n2, &vector_2);
  if (errorCode_2 != 0)
    return errorCode_1;
  errorCode_3 = sum_vectors(n1, vector_1, n2, vector_2, &n3, &vector_3);
  if (errorCode_3 != 0)
    return errorCode_1;
  free_vector(vector_1);
  free_vector(vector_2);
  free_vector(vector_3);
  return 0;
}