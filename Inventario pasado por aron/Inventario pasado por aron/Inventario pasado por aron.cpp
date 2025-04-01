#include <iostream>
#include <string>
#include <vector>
using namespace std;

class item
{
private:
    string nombreItem;
    string tipoItem;
    int cantidadItem;


public:
    item(string _nombreItem, string _tipoItem, int _cantidadItem)
    {
        nombreItem = _nombreItem;// Guardamos el valor que ingreso el usuario
        tipoItem = _tipoItem;
        cantidadItem = _cantidadItem;
    }

    void funcMostrarInfoItem()
    {
        cout << nombreItem << "Tipo: " << tipoItem << "Cantidad: " << cantidadItem << endl;
    }

    void funcMostrarInfoInventario()
    {
        cout << nombreItem << endl;
        cout << "Tipo: " << tipoItem << endl;
        cout << "Cantidad: " << cantidadItem << endl;
    }

};
class personaje
{
private:
    string nombrePersonaje;
    vector<item> inventarioPersonaje;
public:

    personaje(string _nombrePersonaje)
    {
        nombrePersonaje = _nombrePersonaje;
    }

    //metodo para agregar el item al inventario del personaje
    void funcAgregarItemInventario(item paramItem)
    {
        inventarioPersonaje.push_back(paramItem);//Agrgar un Item al vector
        cout << "Item agregado al inventario" << endl;

    }

    void funcMostrarInfoInventario()
    {
        for (size_t i = 0; i < inventarioPersonaje.size(); i++)
        {
            inventarioPersonaje[i].funcMostrarInfoItem();
        }
    }

};


int main()
{
    string nombrePersonaje;
    string nombreItem;
    string tipoItem;
    int cantidadItem;

    cout << "ingrese el nombre delpersonaje" << endl;
    getline(cin, nombrePersonaje);//Leer nombre completo con espacios

    //Crear objeto personaje
    personaje jugador(nombrePersonaje);

    cout << "Nombre del Item: " << endl;
    getline(cin, nombreItem);

    cout << "Tipo: " << endl;
    getline(cin, tipoItem);

    cout << "Cantidad: " << endl;
    cin >> cantidadItem;

    //Enviar información ingresada por el usuario al constructor

    item nuevoItem(nombreItem, tipoItem, cantidadItem);
    jugador.funcAgregarItemInventario(nuevoItem); //Agregamos items al jugador
    jugador.funcAgregarItemInventario();



    return 0;
}