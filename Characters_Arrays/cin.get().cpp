#include<iostream>
#include <chrono>
#include <thread>

using namespace std;
void loadingBar(int total, int current, int width) {
    float progress = static_cast<float>(current) / total;
    int barWidth = static_cast<int>(progress * width);

    std::cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        std::cout << "=";
    }
    std::cout << ">";
    for (int i = barWidth; i < width; ++i) {
        std::cout << " ";
    }
    std::cout << "] " << static_cast<int>(progress * 100.0) << "%\r";
    std::cout.flush();
}

int main(){
    char ch;

    ch = cin.get();

    int alpha = 0;
    int digits = 0;
    int spaces = 0;
    int totalIterations = 100;
    int currentIteration = 0;
    int loadingBarWidth = 50;

    while(ch != '#'){
            if(ch >= '0' and ch <= '9'){
                digits++;
            }
            else if(ch >='A' and ch <= 'z'){
                alpha++;
            }
            else if(ch == ' '){
                spaces++;
            }

            ch = cin.get();
            

            if(ch == '\n'){
                for (int i = 0; i <= totalIterations; ++i) {
                    loadingBar(totalIterations, currentIteration, loadingBarWidth);
                    this_thread::sleep_for(chrono::milliseconds(20)); // Simulate some work
                    ++currentIteration;
                }

                cout << std::endl;
                
                cout << "Spaces\t\t"<<spaces<<endl
                <<"Alphabetic\t"<<alpha<<endl
                <<"Digits\t\t"<<digits<<endl;
                digits = 0; alpha = 0; spaces = 0;
                currentIteration = 0;
            }
    }
    return 0;
}