
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

#define endl '\n'
#define ll long long
//#define fast ios_base::sync_with_stdio;cin.tie(0);cout.tie(0);
using namespace std;

//unsigned char image0[SIZE][SIZE];
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char imageR[SIZE][SIZE];

void loadImage ();
void saveImage ();
void doSomethingForImage ();
//-------------------------
int main()
{
  loadImage();
  doSomethingForImage();
  saveImage();
  return 0;
}
//-------------------------
void loadImage(){
   char imageFileName[100];

   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}
//-------------------------
void saveImage () {
   char imageFileName[100];

   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
  // writeGSBMP(imageFileName, imageR);
}

//-------------------------
void doSomethingForImage() {
    cout << "1-Black and white " << endl << "2-invert " << endl << "3-Merge" << endl << "4-Flip" << endl << "5-rotate" << endl <<"6-darken or lighten" << endl;
    cout << "choose filter : ";
    string filter; cin >> filter;
    if(filter == "1")
    {
        for (int i = 0; i < SIZE; i++){
            for (int j = 0; j < SIZE; j++){
                if(image[i][j] > 127){
                    image[i][j] = 255;
                }
                else{
                    image[i][j] = 0;
                }
            }}
        
    }
    else if(filter == "2")
    {
        for (int i = 0; i < 255; i++){
            for (int j = 0; j < 255; j++){
                image[i][j] = 255 - image[i][j];
                }}
    }
     else if(filter == "3")
    {
        char imageFileName1[100];
        cout << "Enter the source of the second image file name: ";
        cin >> imageFileName1;
        strcat (imageFileName1, ".bmp");
        readGSBMP(imageFileName1, image1);

        for (int i = 0; i < 255; i++){
            for (int j = 0; j < 255; j++){
                image[i][j] = (image1[i][j] + image[i][j])/2;
                }}
    }
     else if(filter == "4")
    {
        cout << "1-sides " << endl << "2-flip" << endl;
        int sf;cin >> sf;
        if(sf == 1)
        {
            for (int i = 0; i <= 255; i++){
            for (int j = 0; j <= 127; j++){
                swap(image[i][j] , image[i][255 - j]);
            }}
        }
        else
        {
            for (int i = 0; i <= 127; i++){
            for (int j = 0; j <= 255; j++){
                swap(image[i][j] , image[255 - i][j]);
            }}
        }
    }
     else if(filter == "5")
    {
        cout << "Choose the Angle: " << endl;
        cout << "1-90 degree" << endl;
        cout << "2-180 degree" << endl;
        cout << "3-270 degree" << endl;
        int Angle; cin >> Angle;
        
        for (int i = 0; i <= 255; i++){
            for (int j = 0; j <= 255; j++){
                imageR[i][j]=image[i][j];
            }}

        if(Angle == 1)
        {
            for (int i = 0; i <= 255; i++){
            for (int j = 0; j <= 255; j++){
                swap(image[255 - j][i] , imageR[i][j]);
            }}
        }
          else if(Angle == 2)
        {
            for (int i = 0; i <= 255; i++){
            for (int j = 0; j <= 255; j++){
                swap(image[255 - i][255 - j] , imageR[i][j]);
            }}
        }
        else if(Angle == 3)
        {
            for (int i = 0; i <= 255; i++){
            for (int j = 0; j <= 255; j++){
                swap(image[j][255 - i] , imageR[i][j]);
            }}
        }
        
    }
     else if(filter == "6")
    {
        cout << "choose lighten or darken" << endl << "1-lighten"  << endl << "2-darken" << endl;
        int ld; cin >> ld;
        if(ld == 1)
        {
            for (int i = 0; i < 255; i++){
            for (int j = 0; j < 255; j++){
                if(image[i][j] + 80 >= 256)
                image[i][j] = 225;
                else
                image[i][j] = image[i][j] + 80;
        }}
        }
        else
        {
            for (int i = 0; i <= 255; i++){
            for (int j = 0; j <= 255; j++){
                if(image[i][j] - 80 < 0)
                image[i][j] = 0 ;
                else
                image[i][j] = image[i][j] - 80;
            }}
        }
    }
}