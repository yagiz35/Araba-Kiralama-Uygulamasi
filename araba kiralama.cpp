#include <iostream>
#include <conio.h>
using namespace std;


class Araba{
protected:
    string model,sinif,vites,yakitTuru;
    int surucuYas,ehliyetYas;
    float fiyat;

public:
   // Araba();
   //copy cons
    Araba(const Araba &a) {model=a.model; sinif=a.sinif; vites=a.vites; yakitTuru=a.yakitTuru;  fiyat=a.fiyat; surucuYas=a.surucuYas; ehliyetYas=a.ehliyetYas; }

    Araba(string _model, string _sinif, string _vites, string _yakitTuru , float _fiyat , int _surucuYas, int _ehliyetYas );

    string modelYazdir()
    {return "Model:"+model+"\t\t\tSinif:"+sinif+"       \t\t*\n\t\t*\t\t\t\t\t\t\t\t\t\t*"+"\t\t\n\t\t*\tVitesi: " + vites + "\t\t\tYakit turu: " +yakitTuru;}

    float fiyatYazdir(){return fiyat;}

    int surucuYasYazdir(){return surucuYas;}

    int ehliyetYasYazdir(){return ehliyetYas;}

    string secilenSinifDondur() {return sinif;}


};
Araba arabalar[15]={Araba("Peugeot 301","Ekonomi","Manuel  ","Benzinli",150.18,21,1),
 Araba("Citroen C Elysee","Ekonomi","Manuel  ","Benzinli",150.18,21,1),
 Araba("Fiat Egea ","Ekonomi","Otomatik","Dizel",120.20,21,1),
 Araba("Honda Civic","Ekonomi","Otomatik","Dizel",143.93,21,1),

 Araba("Toyota Corolla","Orta Sinif","Otomatik","Dizel",175.75,23,2),
 Araba("Opel Corsa","Orta Sinif","Otomatik","Dizel",200.20,23,2),
 Araba("Peugeot 301","Orta Sinif","Manuel   ","Benzinli",220.98,23,2),
 Araba("Ford Focus","Orta Sinif","Manuel   ","Benzinli",250.55,23,2),

 Araba("Volkswagen Passat","Premium","Otomatik","Dizel",241.87,27,2),
 Araba("Audi A3 Sedan","Premium","Otomatik","Dizel",390.87,27,2),
 Araba("Mini Cooper","Premium","Otomatik","Benzinli",280.80,27,2),
 Araba("Seat Toledo","Premium","Otomatik","Benzinli",271.43,27,2),

 Araba("Nissan Qashqai","SUV","Otomatik","Dizel",262.56,27,5),
 Araba("Volvo XC40","SUV","Otomatik","Dizel",475.54,27,5),

 Araba("Jaguar F-Pace","Luks","Otomatik","Dizel",410.20,25,5)};

class elektrikliAraba: public Araba{
    private:
        int menzil,coIkiEmisyonu;

    public:

        elektrikliAraba(const elektrikliAraba &a):Araba(a)
        {menzil=a.menzil; coIkiEmisyonu=a.coIkiEmisyonu; }//https://stackoverflow.com/questions/17311382/how-to-call-base-class-copy-constructor-from-a-derived-class-copy-constructor

        elektrikliAraba();
        elektrikliAraba(string _model, string _sinif, string _vites, string _yakitTuru , float _fiyat , int _surucuYas, int _ehliyetYas,int _menzil, int _coIkiEmisyonu):
        menzil(_menzil),coIkiEmisyonu(_coIkiEmisyonu),Araba(_model,_sinif,_vites,_yakitTuru,_fiyat,_surucuYas,_ehliyetYas){}

        int menzilYazdir(){return menzil;}

        int coIkiEmisyonuYazdir(){return coIkiEmisyonu;}

};
elektrikliAraba ElektrikliArabalar[3]={elektrikliAraba("BMW i3s (120 Ah)","Ozel","Otomatik  ","Elektrikli",150.18,21,1,260,0),
elektrikliAraba("Renault Zoe","Ozel","Otomatik  ","Elektrikli",150.18,21,1,395,0),
elektrikliAraba("Tesla Model 3","Ozel","Otomatik","Elektrikli",300.55,21,1,392,0)};

