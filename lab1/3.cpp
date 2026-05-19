#include <iostream>



char** creat_ar(int n) {
   char** s = new char*[n];
   for (int i=0;i<n;i++){
      s[i]=new char[n];
      for (int j=0;j<n;j++){
         s[i][j]=174;
      } 
   }
   return s;
}


void displaying(char** s,int n){
   std::cout<< "o - empty cell" 
   << std::endl << "_ - miss"
   << std::endl << "! - hit" << std::endl;
   
   std::cout<< "        1    2    3    4    5    6    7    8    9   10" << std::endl << std::endl;
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


void ship_placement(char** s,int n,int pl){
   int x,y,i=1;

   system("cls");
   std::cout << "player "<< pl << " place the ships on the field: " << std::endl;
   
   while (i!=11) {
      std::cout << i << ". ";
      std::cin >> x >> y;

      if (x < 1 || x > n || y < 1 || y > n) {
         std::cout << "invalid coordinates" << std::endl;
         continue;            
      }

      if (s[y-1][x-1] != 111){
         s[y-1][x-1]= 111;
      }
      else{
         std::cout << "This cell is occupied" << std::endl;
         i--;
      }
      i++;
   }
}



void del(char** s,int n){
   for (int i=0;i<n;i++){
         delete[] s[i];
      }
      delete[] s;
}




int main(){   
   int n=10,x,y,ship_1=10,ship_2=10,pl=1,loss=0;

   char** s1=creat_ar(n);
   char** s2=creat_ar(n);

   ship_placement(s1,n,1);
   ship_placement(s2,n,2);


   while (!loss) { 
      system("cls");

      if (pl==1){
         std::cout << "player 1" << std::endl;
         displaying(s2, n);
         std::cout << "Enter coordinates: ";
         std::cin >> x >> y;
         
         if (x < 1 || x > n || y < 1 || y > n) {
            std::cout << "invalid coordinates" << std::endl;
            continue;
         }
      x--;
      y--;

      if (s2[y][x] == 95 || s2[y][x] == 33) {
            std::cout << "The cell has already been shot" << std::endl;
            continue;
         }

      if (s2[y][x] == 111) {
         std::cout << "hit" << std::endl;
         s2[y][x]=33;
         ship_2--;
         system("pause");

         if (ship_2==0) {
            loss = 1;
            std::cout << "player 1 wins" << std::endl;
            system("pause");
            break;
         }
      }

      else {
         s2[y][x] = 95;
         pl=2;
         displaying(s2,n);
         std::cout << "miss" << std::endl;
         system("pause");
      }


      }

      else {
         std::cout << "player 2" << std::endl;
         displaying(s1, n);
         std::cout << "Enter coordinates: ";
         std::cin >> x >> y;
         
         if (x < 1 || x > n || y < 1 || y > n) {
            std::cout << "invalid coordinates" << std::endl;
            continue;
         }

         x--;
         y--;

         if (s1[y][x] == 95 || s1[y][x] == 33) {
            std::cout << "The cell has already been shot" << std::endl;
            continue;
         }

         if (s1[y][x] == 111) {
            std::cout << "hit" << std::endl;
            s1[y][x]=33;
            ship_1--;
            system("pause");

            if (ship_1==0) {
               loss = 1;
               std::cout << "player 2 wins" << std::endl;
               system("pause");
               break;
            }
         }

         else {
            s1[y][x] = 95;
            pl=1;
            displaying(s1,n);
            std::cout << "miss" << std::endl;
            system("pause");
         }
      }
   }
   
   // 95 - _;
   // 33 - !;

   displaying(s1,n);
   displaying(s2,n);




   del(s1,n);
   del(s2,n);

   return 0;
}