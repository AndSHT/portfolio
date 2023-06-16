#include "utility.h"



using namespace std;


void show_menu(){
    cout<<"-Menu: "<<endl
    <<" 1  - Set presicion"<<endl
    <<" 2  - Create matrix"<<endl
    <<" 3  - Create array"<<endl
    <<" 4  - Delete matrix"<<endl
    <<" 5  - Delete array"<<endl
    <<" 6  - Random matrix"<<endl
    <<" 7  - Random array"<<endl
    <<" 8  - Show matrix"<<endl
    <<" 9  - Show array"<<endl
    <<" 10 - Exchange array parts by postion"<<endl
    <<" 11 - Find number in array"<<endl
    <<" 12 - Find minimal value in every column in matrix"<<endl
    <<" 13 - Swap matrices diagonals"<<endl
    <<" 14 - Multiply two matricies"<<endl
    <<" 15 - Sort array"<<endl
    <<" 16 - Find number in sorted array"<<endl
    <<" 17 - Sort matrix"<<endl
      <<" 18 - Array processing"<<endl
    <<" 0  - Exit"<<endl
    <<"Please, select an option: ";
}
static void zero_matrix(float** matrix, int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
               matrix[i][j]=0;
        }
    }
}
static void zero_array(int* array, int row){
    for(int i=0;i<row;i++){
        array[i]=0;
    }
}
float** create_matrix(int row, int col){
    float** temp_matrix = NULL;
    temp_matrix = (float**) malloc (row*sizeof( float*));
    for(int i=0;i<row;i++){
        temp_matrix[i] = (float*) malloc (col* sizeof(float)) ;
    }
    zero_matrix(temp_matrix,row,col);
    return temp_matrix;
}

int* create_array(int col){
    int* temp_array = NULL;
    temp_array = new int [col];
    zero_array( temp_array, col);
    return temp_array;
}

void delete_matrix(float*** matrix, int row){
    for(int i=0;i<row;i++){
        free((*matrix)[i]);
        (*matrix)[i]=NULL;
    }
    free(*matrix);
    *matrix=NULL;

}

void delete_array(int** array){
    delete[] (*array);
    (*array) = NULL;
}
static int float_lenght(float min , float max, int precision){
    int lenght=0;
    if(min<0){
        lenght++;
    }
    while (((int)max/10)>1){
        max/=10;
        lenght++;
    }
    return lenght+precision+2;
}

void random_matrix(float** matrix, int row, int col , float min , float max){
    srand(time(NULL));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            matrix[i][j] = (float)rand()/(float) RAND_MAX*(max-min)+min;
        }
    }
}

void random_array(int* array, int row, int min, int max){
    srand(time(NULL));
    for(int i=0;i<row;i++){
        array[i] = min + rand() % (max - min + 1);
    }
}

void show_matrix(float** matrix, int row, int col,float min, float max, int precision){
    cout<<setprecision(precision)<<fixed<<"Matrix is: "<<endl<<setw(float_lenght(min,max,precision));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout.width(float_lenght(min,max,precision));
           cout<< matrix[i][j]<<" " ;
        }
        cout<<endl;
    }
    cout<<endl;
}
void show_array(int* array, int row){
     cout<<"Array is: "<<endl;
    for(int i=0;i<row;i++){
           cout<< array[i]<<" " ;
    }
    cout<<endl<<endl;
}
int* array_swap(int* array, int row, int pos){
    int* temp_arr=NULL;
    int j=0,i=0;
    temp_arr = create_array(row);
    for(i=pos;i<row;i++){
        temp_arr[j] = array[i];
        j++;
    }
    j= row - pos;
    for(i=0;i<pos;i++){
        temp_arr[j]=array[i];
        j++;
    }
    delete_array(&array);

    return temp_arr;
}

//WARNING!
//This function allocates dynamic memory, free it after use
int* array_find(int* array, int row, int tol, int x){
    int k=0;
    for(int i=0;i<row;i++){
        if((abs(array[i]-x))<=tol){
            k++;
        }
    }
    int* id = create_array(k+1);
    id[0] = k;
    k = 1;
    for(int i=0;i<row;i++){
        if((abs(array[i]-x))<=tol){
            id[k] = i;
            k++;
        }
    }
    return id;
}
//WARNING!!! This function allocates dynamic memory, free it after use
float* minimal_array_from_matrix(float** matrix, int col, int row){
    float* temp_array = NULL;
    temp_array = new float [col];
    float min=0;
    for(int i=0;i<row;i++){
        min = matrix[0][i];
        for(int j=0;j<col;j++){
            if(min>matrix[j][i]){
                min=matrix[j][i];
            }
        }
        temp_array[i]=min;
    }
    return temp_array;
}

