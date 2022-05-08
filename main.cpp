#include <iostream>

using namespace std;

/*
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
APUNTADORES

tipo de dato que contendra una direccion de memoria de donde
se encuentra el dato real

apuntador a cadena guarda la direccion en memoria de la cadena,
si accedemos a la direccion de memoria encontraremos el dato

    | <tipo>* <identificador>; |  prototipo
    | int*    p;               |  declaracion de apuntador
    | int     *p;
    |                          |
    | p = new int;             |  inicalizacion de heap

No podemos definir varios apuntadores en un solo renglon, en caso
de hacerlo pondremos < * > a todos

    < int *p, *q, *t; >

declaramos varios apuntadores para entero en un solo reglon

    < int* p, q, t; >

esta declaracion solo haria un apuntador y dos variables tipo entero

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

STACK & HEAP

Debemos tener cuidado con estos conceptos ya que pueden repre-
sentar una estrcutura de datos, o un concepto relacionado a
memoria dinamica

Stack o Pila:
bloque de memoria o conjunto de direcciones de memoria asignados
para un programa dado por el sistema operativo, aqui estaran
variables, constantes, funciones, etc, incluso la recursividad
que tiene llamados pendientes, se añaden al stack


Heap o "monticulo":
Es la memoria libre del SO, compartida para todos los programas,
todos los programas, desde los instalados hasta los que creamos
pueden solicitar memoria del heap, el uso de esta es responsabilidad
del programa, y esta memoria no se libera de forma automatica, por
lo tanto es responsabilidad del programa liberar el bloque de memoria,
en caso de no hacerlo eventualmente nos quedaremos sin memoria o recursos
en nuestra PC

De estos conceptos nace la memoria dinamica, de la cual tenemos que ser
cuidadosos de no agotar los recursos, aunque, sin sucedira que olvidaramos
liberar todos los bloques de memoria, bastaria con reiniciar la PC

- - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - -

CREACION DE BLOQUES DE MEMORIA HEAP

            <new>

la palabra reservad <new> nos permite crear y reservar un espacio en
memoria en el heap, la palabra <new> nos retornara una direccion de memoria

    | new <tipo>; |
    | new int;    |

estamos pidiendo al SO la memoria necesaria para almacenar un entero
y el control de las direcciones de memoria requeridas

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - -

EJEMPLOS

    < int* p = new int (33); >

p se encuentra en el stack (memoria para el programa),
mientras que new solicita memoria libre al SO con heap,
las direcciones en memoria son asignadas en hexadecimal
y se ha guardado dentro del apuntador p

    p contiene < 0x33221100 >
    0x33221100 contiene < 33 >

si <p> fuera un arreglo, esta variable guardaria
la direccion en memoria donde comienza el arreglo,
heap nos entregara todo el bloque de memoria neceario

Siempre habra mas memoria en heap que en stack, para usar bloques
de memoria grande hemos de pedir al SO memoria en el heap

si saturamos de informacion al stack ocurrira un
< stack overflow >, desbordamiento de memoria y por consecuencia,
fallo del programa

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

CREACION DE BASURA

    | int* p = new int (33); | declaracion de apuntador
    |                        |
    | p = new int (55);      |  redireccionamiento de *

si redireccionamos un apuntador, crearemos un dato basura
ya que no habra forma de volver a la direccion de memoria apuntada
(solo se podra si lo programamos), pero el SO nos entrega el control
de la memoria, si perdemos la referencia se vuelve innaccesible y ningun
programa podra utilizarla ya que se encontrara reservada, el SO
no podra utilizarla ni nosotros acceder a ella

algunos lenguajes cuentan con recolector de basura, pero c++ no cuenta con el

    ¿como evitarlo?
Liberar los bloques de memoria para que el SO pueda reclamarlo
y reasignarlo a otro programa

    delete <identificador>;

    | int* p = new int (33); | declaracion de apuntador
    |                        |
    | delete   p;            | libera la memoria reservada
    |                        |
    | p = new int (55);      | redireccionamiento de *

Asi nuestro programa no creara basura o bloques de memoria
innaccesibles

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

REFERENCIA COLGANTE

sucede cuando la memoria se ha liberado, incluso
podria haber sido reasignado a otro programa y el
apuntador sigue conservando esa direccion de memoria

    | int* p = new int (33); | declaracion de apuntador
    |                        |
    | delete   p;            | libera la memoria reservada

ahora <p> se encuentra apuntando a una direccion de
memoria inutil para nuestro programa

    ¿solucion?
reasignarle una posicion de memoria al apuntador
liberado, en caso de que no se vaya a utilizar mas
le asignaremos un valor de 0

    < p = 0 >

dando a entender que el apuntador sera liberado
asi sea momentaneamente, debemos asignarle un valor
0 para no crear una referencia colgante

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

OPERACIONES CON APUNTADORES

    & Operador de direccion

&<variable> estamos solicitando la direccion en
memoria de la variable, la usamos en pasos por
referencia

las variables han sido creadas en la programacion de
alto nivel para evitar recordar las direcciones en
memoria, con <&> accedemos directamente a donde se ha
almacenado nuestro dato, nos permite realizar operaciones

    * Operador de contenido

*<variable> obtendremos el dato guardado en el
espacio en memoria
*/

int main()
{

int x = 33;
int *p = &x;
cout <<"p: " <<p <<endl;
cout <<"*p: " <<*p <<endl;
cout <<"&*p: " <<&*p <<endl;

/*

|  tipo  |  nombre  |  valor     |  direccion  |
|        |          | 0x33221100 | 0x55443322  |
| int*   | p        |            |             |
|        |          |            |             |
| int    | x        | 33         | 0x33221100  |

int  x esta guardando el dato 33
int* p esta guardando la direccion en memoria de x

todo dato tiene su espacio en memoria, asi que las
variables apuntador contienen una direccion en
memoria mientras que a su vez estan guardadas en una
direccion de memoria

< p > nos imprime una direccion de memoria ya que
es un apuntador y ese es su contenido mientras que
< *p > nos imprimiria 33 ya que estamos señalando el
dato que se encuentra en la direccion de memoria a la
cual apunta < *p >

observamos la direccion a la que apunta <p>, nos
movemos a esa direccion y leemos el dato almacenado
en esta

Todas los datos tienen un espacio en memoria, por lo
tanto todo puede ser modificado con apuntador,
permitiendo un gran control sobre nuestros programas
*/

int y = 44;
int *t = &y;    //*t == y, sinonimos

y = y + 7;      //y = 40
y = *t + 5;     //y = 45  valor de y + 5
*t = *t + 3;    //y = 48

/*

*t COMO ALIAS DE VARIABLE

al crear un apuntador con una variable con operador
de direccion, estamos accediendo a la memoria, por
lo tanto es como si fueran sinonimos

*/

    return 0;
}
