#include <vector>
#include <string>

class Tape
{
private:
    std::vector <char> positive_index_tape;
    std::vector <char> negative_index_tape;
    int position;
    char blank;

public:
    // Constructors    
    Tape(char blank, std::string data);
    Tape(char blank);
    Tape();

    // Sets data of the tape
    void set_data(std::string data);

    // Clears tape
    void clear();
    void clear(char blank);

    // Checks if the tape is empty
    bool empty();

    // Returns current symbol
    char read();
    // Rewrites current symbol
    void write(char s);

    // Moves head one tile to left
    void move_left();
    // Moves head one tile to Right
    void move_right();

    std::string get_data();
};
