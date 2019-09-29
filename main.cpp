#include <iostream>
#include <string>

using namespace std;

struct stats {
    int h;
    int e;
    int f;
};

int main(){
    bool stop = false;
    string action;
    stats atr;
    atr.h=0; atr.e=10; atr.f=0; // initial attribute value
    printf("Program Start.\n");
    printf("Initial Attribute :\n");
    printf("%d\n", atr.h);
    printf("%d\n", atr.e);
    printf("%d\n", atr.f);
    
    while (!stop){
        if ((atr.h>15 & atr.e>15 && atr.f>15) || (atr.h<0 && atr.e<0 && atr.f<0)){
            stop = true;
        }
        scanf("%s", &action);
        
    }

    return 0;
}