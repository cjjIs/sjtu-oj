#include <iostream>
using namespace std;

int mystrlen(const char *s)
{
int i=0;
while (s[i] != '\0')
++i;
return i;
}