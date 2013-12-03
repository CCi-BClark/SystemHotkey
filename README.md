SystemHotkey
============

C++ Library for making a system wide hotkey.  Two versions are inside the source tree.  Currently all versions work for Windows NT 2000, XP, VISTA, 7, & 8.

&SystemHotkey for gerneral use and doesn't contain a return for keyboard response at this moment.
```
SystemHotkey *hotkeys;

hotkeys->addKey(200,MOD_ALT,'X');
hotkeys->beginHotkeys();
//Note no emitter function exist.
```

&QSystemHotkey for Qt5.1.  
```
void hotkeyPressed(int position);  //Handle hotkey SIGNAL

//Create data type.
STDSystemHotkey *hotkeys;

//Connect data type to hadler function.
connect(hotkeys, SIGNAL(runHotkey(int)),this,SLOT(hotkeyPressed(int)));


hotkeys->addKey(200,MOD_ALT,'X'); //Add hotkey to system.

QApplication::processEvents();
hotkeys->beginHotkeys();		  //Start listening for hotkeys.

hotkeyPressed(int position){
    int val = hotkey->getHotkey(position);
    switch (val) {
    case 200:
        //function to run
        break;
    default:
        break;
    }
}

```
See Example

