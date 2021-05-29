/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class array
{
public:
  int *A;
  int size;
  int length;

};
int binarysearch (int a[], int key, int n)
{
  int l = 0, h = n - 1, mid;
  while (l <= h)
    {
      mid = (l + h) / 2;
      if (key == a[mid])
	{
	  return mid + 1;
	}
      else if (key < a[mid])
	{
	  h = mid - 1;
	}
      else
	{
	  l = mid + 1;
	}
    }
  return -1;
}

void display (int a[], int n)
{
  for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
}

int recurbs (int a[], int l, int h, int key)
{
  int mid;
  if (l <= h)
    {
      mid = (l + h) / 2;
      if (key == a[mid])
	return mid + 1;
      else if (key < a[mid])
	{
	  return recurbs (a, l, mid - 1, key);
	}
      else
	{
	  return recurbs (a, mid + 1, h, key);
	}
    }
  return -1;
}


int main ()
{
  // Write C++ code here
  array obj;
  cout << "Enter size ";
  cin >> obj.size;
  obj.A = new int[obj.size];
  for (int i = 0; i < obj.size; i++)
    {
      cin >> obj.A[i];
    }
  //display(obj.A,obj.size);
  int k;
  cout << "Enter key \n";
  cin >> k;
  //cout<<binarysearch(obj.A,k,obj.size);
  cout << recurbs (obj.A, 0, obj.size - 1, k);
  return 0;
}
