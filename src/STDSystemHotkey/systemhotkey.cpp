#include "systemhotkey.h"

SystemHotkey::SystemHotkey(void) {
    running = false;
}

SystemHotkey::~SystemHotkey(){

}

void SystemHotkey::removeKey(int keyID){
    for (int i = 0; i < (int)hotkeys.size(); ++i) {
        if(hotkeys.at(i) == keyID){
            UnregisterHotKey(NULL,hotkeys.at(i));
            hotkeys.erase(hotkeys.begin() + i);
        }
    }
}

void SystemHotkey::addKey(int keyID, UINT holdKey, char charKey){
    hotkeys.push_back(keyID);
    RegisterHotKey(NULL,keyID,holdKey | MOD_NOREPEAT,charKey);
}

void SystemHotkey::beginHotkeys(){
    running = true;
    listen();
}

void SystemHotkey::haltHotkeys(){
    running = false;
}

void SystemHotkey::listen(){
    while(running){
        GetMessage(&msg,NULL,0,0);
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        if (msg.message == WM_HOTKEY){
            for (int i = 0; i < (int)hotkeys.size(); ++i) {
                if (msg.wParam == hotkeys.at(i)) run(i);
            }
        }
    }
}

void SystemHotkey::run(int pos){
    // emit a return signal
}
