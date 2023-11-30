#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

struct ColorConsole
{
    static const char* fg_red;
    static const char* fg_black;
};

const char* ColorConsole::fg_red = "\033[31m";
const char* ColorConsole::fg_black = "\033[30m";

struct ConsoleBox
{
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado

