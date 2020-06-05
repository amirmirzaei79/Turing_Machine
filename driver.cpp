#include "Turing_Machine.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Transition *transitions;
    int number_of_transitions;
    int *final_states;
    int number_of_final_states;
    int initial_state;
    string input;
    char blank = '#';

    cout << "Enter initial state: " << endl;
    cin >> initial_state;
    
    cout << "Enter number of final states:" << endl;
    cin >> number_of_final_states;
    cout << "Enter final states: " << endl;
    final_states = new int[number_of_final_states];
    for (int i = 0; i < number_of_final_states; ++i)
        cin >> final_states[i];
    
    cout << "Enter Number of transitions: " << endl;
    cin >> number_of_transitions;
    cout << "Enter transitions: " << endl;
    cout << "(source state, read symbol, destination state, write symbol, ";
    cout << "head direction (R or L))" << endl;
    transitions = new Transition[number_of_transitions];
    for (int i = 0; i < number_of_transitions; ++i)
    {
        cin >> transitions[i].source_state >> transitions[i].read_symbol;
        cin >> transitions[i].destination_state >> transitions[i].write_symbol;
        cin >> transitions[i].direction;
    }

    Turing_Machine TM(number_of_transitions, transitions, initial_state,
                      number_of_final_states, final_states, blank);

    cout << "Enter input data: " << endl;
    cin >> input;

    TM.set_tape(input);
    TM.run();

    cout << endl << "Machine is in state: " << TM.get_current_state() << endl;
    cout << "Current state is ";
    cout << ((TM.is_current_state_final()) ? "final." : "not final.") << endl;
    cout << "Machine took " << TM.get_run_cycles() << " transitions to halt.";
    cout << endl;
    cout << "Tape data is: " << endl << TM.get_tape_data() << endl;

    return 0;
}