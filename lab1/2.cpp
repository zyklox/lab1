#include <iostream>



void displaying(int** s,int m,int n){
   for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++){ 
         std::cout << s[i][j] << "\t";
      }
      std::cout << std::endl;
   }
}


void row_sums(int** s, int m, int n) {
   for (int i = 0; i < m; i++) {
      int sum_m = 0;
      for (int j = 0; j < n; j++) {
            sum_m += s[i][j];
      }
      std::cout << i + 1 << ": " << sum_m << std::endl;
   }
}

void column_sum(int** s, int m, int n) {
   for (int i = 0; i < n; i++) {
      int sum_n = 0;
      for (int j = 0; j < m; j++) {
         sum_n += s[j][i];
      }
      std::cout << i + 1 << ": " << sum_n << std::endl;
   }
}


void transposition1(int** s,int m){
   for (int i=0;i<m;i++){
      for (int j=i+1;j<m;j++){
         int temp = s[i][j];
         s[i][j]=s[j][i];
         s[j][i]=temp;
      }
   }
} 

int** transposition2(int** s,int m,int n){
   int** s_t = new int*[n];
   for (int i=0;i<n;i++){
      s_t[i]=new int[m];
      for (int j=0;j<m;j++){
         s_t[i][j]=s[j][i];
      }
   }
   return s_t;
}


void del(int** s,int m){
   for (int i=0;i<m;i++){
         delete[] s[i];
      }
      delete[] s;
}



int main() {
   int m,n,x=1;

   std::cout << "set the size of the array: ";
   std::cin >> m >>n;
   int** s = new int*[m];
   for (int i=0;i<m;i++){
      s[i]=new int[n];
      for (int j=0;j<n;j++){
         s[i][j]=x++;
      }  
   }

   std::cout << "array values: " << std::endl;
   displaying(s,m,n);
   std::cout << "the sum of the row elements: "<< std::endl;
   row_sums(s,m,n);
   std::cout << "the sum of the column elements: " << std::endl;
   column_sum(s,m,n);
   std::cout << std::endl <<"maximum element: " << s[m-1][n-1] << std::endl;
   std::cout << "transposition: " << std::endl;
   if (m==n){
      transposition1(s,m);
      displaying(s,m,n);
   }
   else{
      int** s_t = transposition2(s,m,n);
      displaying(s_t,n,m);
      del(s_t,n);
   }

   del(s,m);
   return 0;
}