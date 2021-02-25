#include <iostream>
#include <string>

int main () {
    std::string fellow = "world";
    while ( fellow != "exit" ) {
        std::cout<<"Hello " << fellow << std::endl;
        std::cout << "Introduce yourself: ";
        std::cout.flush();
        std::getline( std::cin, fellow );
        //std::cout << "Hello " << fellow << std:: endl;
    }
}

/* 
Obserwacje z debugowania kodu: 
Na obecnie wykonywane polecenie wskazuje żółta strzałka. Jest także podkreślone.
Możemy także śledzić zmieniające się wartości zmiennych oraz na jakie miejsce w pamięci wskazują.
*/

