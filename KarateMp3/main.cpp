#include <iostream> 
#include <cstdlib>
#include <fstream>
#include <ncurses.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

const char pausekey = 'p';

int c = getch();
int option;
int options_option;
string visualiser;

string path;
string str_vis;

int main(int argc, char **argv) {

	// Main Menu
	printf("-------------------------------------------------- \n \n");

	printf(" _   __                _      ___  ___      _____ \n");
	printf("| | / /               | |     |  \\/  |     |____ | \n");
	printf("| |/ /  __ _ _ __ __ _| |_ ___| .  . |_ __     / / \n");
	printf("|    \\ / _` | '__/ _` | __/ _ | |\\/| | '_ \\    \\ \\ \n");
	printf("| |\\  | (_| | | | (_| | ||  __| |  | | |_) .___/ / \n");
	printf("\\_| \\_/\\__,_|_|  \\__,_|\\__\\___\\_|  |_| .__/\\____/ \n");
	printf("                                     | | \n");
	printf("                                     |_| \n \n");

	cout << "-------------------------------------------------" << endl;
    cout << "choose a option ( 1/2 )" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "1. Play an audio file." << endl;
    cout << "2. Config and GIF paths." << endl;
	cout << "3. Sauce" << endl;
    
    cin >> option;
    
	// Rest of the program
    switch(option) {
        
        default: {
            
            printf("Error 404: there is no such an option \n");
            return 404;
            
        }
            
        case 1: {

			play:

        	printf("Type in path to your desired audio file: ");
        	cin >> path;

			fstream config;
			config.open("config.conf", ios::in);

			if(config.good() == false) {
		
				cout << "there is no config file";
				exit(0);
		
			}

			string line;
			int line_nr = 1;
			while(getline(config, line)) {
				switch(line_nr) {
			
					case 1: visualiser = line; break;
			
				}	
				line_nr++;
			}

			config.close();
			cout << visualiser << endl;

        	if(visualiser == "visualiser = false") {

                int result = 0;
    			int flags = MIX_INIT_MP3;

    			if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        			printf("Failed to init SDL\n");
        			exit(1);
    			}

    			if (flags != (result = Mix_Init(flags))) {
        			printf("Could not initialize mixer (result: %d).\n", result);
        			printf("Mix_Init: %s\n", Mix_GetError());
        			exit(1);
    			}

				const char *path_mp3 = path.c_str();

    			Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    			Mix_Music *music = Mix_LoadMUS(path_mp3);
    			Mix_PlayMusic(music, -1);

    			while (!SDL_QuitRequested()) {
        			SDL_Delay(250);
    			}

    			Mix_FreeMusic(music);
    			Mix_Quit();
				return 0;

			}
        	else {

            	int result = 0;
    			int flags = MIX_INIT_MP3;

    			if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        			printf("Failed to init SDL\n");
        			exit(1);
    			}

    			if (flags != (result = Mix_Init(flags))) {
        			printf("Could not initialize mixer (result: %d).\n", result);
        			printf("Mix_Init: %s\n", Mix_GetError());
        			exit(1);
    			}

				system("mpv --loop $HOME/.config/KarateMp3/visualisation/vis.gif");

				const char *path_mp3 = path.c_str();

    			Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    			Mix_Music *music = Mix_LoadMUS(path_mp3);
    			Mix_PlayMusic(music, 1);

    			while (!SDL_QuitRequested()) {
        			SDL_Delay(250);
    			}

    			Mix_FreeMusic(music);
    			Mix_Quit();
				return 0;

        	}
		}
		break;

        case 2: {
			
			cout << "-------------------------------" << endl;
    		cout << "choose an option ( 1/1 for now )" << endl;
    		cout << "-------------------------------" << endl;
    		cout << "1. Show a GIF path" << endl;
    		
			cin >> options_option;
		
			switch(options_option) {
		
				default: {
				 
            		printf("Error 404: there is no such an option");
            		return 404;
            
				}
			
				case 1: {
				
            		printf("GIF path: $HOME/.config/KarateMp3/visualization/vis.gif");
            		return 0;		

				} 
    		}
		}
		break;

		case 3: {

			printf("there is no sauce you perverted degenerate.\n But here is my site: https://niezesrajsie.tk \n");

		}	
	}
}
