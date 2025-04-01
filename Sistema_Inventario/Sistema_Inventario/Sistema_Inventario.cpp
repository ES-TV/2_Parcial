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
    int cantidadDeItem; //entero para añadir cantidades de los items

public:
	item(string _nombreDelItem, int _cantidadDeItem)//constructor item 
	{
        nombreDelItem = _nombreDelItem;
        cantidadDeItem = _cantidadDeItem;
	}

	void agregarItem()
	{
		cout << "Nombre del item: ";
		getline(cin, nombreDelItem);
		cout << "Cantidad: ";
		cin >> cantidadDeItem;

	}
    void mostrarUnItem()
    {
        cout << "- Nombre del item: " << nombreDelItem << "\n- Cantidad: " << cantidadDeItem << endl;
    }
};

class inventario
{
private:
	vector<item> listaItems; //vector para almacenar los items
    string clasesItems;


public:
	inventario(string _nombreDelItem, int _cantidadDeItem) //constructor inventario
	{
		listaItems.push_back(item(_nombreDelItem, _cantidadDeItem));
	}
	void agregarItem(item _item) //funcion para agregar un item al inventario
	{
		listaItems.push_back(_item);
	}

	void mostrarInventario() //funcion para mostrar el inventario
	{
		cout << "Inventario: \n";

		for (int i = 0; i < listaItems.size(); i++)
		{
			cout << i + 1 << ".- ";
			listaItems[i].mostrarUnItem();
		}
	}

};


int menu(int opcion, bool flag) //menu de seleccion de opciones para el jugador
{
    cout << "1.- Ver inventario\n"; //mostrar el inventario
    cout << "2.- Agregar item al inventario\n"; //agregar un item
    cout << "3.- Eliminar item del inventario\n"; //eliminar un item
    cout << "4.- Salir del menu\n"; //salir del menu
    cin >> opcion; //leemos la opcion que el usuario selecciona
    switch (opcion)
    {
    case 1:
        inventario.mostrarInventario(string _nombreDelItem, int _cantidadDeItem);
        break;
    case 2:
        inventario.agregarItem();
        break;
    case 4:
        flag = false;
        break;
    default:
        break;
    }
}

int main()
{
	string nombreJugador;
    int opcion;
    bool flag = true;
    cout << "----Hola jugador!----\nIntroduzca su nombre.\n"; //le pedimos al usuario ingresar un nombre de jugador
	getline(cin, nombreJugador);
	inventario inventarioJugador(string _nombreJugador);
	cout << "Bienvenido " << nombreJugador << " Seleccione una opcion: \n"; //le mostramos el menu al usuario
    while (flag)
	{
		menu(opcion, flag);
	} 
	return 0;
}

/*
//tienda Aron Carballido Paz 20-03-25
#include <iostream>
#include <string>
#include <vector>
using namespace std; //para evitar poner std::
//jugador -> estado y oro, objeto--> clase
class Jugador
{
private:
    string nombreJugador;
    int oroInicialJugador;



public:
    Jugador() //constructor
    {
        nombreJugador = "Lonki ";   //nombre de el jugador al entrar en la tienda
        oroInicialJugador = 200;   //cantidad de oro con la que empezamos
    }
    void funcMostrarInfoJugador()
    {
        cout << "Nombre: " << nombreJugador << " Oro inicial: " << oroInicialJugador << endl;
    }

    int getOroJugador() 
    {
        return oroInicialJugador;
    }

    int setRestartOroJugador(int paramCantidadOro)
    {
        oroInicialJugador -= paramCantidadOro;
        return oroInicialJugador;
    }

};
//Pocion --> Objeto
class Pocion
{
private:
    int cantidadPocion;
    int precioPocion;
    int nivelPocion;
    string descripcionEfectoPocion;
    string nombrePocion;

public:
    //Constructor pocion
    Pocion(int _cantidadPocion, int _precioPocion, int _nivelPocion, string _descripcionEfectoPocion, string _nombrePocion)
    {
        cantidadPocion = _cantidadPocion;
        precioPocion = _precioPocion;
        nivelPocion = _nivelPocion;
        descripcionEfectoPocion = _descripcionEfectoPocion;
        nombrePocion = _nombrePocion;
    }
    void funcMostrarInfoPocion()
    {
        cout << " Nombre: " << nombrePocion << ", nvl: " << nivelPocion << ", desc: " << descripcionEfectoPocion << ", cantidad: " << cantidadPocion << endl;
        cout << "Precio: " << precioPocion << " de oro" << endl;
    }

    int getPrecioPocion()
    {
        return precioPocion;
    }
};

//Tienda --> objeto
class Tienda
{
private:
    vector<Pocion> listaPociones;

public:
    //Constructor de tienda
    Tienda()
    {
        //Constructor pocion(int _cantidadPocion, int _precioPocion, int _nivelPocion, string _descripcionEfectoPocion, string _nombrePocion)
        listaPociones.push_back(Pocion(3, 50, 2, "Restaura 50 puntos de vida ", "Pocion de vida"));
        listaPociones.push_back(Pocion(8, 100, 5, "Restaura 40 puntos de mana ", "Pocion de mana"));
        listaPociones.push_back(Pocion(2, 150, 10, "Restaura 100 puntos de vida ", "Elixir mayor de vida"));
        listaPociones.push_back(Pocion(2, 150, 10, "Restaura 100 puntos de mana ", "Elixir mayor de mana"));
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
};
int main()
{
    Jugador jugadorObjeto; //Crando el objeto jugador 
    jugadorObjeto.funcMostrarInfoJugador();

    Tienda tienda;
    tienda.funcComprarPocion(jugadorObjeto);

    return 0;
}
*/