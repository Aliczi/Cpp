#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

class Samochod{

    private:
        float pojemnosc_baku;
        float poziom_paliwa;
        unsigned int liczba_kilometrow;
        string model;

    public:
        //Konstruktor bezparametrowy
        Samochod()
        {
            pojemnosc_baku=100.0;
            poziom_paliwa=50.0;
            liczba_kilometrow=10000;
            model="Golf";
        }
        //Konstruktor przyjący jako argumenty model samochodu oraz pojemność baku
        Samochod( float _pp, string _m ):pojemnosc_baku(_pp),model(_m)
        {
            poziom_paliwa=50.0;
            liczba_kilometrow=100;
        }

        // Kilka metod dla tej klasy:
        void display_model()
        {
            cout<<"Model samochodu: "<<this->model<<endl;
        }
        void display_poziom_paliwa()
        {
            cout<<"Poziom paliwa: "<<poziom_paliwa<<"l"<<endl;
        }
        void display_liczba_kilometrow()
        {
            cout<<"Liczba kilometrow: "<<liczba_kilometrow<<endl;
        }
        float odczytaj_pojemnosc_baku() const
        {
            return pojemnosc_baku;
        }
        int add_kilometers(int km)
        {
            liczba_kilometrow+=km;
            return liczba_kilometrow;
        }

        //Przeciążenie operatora bool()
        operator bool() const {
            if (this->pojemnosc_baku > 0 && this->model != "")
                return true;
            return false;
        }

        //Przeciążenie operatora !
        bool operator !() const {
            if (*this)
                return false;
            return true;
        }

        //Przeciążenie operatora <<
        friend ostream & operator << ( ostream &os, const Samochod &samochod){
            os << samochod.model << " " << samochod.poziom_paliwa<<"\n";
            return os;
        }

        /*
        Odpowiedź do podpunktu 8
        Funkcja zaprzyjaźniona ma dostęp do prywatnych atrybutów i metod danej klasy.
        */

        //Przeciążenie operatora <
        bool operator < (const Samochod &samochod) const {
            return this->model < samochod.model; 
        }

        /*
        Odpowiedź do podpunktu 10
        Słowo kluczowe const oznacza obiekty stałe oraz uniemożliwia modyfikację obiektu, także przypadkową.
        */
        
        //Podpunkt 15
        // https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
        Samochod& operator ++ () {
            this->model = this->model + " Plus";
            cout<<"Dodano do nazwy modelu przyrostek Plus.\n";
            return *this;
        } 

        Samochod operator |=( float lvl ){
            Samochod tmp = *this;
            this->poziom_paliwa+=lvl;
            cout<<"Dolano do baku: "<<lvl<<"l paliwa.\n";
            return tmp;
        }

        void operator , ( Samochod& autko){
            float tmp = this->poziom_paliwa;
            this->poziom_paliwa = autko.poziom_paliwa;
            autko.poziom_paliwa = tmp;
            cout<<"Zamieniono paliwo w bakach samochodow.\n";
        }      


};

//Struktura służąca do porównywania obiektów w zbiorze std::set
struct cmp {
            bool operator() (const Samochod &a, const Samochod &b) const{
                return a.odczytaj_pojemnosc_baku() < b.odczytaj_pojemnosc_baku();
            }
};


int main()
{
    Samochod s1 (123 , "audi" ) ;
    Samochod s2 ( 0 , "bmw" ) ;
    Samochod s3 (200 , "" ) ;
    if(s1) s1.display_model();
    if(!s1) s1.display_model();
    if(!s2) s2.display_model(); else cout<<"Obiekt nie posiada nazwy modelu albo pojemnosc baku jest niedodatnia\n";
    if(s2) s2.display_model(); else cout<<"Obiekt nie posiada nazwy modelu albo pojemnosc baku jest niedodatnia\n";
    if(s3) s3.display_model(); else cout<<"Obiekt nie posiada nazwy modelu albo pojemnosc baku jest niedodatnia\n";
    if(!s3) s3.display_model(); else cout<<"Obiekt nie posiada nazwy modelu albo pojemnosc baku jest niedodatnia\n"<<endl;
    
    cout << "Przeciazenie operatora <<: ";
    cout << s1;


    //Podpunkt 11
    cout<<"Sortowanie:"<<endl;
    vector <Samochod> v;
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    sort(v.begin(),v.end()); 
    for(auto it=v.begin(); it!=v.end(); ++it){
        cout<<*it<<endl;
    }
    cout<<"Koniec sortowania."<<endl;
    
    //Podpunkt 13
    set <Samochod, cmp> s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);
    for (auto it=s.begin(); it!=s.end(); ++it)
    {
        cout<<*it<<endl;
    }
    cout<<"Koniec porównywania elementów."<<endl;
    
    //Podpunkt 15
    Samochod s4;
    s4.display_model();
    ++s4;
    s4.display_model();

    s4.display_poziom_paliwa();
    s4|=15;
    s4.display_poziom_paliwa();

    cout<<"s1: "; s1.display_poziom_paliwa();
    cout<<"s4: "; s4.display_poziom_paliwa();
    s1, s4;
    cout<<"s1: "; s1.display_poziom_paliwa();
    cout<<"s4: "; s4.display_poziom_paliwa();

}