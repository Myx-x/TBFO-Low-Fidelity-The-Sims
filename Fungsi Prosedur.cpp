//Melakukan pengecekan terhadap kondisi stats, apakah berada di dalam batas [0..15] atau tidak
bool isStatsValid(stats attribute);

// Mengembalikan true bila kondisi atribut sesuai dengan kondisi berhenti (0,0,0 atau 15,15,15)
bool stopProgram(stats attribute);

// Melakukan print untuk atribut yang ada
void printStats(stats attribute);

// Membuat copy stats attribute ke temp
void copyStats(stats attribute, stats *temp);