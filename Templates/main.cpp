#include <iostream>
using namespace std;

template<typename T>
T maximum(T const& a, T const& b){
    return a > b ? a : b;
}


template <typename T>
class X{
    private:
        T x;
    public:
        X(){}
        X(T _x){
            this->x = _x;
        }
        T getX() const{
            return x;
        }
        friend ostream& operator << (ostream& os, X const& obj){
            os << obj.x;
            return os;
        }
};
template<typename T>
bool operator > (X<T> const &a, X<T> const &b){
    return a.getX() > b.getX();
}

template<>
bool operator > (X<string> const &a, X<string> const &b){
    return a.getX().size() > b.getX().size();
}


template<typename T, typename C = X<T>>
class Y{
    T zmienna;
    C klasaX;
};

//Podpunkt 10
template <typename T>
class A {
    typename T::id i;
    public:
    void f() { i.g(); }
};

class B {
    public:
    class id{
        public: void g() { cout<<"Wywołano funkcję g"<<endl;}
    };
};

auto maxLambda = [](auto a, auto b) {return a>b ? a:b;};

int main(){
    cout<<maximum(6, 7)<<endl;              // jeśli oba argumenty są typu int albo double kompilator automatycznie ustala że typ 
    cout<<maximum(6.3, 7.3)<<endl;          // template może być tylko intem albo i doublem. Nie ma wtedy potrzeby specyfikowania w ostrych nawiasach typu zmiennej template.
    // cout<<maximum(6.5, 7)<<endl;        //błąd, typ template oczekuje dwóch argumentów tych samych typów. http://www.cplusplus.com/doc/oldtutorial/templates/
    cout<<maximum<double>(4, 5)<<endl;
    cout<<maximum<double>(4.1, 5.7)<<endl;
    cout<<maximum<int>(4.6, 3)<<endl;       //ustala, że oba argumenty to inty, wynik to 4
    cout<<maximum<double>(4.6, 3)<<endl;
    cout<<maximum<bool>(4.6, 3)<<endl;
    // cout<<maximum<string>(4.6, 3)<<endl;    //żadne wystąpienie elementu nie jest zgodne z listą argumentów
    cout<<maximum<string>("aaa","bb")<<endl;

    // cout<<maximum(X(4), X(3));              //Podpunkt 4, nie działa po przekształceniu klasy X na szablon, brakuje argumentów template

    cout<<maximum(X<int>(4), X<int>(3))<<endl;      //Śmiga
    cout<<maximum(X<string>("aaa"),X<string>("bb"))<<endl;

    Y<int> y;
    Y<int, double> y2;

    A<B> ab;
    ab.f();

    bool b = maxLambda(3, 3.14);        
    auto c = maxLambda(3, 3.14);
    //auto - zastępczy typ zmiennej, który zostanie wydedukowany na podstawie wartości za pomocą której zmienna zostanie zainicjalizowana.
    cout<<b<<endl;
    cout<<c<<endl;
}