float** swap_matrix_diagonals(float*** matrix, int rows, int cols){
    float** temp_matrix = NULL;
    temp_matrix = create_matrix(rows,cols);
   for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            temp_matrix[i][j] = (*matrix)[i][j];
        }
    }
    int init=rows;
    if(cols<rows){
        init = cols;
    }
    for(int i=0;i<init;i++){
        temp_matrix[i][i] = (*matrix)[(rows-i-1)][i]; // debuger warn thath cols can outrange rows, but it defind in previous 'if'
        temp_matrix[(rows-i-1)][i] = (*matrix)[i][i];
    }
    delete_matrix(matrix,rows);
    return temp_matrix;
}

//WARNING!!! function allocated dynamic memory release it after use
float** multiply_matrcies(float** mat1,int row, int col,int min ,int max, int prec){
    float** mat2 = NULL;
    mat2 = create_matrix(row,col);
    random_matrix(mat2, row, col, min, max);
    cout<<"Created second ";
     show_matrix(mat2,row , col,min, max, prec);
    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++){
            mat2[i][j]=mat1[i][j]*mat2[i][j];
        }
    }
    return mat2;
}


bool ascending(int a,int b){
    return a>b;
}
bool decending(int a,int b){

    return a<b;
}

void show_sort_methods(){
    cout<<"-Sorting methods: "<<endl
    <<" 1  - Simple sort"<<endl
    <<" 2  - Simple insert sort"<<endl
    <<" 3  - Simple choice sort"<<endl
    <<" 4  - Heap Sort"<<endl
    <<" 5  - Shell sort"<<endl
    <<" 6  - Quick sort"<<endl
    <<" 0  - Back to menu"<<endl
    <<"Please, choose sorting method: ";
}
void show_sort_directions(){
cout<<"-Sorting directions:"<<endl
    <<" 1 - Ascending"<<endl
    <<" 2 - Decending"<<endl
    <<"Please, choose diretction: ";
}
void simple_sort(int* array, int row, bool (*comp_func)(int,int)) {
    cout<<"Simple sort"<<endl<<endl;
    for (int i = 0; i < row; i++) {
        for (int j = i + 1; j < row; j++) {
            if (comp_func(array[i],array[j])) {
               swap(array[i],array[j]);
            }
        }
    }
}
void simple_insert_sort(int* array, int row, bool (*comp_func)(int,int) ) {
    cout<<"Simple insert sort"<<endl<<endl;
    int key, i;
    for (int k = 1; k < row; k++) {
        key = array[k];
        i = k - 1;
        while ((i >= 0)&&((*comp_func)(array[i], key ))) {
            array[i + 1] = array[i];
            i = i - 1;
        }
        array[i + 1] = key;
        }
}
void simple_choice_sort(int* array, int row,bool (*comp_func)(int,int)) {
    cout<<"Simple choice sort"<<endl<<endl;
    int  min_index;
    for (int i = 0; i < row - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < row; j++) {
            if ((*comp_func)(array[j],array[min_index])) {
                min_index = j;
            }
        }
        if (min_index != i) {
           swap( array[i] , array[min_index]);
        }
    }
}

static void heapify(int* array, int row, int i,bool (*comp_func)(int,int)) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ((left < row ) && (*comp_func)(array[left],array[largest])){
        largest = left;
    }
    if ((right < row) && (*comp_func)(array[right],array[largest])){
        largest = right;
    }
    if (largest != i) {
      swap(array[i], array[largest]);
      heapify(array, row, largest,comp_func);
    }
}
void heapSort(int* array, int row ,bool (*comp_func)(int,int) ) {
    cout<<"Heap sort"<<endl<<endl;
    for (int i = row / 2 - 1; i >= 0; i--)
    { heapify(array, row, i,comp_func);}
    for (int i = row - 1; i >= 0; i--) {
      swap(array[0], array[i]);
      heapify(array, i, 0,comp_func);
    }
}

