/*ECE 220 MP4
*
*Group Members:
*Kevin Hu, Joe Lopez, Daniel Ao
*kwh2, joseal2, dao3
*
*This program prints all the semiprimes in a given range.
*it uses 2 functions to determine if a number is prime and another to print
*/
#include <stdlib.h>
#include <stdio.h>


int is_prime(int number);
int print_semiprimes(int a, int b);


int main(){
   int a, b;
   printf("Input two numbers: ");
   scanf("%d %d", &a, &b);
   if( a <= 0 || b <= 0 ){
     printf("Inputs should be positive integers\n");
     return 1;
   }

   if( a > b ){
     printf("The first number should be smaller than or equal to the second number\n");
     return 1;
   }

   // TODO: call the print_semiprimes function to print semiprimes in [a,b] (including a and b)
   print_semiprimes(a,b);
}


/*
 * This function checks if the number is prime or not.
 * Input    : a number
 * Return   : 0 if the number is not prime, else 1
 */
int is_prime(int number)
{
  if(number==1)
    return 0;
  for(int i=2; i<number; i++){
    if(number%i==0)
      return 0;
  }
  return 1;
}


/*
 * This function prints all semiprimes in [a,b] (including a, b).
 * Input   : a, b (a should be smaller than or equal to b)
 * Return  : 0 if there is no semiprime in [a,b], else 1
 */
int print_semiprimes(int a, int b)
{
  int flag = 0;
  for(int n=a ;n<=b; n++){
    bool flag1 = true;
    for(int k=2; k<n; k++){
      if(is_prime(k)==1 && n%k==0 && is_prime(n/k)==1 && flag1){
	printf("%d ", n);
	flag = 1;
        flag1 = false;
      }
    }

  }
  printf("%c", '\n');
  return flag;

}
