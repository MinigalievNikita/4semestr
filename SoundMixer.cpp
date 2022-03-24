#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <math.h>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>

std::vector<std::string> files({"carsound.ogg", "file1.ogg", "file2.ogg"});

class MusicPlayer{
public:
    std::vector<std::string> files;
    sf::Music music;
    int curFile = 0;
    void SetMusic(const std::vector<std::string>& musicFiles) {
        files = musicFiles;
    }
    void Play() {
        for(;;){
            std::this_thread::sleep_for (std::chrono::seconds(1));
            if(music.getStatus() == sf::SoundSource::Stopped) {
                music.openFromFile(files[curFile]);
                music.play();
                curFile++;
            }
            if(files.size() <= curFile) {
                break;
            }
        }
    }
};

int main()
{
    MusicPlayer media;
    media.SetMusic(files);
    media.Play();
    while (1)
    {
    }
}
