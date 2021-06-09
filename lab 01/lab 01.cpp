#include <iostream>
#include <vector>
using namespace std;


int main()
{
	const size_t SCREEN_WIDTH = 80;
	const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;
	setlocale(LC_ALL, "RUS");

	size_t number_count;
	cerr << "Введите количество чилел:\t"; cin >> number_count;

	vector<double> numbers(number_count);
	for (size_t i = 0; i < number_count; i++)
	{
		cerr << "Введите " << i + 1 << " число:\t"; cin >> numbers[i];
	}

	size_t bin_count;
	cerr << "Введите количество групп:\t"; cin >> bin_count;

	double min = numbers[0];
	double max = numbers[0];
	for (size_t i = 0; i < number_count; i++)
	{
		if (numbers[i] < min)
		{
			min = numbers[i];
		}
		if (numbers[i] > max)
		{
			max = numbers[i];
		}
	}

	double bin_size = (max - min) / bin_count;

	vector<size_t> bins(bin_count);


	for (size_t i = 0; i < number_count; i++)
	{
		bool found = false;
		for (size_t j = 0; (j < bin_count - 1) && !found; j++)
		{
			auto low = min + j * bin_size;
			auto high = min + (j + 1) * bin_size;
			if ((numbers[i] >= low) && (numbers[i] < high))
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

	size_t max_count = bins[0];

	for (size_t i = 0; i < bin_count; i++)
	{
		if (bins[i] > max_count)
		{
			max_count = bins[i];
		}
	}
	if (max_count > MAX_ASTERISK)
	{

		size_t height;
		for (size_t i = 0; i < bin_count; i++)
		{
			height = MAX_ASTERISK * (static_cast<double>(bins[i]) / max_count);
			if (bins[i] < 100)
				cout << " ";
			if (bins[i] < 10)
				cout << " ";
			cout << bins[i] << "|";
			for (size_t j = 0; j < height; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
	else
	{
		for (size_t i = 0; i < bin_count; i++)
		{
			if (bins[i] < 100)
				cout << " ";
			if (bins[i] < 10)
				cout << " ";
			cout << bins[i] << "|";
			for (size_t j = 0; j < bins[i]; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
}
