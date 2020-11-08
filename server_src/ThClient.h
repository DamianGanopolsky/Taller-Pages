#ifndef SERVER_SRC_THCLIENT_H_
#define SERVER_SRC_THCLIENT_H_
#include "../common_src/Thread.h"
#include "../common_src/Socket.h"
#include <atomic>
#include <unordered_map>
#include <utility>
#include <string>


class ThClient: public Thread{
private:
	Socket Peer;
	std::unordered_map<std::string,std::string>& hash;
	std::atomic<bool> keep_talking;
	std::atomic<bool> is_running;


public:
	ThClient(Socket peer,std::unordered_map<std::string,std::string>&\
			hash_recursos):Peer(std::move(peer)),hash(hash_recursos),
			keep_talking(true),is_running(true){
	}

	void send_answer(std::string server_answer);

	void process_command(std::string input_client);

	void run() override;

	void stop_ex();
};



#endif /* SERVER_SRC_THCLIENT_H_ */
