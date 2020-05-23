// 1. Verilen 2 adet say�y� recursive fonksiyon ile �arpan fanksiyonu yaz�n�z. Say�lar fonksiyon parametresi olarak al�nacakt�r.
// 2. Macro yard�m�yla verilen  2 say�dan birincisini bir azalt�p ikinci say�n�n 3 eklenmi� haliyle �arp�n�z.
#include <stdio.h>
#define birincisoru(a,b) (((a)-1)*((b)+3)) // 2018-Vize2  2. sorunun cevab�, sadece 1 sat�r. :)
//  2018-Vize2  1. sorunun cevab�sadece int lale fonksiyonudur. 5 sat�rl�k kod. 
int recursive(int d, int e){
		static int c=0;
		
			if (e > 0) {
				c=d + c;
				e--;
				recursive(d,e);
			}
	return c;
	}

int main(){
	int d=20, e=7;
	printf("%d\n",recursive(d,e));
	printf("%d",birincisoru(d,e));  // 2018-Vize2  2. sorunun ekran ��kt�s�.
}

