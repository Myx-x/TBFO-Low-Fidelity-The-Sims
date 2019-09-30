#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int hygiene;
    int energy;
    int fun;
} stats;

map <string, stats> activity;
map <stats, string> states;

void makeStats(stats *attribute, int hygieneModifier, int energyModifier, int funModifier){
    (*attribute).hygiene += hygieneModifier;
    (*attribute).energy += energyModifier;
    (*attribute).fun += funModifier;
}

bool isStatsValid(stats attribute){
    return attribute.hygiene >= 0 && attribute.hygiene <= 15 && attribute.energy >= 0 && attribute.energy <= 15 && attribute.fun >= 0 && attribute.fun <= 15;
}

bool stopProgram(stats attribute){
    return (attribute.hygiene + attribute.energy + attribute.fun == 0) || (attribute.hygiene + attribute.energy + attribute.fun == 45);
}

void printStats(stats attribute){
    printf("Hygiene = %d\n", attribute.hygiene);
    printf("Energy = %d\n", attribute.energy);
    printf("Fun = %d\n", attribute.fun);
}

void copyStats(stats attribute, stats *temp){
    (*temp).hygiene = attribute.hygiene;
    (*temp).energy = attribute.energy;
    (*temp).fun = attribute.fun;
}

void initStates(){
    int counter = 0;
    for (int i = 0; i <= 15; i += 5){
        for (int j = 0; j <= 15; j += 5){
            for (int k = 0; k <= 15; k += 5){
                states[{i,j,k}] = "q"+to_string(counter);
            }
        }
    }
}

void initActivity(){
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
}

int main(){
    initStates();
    initActivity();

    stats attribute, temp;
    attribute.hygiene = 0; attribute.energy = 10; attribute.fun =0;
    bool stop = false;
    string action;
        
    printf("Sims Start.\n");
    printf("Initial Attribute :\n");
    printStats(attribute);

    while (!stop){
        if (stopProgram(attribute)){
            stop = true;
        }

        printf("Activity : ");
        cin >> action;
        temp.hygiene += activity[action].hygiene;
        temp.energy += activity[action].energy;
        temp.fun += activity[action].fun;

        if (isStatsValid(temp)){
            copyStats(temp, &attribute);
            cout << "State : " << states[{attribute.hygiene, attribute.energy, attribute.fun}] << endl;
        } else {
            printf("Aksi Tidak Valid\n");
            temp.hygiene -= activity[action].hygiene;
            temp.energy -= activity[action].energy;
            temp.fun -= activity[action].fun;
        }

        cout << states[{attribute.hygiene, attribute.energy, attribute.fun}] << endl;
        printStats(attribute);
    }
    printf("Program Has Finished.\n");
    printf("Final Attribute : \n");
    printStats(attribute);

    return 0;
}