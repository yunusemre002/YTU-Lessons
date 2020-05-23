#include <stdio.h>
#include <stdlib.h>
// 4. terim ile 5. terim aras�na x i 500 olan node ekledik.


struct n{   // bir structure olu�turdum. BU structure bir adet x ten ve kendini point eden bir pointer next ten m�te�ekkil.
	int x;
	n *next;	
};
typedef struct n node; // n structure cinsinden node diye bir structure yaratt�m.

void bastir( node *r ){ // bastir diye bir fonctio nyazd�k bu fonsiyon 
	while(r!=NULL){		// verilen node null olana kadar node un x ini yazd�r�yor.
		printf("%d\n",r->x);	// 
		r = r->next ; // r node ponterimizi  bir sonraki node a ge�iriyoruz							
	}
}

void ekle (node *r, int x){		//ekle fonksiyonumuz
		while( r->next!= NULL )		//	nexti null g�sterern noda gitmeyi sa�l�yor yani en son node
			r = r->next;
		r->next=(node*)malloc(sizeof(node)); // en son node den sonra bir node daha a� nextine koy adresini
		r-> next -> x = x;					// yeni a��lan nosun x i verilen x olasun
		r-> next -> next = NULL;			// yeni olu�turulan nodumuzun nextini NULL yap�yoruz.
	}
		
int main(){
	int i=0;
	node *root, *iter; 
	root = (node*)malloc(sizeof(node)); // root un i�ine bir kutucuk a�t�m kutucuk iki k�s�ndan m�te�ekkil: 1 data 2 next
	root-> x =555; 
	root -> next = NULL;
	
	for(i=0;i<5;i++)
		ekle(root,(i*10));
	
	iter = root; // iterin 1. kutuyu g�stersin
	for(i=0;i<2;i++)		// iterimizi 3 node ilerletiyoruz
		iter = iter->next;  // �imdi iterimiz araya eleman ekleyece�imiz de�erden ilkini g�steriyor
		
	node *temp=(node*)malloc(sizeof(node));  // ekleyece�imiz node temp isimli bir pointerde tutuyoruz yaratt�k ayn� y-zamanda burada
	temp->next = iter->next;  // iterin nexti art�k nodumuzun nexti olacak ve  !!�NEML� �LK BUNU YAPMALIYIZ ki next bilgisini kaybetmeyelim.
	temp-> x =800;
	iter->next= temp;
	bastir(root);
}




