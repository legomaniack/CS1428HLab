#include <iostream>
#include <iomanip>
#include <cmath>


// Nolan Groves
// Lab 09 - Don't mp3 files do this by themselves?

using namespace std;


struct song {
    string title;
    string filename;
    string genre;
    int tracknumber;
    bool fav;
};

song podPod[256];
int podPodCounter = 0;
void newSong() {
    if (podPodCounter > 256) {
        cout << "Cannot hold any more songs"<<endl;;
        return;
    }
    song temp;
    cout << "Enter song title: ";cin>> temp.title;
    cout << "Enter song filename: ";cin>> temp.filename;
    cout << "Enter song genre: ";cin>> temp.genre;
    cout << "Enter song track number: ";cin>> temp.tracknumber;
    string tempst;
    cout << "Is the song a favorite? [y/N]: ";cin>> tempst;
    if (tempst == "y" || tempst == "Y") {temp.fav = true;} else {temp.fav = false;}
    podPod[podPodCounter++] = temp;
    return;
}

int nameSearch(string name, bool nam) {
    int k = -1;
    for (int i = 0; i <= podPodCounter; i++) {
        if(nam) {
            if (podPod[i].title == name) k = i;
        } else {
            if (podPod[i].filename == name) k = i;
        }
    }
}

void delIndex(int k) {
    if (podPodCounter == 1) {
        podPodCounter--;
        return;
    }
    for (int i = k; i < podPodCounter-1; i++) {
        podPod[i] = podPod[i++];
    }
    podPodCounter--;
}

void deleteSong() {
    cout << "Delete song by?" <<endl;
    cout << "1) Song id"<<endl;
    cout << "2) Song name"<<endl;
    cout << "3) Song filename"<<endl;
    int choice = 0;
    cin >> choice;
    string inp;
    int inpi;
    int k;
    switch (choice) {
        case 1:
            cout << "Id: ";cin >> inpi;
            if (inpi > podPodCounter) {
                cout << "Song does not exist." << endl;
            } else {
                delIndex(inpi-1);
                cout << "Song "<<inpi<<" deleted."<<endl;
            }
            break;
        case 2:
            cout << "Name: ";cin >> inp;
            k = nameSearch(inp, true);
            if (k == -1) {
                cout << "Song does not exist." << endl;
            } else {
                delIndex(k);
                cout << "Song "<<k+1<<" deleted."<<endl;
            }
            break;
        case 3:
            cout << "Filename: ";cin >> inp;
            k = nameSearch(inp, false);
            if (k == -1) {
                cout << "Song does not exist." << endl;
            } else {
                delIndex(k);
                cout << "Song "<<k+1<<" deleted."<<endl;
            }
            break;
        default:
            cout << "Invalid choice" <<endl;
            break;
    }
}

void displaySongs(bool favs) {
    bool disp = true;
    cout << "All songs: "<<endl;
    for (int i = 0; i< podPodCounter;i++) {
        song isong = podPod[i];
        if (favs) {
            disp = isong.fav;
        } else { disp = true;}
        if (disp) {
            cout << "  "  << isong.title;
            if (isong.fav) {
                cout <<" *";
            }
            cout<<endl;
            cout << "    "<< isong.filename<<endl;
            cout << "    "<< isong.genre<<endl;
            cout << "    track "<< isong.tracknumber<<endl;
            cout << endl;
        }
    }
}

void editSongData(song &s) {
    cout << "Edit which attribute of the song?"<<endl;
    cout << "1) Title ("<<s.title<<")"<<endl;
    cout << "2) Filename ("<<s.filename<<")"<<endl;
    cout << "3) Genre ("<<s.genre<<")"<<endl;
    cout << "4) Track number ("<<s.tracknumber<<")"<<endl;
    cout << "5) Favorite ("<<s.fav<<")"<<endl;
    int choice;
    string inp;
    int inpi;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Enter new title: ";cin>>inp;
            s.title = inp;
            break;
        case 2:
            cout << "Enter new filename: ";cin>>inp;
            s.filename = inp;
            break;
        case 3:
            cout << "Enter new genre: ";cin>>inp;
            s.genre = inp;
            break;
        case 4:
            cout << "Enter new track number: ";cin>>inpi;
            s.tracknumber = inpi;
            break;
        case 5:
            s.fav = !s.fav;
            break;
        default:
            cout << "Invalid choice" <<endl;
            break;
    }
}

void editSong() {
    cout << "Select song by?" <<endl;
    cout << "1) Song id"<<endl;
    cout << "2) Song title"<<endl;
    cout << "3) Song filename"<<endl;
    int choice = 0;
    cin >> choice;
    string inp;
    int inpi;
    int k;
    switch (choice) {
        case 1:
            cout << "Id: ";cin >> inpi;
            if (inpi > podPodCounter) {
                cout << "Song does not exist." << endl;
            } else {
                editSongData(podPod[inpi-1]);
            }
            break;
        case 2:
            cout << "Name: ";cin >> inp;
            k = nameSearch(inp, true);
            if (k == -1) {
                cout << "Song does not exist." << endl;
            } else {
                editSongData(podPod[k]);
            }
            break;
        case 3:
            cout << "Filename: ";cin >> inp;
            k = nameSearch(inp, false);
            if (k == -1) {
                cout << "Song does not exist." << endl;
            } else {
                editSongData(podPod[k]);
            }
            break;
        default:
            cout << "Invalid choice" <<endl;
            break;
    }
}

int main() {
    while (true) {
    cout << "PodPod Menu"<<endl<<endl;
    cout << "1) New Song"<<endl;
    cout << "2) Edit Song"<<endl;
    cout << "3) Delete Song"<<endl;
    cout << "4) Display Songs"<<endl;
    cout << "5) Display Favorites"<<endl;
    int choice;
    cout<<"> ";cin >> choice;cout<<endl;
    switch (choice) {
        case 1:
            newSong();
            break;
        case 2:
            editSong();
            break;
        case 3:
            deleteSong();
            break;
        case 4:
            displaySongs(false);
            break;
        case 5:
            displaySongs(true);
            break;
        default:
            cout << "Invalid choice";
            break;
    }
    cout <<endl<<endl;
    }
    return 0;
}
