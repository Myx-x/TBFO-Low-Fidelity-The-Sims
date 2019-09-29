#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int hygiene;
    int energy;
    int fun;
} stats;

void makeStats(stats *attribute, int hygieneModifier, int energyModifier, int funModifier){
    (*attribute).hygiene += hygieneModifier;
    (*attribute).energy += energyModifier;
    (*attribute).fun += funModifier;
}

map <string, stats> activity;
map <stats, string> states;

int main(){
    stats attribute;
    attribute.hygiene = 0; attribute.energy = 0; attribute.fun =0;
    bool stop = false;
    string action;
    
    printf("Sims Start.\n");
    printf("Initial Attribute :\n");
    printf("Hygiene = %d\n", attribute.hygiene);
    printf("Energy = %d\n", attribute.energy);
    printf("Fun = %d\n", attribute.fun);
    
    activity["Tidur Siang"] = {0,10,0};
    activity["Tidur Malam"] = {0,15,0};
    activity["Makan Hamburger"] = {0,5,0};
    activity["Makan Pizza"] = {0,10,0};
    activity["Makan Steaks and Beans"] = {0,15,0};
    activity["Minum Air"] = {-5,0,0};
    activity["Minum Kopi"] = {-10,5,0};
    activity["Minum Jus"] = {-5,10,0};
    activity["Buang Air Kecil"] = {5,0,0};
    activity["Buang Air Besar"] = {10,-5,0};
    activity["Bersosialisasi ke Kafe"] = {-5,-10,15};
    activity["Bermain Media Sosial"] = {0,-10,10};
    activity["Bermain Komputer"] = {0,-10,15};
    activity["Mandi"] = {15,-5,0};
    activity["Cuci Tangan"] = {5,0,0};
    activity["Mendengarkan Musik di Radio"] = {0,-5,10};
    activity["Membaca Koran"] = {0,-5,5};
    activity["Membaca Novel"] = {0,-5,10};

    states[{0,0,0}] = "q0";

    while (!stop){
        if ((attribute.hygiene>15 & attribute.energy>15 && attribute.fun>15) || (attribute.hygiene<0 && attribute.energy<0 && attribute.fun<0)){
            stop = true;
        }
        cin >> action;
    }

    return 0;
}