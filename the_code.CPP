#include <iostream>
#include <conio.h>
#include <windows.h>
#include <random>


#define RESET "\033[0m"
#define GREEN "\033[32m"  

bool S_DAF;

////////////////////////////////////////////////////////////////////////////////
static void randowblimp(int ini, int fim, int probabilityOfStar) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(ini, fim);

    for (int i = ini; i <= fim; i++) {
        if (distrib(gen) <= probabilityOfStar) {
            std::cout << "*";
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

static void brightness_transition(int speed) {
    int i = 0;
    while (i != 100) {
        i += speed;
        randowblimp(0, 100, i);
    }

    while (i != 0) {
        i -= speed;
        randowblimp(0, 100, i);
    }
}
////////////////////////////////////////////////////////////////////////////////



static void limparTela() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordScreen = { 0, 0 };
    DWORD cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConSize;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return;
    }

    dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    if (!FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConSize, coordScreen, &cCharsWritten)) {
        return;
    }
    if (!SetConsoleCursorPosition(hConsole, coordScreen)) {
        return;
    }
}


std::string logo = R"(
  _  ___  ___                   
 | |/ / |/ / |                  
 | ' /| ' /| | ___   __ _  ___  
 | ; |   ; | |/ _ \ / _` |/ _ \ 
 | . \| . \| | (_) | (_| | (_) |
 |_|\_\_|\_\_|\___/ \__, |\___/ 
  github Obentemiller__/ |      
                    |___/           
)";


std::string ascii_art0 = R"(
    ._________________.       
    |.---------------.|       
    ||               ||       
    ||    PRONTO!    ||        
    ||               ||       
    ||               ||       
    ||_______________||       
    /.-.-.-.-.-.-.-.-.\       
   /.-.-.-.-.-.-.-.-.-.\      
  /.-.-.-.-.-.-.-.-.-.-.\    
 /______/__________\___o_\
 \_______________________/                                                             
)";

std::string ascii_art1 = R"(
    ._________________.       
    |.---------------.|       
    ||               ||       
    ||   ATÉ MAIS!   ||        
    ||  Obentemiller ||       
    ||               ||       
    ||_______________||       
    /.-.-.-.-.-.-.-.-.\     
   /.-.-.-.-.-.-.-.-.-.\    
  /.-.-.-.-.-.-.-.-.-.-.\    
 /______/__________\___o_\
 \_______________________/                                                             
)";

std::string ascii_art2 = R"(
     _________________     
    /                  \      
   /                    \       
  /                      \      
 /_____________obrigado __\     
 |------------------------|
 \________________________/                                                             
)";


static void finalização() {
    Sleep(1000);
    limparTela();
    std::cout << ascii_art0 << std::endl;
    Sleep(1000);
    limparTela();
    std::cout << ascii_art1 << std::endl;
    Sleep(1000);
    limparTela();
    std::cout << ascii_art2 << std::endl;
}


static void renova_interface() {
    limparTela();
    std::cout << logo << std::endl;
}

static void selectgrafic() {
    char in = ' ';
    bool modo = false;

    while (in != 'q') {
        limparTela();
        std::cout << logo << std::endl;
        std::cout << "  <Pressione 'q' para continuar>" << std::endl;
        in = _getch();
    }
    brightness_transition(1);

        in = ' ';
        while (in != 'q') {
            limparTela();
            std::cout << logo << std::endl;
            std::cout << "  selecione o modo " << (modo ? "<modo 2>" : "<modo 1>") << std::endl;
            std::cout << "  <'q' para continuar>" << std::endl;
            in = _getch();
            if (in == 77 || in == 75) {
                modo = !modo;
                S_DAF = modo;
            }
        }
    brightness_transition(1);

}


static void case1() {

    limparTela();

    std::cout << logo << std::endl;
    std::cout << "case1" << std::endl;
    
    Sleep(1000);
    brightness_transition(1);
    limparTela();
    finalização();
}

static void case2() {

    limparTela();

    std::cout << logo << std::endl;
    std::cout << "case2" << std::endl;

    Sleep(1000);
    brightness_transition(1);
    limparTela();
    finalização();
}


int main() {
    selectgrafic();

        switch (S_DAF) {
        case 0:
            case1();
            return 0;
        case 1:
            case2();
            return 0;
        }
    
    return 0;
}
