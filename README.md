# Examen-Tema3
https://github.com/adrianarmm/Examen-Tema3.git

TIPO TEST
1.	¿Cuál es el propósito principal de la clase Variant en el lenguaje Tiny Lisp?
b) Representar cualquier tipo de dato Lisp

2.	¿Qué representación se obtiene al utilizar el método to_string() en un objeto Variant?
a) Una cadena de texto que representa una instancia de Variant

3.	¿Qué función cumple el método to_json_string() en la clase Variant?
b) Convierte un objeto Variant a una cadena JSON

4.	¿Qué función cumple el método from_json_string() en la clase Variant?
c) Parsea un objeto JSON a un objeto Variant

EXPLICACIONES
ESTRUCTURA BASICA
Primero creo una clase enviroment y luego defino con 3 letras o símbolos, “x”, ”y”, ”z”.
Lookup lo utilizo para imprimir los valores de estos, y si intentas acceder a uno que no este definido, se lanzara un runtime_error.

INSERTAR SIMBOLOS
Utilizo la estructura básica y continuo añadiendo.
Utilizo insert para agregar a las letras mencionadas anteriormente al entorno.
Vuelvo a utilizar lookup para su impresión. Al intentar acceder a z lanza un error, que se maneja el bloque try-catch.
Para comprobar insert, puede insertar una nueva letra.

BUSQUEDA DE SIMBOLOS
Siguiendo con lo hecho en los anteriores pasos, añado lo siguiente:
Inserto en public un void, y mas abajo lo defino para que compruebe que todos símbolos esten definidos.

GESTION DE ERRORES
