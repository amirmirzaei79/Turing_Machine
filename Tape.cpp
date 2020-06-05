#include "Tape.h"

using namespace std;

Tape::Tape(char blank, string data)
{
    this->blank = blank;
    
    if (data.size() > 0)
    {
        positive_index_tape.assign(data.begin(), data.end());
    }
    else
    {
        positive_index_tape.push_back(blank);
    }
    
    position = 0;
}

Tape::Tape(char blank)
{
    this->blank = blank;
    
    positive_index_tape.push_back(blank);
    
    position = 0;
}

Tape::Tape()
{
    blank = ' ';
    
    positive_index_tape.push_back(blank);
    
    position = 0;
}

void Tape::set_data(string data)
{
    if (data.size() > 0)
    {
        positive_index_tape.assign(data.begin(), data.end());
    }
    else
    {
        positive_index_tape.push_back(blank);
    }

    position = 0;
}

void Tape::clear()
{
    positive_index_tape.clear();
    positive_index_tape.push_back(blank);
    negative_index_tape.clear();

    position = 0;
}

void Tape::clear(char blank)
{
    positive_index_tape.clear();
    positive_index_tape.push_back(blank);
    negative_index_tape.clear();

    this->blank = blank;

    position = 0;
}

bool Tape::empty()
{
    for (int i = 0; i < positive_index_tape.size(); ++i)
        if (positive_index_tape[i] != blank)
            return false;
    
    for (int i = 0; i < negative_index_tape.size(); ++i)
        if (negative_index_tape[i] != blank)
            return false;
    
    return true;
}

char Tape::read()
{
    if (position >= 0)
        return positive_index_tape[position];
    else
        return negative_index_tape[-position - 1];
}

void Tape::write(char s)
{
    if (position >= 0)
        positive_index_tape[position] = s;
    else
        negative_index_tape[-position - 1] = s;
}

void Tape::move_left()
{
    --position;
    
    if (position < 0 && -position > negative_index_tape.size())
        negative_index_tape.push_back(blank);
}

void Tape::move_right()
{
    ++position;

    if (position > 0 && position >= positive_index_tape.size())
        positive_index_tape.push_back(blank);
}

string Tape::get_data()
{
    string data = "";
    
    int last_data_index = -1;
    for (int i = negative_index_tape.size() - 1; i >= 0 && last_data_index < 0; --i)
        if (negative_index_tape[i] != blank)
            last_data_index = i;
    for (int i = last_data_index; i >= 0; --i)
        data += negative_index_tape[i];
    
    last_data_index = -1;
    for (int i = 0; i < positive_index_tape.size(); ++i)
        if (positive_index_tape[i] != blank)
            last_data_index = i;
    for (int i = 0; i <= last_data_index; ++i)
        data += positive_index_tape[i];

    return data;
}