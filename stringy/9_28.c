#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxstrlen(char *s){
  return *s?1+maxstrlen(s+1):0;
}

char * maxstrncpy(char *dest, char *src, int n){
  while(*src && n){
    *dest = *src;
    dest++;src++; n--;
  }
  return dest;
}


int maxstrcmp(char *x, char *y){
  //printf("this is nto a seg fault");
  return   !*x&&!*y?0:*x>*y?-1:*x>*y?1:maxstrcmp(x+1,y+1);
}

char * maxstrchr(char *s, char c){
  printf("*s = %p \n c = %\n",*s,c);
  if(!*s){
    return 0;
  }else if(*s==c){
    return s;
  }else{
    return maxstrchr((s+1),c);
  }

}

char * maxstrcat(char *s1, char *s2){
  char *s3 = s1;
  while(*s1){
    s1++;
  }
  while(*s2){
    *s1 = *s2;
    s2++;
  }
  return s3;
}
    
  
int main(){
  char a[] = "abc";
  char b[] = "axyz";
  printf("copy");
  char c[4]= "hii";
  char d[4]= "hii";
  strncpy(c,a,2);
  maxstrncpy(d,a,2);
  printf(" a --> c = %s\n a --> d = %s\n",c ,d);
  int e = strcmp(a,b);
  int f = maxstrcmp(a,b);
   printf("\ncompare\n a vs b reg = %d\n a vs b max = %d\n",e,f);
   printf("whatebver\n");
   char g = 'b';
   printf("strchr\n a --> 'b' regular=%s \n a --'b' max=%s\n",strchr(a,g),maxstrchr(a,g));
   printf("strcat\n c + a reguar %s \n c + a max =%s\n",strcat(c,"a"),maxstrcat(d,"a")); 
 return 0;
}
