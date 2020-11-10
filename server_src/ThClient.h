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
	std::unordered_map<std::string,std::string>& hash;
	std::atomic<bool> is_dead;
	Monitor_Respuesta monitor;


public:
	ThClient(Socket peer,std::unordered_map<std::string,std::string>&\
			hash_recursos):Peer(std::move(peer)),hash(hash_recursos),is_dead(false),\
			monitor(hash_recursos){
	}

	void send_answer(std::string server_answer);

	void process_command(std::string input_client);

	bool is_alive();

	void run() override;
};



#endif /* SERVER_SRC_THCLIENT_H_ */
