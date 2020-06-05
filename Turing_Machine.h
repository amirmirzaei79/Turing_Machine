#include "Tape.h"
#include <map>
#include <set>
#include <string>

struct Transition
{
    int source_state;
    int destination_state;
    char read_symbol;
    char write_symbol;
    char direction; // R for Right, L for Left
};

class Turing_Machine
{
private:
    struct Transition_Result
    {
        int destination_state;
        char write_symbol;
        char direction; // R for Right, L for Left
    };

private:
    Tape tape;
    std::map <int, std::map <char, Transition_Result> > transition_function;
    int current_state;
    int initial_state;
    std::set <int> final_states;
    std::set <int> states;
    char blank;
    int run_cycles; // Number of transitions taken from start

private:
    bool add_transition(int source_state, char read_symbol, 
                        int destination_state, char write_symbol, 
                        char direction);

    bool is_state_final(int state);

public:
    Turing_Machine(int number_of_transitions, Transition *transitions,
                   int initial_state, int number_of_final_states,
                   int *final_states, char blank = ' ');

    std::set <int> get_states();
    std::set <int> get_final_states();
    int get_initial_state();
    char get_blank();

    int get_current_state();
    char get_current_symbol();
    bool is_current_state_final();
    bool is_machine_halted();
    int get_run_cycles();

    std::string get_tape_data();

    // Clears tape and resets machine to initial state
    void reset();

    // Sets tape data and resets machine to initial state
    void set_tape(std::string data);

    // Runs machine for one transition
    void run_one_cycle();
    // Runs machine until halted or to maximum of cycle_limit transitions.
    // if (cycle_limit < 0): runs machine until halted (machine might get 
    // stuck in loop).
    void run(int cycle_limit = -1);
};
