#include<stdio.h>
#include<math.h>
void printArray( int A[] , int p ,int r)
{  int i ;
   for ( i = p ; i <=r  ; i++)
     printf ( " %d " , A[i] );  
   printf ( "\n");}
void merge(int A[] , int p , int q, int r)
{ int i,j,k;
  int n1 = q-p+1;
  int n2 = r-q;
  int L[n1+1];
  int M[n2+1];
  L[n1] = 1999999;
  M[n2] = 1999999;
  for ( i = 0 ; i < n1 ; i++)
  {  L[i] = A[p+i];}
  for ( j = 0 ; j < n2 ; j++)
  {  M[j] = A[q+j+1]; }
  i = 0;
  j = 0;
  for ( k = p ;  k < r+1 ; k++)
  {  if ( L[i] <= M[j] )
     {  A[k] = L[i];
        i = i + 1 ;}
     else 
     {  A[k] = M[j];
        j = j + 1;}}
  } 
void mergeSort ( int A[] , int p , int r)
{    if ( p < r )
   {   int q = floor( (p+r)/2);
       mergeSort( A , p , q);
       mergeSort( A , q+1 , r);
       merge( A , p , q , r) ;}
   }    
int main()
{ printf("Welcome to Merge-Sort Programme!\n\n");
  int i ,n , A[1000] ,p , r;
  printf (" please insert the length of your array:\n\n");
  scanf ( " %d" , &n);
  printf("\n");
  printf (" please insert the values:\n\n");
  for ( i = 0 ; i < n ; i ++)
    scanf ( " %d",&A[i]);
  printf("\n");  
  printf(" your array is:\n");
  printArray(A,0,n-1);
  printf("\n");
  printf(" please select the portion of the array \n that you want to sort through inserting\n starting and ending indices  \n ( separate them by comma):\n");
  scanf("%d , %d",&p,&r); 
  mergeSort(A,p,r);
  printf("\n");
  printf(" The selectively sorted array is :\n");
  printArray(A,0,n-1);
  return 0;}