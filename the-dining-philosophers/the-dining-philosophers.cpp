class DiningPhilosophers {
public:
    mutex m;
    condition_variable cv;
    vector<bool> fork;
    DiningPhilosophers() {
        fork.resize(5,true);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {

               { 
                    unique_lock<mutex> lock(m);

                     cv.wait(lock, [&](){
                        return fork[philosopher] && fork[(philosopher + 1) % 5]; 
                    });
                    pickLeftFork();
                    pickRightFork();
                    fork[philosopher]=false;
                    fork[(philosopher+1)%5]=false;
                }

                eat();
                {
                    lock_guard<mutex> lg(m);
                    putLeftFork();
                    putRightFork();

                    fork[philosopher]=true;
                    fork[(philosopher+1)%5]=true;
                }
                cv.notify_all();
    }
};