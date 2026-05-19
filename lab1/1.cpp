#include <iostream>

int main() {
   float av_s;
   int n,sum_s=0;
   

   std::cout << "set the size of the array: ";
   std::cin >> n;
   int*s = new int[n];
   std::cout << "array values: "; 

   for (int i=0;i<n;i++){
      s[i]=i*i;
      std::cout << s[i] << " ";
      sum_s+=s[i];
   }

   av_s=(float)sum_s/n;

   std::cout << std::endl <<"amount: " << sum_s;
   std::cout << std::endl <<"averge value: " << av_s;
   std::cout << std::endl <<"maximum element: " << s[n-1];

   delete[] s; 
   return 0;
}