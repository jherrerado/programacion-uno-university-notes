#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <fstream> // Para exportar los datos a un archivo

class Persona {
private:
  std::string nombre;
  std::string cedula;
  char sexo;
  std::vector<Persona*> padres;
  std::vector<Persona*> hijos;
  std::vector<Persona*> hermanos;

public:
  Persona(const std::string& nombre, const std::string& cedula, char sexo)
    : nombre(nombre), cedula(cedula), sexo(sexo) {}

  std::string obtenerNombre() const {
    return nombre;
  }

  std::string obtenerCedula() const {
    return cedula;
  }

  char obtenerSexo() const {
    return sexo;
  }

  void agregarPadre(Persona* padre) {
    if (std::find(padres.begin(), padres.end(), padre) == padres.end()) {
      padres.push_back(padre);
      padre->hijos.push_back(this); // Relación bidireccional
    }
  }

  void agregarHermano(Persona* hermano) {
    if (std::find(hermanos.begin(), hermanos.end(), hermano) == hermanos.end()) {
      hermanos.push_back(hermano);
      hermano->hermanos.push_back(this); // Relación bidireccional
    }
  }

  std::vector<Persona*> obtenerAbuelos() {
    std::vector<Persona*> abuelos;
    for (Persona* padre : padres) {
      for (Persona* abuelo : padre->padres) {
        abuelos.push_back(abuelo);
      }
    }
    return abuelos;
  }

  std::vector<Persona*> obtenerTios() {
    std::vector<Persona*> tios;
    for (Persona* padre : padres) {
      for (Persona* hermano : padre->hermanos) {
        tios.push_back(hermano);
      }
    }
    return tios;
  }

  void mostrarInformacion() {
    std::cout << "Nombre: " << nombre << "\n";
    std::cout << "Cédula: " << cedula << "\n";
    std::cout << "Sexo: " << (sexo == 'M' ? "Masculino" : "Femenino") << "\n";

    std::cout << "Padres:\n";
    for (Persona* padre : padres) {
      std::cout << "- " << padre->obtenerNombre() << " (" << padre->obtenerCedula() << ")\n";
    }

    std::cout << "Hijos:\n";
    for (Persona* hijo : hijos) {
      std::cout << "- " << hijo->obtenerNombre() << " (" << hijo->obtenerCedula() << ")\n";
    }

    std::cout << "Hermanos:\n";
    for (Persona* hermano : hermanos) {
      std::cout << "- " << hermano->obtenerNombre() << " (" << hermano->obtenerCedula() << ")\n";
    }
  }

  // Función para exportar la información de la persona a un archivo
  void exportarInformacion(std::ofstream& archivo) {
    archivo << "Nombre: " << nombre << "\n";
    archivo << "Cédula: " << cedula << "\n";
    archivo << "Sexo: " << (sexo == 'M' ? "Masculino" : "Femenino") << "\n";

    archivo << "Padres:\n";
    for (Persona* padre : padres) {
      archivo << "- " << padre->obtenerNombre() << " (" << padre->obtenerCedula() << ")\n";
    }

    archivo << "Hijos:\n";
    for (Persona* hijo : hijos) {
      archivo << "- " << hijo->obtenerNombre() << " (" << hijo->obtenerCedula() << ")\n";
    }

    archivo << "Hermanos:\n";
    for (Persona* hermano : hermanos) {
      archivo << "- " << hermano->obtenerNombre() << " (" << hermano->obtenerCedula() << ")\n";
    }

    archivo << "-----------------------\n";
  }
};

class SistemaGenealogico {
private:
  std::unordered_map<std::string, Persona*> personas;

public:
  void agregarPersona(const std::string& nombre, const std::string& cedula, char sexo) {
    if (personas.find(cedula) != personas.end()) {
      std::cout << "Error: Persona con la cédula " << cedula << " ya existe.\n";
    }
    else {
      personas[cedula] = new Persona(nombre, cedula, sexo);
      std::cout << "Persona " << nombre << " agregada correctamente.\n";
    }
  }

  Persona* buscarPersonaPorCedula(const std::string& cedula) {
    if (personas.find(cedula) != personas.end()) {
      return personas[cedula];
    }
    else {
      std::cout << "Persona con cédula " << cedula << " no encontrada.\n";
      return nullptr;
    }
  }

