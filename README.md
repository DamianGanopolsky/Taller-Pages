# Trabajo Practico 3: Taller-Pages

## Agregue una breve lista de cambios hechos para la reentrega al final del informe

*Nombre*: Damian Ganopolsky  
*Padrón*: 101.168  
*Repositorio*: https://github.com/DamianGanopolsky/Taller-Pages


## Introducción
En el siguiente trabajo se tuvo como principal objetivo poner en practica los nuevos conocimientos adquiridos sobre el manejo de multiples clientes desde un servidor, teniendo este recursos compartidos que son accesibles por los clientes. Para realizar esto, tambien se usaron otros conceptos aprendidos en la materia, como lo son el uso de sockets, threads y la proteccion de recursos compartidos, entre otros tantos.

## Descripcion de la resolucion

**Dificultad:Correcta finalizacion del servidor**  
La mayor dificultad la encontre a la hora de cerrar el servidor cuando el usuario ingresa una 'q' por entrada estandar. Esto fue asi, porque al momento de ingresar dicha 'q' hay varios hilos en funcionamiento.  
Para poder hacer que finalice correctamente, voy a explicar secuencialmente como se inicia y finaliza el servidor. En server_main se lanza el hilo "Server_Manager", el cual sera el encargado de aceptar los clientes, despues de lanzar dicho hilo, el hilo "main" se queda esperando una 'q' por entrada estandar. En paralelo, el hilo previamente lanzado sera el encargado del manejo del socket "Listener" por lo que ira aceptando clientes y debido a esto ira generando sockets 'Peer' los cuales movera hacia los ThClient generados para que estos lo manejen.  
El hilo del server_manager se quedara bloqueado en el Accept esperando nuevos clientes, en caso de que este Accept fallara se lanza una excepcion y se llama al destructor de Server_Manager. Una vez ingresada la 'q', el hilo principal llamara a una funcion del Server_Manager, la cual cerrara el socket Listener. Este cierre hara que falle el Accept del listener, por lo que se llamara al destructor de esta clase y se liberaran todos los recursos necesarios.

**Dificultad:Enviado y procesamiento de datos entre el servidor y el cliente**  
Otra dificultad con la que me encontre en este tp fue como enviar y procesar los datos. Esto es asi porque mi clase socket recibe char*, y al mismo tiempo para el parseo y manipulacion de datos se usan las strings de C++ o stringstreams.  
Los datos se fueron enviando usando buffers de 64 Bytes, y el servidor para cada cliente dispone de una string en la cual se fueron appendeando los distintos buffers hasta que el cliente cierre la escritura. Una vez tenida la string resultante del mensaje enviado por el cliente, se paso esta a un StringStream, para poder usar la funcion getline e ir parseando segun el protocolo HTTP el mensaje completo.



### Diagrama de clases
Adjunto los diagramas de clases correspondientes al diseño del servidor, ya que, en este tp el cliente tuvo muy poca responsabilidad y es bastante trivial su diseño.  

En este primer diagrama se puede ver un esquema general del programa, dejando de lado ciertas clases de mas bajo nivel
![DiagramaClases1](DiagClases1.png)  

En este segundo diagrama se puede ver al monitor encargado de proteger los recursos, y la obtencion de la respuesta para el cliente. Si bien, en C++ no existen "interfaces" Comando es una clase abstracta sin niguna implementacion de metodos, por lo que se puede considerar a tal como una interfaz.
![DiagramaClases2](DiagClases2.png)


### Diagrama de secuencia

Adjunto el diagrama de secuencia correspondiente a las acciones que se realizan luego del ingresado de la letra 'q' por entrada estandar  

![DiagramaSecuencia](Diagrama_secuencia.png)


### Cambios hechos en la Re-Entrega

- Issue #1 : Agregue un diagrama de secuencia mostrando lo que sucede cuando se ingresa una 'q'.

- Issue #2: No me lo retorna, segui la documentacion en http://www.cplusplus.com/reference/istream/istream/read/ y obtuve los caracteres leidos llamando a gcount.

- Issue #3: En vez de ir appendeando en una string del lado del cliente para despues mostrar dicha string, imprimo la respuesta que voy recibiendo del servidor de a bloques

- Issue #4: Dejo de eliminar los saltos de linea porque no hacia falta(en Client_Manager.cpp)

- Issue #5: Cambio "Asign" por "Assign"

- Issue #6: Elimino el metodo innecesario "longitud_archivo"

- Issue #7: Dejo de usar el heap para el manejo del archivo, ahora uso el stack(era injustificado el uso del heap en este caso)

- Issue #8: Seteo ai_flags a passive

- Issue #9: Uso excepciones en Socket.cpp en vez de fprintfs

- Issue #10: Dejo de pasarle los dos ultimos parametros a Accept, ya que, no se usaban realmente y genera una mayor claridad en el codigo pasarle NULL en esos parametros

- Issue #11: Invierto la suma, ademas, dejo de usar longitud_restante y uso total_bytes_recibidos para una mayor claridad

- Issue #12: Saco los 3 ifs innecesarios, el propio parametro determina el canal a cerrar

- Issue #13: Evito esa copia de string, paso a usar const & (porque no modifico la referencia)

- Issue #14: Dejo de usar 2 veces el operador <<, ya que, generaba una race condition. Lo uso 1 vez y no hace falta agregarle un mutex porque es thread safe.

- Issue #15: Dejo de tener un mutex por hilo, ahora los distintos hilos comparten el monitor pero no el hash. Al compartir el monitor, el mutex usado sera el mismo para los distintos hilos, y es por esto que no se podra acceder desde 2 o mas hilos al recurso compartido al mismo tiempo.

- Issue #16: Ahora el server manager construye su propio socket, quedo mas prolijo porque ahora server_main no construye el socket y lo mueve a server_manager(era innecesario hacer eso).
