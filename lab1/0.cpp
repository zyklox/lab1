#include <iostream>




//protokol_1:

//protokol_1.1
//creat
// int** creat_ar_1(int n) {
//    int** s = new int*[n];
//    for (int i=0;i<n;i++){
//       s[i]=new int[n];
//       for (int j=0;j<n;j++){
//          s[i][j]=0;
//       } 
//    }
//    return s;
// }
char** creat_ar_2(int n) {
   char** s = new char*[n];
   for (int i=0;i<n;i++){
      s[i]=new char[n];
      for (int j=0;j<n;j++){
         s[i][j]='~';
      } 
   }
   return s;
}



// void displaying_1(int** s,int n){
//    for (int i = 0; i < n; i++) {
//       for (int j = 0; j < n; j++){ 
//          std::cout << s[i][j] << "     ";// << "\t"
//       }
//       std::cout << std::endl;
//    std::cout << std::endl;
//    }
//    std::cout << std::endl;
// }
void displaying_2(char** s,int n){
   std::cout<< "       1    2    3    4    5    6    7    8    9   10" << std::endl << std::endl;
   for (int i = 0; i < n; i++) {
      std::cout<< i+1 << "\t";
      for (int j = 0; j < n; j++){ 
         std::cout << s[i][j] << "    ";
      }
      std::cout << std::endl;
   std::cout << std::endl;
   }
   std::cout << std::endl;
}


// void del_1(int** s,int n){
//    for (int i=0;i<n;i++){
//          delete[] s[i];
//       }
//       delete[] s;
// }
void del_2(char** s,int n){
   for (int i=0;i<n;i++){
         delete[] s[i];
      }
      delete[] s;
}




int main(){
   int n=10;

   // int** a1=creat_ar_1(n);
   char** b1=creat_ar_2(n);
   // int** a2=creat_ar_1(n);
   char** b2=creat_ar_2(n);


   b2[1][1] = 95;
   b2[1][0] = 33;

   // displaying_1(a1,n);
   displaying_2(b1,n);
   // displaying_1(a2,n);
   displaying_2(b2,n);




   // del_1(a1,n);
   del_2(b1,n);
   // del_1(a2,n);
   del_2(b2,n);

   return 0;
}