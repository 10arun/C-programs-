#include<stdio.h>
#include<stdlib.h>
#define HZ 3

FILE *fp;

struct employee
{
  int empno;
  char nm[20];
  int sal;
};
typedef struct employee EMP;


struct hashtable
{
  int key;
  long int addr;
};
typedef struct hashtable ht;


int hashval (int num)
{
  int key;
  key = num % HZ;
  return key;
}

void search (ht * h, int n)
{
  EMP a;
  int hindex, countindex;
  printf ("Enter emp no to be searched\n");
  scanf ("%d", &(a.empno));
  hindex = hashval (a.empno);
  countindex = hindex;

  while (h[hindex].key != a.empno)
    {
      hindex = (hindex + 1) % HZ;
      if (countindex == hindex)
	    {
	   printf ("Search successful\n");
	    return;
	    }
    }
  printf ("search successful\n");
  fseek (fp, h[hindex].addr, SEEK_SET);
  fscanf (fp, "%d%s%d", &(a.empno), a.nm, &(a.sal));
  printf ("%d  %s  %d\n", a.empno, a.nm, a.sal);
}

void display (ht * h, int n)
{
  EMP a;
  int j, i;
  for (i = 0; i < HZ; i++)
  {
      if (h[i].key != -1)
	    {
	       printf ("Hash table: %d%ld|\t", h[i].key, h[i].addr);
	       fseek (fp, h[i].addr, SEEK_SET);
	       fscanf (fp, "%d%s%d", &(a.empno), a.nm, &(a.sal));
	        printf ("Contents in secondary storage:%d %s %d\n", a.empno, a.nm,
		      a.sal);
	    }
    }
}


void insert (ht * h, int n)
{
  EMP a;
  int flag = 0;
  int i, hindex, countindex;
  for (i = 0; i < n; i++)
   {
      flag = 0;
      printf ("enter empno name and salary\n");
      scanf ("%d%s%d", &(a.empno), a.nm, &(a.sal));
      hindex = hashval (a.empno);
      countindex = hindex;
      while (h[hindex].key != -1)
	   {
	    hindex = (hindex + 1) % HZ;
	    flag = 1;
	    if (hindex == countindex)
	     {
	      printf ("Entry not possible\n");
	      return;
	     }
	   }
      h[hindex].key = a.empno;
      fseek (fp, 0, SEEK_END);
      h[hindex].addr = ftell (fp);
      fprintf (fp, "%d %s %d\n", a.empno, a.nm, a.sal);
      printf ("Entry successful....\n");
      if (flag)
	printf ("Linear probing used\n");
  }
}


int main ()
{
  ht h[HZ];
  EMP d;
  int n, ch;
  fp = fopen ("emp.txt", "w+");
  for (n = 0; n < HZ; n++)
    h[n].key = -1;
  for (;;)
   {
      printf ("1.Insert\n 2. Search\n 3.Display\n 4.exit\n");
      printf ("Enter the choice\n");
      scanf ("%d", &ch);
      switch (ch)
	   {
	    case 1:
	     printf ("Enter no of employees\n");
	     scanf ("%d", &n);
	     insert (h, n);
	     break;
	    case 2:
	      search (h, n);
	        break;
	    case 3:
	     display (h, n);
	      break;
	  default:
	    exit (0);
	}
}
  return 0;
}






