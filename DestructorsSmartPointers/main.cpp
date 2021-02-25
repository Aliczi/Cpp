#include <memory>
#include "Wezel.h"
#include <iostream>

int main() {
    for (int i = 0; i < 10; i++) {
        //std::unique_ptr<Wezel>(new Wezel());
        std::shared_ptr<Wezel> w1 = std:: make_shared<Wezel>();
        std::shared_ptr<Wezel> w2 = std:: make_shared<Wezel>();
        w1->next = w2;
        w2->next = w1;
    }
    return 0;
}

/*
Podpunkt 4
Destruktor jest wywoływany za każdym razem gdy kończymy używanie obiektu.
*/

/*
Podpunkt 6
Uruchomienie takiego kodu nic nie zmieniło.
*/

/*
Podpunkt 9
Teraz program nie zwalnia pamięci jak należy.
Nie może usuwać obiektów do których nadal istnieją dowiązania.
Wskaźniki shared_ptr to wskaźniki współdzielone i może istnieć wiele wskaźników do tego samego obiektu.
Obiekty są wtedy usuwane dopiero w momencie gdy przestaje istnieć ostatni wskaźnik typu shared_ptr.

Dla porównania unique_ptr to wskaźnik uniwersalny i może istnieć tylko jeden wskaźnik tego typu pokazujacy na dany obiekt.
W momencie gdy przestaje istnieć wskaźnik usuwany jest obiekt.
Ponadto jeśli do wskaźnika przypiszemy inny obiekt to ten wcześniejszy także jest usuwany i zwalniana jest pamięć.
Obiekt wskazywany przez unique_ptr nie może być zarządzany przez inny obiekt tego typu ani też shared_ptr.
*/

/*
Podpunkt 10
weak_ptr to także sprytny wskaźnik (ang. smart pointer), który tworzy odwołanie do obiektu nie zwiększając liczby odwołań. (ang. weak reference).
Takie powiązanie pozwala na ttymczasowy dostęp do obiektu jeśli on istnieje, ponieważ może on być usunięty jako że weak_ptr nie jest wliczane do liczby odwołań.
Są używane żeby zapobiec cyklom odwołań kiedy reference count/liczba odwołań nie może osiągnąć zera.
Typowa implementacja weak_ptr wykorzystuje dwa wskaźniki, wskaźnik do bloku oraz wskaźnik to shared_ptr z którego był skonstruowany.

W projekcie RecyclingCpp można rozwiązać problem zwalniania pamięci poprzez zmianę wskaźnika next(10 i 11 linijka) na weak_ptr.
*/
