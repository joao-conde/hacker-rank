#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Spell {
   private:
    string scrollName;

   public:
    Spell() : scrollName("") {}
    Spell(string name) : scrollName(name) {}
    virtual ~Spell() {}
    string revealScrollName() { return scrollName; }
};

class Fireball : public Spell {
   private:
    int power;

   public:
    Fireball(int power) : power(power) {}
    void revealFirepower() { cout << "Fireball: " << power << endl; }
};

class Frostbite : public Spell {
   private:
    int power;

   public:
    Frostbite(int power) : power(power) {}
    void revealFrostpower() { cout << "Frostbite: " << power << endl; }
};

class Thunderstorm : public Spell {
   private:
    int power;

   public:
    Thunderstorm(int power) : power(power) {}
    void revealThunderpower() { cout << "Thunderstorm: " << power << endl; }
};

class Waterbolt : public Spell {
   private:
    int power;

   public:
    Waterbolt(int power) : power(power) {}
    void revealWaterpower() { cout << "Waterbolt: " << power << endl; }
};

class SpellJournal {
   public:
    static string journal;
    static string read() { return journal; }
};
string SpellJournal::journal = "";

void counterspell(Spell* spell) {
    struct LCS {
        static string lcs_str(const string& X, const string& Y) {
            typedef vector<string> VS;
            typedef vector<VS> VVS;
            unsigned long long L = X.size() + 1, C = Y.size() + 1;
            if (L < C) return lcs_str(Y, X);
            VVS LCS(2, VS(C, ""));

            for (unsigned long long i = 1; i != L; ++i) {
                for (unsigned long long j = 1; j != C; ++j) {
                    string& s = LCS[1][j];
                    s = LCS[0][j - 1];
                    if (X[i - 1] == Y[j - 1]) s += string(1, X[i - 1]);
                    if (LCS[0][j].size() > s.size() ||
                        (LCS[0][j].size() == s.size() && LCS[0][j] < s))
                        s = LCS[0][j];
                    if (LCS[1][j - 1].size() > s.size() ||
                        (LCS[1][j - 1].size() == s.size() && LCS[1][j - 1] < s))
                        s = LCS[1][j - 1];
                }
                LCS[0] = LCS[1];
            }
            return LCS[1][C - 1];
        }
    };

    if (Fireball* fireball = dynamic_cast<Fireball*>(spell)) {
        fireball->revealFirepower();

    }

    else if (Frostbite* frostbite = dynamic_cast<Frostbite*>(spell)) {
        frostbite->revealFrostpower();
    }

    else if (Thunderstorm* thunderstorm = dynamic_cast<Thunderstorm*>(spell)) {
        thunderstorm->revealThunderpower();
    }

    else if (Waterbolt* waterbolt = dynamic_cast<Waterbolt*>(spell)) {
        waterbolt->revealWaterpower();
    }

    else
        cout << LCS::lcs_str(spell->revealScrollName(), SpellJournal::journal)
                    .size()
             << endl;
}

class Wizard {
   public:
    Spell* cast() {
        Spell* spell;
        string s;
        cin >> s;
        int power;
        cin >> power;
        if (s == "fire") {
            spell = new Fireball(power);
        } else if (s == "frost") {
            spell = new Frostbite(power);
        } else if (s == "water") {
            spell = new Waterbolt(power);
        } else if (s == "thunder") {
            spell = new Thunderstorm(power);
        } else {
            spell = new Spell(s);
            cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while (T--) {
        Spell* spell = Arawn.cast();
        counterspell(spell);
    }
}