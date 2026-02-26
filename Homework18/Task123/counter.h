#pragma once

class Counter {
    static int created;
    static int copied;
    static int existing;
public:
    static void onDefault() { created++; existing++; }
    static void onCopy()    { copied++;  existing++; }
    static void onDestroy() { existing--; }


    static int getCreated()  { return created; }
    static int getCopied()   { return copied; }
    static int getExisting() { return existing; }
    static int getTotal()    { return created + copied; }
};