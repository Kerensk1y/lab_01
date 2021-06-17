#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const size_t SCREEN_WIDTH = 80;
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;
    vector<double> numbers(number_count);
    cerr << "Enter numbers: ";
    for (int i = 0; i < number_count; i++)
    {
        cin >> numbers[i];
    }

    size_t bin_count;
    cerr << "Enter bins count: ";
    cin >> bin_count;
    cerr << "+------------------+" << endl;

    double min = numbers[0];
    double max = numbers[0];
    for (double x : numbers)
    {
        if (x < min)
        {
            min = x;
        }
        else if (x > max)
        {
            max = x;
        }
    }
    vector<size_t> bins(bin_count);
    double bin_size = (max - min) / bin_count;

    for (size_t i = 0; i < number_count; i++)
    {
        bool found = false;
        for (int j = 0; (j < bin_count - 1) && !found; j++)
        {
            auto lo = min + j * bin_size;
            auto hi = min + (j + 1) * bin_size;
            if ((lo <= numbers[i]) && (numbers[i] < hi))
            {
                bins[j]++;
                found = true;
            }
        }
        if (!found)
        {
            bins[bin_count - 1]++;
        }
    }

    size_t count;
    size_t max_count = bins[0];
    for (int i = 1; i < bin_count; i++)
    {
        if (bins[i] > max_count)
        {
            max_count = bins[i];
        }
    }

    bool flag = false;
    int n = 1;
    while (!flag)
    {
        if (max_count / 10 >= 1)
        {
            n++;
            max_count = max_count / 10;
        }
        else
            flag = true;
    }

    const size_t MAX_ASTERISK = SCREEN_WIDTH - n - 1;

    if (max_count > MAX_ASTERISK)
    {
        for (int i = 0; i < bin_count; i++)
        {
            count = bins[i];
            size_t height = MAX_ASTERISK * (static_cast<double>(count) / max_count);
            size_t r = max_count;
            for (size_t i = 0; i < n; i++)
            {

                if (bins[i] / r == 0)
                {
                    cout << " ";
                }
                else
                {
                    cout << bins[i];
                    break;
                }
                r = r / 10;

            }
            for (int j = 0; j < height; j++)
            {
                cout << '*';
            }
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i < bin_count; i++)
        {
            if (bins[i] < 100) cout << ' ';
            if (bins[i] < 10) cout << ' ';
            cout << bins[i] << '|';
            for (int j = 0; j < bins[i]; j++)
            {
                cout << '*';
            }
            cout << endl;
        }
    }


    return 0;
}
