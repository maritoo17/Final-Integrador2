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

ConsoleBox *consoleBox = new ConsoleBox;

void load_script(const char* filename, bool show_script = false)
{
    string script;
    FILE* f = nullptr;
    try
    {
        f = fopen(filename, "rb");
        if (!f)
        {
            cerr << "Error al abrir " << filename << endl;
            return;
        }

        char buf[4001];
        size_t bytes_read = fread(buf, 1, 4000, f);
        while (bytes_read > 0)
        {
            buf[bytes_read] = '\0'; // Null-terminate the buffer
            script.append(buf, bytes_read);
            bytes_read = fread(buf, 1, 4000, f);
        }

        fclose(f);
        f = nullptr;

        if (show_script)
        {
            cout << ColorConsole::fg_red << ColorConsole::fg_black << endl;
            cout << script << endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (const std::exception& e)
    {
        cerr << "Error durante la lectura del archivo: " << e.what() << endl;
        if (f)
            fclose(f);
    }
}

int main() {
    load_script("main.cpp", true);
    return 0;
}