void shell_sort(int* array, int row, bool (*comp_func)(int,int)) {
     cout<<"Shell sort"<<endl<<endl;
    int j,temp, gap = row / 2;
    while (gap > 0) {
        for (int i = gap; i < row; i++) {
            temp = array[i];
            for (j = i; j >= gap && (*comp_func)( array[j - gap],temp ); j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
        gap /= 2;
    }
}
void quick_sort(int* array, int left, int right , bool (*comp_func)(int,int)){
        int i = left, j = right;
        int pivot = array[(left + right) / 2];

        while (i <= j) {
            while ((*comp_func)(array[i],pivot  ))
                i++;
            while ((*comp_func)(pivot,array[j]  ))
                j--;
            if (i<=j) {
               swap (array[i] , array[j]);
                i++;
                j--;
            }
        }
        if ((*comp_func)(left , j))
            quick_sort(array, left, j, comp_func);
        if ((*comp_func)(i , right))
            quick_sort(array, i, right, comp_func);
    }



int find_pos(int x, int* array, int row){
    int left=0, right=row-1,pos=0;
    while(left<=right){
        pos = (left+right)/2;
        if(array[pos]==x){
            return pos;
        }
        if(x<array[pos]){
            right=pos-1;
        }
        else {
            left = pos+1;
        }
    }

    return -1;

}

float** sort_matrix(float** matrix,int col, int row, float* (*routing_matrix_in)(float**,int,int), bool (*comp_func)(int,int) , float** (*routing_matrix_out)(float* array,int col,int row)){

      float* temp_arr;
      temp_arr = (*routing_matrix_in)(matrix, col, row);
      int j, gap = (row*col) / 2;
      float temp;
      while (gap > 0) {
          for (int i = gap; i < (row*col) ; i++) {
              temp = temp_arr[i];
              for (j = i; j >= gap && (*comp_func)( temp_arr[j - gap], temp ); j -= gap) {
                  temp_arr[j] = temp_arr[j - gap];
              }
              temp_arr[j] = temp;
          }
          gap /= 2;
      }
    matrix = routing_matrix_out(temp_arr, col, row);
    delete[] temp_arr;
    temp_arr = NULL;
    return matrix;

}
float* routing_matrix(float** mat,int col,int row){
    float* arr;
    arr = new float [((col)*(row))];
    int y=0,x=col-1,k=0;
    int cx,cy;
    arr[k]=mat[y][x];
    cx=col-1;
    cy=0;
    k++;
    while(k < (row*col)-1 ){
        if(x==(col-1)){
            cx--;
            x=cx;
            y=0;
            arr[k] = mat[y][x];
            k++;
        }
        cy++;
        while(((y<(cy)))&&(y<row)){
            y++;
            arr[k] = mat[y][x];
            k++;
        }
        if((col-x)==y){
            y=cy;
            arr[k]=mat[y][x];
            k++;
        }
        while((x!=(col-1))&&(x<col)){
            x++;
            arr[k]=mat[y][x];
            k++;
        }
    }
   return arr;
}

float** routing_matrix_out(float* array,int col,int row){
    float** matrix;
    matrix = create_matrix(row,col);
    int y=0,x=col-1,k=0;
    int cx,cy;
    matrix[y][x] = array [k];
    cx=col-1;
    cy=0;
    k++;
    while(k<(row*col)-1){
        if(x==(col-1)){
            cx--;
            x=cx;
            y=0;
            matrix[y][x] = array [k];
            k++;
        }
        cy++;
        while(((y<(cy)))&&(y<row)){
            y++;

            matrix[y][x] = array [k];
            k++;
        }
        if((col-x)==y){
            y=cy;
            matrix[y][x] = array [k];
            k++;
        }
        while((x!=(col-1))&&(x<col)){
            x++;
            matrix[y][x] = array [k];
            k++;
        }
    }
    return matrix;
}



int* array_processing (int** array,int size, int indicator){

        int temp_size=2;
        for(int i=0;i<size;i++){

            if((*array)[i]==0){

            }
            else if((((*array)[i])%5==0)&&((*array)[i]%3!=0)){
                temp_size++;
                temp_size++;
            }
            else if(((*array)[i]%5!=0)&&((*array)[i]%3!=0)){
                temp_size++;
            }

            //if(((*array)[i]%2==0)&&((*array)[i]%5==0)){}


        }

        if(temp_size <=0){
            cout<<"Nothing was found"<<endl;
            return *array;
        }

        int* temp_array = NULL;
        temp_array = (int*) malloc (temp_size * sizeof( int));
        temp_array[0] = temp_size;

        for(int i=1;i<temp_size;i++)
        { temp_array[i]=0; }
        int j=0;
        int l=0;
        for(int i=1;i<temp_size-1;i++)
        {

            for(int k=j;k<size;k++){

                 if((*array)[k]==0){
                    break;

                }
                else if(((*array)[k]%3!=0)&&(((*array)[k]%5==0))){
                     temp_array[i]= (*array)[k];
                     i++;
                    temp_array[i] = indicator;
                    break;

                }
                else if(((*array)[k]%3!=0)&&(((*array)[k]%5!=0))){
                    temp_array[i] = (*array)[k];
                    break;
                }
                 else {
                     l++;
                 }
           }
           j=j+l+1;
           l=0;
        }

   return temp_array;
}
