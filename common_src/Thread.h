#ifndef COMMON_SRC_THREAD_H_
#define COMMON_SRC_THREAD_H_

#include <thread>

class Thread {
private:
  std::thread thread;
public:
  Thread();

  virtual ~Thread();

  Thread(const Thread&) = delete;

  Thread& operator=(const Thread&) = delete;

  Thread(Thread&& other);

  Thread& operator=(Thread&& other);

  // Inicia el hilo
  void start();

  // Metodo que contiene la tarea ser ejecutada por el hilo actual
  virtual void run() = 0;

  // Realiza un join del hilo actual
  void join();
};



#endif /* COMMON_SRC_THREAD_H_ */
