#include "Turing_Machine.h"

using namespace std;

bool Turing_Machine::add_transition(int source_state, char read_symbol, 
                                    int destination_state, char write_symbol, 
                                    char direction)
{
    if (transition_function.count(source_state) > 0 
        && transition_function[source_state].count(read_symbol) > 0
        || (direction != 'R' && direction != 'L'))
    {
        return false;
    }
    else
    {
        Transition_Result t;
        t.direction = direction;
        t.write_symbol = write_symbol;
        t.destination_state = destination_state;
        transition_function[source_state][read_symbol] = t;

        states.insert(source_state);
        states.insert(destination_state);

        return true;
    }
}

bool Turing_Machine::is_state_final(int state)
{
    return (final_states.count(state) > 0);
}

Turing_Machine::Turing_Machine(int number_of_transitions, 
                               Transition *transitions,
                               int initial_state, int number_of_final_states,
                               int *final_states, char blank)
{
    for (int i = 0; i < number_of_transitions; ++i)
    {
        add_transition(transitions[i].source_state, transitions[i].read_symbol,
                        transitions[i].destination_state, 
                        transitions[i].write_symbol,
                        transitions[i].direction);
    }

    this->initial_state = initial_state;
    states.insert(initial_state);
    
    for (int i = 0; i < number_of_final_states; ++i)
    {
        this->final_states.insert(final_states[i]);
        states.insert(final_states[i]);
    }

    this->blank = blank;
    tape.clear(blank);
}

set <int> Turing_Machine::get_states()
{
    return states;
}

set <int> Turing_Machine::get_final_states()
{
    return final_states;
}

int Turing_Machine::get_initial_state()
{
    return initial_state;
}

char Turing_Machine::get_blank()
{
    return blank;
}

int Turing_Machine::get_current_state()
{
    return current_state;
}

char Turing_Machine::get_current_symbol()
{
    return tape.read();
}

bool Turing_Machine::is_current_state_final()
{
    return is_state_final(current_state);
}

bool Turing_Machine::is_machine_halted()
{
    return (transition_function.count(current_state) == 0 ||
            transition_function[current_state].count(tape.read()) == 0);
}

int Turing_Machine::get_run_cycles()
{
    return run_cycles;
}

string Turing_Machine::get_tape_data()
{
    return tape.get_data();
}

void Turing_Machine::reset()
{
    tape.clear(blank);
    current_state = initial_state;
    run_cycles = 0;
}

void Turing_Machine::set_tape(string data)
{
    reset();
    tape.set_data(data);
}

void Turing_Machine::run_one_cycle()
{
    if (!is_machine_halted())
    {
        Transition_Result t = transition_function[current_state][tape.read()];
        current_state = t.destination_state;
        tape.write(t.write_symbol);
        if (t.direction == 'R')
            tape.move_right();
        else if (t.direction == 'L')
            tape.move_left();

        ++run_cycles;
    }
}

void Turing_Machine::run(int cycle_limit)
{
    if (cycle_limit < 0)
    {
        while (!is_machine_halted())
        {
            run_one_cycle();
        }
    }
    else
    {
        int cycle = 0;

        while (!is_machine_halted() && cycle < cycle_limit)
        {
            run_one_cycle();
            ++cycle;
        }
    }
    
}
