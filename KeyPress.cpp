#include <iostream>;

#include <Windows.h>;

bool running = true;

void RegisterKey(int nVirtKey, int cooldown) {
    if (!running) return;

    do {
        bool keypress = false;

        if (GetKeyState(nVirtKey) & 0x8000) {
            if (keypress) return;
            if (!keypress) keypress = true;

            char character = nVirtKey;
            std::cout << character << " was pressed" << "\n";

            Sleep(cooldown);
            keypress = false;
        }
    } while (running);
}

int main()
{
    RegisterKey('A', 250);
    return 0;
}
