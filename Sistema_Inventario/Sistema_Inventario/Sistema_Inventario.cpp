// Arón Carballido Paz - Esteban Chávez Alvarez 
// Nomenclatura: camelCase // en los constructores y variables de clase se usa el guion bajo junto con el camelCase
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std; //usamos la funcion namespace std, para evitar poner std::

class item //creamos la clase item 
{

private:
    string nombreDelItem; //string para colocar nombres a cada item

public:
    item() //constructor item 
    {
        // lo pusimos vacio porque tenemos una funcion que sirve para que el usuario cree el item
    }

    void crearItem() //funcion para crear un item para el inventario
    {
		cin.ignore(); //limpiamos el buffer
        cout << "Nombre del item: ";
        getline(cin, nombreDelItem);
    }

    void mostrarUnItem() // funcion para mostrar un item  en el inventario
    {
        cout << " Nombre del item: " << nombreDelItem <<  endl;
    }
};

class inventario
{
private:
    string inventarioJugador; //string para almacenar el nombre del jugador
    vector<item> listaItems; //vector para almacenar los items

public:
    inventario(string _nombreJugador) //constructor inventario
    {
        inventarioJugador = _nombreJugador;
    }

    void agregarItem(item _item) //funcion para agregar un item al inventario
    {
        listaItems.push_back(_item); // agrega el item al vector de items
    }

    void mostrarInventario() //funcion para mostrar el inventario
    {
        cout << "Inventario: \n";

        for (int i = 0; i < listaItems.size(); i++)
        {
            cout << i + 1 << ".- ";
            listaItems[i].mostrarUnItem(); //muestra el numero de los items en el orden que se introdujieron
        }
    }

    void eliminarItem() //funcion para eliminar item 
    {
        int posicion;
        cout << "Que item deseas eliminar? \n";
        mostrarInventario();
        cin >> posicion;
        if (posicion > 0 && posicion <= listaItems.size()) // hacemos un if donde decimos que si la posicion es mayor a 0 y/o la posicion es igual a la lista de items pasa lo siguiente
        {            
            listaItems.erase(listaItems.begin() + posicion - 1); //usamos esta funcion para mandar a la lista al principio esto para poder eliminar los items que hayamos puesto y esto le agrega un espacio a el inventario
            cout << "Item eliminado.\n"; //se elimina el item seleccionado
        }
        else
        {
            cout << "Posicion invalida.\n"; // si no, nos marca que la posicion elegida no es correcta o no existe
        }
    }

    void menu() //menu de seleccion de opciones para el jugador
    {
        int opcion;
        item itemNuevo;
		bool flag = true;   //La bandera nos sirve para darle una condicion al while, para que el menu se repita hasta que el jugador decida salir
        while (flag) 
        {
            cout << "1.- Ver inventario\n"; //mostrar el inventario
            cout << "2.- Agregar item al inventario\n"; //agregar un item
            cout << "3.- Eliminar item del inventario\n"; //eliminar un item
            cout << "4.- Salir del menu\n"; //salir del menu
            cin >> opcion; //leemos la opcion que el usuario selecciona
            switch (opcion)
            {
            case 1:
                mostrarInventario();
				system("pause");
				system("cls"); //Limpiar la pantalla
                break;
            case 2:
                itemNuevo.crearItem();
                agregarItem(itemNuevo);
                system("pause");
                system("cls");
                break;
            case 3:      
                eliminarItem();
                system("pause");
                system("cls");
                break;
            case 4:
				flag = false;
                break;      //convierte la bandera en false para salir del menu
            default:
				cout << "Opcion no valida, por favor elige una opcion valida.\n"; //esta funcion sirve para que al introducir una opcion que no se encuentre dentro de el menu le mande de vuelta a la ventana menu
                break;
            }
        }
    }
};
int main()
{
    string nombreJugador;
    cout << "----Hola jugador!----\nIntroduzca su nombre.\n"; //le pedimos al usuario ingresar un nombre de jugador
    getline(cin, nombreJugador); 
    inventario inventarioJugador(nombreJugador);
    cout << "Bienvenido " << nombreJugador << " Seleccione una opcion: \n"; //le mostramos el menu al usuario
    inventarioJugador.menu();
    return 0;
}