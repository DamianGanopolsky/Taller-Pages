#ifndef SERVER_SRC_THCLIENT_H_
#define SERVER_SRC_THCLIENT_H_

#include "../common_src/Thread.h"
#include "../common_src/Socket.h"
#include <unordered_map>


class ThClient: public Thread{
private:
	Socket Peer;
	std::unordered_map<std::string,std::string>& hash;

public:
	ThClient(Socket peer,std::unordered_map<std::string,std::string>&\
			hash_recursos):Peer(std::move(peer)),hash(hash_recursos){

	}

	void send_answer(std::string server_answer);

	void process_command(std::string input_client);

	void run();
};



#endif /* SERVER_SRC_THCLIENT_H_ */
