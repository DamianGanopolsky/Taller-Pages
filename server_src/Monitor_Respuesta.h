#ifndef SERVER_SRC_MONITOR_RESPUESTA_H_
#define SERVER_SRC_MONITOR_RESPUESTA_H_
#include <unordered_map>
#include <mutex>
#include <tuple>
#include <string>


class Monitor_Respuesta{
private:
	std::unordered_map<std::string, std::string>& protected_hash;
	std::mutex m;

public:
	explicit Monitor_Respuesta(std::unordered_map<std::string, std::string>&\
			hash_recursos):protected_hash(hash_recursos){
	}

	void Respuesta_Servidor(const std::tuple<std::string,std::string,\
			std::string>petitorio,std::string& respuesta_al_cliente);

	~Monitor_Respuesta();
};


#endif /* SERVER_SRC_MONITOR_RESPUESTA_H_ */
