#include <iostream>
#include <limits>
/*
biblioteca para usar las funciones que nos permitirán ver 
los límites en bytes
*/

using namespace std;

int main () {

    cout<< "Lo mínimo que puede almacenar un entero es: "
    <<numeric_limits <int>::min() <<endl;

    cout<< "Lo máximo que puede almacenar un entero es: " 
    <<numeric_limits <int>::max();

/*
    numeric_limits <tipo de dato>::min()
    numeric_limits <tipo de dato>::max()
*/
    return 0;
}