class Musteri{
string ad,soyad,ePosta,tc,telNo;
int dogumYas,ehliyetYasi;
public:
friend string uyelikBilgileri(Musteri&);
void musteriEris(int _dogumYas, int _ehliyetYasi){dogumYas=_dogumYas; ehliyetYasi=_ehliyetYasi;}
int dogumYasYazdir(){return dogumYas;}
int ehliyetYasiYazdir(){return ehliyetYasi;}
}arabaMusteri;



Araba :: Araba(string _model, string _sinif, string _vites, string _yakitTuru , float _fiyat, int _surucuYas, int _ehliyetYas){

    model= _model;
    sinif=  _sinif;
    vites= _vites;
    yakitTuru= _yakitTuru;
    fiyat= _fiyat;
    surucuYas= _surucuYas;
    ehliyetYas = _ehliyetYas;

}

string uyelikBilgileri(Musteri& a){

cout<<"Adinizi giriniz:";
cin>>a.ad;
cout<<"\nSoyadinizi giriniz:";
cin>>a.soyad;
cout<<"\nE-postanizi giriniz:";
cin>>a.ePosta;
cout<<"\nTc kimlik numaranizi giriniz:";
cin>>a.tc;
cout<<"\nTelefon numaranizi giriniz: +90";
cin>>a.telNo;

return "Sn. "+a.ad+" "+a.soyad+",\nFatura bilginiz, "+a.ePosta+"  adresine ve "+a.telNo+" nolu telefon numaraniza sms olarak gonderilmistir.\n";


}

bool musteriDy(int y,int ey,string sf){
    if(sf=="Ekonomi" && y>=21 && ey>=1)
        return true;

    else if(sf== "Ozel" && y>=21 && ey>=1)
        return true;

    else if(sf=="Orta Sinif" && y>=23 && ey>=2)
        return true;

    else if(sf=="Premium" && y>=27 && ey>=2)
        return true;

    else if(sf=="SUV" && y>=27 && ey>=5)
        return true;

    else if(sf=="Luks" && y>=25 && ey>=5)
        return true;

    else
        return false;

}


float hesapla(float i){
    int birIki;
    char eh,eh2;
   cout<<"Arabayi gunluk kiralamak icin(1) Aylik kiralamak icin (2)(aylik kiralamada %25 inidirim mevcuttur)"<<endl;
   cout<<"Seciminiz?:";
   cin>>birIki;
   if(birIki==1){
        int kacGun;
        cout<<"Kac gun kiralamak istersiniz?"<<endl;
        cin>>kacGun;
        cout<<"Ekstra olarak: Bebek koltugu ister misiniz?(35TL x Gun) Evet icin(E) - Hayir icin(H)"<<endl;
        cin>>eh;
        cout<<"Ekstra olarak: Sofor hizmeti ister misiniz?(40TL x Gun) Evet icin(E) - Hayir icin(H)"<<endl;
        cin>>eh2;
        if((eh=='E'||eh=='e')&&(eh2=='H'||eh2=='h'))
            return (i+35)*kacGun;

        else if((eh=='H'||eh=='h')&&(eh2=='E'||eh2=='e'))
            return (i+40)*kacGun;

        else if((eh=='E'||eh=='e')&&(eh2=='E'||eh2=='e'))
            return (i+75)*kacGun;

        else if((eh=='H'||eh=='h')&&(eh2=='H'||eh2=='h'))
            return kacGun*i;

        else{
        cout<<"Hatali ya da eksik veri girdiniz \nLutfen tekrar giriniz"<<endl;
        return hesapla(i);
    }

}
    else if(birIki==2){
        int kacAy;
        cout<<"Kac ay kiralamak istersiniz?"<<endl;
        cin>>kacAy;
        cout<<"Ekstra olarak: Bebek koltugu ister misiniz?(26.25TL x Gun) Evet icin(E) - Hayir icin(H)"<<endl;
        cin>>eh;
        cout<<"Ekstra olarak: Sofor hizmeti ister misiniz?(40TL x Gun) Evet icin(E) - Hayir icin(H)"<<endl;
        cin>>eh2;

        if((eh=='E'||eh=='e')&&(eh2=='H'||eh2=='h'))
            return ((i+35)*kacAy*30)*0.75;

        else if((eh=='H'||eh=='h')&&(eh2=='H'||eh2=='h'))
            return kacAy*i*30*0.75;

        else if((eh=='H'||eh=='h')&&(eh2=='E'||eh2=='e'))
        return (i+40)*30*kacAy*0.75;

        else if((eh=='E'||eh=='e')&&(eh2=='E'||eh2=='e'))
            return (i+75)*kacAy*30*0.75;

    else{
    cout<<"Hatali ya da eksik veri girdiniz \nLutfen tekrar giriniz"<<endl;
    return hesapla(i);
    }


}
else{
cout<<"Hatali ya da eksik veri girdiniz \nLutfen tekrar giriniz"<<endl;
return hesapla(i);
    }
}

