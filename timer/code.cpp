#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

void wait(){
    std::this_thread::sleep_for(std::chrono::seconds(1));
}

void clear_terminal(){
#ifdef _WIN32
    std::system("cls");
#else
    std::cout << "\x1B[2J\x1B[H";
    std::cout.flush();
#endif
}

void timer(int hours, int minutes, int seconds){
    while(true){
        
        if(hours!=0){
            std::cout << hours << "h - " << minutes << "m - " << seconds << "s\n";
        }

        else if(hours == 0 && minutes != 0){
            std::cout << minutes << "m - " << seconds << "s\n";
        }

        else if(minutes == 0 && seconds != 0){
            std::cout << seconds << "s\n";
        }

        wait();

        if(seconds==0){
            if(minutes==0){
                if(hours==0){
                    clear_terminal();
                    break;
                }

                else{
                    hours--;
                    minutes+=59;
                    seconds+=59;
                }
            }

            else{
                minutes--;
                seconds+=59;
            }
        }

        else{
            seconds--;
        }

        clear_terminal();
    }
}

int main(){
    std::cout << "Timer\n";

    int h;
    int m;
    int s;

    std::cout << "Enter amount of hours: ";
    std::cin >> h;

    if(h < 0 || h > 100){
        std::cout << "Hours must be between 0 - 100\n";
        return 1;
    }

    std::cout << "Enter amount of minutes: ";
    std::cin >> m;

    if(m < 0 || m > 60){
        std::cout << "Minutes must be between 0 - 60\n";
        return 1;
    }

    std::cout << "Enter amount of seconds: ";
    std::cin >> s;

    if(s < 0 || s > 60){
        std::cout << "Seconds must be between 0 - 60\n";
        return 1;
    }

    timer(h, m, s);

    std::cout << "Time's up !\n";

    return 0;
}