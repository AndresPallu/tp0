#include "client.h"
//#include <readline/readline.h>      Es la que incluye la función redline ("> "), pero no se agrega porqeue está en ¿las commons? 

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();
	
	log_info(logger, "Hola! Soy un log maravilloso.");

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	valor = config_get_string_value(config, "CLAVE");
	char * ipDeConfig = config_get_string_value(config, "IP");
	char * puertoDeConfig = config_get_string_value(config, "PUERTO");

	if (valor == NULL) {
		abort();
		};

		
	log_info(logger, valor);
	log_info(logger, ipDeConfig);
	log_info(logger, puertoDeConfig);
	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config


	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	//conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	//paquete(conexion);




	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
	/*-----------------------------------------------------------------------------------------------------------------------*/

	terminar_programa(conexion, logger, config);
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger = log_create("tp0.log","EL logger",1,LOG_LEVEL_INFO);

	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config = config_create("cliente.config");   // /home/utnso/tp0/client/cliente.config

	return nuevo_config;
}  //Al ejecutar VS hace un cd a la carpeta del proyecto. Variable workspaceFolder del launch.json:   /home/utnso/tp0/client

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío

	while (leido !=NULL && strcmp(leido, "")){
		log_info(logger, leido);
		free (leido);			//Hay que poner el free antes de leer el proximo y no después, porque si no sería escibirlo y borrarlo
		leido = readline("> ");
	}
	// ¡No te olvides de liberar las lineas antes de regresar!
	free (leido); //Libera el último leido que no entra al while
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	log_destroy(logger);
	config_destroy(config); //Cuando hice el config=iniciarConfig se reservaron bloques de memoria en el Heap y no se libera cunado termtina el programa, por eso debo eliminarla a manopla.
	liberar_conexion(conexion);
}