void yazdir();

void elektrikliYazdir();

void anaMenu();



int main()
{
    int arabasec,girdi;
    float c;
    bool m;
    string a,i;
    int mYas,eSure;
    char yeniSec;
        anaMenu();
        cin>>girdi;
        if(girdi==1){
         buraya:
        cout<<"\t\tLutfen araba seciniz"<<endl;
        yazdir();
        cin>>arabasec;
        Araba secilen(arabalar[arabasec-1]);
        a=uyelikBilgileri(arabaMusteri);
        cout<<"Lutfen sirasiyla yasinizi ve ehliyetinizin kac yillik oldugunu giriniz:"<<endl;
        cin>>mYas>>eSure;
        arabaMusteri.musteriEris(mYas,eSure);
        m=musteriDy(arabaMusteri.dogumYasYazdir(),arabaMusteri.ehliyetYasiYazdir(),secilen.secilenSinifDondur());
            if(m==true){
                c= hesapla(secilen.fiyatYazdir());
                    cout<<"Odemeniz gereken ucret: "<<c<<"TL"<<endl;
                    cout<<a<<endl;
            }
                else{
                    cout<<"Yasiniz ya da gereken ehliyet suresi uygun degil"<<endl;
                    cout<<"Yeni bir araba secmek icin (E) Araba secmeden cikmak icin (H) giriniz"<<endl;
                    cin>>yeniSec;
                    if(yeniSec=='E' || yeniSec=='e'){
                        system("cls"); //https://stackoverflow.com/a/64937773/13818031
                        goto buraya;
                    }


                    else if(yeniSec=='H' || yeniSec=='h')
                        cout<<"Bir sonraki kiralama isleminizde bizi secmeniz umuduyla";
                    else
                        cout<<"Upps bir seyler ters gitti";
            }
        }
        else if(girdi==2){
        bura:
        cout<<"\t\tLutfen araba seciniz"<<endl;
        elektrikliYazdir();
        cin>>arabasec;
        elektrikliAraba secilen(ElektrikliArabalar[arabasec-1]);
        a=uyelikBilgileri(arabaMusteri);
        cout<<"Lutfen sirasiyla yasinizi ve ehliyetinizin kac yillik oldugunu giriniz:"<<endl;
        cin>>mYas>>eSure;
        arabaMusteri.musteriEris(mYas,eSure);
        m=musteriDy(arabaMusteri.dogumYasYazdir(),arabaMusteri.ehliyetYasiYazdir(),secilen.secilenSinifDondur());
            if(m==true){
                c= hesapla(secilen.fiyatYazdir());
                    cout<<"Odemeniz gereken ucret: "<<c<<"TL"<<endl;
                    cout<<a<<endl;
            }
                else{
                    cout<<"Yasiniz ya da gereken ehliyet suresi uygun degil"<<endl;
                    cout<<"Yeni bir araba secmek icin (E) Araba secmeden cikmak icin (H) giririniz"<<endl;
                    cin>>yeniSec;
                    if(yeniSec=='E' || yeniSec=='e'){
                        system("cls"); //https://stackoverflow.com/a/64937773/13818031
                        goto bura;
                    }


                    else if(yeniSec=='H' || yeniSec=='h')
                        cout<<"Bir sonraki kiralama isleminizde bizi secmeniz umuduyla";
                    else
                        cout<<"Upps bir seyler ters gitti";
            }
        }
        else if(girdi==3){
            cout<<"\n\t\t1-)Bebek koltugu 1 gun icin 35TL,"<<endl;
            cout<<"\t\t2-)Sofor hizmeti 1 gun icin 40TL\n"<<endl;
            cout<<"\t\tDevam etmek icin herhangi bir tusa basiniz ve enterlayiniz "<<endl;
            cin>>i;
            system("cls"); //https://stackoverflow.com/a/64937773/13818031
            return main();
        }
        else if(girdi==0){
            cout<<"Bir sonraki kiralama isleminizde bizi secmeniz umuduyla";
        }



return 0;
}


