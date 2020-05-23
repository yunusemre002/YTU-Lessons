#include <stdio.h>
#include <stdlib.h>

struct n{   // bir structure olu�turdum. BU structure bir adet x ten ve kendini point eden bir pointer next ten m�te�ekkil.
	int x;
	n *next;	
};
typedef struct n node; // n structure cinsinden node diye bir structure yaratt�m.

void bastir( node *r ){
	while(r!=NULL){
		printf("%d\n",r->x);
		r = r->next ;
	}
}

int main(){
	int i=0;
	node *root; /* node structuremizin root yani ba�lang�� adresini tutan bir pointer yaratt�m bu root �ok �nemli
				 Linked listlerde e�er ba�lang�c� bilmiyorsak liste yok demektir oy�zden root �nemli*/
	root = (node*)malloc(sizeof(node));  // root un i�ine bir kutucuk a�t�m kutucuk iki k�s�ndan m�te�ekkil: 1 data 2 next
	root -> x =10;		// kutucu�un data k�sm�na 10 koydum				
	root -> next = (node*)malloc(sizeof(node)); //next k�sm�ndada a�t���m bir kutucu�un adresini tutuyorum ��nk� next bir pointer.
	root -> next -> x =20; // 1. kutu i�indeki nextin g�sterdi�i adresteki kutunun (yani 2. kutu) data k�sm�na 20 koyuyorum.
	root -> next -> next = (node*)malloc(sizeof(node)); // 2. kutunun next k�sm�na 3. kutu yarat�p adresini koyuyorum.
	root ->next ->next -> x =30; // 3. kutunun data k�sm�na 30 koyduk
	root ->next ->next -> next =NULL;
	node *iter;  // iteration adl� bir pointer tan�ml�yorum buda ayn� structureyi point ediyor bunu istedi�im gibi gezmek i�in tan�mlad�m. Rootu sadece 1. kutunun yerini tutmak i�in ta�mlam��t�m bunun gezmek i�in tan�mlad�m.
	iter = root; // iterin 1. kutuyu g�stersin
	printf("%d\n",iter->x);  // data k�sm�nda birinci kutunun data k�sm� var.
	iter = iter->next; // iter 2. kutuyu g�stersin
	printf("%d\n",iter->x);  // data k�sm�nda 2. kutunun datas� var
	iter=root;
	while(iter->next != NULL){
		i++;
		printf("%d.eleman = %d\n",i,iter ->x);
		iter= iter->next;
	}
	
	for(i=0;i<5;i++){
		iter->next= (node*)malloc(sizeof(node));
		iter = iter->next;
		iter -> x = i*10;	
		iter -> next= NULL;
	}
//	iter -> next= NULL; burayada koyabiliriz.
	bastir(root);
}
