#include "utility.h"

using namespace std;

int main()
{
bool exit_key=false,arr_sorted=false;
int menu_key, precision=1;
float** mat = NULL; int mat_row=2, mat_col=2; float mat_min=0, mat_max=1;
int* arr = NULL; int arr_row=2, arr_min=0, arr_max=1;

bool (*asc_func)(int,int ) = NULL;
bool (*dec_func)(int,int ) = NULL;
float* (*routing_in)(float** mat,int col,int row);
float** (*routing_out)(float* array,int col,int row);
asc_func = &ascending;
dec_func = &decending;
routing_in = routing_matrix;
routing_out = routing_matrix_out;

cout<<"Default precison for value output is "<<precision<<" numbers after decimal point"<<endl
   <<"You change that with 'Set precision' option in menu "<<endl<<endl
   <<"The values without using the assignment function will be zero !"<<endl<<endl;

while(!exit_key) {
    show_menu();
    cin>>menu_key;
    cout<<endl;
    switch(menu_key){
        default :
                cout<<"Error! Wrong input"<<endl
                    <<"Please, select one from the menu."<<endl<<endl;
        break;
        case 0:
            exit_key = true;
        break;
        case 1:
        cout<<"Please, enter precision : ";
        cin>>precision;
        if(precision<0){
            cout<<"Wrong input! Please enter a positive integer greater than 1"<<endl<<endl;
            precision = 1;
        }
        cout<<endl;
        break;
        case 2:
        if(mat==NULL){
            cout<<"Please, enter quantity of columns: ";
            cin>>mat_col;
            cout<<"Please, enter quantity of rows: ";
            cin>>mat_row;
            cout<<endl;
            if((mat_col>1)&&(mat_row>1)){
                mat = create_matrix(mat_row,mat_col);
                cout<<"Matrix created succeessful!"<<endl<<endl;
            }
            else{
                cout<<"Wrong input!"<<endl
                <<"Please, enter a positive integer greater than 1"<<endl<<endl;
            }
        }
        else{
            cout<<"Error! Matrix is already exist."<<endl
               <<"Delete it first."<<endl<<endl;
        }
        break;
        case 3:
        if(arr==NULL){
            cout<<"Please, enter quantity of columns: ";
            cin>>arr_row;
            cout<<endl;
            if(arr_row>1){
               arr = create_array(arr_row);
               arr_sorted=true;
                cout<<"Array created succeessful!"<<endl<<endl;
            }
            else{
                cout<<"Wrong input!"<<endl
                <<"Please enter a positive integer greater than 1"<<endl<<endl;
            }
        }
        else {
            cout<<"Error! Array is already exist."<<endl
               <<"Delete it first."<<endl<<endl;
        }
        break;
        case 4:
        if(mat!=NULL){
            delete_matrix(&mat,mat_row);

            cout<<"Matrix deleted succeessful!"<<endl<<endl;
        }
        else{
            cout<<"Error! Matrix does not exist."<<endl
               <<"Create it first."<<endl<<endl;
        }
        break;
        case 5:
        if(arr!=NULL){
            delete_array(&arr);
            arr_sorted=false;
            cout<<"Array deleted succeessful!"<<endl<<endl;
        }
        else{
            cout<<"Error! Array does not exist."<<endl
               <<"Create it first."<<endl<<endl;
        }
        break;
        case 6:
        if(mat!=NULL){
            cout<<"Please, enter minimum value: ";
            cin>>mat_min;
            cout<<"Please, enter maximum value: ";
            cin>>mat_max;
            cout<<endl;
            random_matrix(mat,mat_row,mat_col,mat_min,mat_max);
            cout<<"Matrix randomized succeessful!"<<endl<<endl;
            show_matrix(mat,mat_row,mat_col, mat_min, mat_max,precision);
        }
        else{
            cout<<"Error! Matrix does not exist."<<endl
               <<"Create it first."<<endl<<endl;
        }
        break;
        case 7:
        if(arr!=NULL){
            cout<<"Please, enter minimum value: ";
            cin>>arr_min;
            cout<<"Please, enter maximum value: ";
            cin>>arr_max;
            cout<<endl;
            if((arr_min%1==0)&&(arr_max%1==0)){
                random_array(arr,arr_row,arr_min,arr_max);
                arr_sorted=false;
                cout<<"Array randomized succeessful!"<<endl<<endl;
                show_array(arr,arr_row);
            }
            else{
                cout<<"Number is not integer."<<endl
                    <<"Please, enter an integer."<<endl<<endl;
            }
        }
        else{
            cout<<"Error! Array does not exist."<<endl
               <<"Create it first."<<endl<<endl;
        }
        break;

        break;
        case 8:
            if(mat!=NULL){
                show_matrix(mat, mat_row, mat_col, mat_min, mat_max,precision);
            }
            else{
                cout<<"Error! Matrix does not exist."<<endl
                    <<"Create it first."<<endl<<endl;
            }
        break;
        case 9:
            if(arr!=NULL){
                show_array(arr, arr_row);
            }
            else{
                cout<<"Error! Array does not exist."<<endl
                    <<"Create it first."<<endl<<endl;
            }
        break;
        case 10:
            if(arr!=NULL){
                int position=0;
                cout<<"Please, enter position for exchange: ";
                cin>>position;
                cout<<endl;
                if((position>=1)&&(position<arr_row)){
                    cout<<"Before exchange: ";
                    show_array(arr, arr_row);
                    arr = array_swap(arr, arr_row, position);
                    arr_sorted=false;
                    show_array(arr, arr_row);
                }
                else{
                    cout<<"Error! Wrong input"<<endl
                        <<"Please enter a positive integer greater than 1 and less than "<<arr_row<<endl<<endl;
                }
        }
        else{
            cout<<"Error! Array does not exist."<<endl
                <<"Create it first."<<endl<<endl;
        }
        break;
        case 11:
        if(arr!=NULL){
            int wanted=0,tolerance=0;
            cout<<"Please, enter number which is looking for: ";
            cin>>wanted;
            cout<<"Please, enter tolerance for search (0 - if you need exact same number): ";
            cin>>tolerance;
            int* id_arr = array_find(arr, arr_row, tolerance, wanted);
            if(id_arr[0]!=0){
                cout<<"Indices of found variables: ";
                for(int i=0;i<id_arr[0];i++){
                    cout<< id_arr[i+1]<<" ";
                }
                cout<<endl<<endl;
             }
            else {
                cout<<"Nothing was found in the search result"<<endl<<endl;
            }
            delete_array(&id_arr);
        }
        else{
            cout<<"Error! Array does not exist."<<endl
                <<"Create it first."<<endl<<endl;
        }
        break;
        case 12:
            if(mat!=NULL){
                 show_matrix(mat, mat_row, mat_col, mat_min, mat_max, precision);
                float* minimum = NULL;
                minimum = minimal_array_from_matrix(mat, mat_col, mat_row);
                cout<<"Minimal values in every column in matrix are: ";
                for(int i=0;i<mat_col;i++){
                    cout<<minimum[i]<<" ";
                }
                cout<<endl;
                delete[] minimum;
                minimum = NULL;
            }
            else{
                cout<<"Error! Array does not exist."<<endl
                    <<"Create it first."<<endl<<endl;
            }
        break;
        case 13:
            if(mat!=NULL){
                cout<<"Before swaping diagonals. ";
                show_matrix(mat,mat_row,mat_col,mat_min, mat_max,precision);
                mat = swap_matrix_diagonals(&mat, mat_row, mat_col);
                cout<<"After swaping diagonals. ";
                show_matrix(mat,mat_row,mat_col, mat_min, mat_max,precision);
            }
            else{
                cout<<"Error! Array does not exist."<<endl
                    <<"Create it first."<<endl<<endl;
            }
        break;
        case 14:{
            if(mat!=NULL){
                float** result = NULL;
                int mat2_min,mat2_max;
                cout<<"Please, enter minimum value for second matrix: ";
                cin>>mat2_min;
                cout<<"Please, enter maximum value for second matrix: ";
                cin>>mat2_max;
                result = multiply_matrcies(mat, mat_row, mat_col,mat2_min, mat2_max,precision);
                cout<<"Result of multiplication ";
                show_matrix(result, mat_row, mat_col, mat2_min, mat2_max, precision);
                delete_matrix(&result,mat_row);

            }
            else{
                cout<<"Error! Matrix does not exist."<<endl
                    <<"Create it first."<<endl<<endl;
            }
        }
        break;
        case 15:
            if(arr!=NULL){
            show_sort_methods();

            int sorting_key=0;
            int direction_key=0;
            cin>>sorting_key;
            cout<<endl;
            cout<<"Unsorted ";
            show_array(arr, arr_row);
            switch (sorting_key){
            case 0:
                cout<<"Back to menu..."<<endl<<endl;
            break;
            case 1:{

                show_sort_directions();
                cin>>direction_key;cout<<endl;
                switch (direction_key){
                case 1:
                    simple_sort(arr, arr_row, asc_func);
                break;
                case 2:
                    simple_sort(arr, arr_row, dec_func);
                break;
                default:
                        cout<<"Error! Wrong input"<<endl
                            <<"Please, select one from the menu."<<endl<<endl;
                break;
                }
                arr_sorted=true;
            }
           break;

           case 2:
               show_sort_directions();
               cin>>direction_key;cout<<endl;
               switch (direction_key){
               case 1:
                    simple_insert_sort(arr, arr_row, asc_func);
               break;
               case 2:
                    simple_insert_sort(arr, arr_row, dec_func);
               break;
               default:
                       cout<<"Error! Wrong input"<<endl
                           <<"Please, select one from the menu."<<endl<<endl;
               break;
               }
               arr_sorted=true;
           break;
           case 3:
                show_sort_directions();
                cin>>direction_key;cout<<endl;
                switch (direction_key){
                case 1:
                     simple_choice_sort(arr, arr_row,dec_func);
                break;
                case 2:
                     simple_choice_sort(arr, arr_row,asc_func);
                break;
                default:
                        cout<<"Error! Wrong input"<<endl
                            <<"Please, select one from the menu."<<endl<<endl;
                break;
                }
                arr_sorted=true;
           break;
           case 4:
                show_sort_directions();
                cin>>direction_key;cout<<endl;
                switch (direction_key){
                case 1:
                     heapSort(arr, arr_row, asc_func);
                break;
                case 2:

                     heapSort(arr, arr_row, dec_func);
                break;
                default:
                        cout<<"Error! Wrong input"<<endl
                            <<"Please, select one from the menu."<<endl<<endl;
                break;
                }
                arr_sorted=true;
           break;
           case 5:
                show_sort_directions();
                cin>>direction_key;cout<<endl;
                switch (direction_key){
                case 1:
                     shell_sort(arr, arr_row,asc_func);
                break;
                case 2:
                     shell_sort(arr, arr_row,dec_func);
                break;
                default:
                        cout<<"Error! Wrong input"<<endl
                            <<"Please, select one from the menu."<<endl<<endl;
                break;
                }
                arr_sorted=true;

           break;
           case 6:
                   show_sort_directions();
                   cin>>direction_key;cout<<endl;
                   switch (direction_key){
                   case 1:
                        cout<<"Quick sort"<<endl<<endl;
                        quick_sort(arr, 0, arr_row - 1, asc_func);
                   break;
                   case 2:
                        cout<<"Quick sort"<<endl<<endl;
                        quick_sort(arr, 0, arr_row - 1 , dec_func);
                   break;
                   default:
                           cout<<"Error! Wrong input"<<endl
                               <<"Please, select one from the menu."<<endl<<endl;
                   break;
                   }
                   arr_sorted=true;
           break;
           default :
                cout<<"Error! Wrong input"<<endl
                    <<"Please, select one from the menu."<<endl<<endl;
           break;
        }
            if(sorting_key!=0){
                cout<<"Sorted ";
                show_array(arr, arr_row);
            }
        }
        else{
            cout<<"Error! Array does not exist."<<endl
                <<"Create it first."<<endl<<endl;
            }
        break;
        case 16: {
        if(arr_sorted){
            int x=0, pos;
            cout<<"Please, enter number which is looking for: ";
            cin>>x;
            pos = find_pos( x, arr, arr_row);
            if(pos!=-1){
                cout<<"Index of found variable: "<<pos<<endl<<endl;
            }
            else{
                 cout<<"Nothing was found in the search result"<<endl<<endl;
            }
        }
        else{
            cout<<"Error! Array does not exist or not sorted"<<endl
                <<"Create it and sort first."<<endl<<endl;
            }
        break;
        }
        case 17:{
            if(mat!=NULL){
                show_sort_directions();
                int direction_key;
                cin>>direction_key;cout<<endl;
                switch (direction_key){
                    case 1:
                        mat = sort_matrix(mat, mat_col, mat_row,routing_in, asc_func , routing_out);
                    break;
                    case 2:
                       mat = sort_matrix(mat, mat_col, mat_row,routing_in, dec_func , routing_out);
                break;
                default:
                    cout<<"Error! Wrong input"<<endl
                        <<"Please, select one from the menu."<<endl<<endl;
                break;
            }
            show_matrix(mat, mat_row, mat_col, mat_min, mat_max, precision);
        }
        else{
            cout<<"Error! Array does not exist or not sorted"<<endl
                <<"Create it and sort first."<<endl<<endl;
        }
            case 18:{
                if(arr!=NULL){
                   int indicator = 0;
                   cout<<"Array before processing is: "<<endl;
                   for(int i=0;i<arr_row;i++){
                          cout<< arr[i]<<" " ;
                   }
                   cout<<endl<<endl;
                    cout<<"Please, enter indicator for number is divisible by 2: ";
                    cin>>indicator;
                    arr = array_processing(&arr,arr_row,indicator);
                    arr_row = arr[0];
                    cout<<"Array after processing is: "<<endl;
                    for(int i=1;i<arr_row-1;i++){
                           cout<< arr[i]<<" " ;
                    }

                }
                else {
                    cout<<"Error! Array does not exist or not sorted"<<endl
                    <<"Create it and sort first."<<endl<<endl;
                }


            }

    break;

    }
   }
  }
    return 0;
}

