#include <iostream>
/*
multidimensional 2d 3d arrays

how do they function, why do we use them, etc

2D arrays are arrays of arrays

pointer to the begining of an array is like the array itself //only difference is in the behavior of sizeof

a collection of pointers that point to the start of 1D arrays is a 2D array

*/

int main()
{
    int* array = new int[50]; //heap allocation
    int** a2d =new int*[50]; //storing a buffer of pointer objects, collection of pointer of pointers
          // pointer to an integer pointer
          // complicated allocation of memory because pointers and integers are the same size
          // say I allocate a 2d array of a class that is 20 bytes large 
          // Memory needed 50 20 byte chunks : 1000 bytes total 
          // Here instead 50 4 byte pointers : 200 bytes total

    //arrays have not really been allocated, also allocation is not type-bound 
    //I use the size of int to reserve a piece of memory that I could then use
    //to store floats or objects whatsoever


    // also the two allocations above are identical in terms of the memory
    // since pointers are all integers and I'm reserving space for 50 int pointers

    // now we use the 200 bytes of memory to save the pointers to 50 arrays
    // then, morally we have an array of arrays

    for (int i=0; i<50; i++)
        a2d[i] = new int[50];

    // for higher dimensional arrays we would have a nested for loop
    int*** a3d =new int**[50];

    for (int i=0; i<50; i++){
        a3d[i] = new int*[50];
        for (int j=0; j<50; j++)
            a3d[i][j] = new int[50];
            // int ** ptr =a3d[i]; same code
            // ptr[j]= new int[50]
        }

    a3d[0][0][0]=0;

    //for the 2d one
    a2d[0][0]=0;
    a2d[0][1]=0;
    a2d[0][2]=0;

    // first column [0]'s , is the index of the array that I'm modifying
    // second column [0], [1],  [2] , is the index of the integer within that array


    // deleting is tricky cant just delete the list of pointers to pointers
    // because I haven't deleted the pointers themselves (only the list that held them)
    // that would be a memory leak (memory that can't be accessed)
    // I have to go through each pointer (array) and delete individually 
    // DELETE each array in the array of arrays

    //delete[] a2d; would delete 200 bytes of memory (but total memory held is 50x50x4 bytes)

    //correct way to delete is 
    for (int i=0; i<50; i++)
        delete[] a2d[i]; //deleting each array on the list of arrays
    delete[] a2d; // then deleting the list of arrays


    //issue with this is that it results in memory fragmentation
    // each allocation in the inner loop in line 36 happens in random locations in memory
    // (unless we have a custo allocator or something fancy)
    // it is very slow to jump all over memory each time we traverse a 2d array

    // instead we should store the array contiguously -- optimizing memory access
    // the way to deal with this
    int * array2d = new int[5*5];

    //setting the 2d array a2d
    for (int i=0; i<50; i++){
        for (int j=0; j<50; j++)
            a2d[i][j] =2;
        }
    //setting the wrapped 2d array
    for (int i=0; i<25; i++){
        array2d[i]=2;
    }

    //but can also write
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++)
            array2d[i+j*5] =2; // each time I increase one j I want to increase 5 positions
        }
    
    //row major -c order (lexicographical, going first through row traversing columns and then jump to next row)
    int nrow=2;
    int ncol=3;
    
    int * array2d_c = new int[nrow*ncol];
    
    for (int i=0; i<nrow; i++){
        for (int j=0; j<ncol; j++)
            array2d_c[i*ncol+j] =2; // each time I increase one j I want to increase 5 positions
        }

    //column major -f order (colexicographical, going first through column traversing rows and then jump to next column)
    
    
    int * array2d_f = new int[nrow*ncol];
    
    for (int j=0; j<ncol; j++){
        for (int i=0; i<nrow; i++)
            array2d_f[i+j*nrow] =2; // each time I increase one j I want to increase 5 positions
        }
    //column major is used in armadillo and Eigen for C++

    //easiest way to transpose is to keep track of how should the array be read, row major read as column major will appear transposed and vice vers
    // transposing is memory is much more expensive
}