// Arón Carballido Paz - Esteban Chávez Alvarez 
// Nomenclatura: - nombres de variables: camelCase / Nombres de funciones: snake_case / variables de constructor: camelCase

#include <iostream>
#include <string>
#include <vector>
using namespace std; //usamos la funcion namespace std, para evitar poner std::

class item //creamos la clase item 
{

private:
	string nombreDelItem; //string para colocar nombres a cada item
	string tipoDeItem; //string para asignar el tipo de item
    int cantidadDeItem; //entero para añadir cantidades de los items

public:
	item(string _nombreDelItemm, string _tipoDeItem, int _cantidadDeItem)//constructor item 
	{
		nombreDelItem = "Espada";
		tipoDeItem = "Arma";
		cantidadDeItem = 1;
	}


};

class inventario
{

private:
	vector<item> listaItems; //vector para almacenar los items
    string clasesItems;


public:


	void mostrarInventario() //funcion para mostrar el inventario
	{
		cout << "Inventario: \n";

		for (int i = 0; i < listaItems.size(); i++)
		{
			cout << i + 1 << ".- ";
			listaItems[i].mostrarInfoItem();
		}
	}

};

class personaje
{

private:
	string nombrePersonaje;


public:


};

void menu() //menu de seleccion de opciones para el jugador
{
	
}
void funcMostrarMenu()
    {
        cout << "---- Bienvenido a la tienda de pociones ---- " << endl;
        cout << "Selecciona un numero del menu: " << endl;



        for (size_t i = 0; i < listaPociones.size(); i++)
        {
            cout << i + 1 << ".- ";

            listaPociones[i].funcMostrarInfoPocion();
        }

        cout << listaPociones.size() + 1 << ".- Salir de menu " << endl;

    }
    int funcComprarPocion(Jugador paramJugador)
    {
        int opcionSeleccionada;

        do
        {
            funcMostrarMenu();
            cin >> opcionSeleccionada;

            switch (opcionSeleccionada)
            {
            case 1:
            case 2:
            case 3:     
            case 4:
            {
                int posicionListaPociones = opcionSeleccionada - 1;
                Pocion pocionSeleccionada = listaPociones[opcionSeleccionada - 1];
                break;
            }
            default:
                if (listaPociones.size() + 1 == opcionSeleccionada)
                {
                    break;
                }
                else
                {
                    cout << "Opcion no valida, subnormal, hazme el favor de elegir una opcion valida. \n";
                }
                break;
            }


        } while (opcionSeleccionada != listaPociones.size() + 1); //Repetir hasta que el usuario elija salir

        return 0;

        
      


    }

int main()
{
	string nombreJugador;
    int opcion;
    cout << "----Hola jugador!----\nIntroduzca su nombre.\n"; //le pedimos al usuario ingresar un nombre de jugador
	getline(cin, nombreJugador);

    cout << "Bienvenido " << nombreJugador << " Seleccione una opcion: \n"; //le mostramos el menu al usuario
    cout << "1.- Ver inventario\n"; //mostrar el inventario
    cout << "2.- Agregar item al inventario\n"; //agregar un item
    cout << "3.- Eliminar item del inventario\n"; //eliminar un item
    cout << "4.- Salir del menu\n"; //salir del menu

	cin >> opcion; //leemos la opcion que el usuario selecciona

    switch (opcion)
    {
	case 1:

		break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;


    default:
        break;
    }

	return 0;
}