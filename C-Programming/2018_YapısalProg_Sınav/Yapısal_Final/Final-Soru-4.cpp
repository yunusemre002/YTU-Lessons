#include <stdio.h>
#include <string.h>

char *copy(char *strana, unsigned int n){
	char *strdonn;
	int i=0, k=0;
//  int lenght=strlen(strana); // b�yle bir�ey yok s�navda sallam��s�n!
	for(i=n;i<30;i++){
		strdonn[k]=strana[i];
		k++;
}
	return strdonn;
	
}
//15 ve sonras� i�in d�zg�n �al���yor ama 15 in alt� i�in sa�mal�yor.

int main(){
	char *strana="yunus emre demir sinopta dogdu";
	char *strdonn;
	unsigned int n=0, i=0;	
	
	printf("Kacinci elemandan itibaren kopyalamk istersiniz!\n");
	scanf("%d",&n);
	
	strdonn=copy(strana,n);
	printf("%s",strdonn);
	return 0;
}
