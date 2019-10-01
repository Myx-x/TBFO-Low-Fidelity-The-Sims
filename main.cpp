#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int hygiene;
    int energy;
    int fun;
} stats;

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

int main(){
    stats attribute, temp;
    attribute.hygiene = 0; attribute.energy = 10; attribute.fun =0;
    bool stop = false;
    string action;
    
    printf("\n");
    printf("                               `--`  -+:/+.       \n");
    printf("           ``-:::- `-:::`   `-/:..//o/`:/:.       \n");
    printf("        `:::-`   +-o`  `o.-::.../:..:-`o.      `. \n");
    printf("      `/:`    `.-:oo-``.s/--/++`.`-o/-.+:`  ````  \n");
    printf("      o.    -::-.``o:..-y/o-`o/---:o:+o:o:::---+- \n");
    printf("      o`    +:     o`   o`o  `+` `+- `o.s-` `.-:+`\n");
    printf("      -/`   `:/.   o`   o:/   .+`+-   ++/   +:``  \n");
    printf("...... `::`   `-/- o`   oo.    .o-    -o/-  ./:.  \n");
    printf("+-`-.-::-/o/`   `:/o`   so      `      o..:-  `/: \n");
    printf("+-`-.-::-/o/`   `:/o`   so      `      o..:-  `/: \n");
    printf(" --/-////++/-     +s`   y`   -`   `:   `s:-.  `-/`\n");
    printf("     `++.``    `-/-o:---+    o+   /s    ++---::.` \n");
    printf("       -/`.--:::.`  ```+-   .+:/`/:/-   .o```     \n");
    printf("        `--.``         :::::/- .--``:::::/`       \n");
    printf("\n");

    printf("Initial attribute :\n");
    printStats(attribute);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    while (!stop){
        printf("|******************************************************************|\n");
        printf("|*---------------------Available Activity-------------------------*|\n");
        printf("|*   Tidur Siang               ||    Buang Air Kecil              *|\n");
        printf("|*   Tidur Malam               ||    Buang Air Besar              *|\n");
        printf("|*   Makan Hamburger           ||    Bersosialisasi ke Kafe       *|\n");
        printf("|*   Makan Pizza               ||    Bermain Media Sosial         *|\n");
        printf("|*   Makan Steaks and Beans    ||    Bermain komputer             *|\n");
        printf("|*   Minum Air                 ||    Mandi                        *|\n");
        printf("|*   Minum Kopi                ||    Cuci Tangan                  *|\n");
        printf("|*   Minum Jus                 ||    Mendengarkan Musik di Radio  *|\n");
        printf("|*   Membaca Koran             ||    Membaca Novel                *|\n");
        printf("|******************************************************************|\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

        printf("Activity : ");
        getline(cin, action);
        copyStats(attribute, &temp);
        if (action == "Tidur Siang"){
            temp.energy += 10;
        } else if (action == "Tidur Malam"){
            temp.energy += 15;
        } else if (action == "Makan Hamburger"){
            temp.energy += 5;
        } else if (action == "Makan Pizza"){
            temp.energy += 10;
        } else if (action == "Makan Steak and Beans"){
            temp.energy += 15;
        } else if (action == "Minum Air"){
            temp.hygiene += -5;
        } else if (action == "Minum Kopi"){
            temp.hygiene += -10;
            temp.energy += 5;
        } else if (action == "Minum Jus"){
            temp.hygiene += -5;
            temp.energy += 10;
        } else if (action == "Buang Air Kecil"){
            temp.hygiene += 5;
        } else if (action == "Buang Air Besar"){
            temp.hygiene += 10;
            temp.energy += -5;
        } else if (action == "Bersosialisasi ke Kafe"){
            temp.hygiene += -5;
            temp.energy += -10;
            temp.fun += 15;
        } else if (action == "Bermain Media Sosial"){
            temp.energy += -10;
            temp.fun += 10;
        } else if (action == "Bermain komputer"){
            temp.energy += -10;
            temp.fun += 15;
        } else if (action == "Mandi"){
            temp.hygiene += 15;
            temp.energy += -5;
        } else if (action == "Cuci Tangan"){
            temp.hygiene += 5;
        } else if (action == "Mendengarkan Musik di Radio"){
            temp.energy += -5;
            temp.fun += 10;
        } else if (action == "Membaca Koran"){
            temp.energy += -5;
            temp.fun += 5;
        } else if (action == "Membaca Novel"){
            temp.energy += -5;
            temp.fun += 10;
        } else {
            printf("Aksi tidak terdaftar\n");
        }

        if (isStatsValid(temp)){
            copyStats(temp, &attribute);
        } else {
            printf("Aksi tidak valid\n");
        }

        printStats(attribute);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        if (stopProgram(attribute)){
            stop = true;
        }
    }
    printf("Program has finished.\n");
    if (attribute.hygiene == 15 && attribute.energy == 15 && attribute.fun == 15){
        printf("You win in life.\n");
    } else {
        printf("Try again next life.\n");
    }

    return 0;
}