  Persona* buscarPersonaPorNombre(const std::string& nombre) {
    for (auto& entry : personas) {
      if (entry.second->obtenerNombre() == nombre) {
        return entry.second;
      }
    }
    std::cout << "Persona con nombre " << nombre << " no encontrada.\n";
    return nullptr;
  }

  void agregarRelacionPadreHijo(const std::string& cedulaPadre, const std::string& cedulaHijo) {
    Persona* padre = buscarPersonaPorCedula(cedulaPadre);
    Persona* hijo = buscarPersonaPorCedula(cedulaHijo);
    if (padre && hijo) {
      hijo->agregarPadre(padre);
      std::cout << padre->obtenerNombre() << " es ahora padre de " << hijo->obtenerNombre() << ".\n";
    }
  }

  void mostrarAbuelos(const std::string& cedula) {
    Persona* persona = buscarPersonaPorCedula(cedula);
    if (persona) {
      std::vector<Persona*> abuelos = persona->obtenerAbuelos();
      std::cout << "Abuelos de " << persona->obtenerNombre() << ":\n";
      for (Persona* abuelo : abuelos) {
        std::cout << abuelo->obtenerNombre() << " (" << abuelo->obtenerCedula() << ")\n";
      }
    }
  }

  void mostrarInformacionPersona(const std::string& cedula) {
    Persona* persona = buscarPersonaPorCedula(cedula);
    if (persona) {
      persona->mostrarInformacion();
    }
  }

  void exportarDatos() {
    std::ofstream archivo("exportacion_genealogia.txt");
    if (archivo.is_open()) {
      archivo << "Exportación de Datos Genealógicos\n";
      archivo << "===============================\n";
      for (auto& entry : personas) {
        entry.second->exportarInformacion(archivo);
      }
      archivo.close();
      std::cout << "Datos exportados correctamente a exportacion_genealogia.txt\n";
    }
    else {
      std::cout << "Error al abrir el archivo para exportar los datos.\n";
    }
  }

  ~SistemaGenealogico() {
    for (auto& entry : personas) {
      delete entry.second;
    }
  }
};

int main() {
  SistemaGenealogico sistema;
  int opcion;
  std::string nombre, cedula, cedulaPadre, cedulaHijo;
  char sexo;

  do {
    std::cout << "\nSistema Genealógico\n";
    std::cout << "1. Agregar persona\n";
    std::cout << "2. Establecer relación padre-hijo\n";
    std::cout << "3. Mostrar abuelos de una persona\n";
    std::cout << "4. Buscar persona por nombre\n";
    std::cout << "5. Mostrar información completa de una persona\n";
    std::cout << "6. Exportar datos\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;

    switch (opcion) {
    case 1:
      std::cout << "Ingrese nombre: ";
      std::cin.ignore(); // Limpiar buffer
      std::getline(std::cin, nombre);
      std::cout << "Ingrese cédula: ";
      std::cin >> cedula;
      std::cout << "Ingrese sexo (M/F): ";
      std::cin >> sexo;
      sistema.agregarPersona(nombre, cedula, sexo);
      break;

    case 2:
      std::cout << "Ingrese cédula del padre: ";
      std::cin >> cedulaPadre;
      std::cout << "Ingrese cédula del hijo: ";
      std::cin >> cedulaHijo;
      sistema.agregarRelacionPadreHijo(cedulaPadre, cedulaHijo);
      break;

    case 3:
      std::cout << "Ingrese cédula de la persona: ";
      std::cin >> cedula;
      sistema.mostrarAbuelos(cedula);
      break;

    case 4:
      std::cout << "Ingrese nombre: ";
      std::cin.ignore(); // Limpiar buffer
      std::getline(std::cin, nombre);
      sistema.buscarPersonaPorNombre(nombre);
      break;

    case 5:
      std::cout << "Ingrese cédula de la persona: ";
      std::cin >> cedula;
      sistema.mostrarInformacionPersona(cedula);
      break;

    case 6:
      sistema.exportarDatos();
      break;

    case 0:
      std::cout << "Saliendo del sistema...\n";
      break;

    default:
      std::cout << "Opción no válida.\n";
      break;
    }
  } while (opcion != 0);

  return 0;
}
