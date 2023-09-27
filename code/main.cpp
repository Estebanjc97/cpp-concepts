#include "header.h"

struct Entity
{
    int x, y;
};


int main() 
{
    int a = 50;

    //Type Punning: Basicamente es un casteo de entero (int) a doble (double), pero haciendo una copia exacta en memoria de lo que tenía a
    //int a = 50 en memoria es 32 00 00 00 (4 bytes)
    //Lo que hacemos es tomar la dirección de memoria de a usando &a
    //castearlo en un puntero doble (double*) ya que estamos hablando de direcciones de memoria
    //Y finalmente desreferenciando el puntero resultante para obtener el valor exacto en memoria * 
    //Para finalmente asignarlo a el doble b
    //es lo mismo que -> double b = 32 00 00 00;
    double b = *(double*)&a;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    //Tomando otro ejemplo usando el struct Entity

    Entity e = { 5, 8 };

    //positionY es un entero (int) lo que en memoria se traduce a 4 bytes consecutivos almacenados así: 00 00 00 00
    //e es una entidad (Entity) objeto de mi struct. Contiene 2 enteros x,y por lo que e se traduce en memoria así: 00 00 00 00 00 00 00 00
    //e también puede verse como un arreglo de enteros de longitud 2, que en código es: int* array = int[2];
    //e también puede ser un arreglo de char de longitud 8
    //&e es la dirección en memoria que aloja a e
    //char* es un puntero a un char - dirección de memoria a (00)
    //int* es un puntero a un int - dirección de memoria a (00 00 00 00)
    //*() es una desreferenciación, lo que se traduce a recibir el valor detrás del puntero
    //+ 4, para moverse en memoria y saltar los valores de entity asignados a la variale x
    int positionY = *(int*)((char*)&e + 4);

    std::cout << positionY << std::endl;

    std::cout << &e.x + 1 << std::endl; //Obtengo la dirección de memoria de e.y
    std::cout << &e.y << std::endl;

    std::cin.get();
}