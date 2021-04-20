#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Prof {
    string first;
    string last;
    string lecture_link;
    string oh_link;
};

int main(int argc, char * argv[]) {
    if (argc == 1) {
        system("cat links.txt");
    }
    else {
        vector<Prof> profs;

        // Tev
        profs.push_back(Prof());
        profs[0].first = "Tevian";
        profs[0].last = "Dray";
        profs[0].lecture_link = "https://oregonstate.zoom.us/j/92350336223?pwd=NS81a0RtaTQzSmN1NUV6M002VnZQdz09";
        profs[0].oh_link = "https://oregonstate.zoom.us/j/949650820?pwd=TitDMnBZWTltN3AyeVpzVWJuQkNYdz09";

        // Juha 
        profs.push_back(Prof());
        profs[1].first = "Petri";
        profs[1].last = "Juha";
        profs[1].lecture_link = "https://oregonstate.zoom.us/j/97384537147?pwd=SSs2SURtTzRkZzVhaWNQYkh4U1ByZz09";
        profs[1].oh_link = "https://oregonstate.zoom.us/j/949650820?pwd=TitDMnBZWTltN3AyeVpzVWJuQkNYdz09";

        string input_1 = argv[1];
        string input_2 = argv[2];
        string command = "open ";
        if (input_1 == "lecture") {
            for (int i = 0; i < profs.size(); i++) {
                if (profs[i].first == input_2 || profs[i].last == input_2) {
                    command.append(profs[i].lecture_link);
                }
            }
        }
        else {
            for (int i = 0; i < profs.size(); i++) {
                if (profs[i].first == input_2 || profs[i].last == input_2) {
                    command.append(profs[i].oh_link);
                }
            }
        }
        const char* run = command.c_str();
        system(run);
    }
    return 0;
}
