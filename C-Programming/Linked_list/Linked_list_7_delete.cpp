#include <stdio.h>
#include <stdlib.h>
// s�ral� eleman ekleme
struct n{   // bir structure olu�turdum. BU structure bir adet x ten ve kendini point eden bir pointer next ten m�te�ekkil.
	int x;
	n *next;	
};
typedef struct n node; // n structure cinsinden node diye bir structure yaratt�m.

void bastir( node *r ){ // bastir diye bir fonctio nyazd�k bu fonsiyon 
	while(r!=NULL){		// verilen node null olana kadar node un x ini yazd�r�yor.
		printf("%d  ",r->x);	// 
		r = r->next ; // r node ponterimizi  bir sonraki node a ge�iriyoruz							
	}
	printf("\n");
}
void ekle (node *r, int x){		//ekle fonksiyonumuz
		while( r->next!= NULL )		//	nexti null g�sterern noda gitmeyi sa�l�yor yani en son node
			r = r->next;
		r->next=(node*)malloc(sizeof(node)); // en son node den sonra bir node daha a� nextine koy adresini
		r-> next -> x = x;					// yeni a��lan nosun x i verilen x olasun
		r-> next -> next = NULL;			// yeni olu�turulan nodumuzun nextini NULL yap�yoruz.
	}
node *ekleSirali(node *r, int x){
	
	if(r==NULL){  // durum 1 e�er tamammen bo�sa hi� bi�i yoksa i�eride
		r=(node*)malloc(sizeof(node));
		r->next=NULL;
		r -> x = x;
		return r;
	}
	if (x < (r->x) ){ // e�er gelen eleman ilk elemandan k���k ise
		//root de�i�iyor �nemli bir nokta
		node *temp =(node*)malloc(sizeof(node));  // ekleyece�imiz node temp isimli bir pointerde tutuyoruz yaratt�k ayn� y-zamanda burada
		temp-> x = x;
		temp->next = r;  // iterin nexti art�k nodumuzun nexti olacak ve  !!�NEML� �LK BUNU YAPMALIYIZ ki next bilgisini kaybetmeyelim.
		return temp;
	}
	
	node *iter=r;
	while(iter->next!=NULL && (iter->next->x) < x) // iterin sonuna kadar ve x ten b�y�k bir say� g�rene dkadar git x ten b�y�k say�y� bulup �n�ne ekleme yapaca��m�z i�in iter->next->x yazd�k
		iter=iter->next;
	node *temp=(node*)malloc(sizeof(node));  // ekleyece�imiz node temp isimli bir pointerde tutuyoruz yaratt�k ayn� y-zamanda burada
	temp->next =iter->next;  // iterin nexti art�k nodumuzun nexti olacak ve  !!�NEML� �LK BUNU YAPMALIYIZ ki next bilgisini kaybetmeyelim.
	iter->next=temp;
	temp->x=x;
	return r;
	
}
	
node *sil(node *r, int x){
	node *temp;
	node *iter=r;

	if(r->x == x){
		temp = r;
		r = r ->next;
		free(temp);
		return r;
	}	
	while (iter->next != NULL && iter->next->x != x){
		iter=iter->next;
	}
	if (iter->next == NULL){
		printf("Sayi bulunamadi  ");
		return r;
	}
	temp =iter->next;
	iter->next=iter->next->next;
	free(temp);
	return r;
}
	
int main(){
	int i=0;
	node *root, *iter; /// node structuremizin root yani ba�lang�� adresini tutan bir pointer yaratt�m bu root �ok �nemli
    root = NULL;

	root= ekleSirali(root,555); // neden roota e�itledik ��nk� verilen eleman �ok k���kse en ba�a alacak ve art�k root bu eleman olacak di�erlerinin hepside ba�lang�c� d�nd�r�yor zaten no problemo
	root= ekleSirali(root,55);
	root= ekleSirali(root,5);
	root= ekleSirali(root,700);
	root= ekleSirali(root,57);
	bastir(root);
	root=sil(root,57);
	bastir(root);
	root=sil(root,999);
	bastir(root);
	root=sil(root,555);
	bastir(root);
	root=sil(root,700);
}




