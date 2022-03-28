//Tipos de datos primitivos en C++

#include <iostream>
using namespace std;

/*
data type     |        meaning            size (in bytes)
----------------------------------------------------------
int           |        integer                  2 
float         |        floating-point           4 
double        |        double floating-point    8   
char          |        character                1
wchar_t       |        wide character           2
bool          |        boolean                  1
void          |        empty                    0
*/

int main () {

/*
alt + shift + ↕     |   Duplica linea de codigo
alt + ↕             |   Mueve linea de código
*/
    cout<< sizeof (int) <<endl;

    double d;
    cout<< sizeof(d) <<endl;

    char a[10];
    cout<< sizeof(a) <<endl;

/*
la función 'sizeof(<dato>)' nos permite saber el tamaño en
bytes de 
*/

    return 0;
}
