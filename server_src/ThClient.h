#ifndef SERVER_SRC_THCLIENT_H_
#define SERVER_SRC_THCLIENT_H_
#include "../common_src/Thread.h"
#include "../common_src/Socket.h"
#include <atomic>
#include <unordered_map>
#include <utility>
#include <string>
#include "Monitor_Respuesta.h"


class ThClient: public Thread{
private:
	Socket Peer;
	Monitor_Respuesta& monitor;
	std::atomic<bool> is_dead;

	void send_answer(const std::string& server_answer);

	void process_command(const std::string& input_client);


public:
	ThClient(Socket peer,Monitor_Respuesta& monitor_):Peer(std::move(peer))\
	,monitor(monitor_),is_dead(false){
	}

	//Devuelve si se sigue ejecutando el hilo o no, se usa para que
	//la clase llamadora sepa si esta en modo zombie el hilo
	bool is_alive();

	void run() override;
};



#endif /* SERVER_SRC_THCLIENT_H_ */
