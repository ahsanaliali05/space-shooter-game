#include"logger.h"
#include<ctime>
using namespace std;
void log_action(const string& msg) {
    ofstream log_file("logger.txt", ios::app);
    if (log_file.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        log_file << "[" << dt << "] " << msg << endl;
        log_file.close();
    }
}
void ClearLogger() {
    std::ofstream file("logger.txt", std::ios::out);
    file.close();
}