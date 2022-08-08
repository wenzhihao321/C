#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

class Sem{
    private:
        sem_t sem;
    public:
        Sem(int num)
        {
            sem_init(&sem, 0, num);
        }
        void P()
        {
            sem_wait(&sem);
        }
        void V()
        {
            sem_post(&sem);
        }
        ~Sem()
        {
            sem_destroy(&sem);
        }
};

Sem sem(1);
int tickets = 2000;

void *GetTickets(void *arg)
{
    std::string name =(char*)arg;

    sleep(1);
    while(true){
        sem.P();
        if(tickets > 0){
            std::cout << name << " get ticket: " << tickets-- << std::endl;
            sem.V();
            usleep(10000);
        }
        else{
            sem.V();
            break;
        }
    }

    std::cout << name << " quit" << std::endl;

    pthread_exit((void*)0);
}


int main()
{
    pthread_t tid1, tid2, tid3;
    pthread_t tid4, tid5, tid6;
    pthread_create(&tid1, nullptr, GetTickets, (void*)"thread 1");
    pthread_create(&tid2, nullptr, GetTickets, (void*)"thread 2");
    pthread_create(&tid3, nullptr, GetTickets, (void*)"thread 3");
    pthread_create(&tid4, nullptr, GetTickets, (void*)"thread 4");
    pthread_create(&tid5, nullptr, GetTickets, (void*)"thread 5");
    pthread_create(&tid6, nullptr, GetTickets, (void*)"thread 6");

    pthread_join(tid1, nullptr);
    pthread_join(tid2, nullptr);
    pthread_join(tid3, nullptr);
    pthread_join(tid4, nullptr);
    pthread_join(tid5, nullptr);
    pthread_join(tid6, nullptr);

    return 0;
}
