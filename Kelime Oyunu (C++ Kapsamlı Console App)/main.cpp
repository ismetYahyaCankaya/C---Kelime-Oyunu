#include <iostream>
#include <string>
#include <stdlib.h> 
#include <ctime> 
#include <algorithm> 
#include <windows.h>
using namespace std;
int main() {
	int secim,secim_oyun,puan=0,sayac=0,rastDizi[8];
	bool secim_kontrol,kelime_harf_kontrol,harf_alayim_kontrol,kelime_gec_kontrol=true;
	string kelime,girilen_k_tanim,cevap,kelime_yedek,derecelendirme="";
	string kelimeler[5],kelime_tanim[5];
	string def_kelimeler[5]={"saat","kalem","klavye","karakol","karargah"};
			string def_kelime_tanim[5]={"Bir gunun 24'te birine esit zaman birimi ve bu zamani olcmek için kullanilan alet.",
			"Yazma, cizme vb. islerde kullanilan cesitli bicimlerde arac.",
			"Bilgisayara veri ve komut girisini saglayan birim.",
			"Guvenligi saglamakla gorevli kimselerin bulundugu yapi",
			"Bir birlik ya da kurumun, kumandan, yardimci sube ve bolumlerinden olusan kurulus."};
			/* Oyunu Tasarlayan Kisinin Girdigi Kelimeleri ve Oyuncunun Girdi?i Kelimeleri Bir Karisiklik Olmamasi Icin Kucuk Harfe 
			Ceviriyorum, Asagidaki Diziler Bundan Oturu Tanimlanmistir.*/
	char kucuk_harf[23] ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','s','t','u','v','y','z'};
	char buyuk_harf[23] ={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Y','Z'};
	cout<<"Kelime Oyununa Hosgeldiniz"<<endl;
	cout<<"Elimizde sizin oynamaniz için hazir sorular bulunuyor fakat sorulari isterseniz kendiniz olusturup Baskasina Oynatabilirsiniz"<<endl;
	cout<<"1-Oyunu Hazir Sorularla Oynamak Istiyorum\n2-Sorulari Kendim Hazirlayip Baskasina Oynatmak Istiyorum"<<endl;
	
	do{	
	cout<<"Secim(1/2): "; cin>>secim;
	switch(secim)
	{ 
		case 1:{for(int b=0; b<5; b++) {kelimeler[b]=def_kelimeler[b]; kelime_tanim[b]=def_kelime_tanim[b];}
				secim_kontrol=false; break;}
				
		case 2:{
			for(int i=0; i<5; i++)
			{
			do{	
				cout<<i+4<<" Harfli Kelimeyi Girin (Buyuk Kucuk Harf Onemsiz): ";
				cin>>kelime; 
				if(kelime.length()==i+4)
				{
					cout<<i+4<<" Harfli Kelimeniz Kabul Edildi."<<endl;
					
					for(int k=0; k<i+4; k++)
					{
						for(int b=0; b<23; b++) {if(kelime[k]==buyuk_harf[b]) {kelime[k]=kucuk_harf[b];}}
					}
					kelimeler[i]=kelime;
					cout<<i+4<<" Harfli Kelimeyi Oyuncuya Tanimlayin: "<<endl;
					cin>>girilen_k_tanim; kelime_tanim[i]=girilen_k_tanim; kelime_harf_kontrol=false;
				}
				else
				{
					cout<<i+4<<" Harfli Bir Kelime Girmeniz Gerekiyordu, Siz "<<kelime.length()<<" Harfli Kelime Girdiniz."<<endl;
					cout<<"Lutfen Yeniden Deneyiniz..."<<endl; kelime_harf_kontrol=true;
					
				}
			  } while(kelime_harf_kontrol);	
			}
				secim_kontrol=false; break;
			}
			default:{ cout<<"Lutfen Mevcut Seceneklerden Birisini Secin !"<<endl; secim_kontrol=true;  break;}
		}
	}while(secim_kontrol);	
	if(secim==2){
	cout<<"* Girdiginiz Kelimeler ve Tanimlari *"<<endl;
	for(int y=0; y<5; y++)
	{
		cout<<"Girdiginiz "<<y+1<<". Kelime: "<<kelimeler[y]<<endl;
		cout<<"Girdiginiz"<<y+1<<". Kelimenin Tanimi: "<<kelime_tanim[y]<<endl;
	}
	cout<<"Oyun Ekranina Yonlendiriliyorsunuz...";
	Sleep(3000); //Kullanici 3 saniye bekletiliyor.
	system("cls");
	}
	cout<<"Toplam Puan: "<<puan<<endl;
	for(int c=0; c<8; c++){rastDizi[c]=c;}	
	for(int x=0; x<5; x++)
	{		
		if(kelime_gec_kontrol)
		{	
			kelime_yedek=kelimeler[x];
			srand(time(NULL));	
			random_shuffle(rastDizi,rastDizi+(x+4));
			cout<<"\n\n"<<x+1<<"- "<<kelime_tanim[x]<<"\n"<<endl;
			for(int d=0; d<x+4; d++)
				{Sleep(200); cout<<" _ ";}
		}
		cout<<"\n\n1-Harf Alayim\n2-Cevap Vermek Istiyorum\nSecim(1/2): "; cin>>secim_oyun;
		
		switch(secim_oyun)
		{
			case 1:
			{
				puan-=100;cout<<"\nHarf Aldiginiz Icin -100 Puan.\nPuan: "<<puan<<"\n"<<endl;
				for(int a=0; a<x+4; a++)
				{
				 harf_alayim_kontrol=true;
				 for(int l=0; l<sayac+1; l++)
				 {
				 	if(rastDizi[l]==a){Sleep(200); cout<<" "<<kelime_yedek[a]<<" ";harf_alayim_kontrol=false;}
				 }	
					if(harf_alayim_kontrol){Sleep(200); cout<<" _ ";}
				}	
				if(sayac!=x+3){sayac++; x--; kelime_gec_kontrol=false;}
				else{kelime_gec_kontrol=true;sayac=0;} break;}
			case 2:{
				do{
				cout<<"Cevabiniz: "; cin>>cevap; kelime_harf_kontrol=false;
				for(int r=0; r<x+4; r++)
					{
						for(int n=0; n<23; n++) {if(cevap[r]==buyuk_harf[n]) {cevap[r]=kucuk_harf[n];}}
					}
				if(cevap.length()==x+4)
				{
				if(cevap==kelimeler[x]) {puan+=(x+4-sayac)*100; 
				cout<<endl;
				for(int g=0; g<x+4; g++)
				{
					Sleep(200);
					cout<<" "<<kelime_yedek[g]<<" ";
				}
				cout<<"\n\nCevabiniz Dogru! + "<<(x+4-sayac)*100<<" Puan!"<<endl;}
				else { puan-=(x+4-sayac)*100; cout<<"\n\nYanlis Cevap - "<<(x+4-sayac)*100<<" Puan."<<endl;}
				cout<<"\nToplam Puan: "<<puan<<endl;
				kelime_gec_kontrol=true;
				sayac=0;
				}
				else{cout<<"\n"<<x+4<<" Harfli Bir Kelime Girmeniz Gerekiyordu, Siz "<<cevap.length()<<" Harfli Kelime Girdiniz."<<endl;
					cout<<"\nLutfen Yeniden Deneyiniz..."<<endl; kelime_harf_kontrol=true;}
			}while(kelime_harf_kontrol); break;
			}
			default: {cout<<"\nLutfen Mevcut Seceneklerden Birisini Secin !"<<endl; x--; break;}
		}
	}
	
	if(puan>0 && puan<1000){derecelendirme="Idare Edersiniz Iste...";}
	else if(puan>=1000 && puan<2000){derecelendirme="Masallahiniz Var :)";}
	else if(puan>=2000 && puan<3000){derecelendirme="Tas Gibisiniz Tasss...";}
	else if(puan==3000){derecelendirme="Siz Bir Mucizesiniz...";}
	else{derecelendirme="Berbatsiniz.";}
	cout<<"\nOyunun Sonuna Geldik, "<<puan<<" Puan Ile "<<derecelendirme;	
}