void yazdir(){
cout<<"\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
for(int i=0; i<15; i++){
    cout<<"\t\t*\tAraba "<<i+1<<"-)\t\t\t\t"<<"Fiyat: "<<arabalar[i].fiyatYazdir()<<"TL\t\t\t*"<<endl;
    cout<<"\t\t*\t\t\t\t\t\t\t\t\t\t*"<<endl;
    cout<<"\t\t*\t"<<arabalar[i].modelYazdir()<<"\t\t*"<<endl;
    cout<<"\t\t*\t\t\t\t\t\t\t\t\t\t*"<<endl;
    cout<<"\t\t*\tMin Surucu Yasi:"<<arabalar[i].surucuYasYazdir();
    cout<<"\t\t\tGereken Ehliyet Suresi:"<<arabalar[i].ehliyetYasYazdir()<<"\t*"<<endl;
cout<<"\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    }
    cout<<"Araba Seciminiz?:";

}

void elektrikliYazdir(){
cout<<"\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
for(int i=0; i<3; i++){
    cout<<"\t\t*\tAraba "<<i+1<<"-)\t\t\t\t"<<"Fiyat: "<<ElektrikliArabalar[i].fiyatYazdir()<<"TL\t\t\t*"<<endl;
    cout<<"\t\t*\t\t\t\t\t\t\t\t\t\t*"<<endl;
    cout<<"\t\t*\t"<<ElektrikliArabalar[i].modelYazdir()<<"\t\t*"<<endl;
    cout<<"\t\t*\t\t\t\t\t\t\t\t\t\t*"<<endl;
    cout<<"\t\t*\tMin Surucu Yasi:"<<ElektrikliArabalar[i].surucuYasYazdir();
    cout<<"\t\t\tGereken Ehliyet Suresi:"<<ElektrikliArabalar[i].ehliyetYasYazdir()<<"\t*"<<endl;
    cout<<"\t\t*\t\t\t\t\t\t\t\t\t\t*"<<endl;
    cout<<"\t\t*\tAlabilecegi Menzil:"<<ElektrikliArabalar[i].menzilYazdir()<<"\t";
    cout<<"\t\tGunluk CO2 Emisyonu:"<<ElektrikliArabalar[i].coIkiEmisyonuYazdir()<<"\t\t*"<<endl;
cout<<"\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    }
    cout<<"Araba Seciminiz?:";

}

void anaMenu(){
    cout<<"\n\t\t\t\t**************** Alo Arac a hosgeldiniz ****************\n"<<endl;
    cout<<"\t\t\t\t\t******************************************\n";
	cout<<"\t\t\t\t\t**\t\t\t\t\t**\n";
	cout<<"\t\t\t\t\t**\t   1-) Araclari Listele\t\t**\n";
	cout<<"\t\t\t\t\t**\t   2-) Elektrikli Araclari\t**\n";
	cout<<"\t\t\t\t\t**\t       Listele\t\t\t**\n";
	cout<<"\t\t\t\t\t**\t   3-) Ekstralari gor\t\t**\n";
	cout<<"\t\t\t\t\t**\t   0-) Cikis\t\t\t**\n";
	cout<<"\t\t\t\t\t**\t\t\t\t\t**\n";
	cout<<"\t\t\t\t\t**\t\t\t\t\t**\n";
	cout<<"\t\t\t\t\t******************************************\n";
	cout<<"\t\t\t\t       Lutfen Secim Yapiniz  :  ";
}
