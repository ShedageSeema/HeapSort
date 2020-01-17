#include <iostream>
#include <fstream>//Input/output stream class to operate on files.
#include <cstdlib>//sorting
#include <ctime>//Convert time_t value to string
#include <string>
using namespace std;

//build heap in top down manner
void build_heapify(int list[], int count, int i)
{
	int largest_index = i;//Initialize largest as root
	int left = 2 * i; //left = 2 * i
	int right = 2 * i + 1;//// right = 2*i + 1
	
 // If left child is larger than root
	if ( list[left]!=-1 && list[left] > list[largest_index])
	{ 
		
		largest_index = left;
		
	}
	// If right child is larger than largest so far
		if (list[right]!=-1 && list[right] > list[largest_index])
		{
			
			largest_index = right;
			
		}
		// If largest is not root
	if (largest_index != i) {
		swap(list[i], list[largest_index]);
		
	}
	if(i/2!=0)//go to the parents 
	{ 
	build_heapify(list, count, i/2);
	}
}



void heap_sort(int list[], int count)//list is an array and count total size of array
{
	int largest_index = count; 
	// Build heap (rearrange array)
	for (int i = count / 2; i >= 0; i--)
		build_heapify(list, count, i);
	
	//swap the maximum number with the last element and remove that element.
	for (int i = count; i >= 1; i--) {
		
		swap(list[largest_index], list[1]);
		largest_index--;
		build_heapify(list, largest_index,1);

	}
}


int main()
{
	int count = 0;
	fstream infile("one.txt", ios::in);
	/*int a;
	while (infile >> a) {
		count++;
	}*/
	int *list = new int[count+1];//store data into an array initialize in index 1. 

	//fstream infile("one.txt");
	int i = 1;
	int value = 0;
	for (i = 1; i <= 7; i++) {
		infile >> value;
		list[i] = value;

	}
	count = i+1;
	
	

	clock_t start = clock();

	heap_sort(list, count);

bool check = true;
	for (int i = 1; i < count - 2; i++)
	{
		if(list[i+1]<list[i])
		{
			cout << "Number at index" << i + 1 << "is not sorted!" << endl;
			check = false;
			break;
		}
	}
	if( check ==true)
	cout << "sorted";
	for (int i = 1; i <= count - 1; i++)
		cout << list[i];

	clock_t stop = clock();
	double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
	cout << "Time elapsed in ms:" << elapsed;

	delete[] list;

	return 0;
}