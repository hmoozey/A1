
// FCAI – OOP Programming – 2023 - Assignment 1 
// Program Name:				A1 test.cpp
// Last Modification Date:	9/10/2023
// Author1 and ID and Group:	20220729
// Author2 and ID and Group:	20220974
// Author3 and ID and Group:	xxxxx xxxxx
// Teaching Assistant:		xxxxx xxxxx
// Purpose:..........	

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
//declare image...
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char imageR[SIZE][SIZE];

//declare filter functions...
void Black_and_White();
void Invert();
void Merge();
void Flip();
void Rotate();
void Darken_or_Lighten();

//declare the program functions...
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

//loadimage function to load the image from the file...
void loadImage(){
   char imageFileName[100];

   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   strcat (imageFileName, ".bmp");
   readGSBMP(imageFileName, image);
}

//saveImage to return the result of the procces...
void saveImage () {
   char imageFileName[100];

   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   strcat (imageFileName, ".bmp");
   writeGSBMP(imageFileName, image);
}

//doSomethingForImage is used to choose which filter would you like to use...
void doSomethingForImage() {
    cout << "1-Black and White" << endl;
    cout << "2-invert " << endl;
    cout << "3-Merge" << endl;
    cout << "4-Flip" << endl;
    cout << "5-rotate" << endl;
    cout << "6-darken or lighten" << endl;
    cout << "choose filter : ";
    string filter; cin >> filter;
    if(filter == "1")
    {
        Black_and_White();
    }
    else if(filter == "2")
    {
        Invert();
    }
     else if(filter == "3")
    {
        Merge();
    }
     else if(filter == "4")
    {
        Flip();
    }
     else if(filter == "5")
    {
        Rotate();
    }
     else if(filter == "6")
    {
        Darkenand_or_Lighten();
    }
}
//The Black and White filter it changes each pixel to black or white...
void Black_and_White();
{
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
            if (image[i][j] > 127) {
                image[i][j] = 255;
            }
            else {
                image[i][j] = 0;
            }
        }
    }
}
//The Invert filter changes each pixel to it's opposet thing...
void Invert();
{
    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
            image[i][j] = 255 - image[i][j];
        }
    }
}
//The Merge filter merges two images into one...
void Merge()
{
    char imageFileName1[100];
    cout << "Enter the source of the second image file name: ";
    cin >> imageFileName1;
    strcat(imageFileName1, ".bmp");
    readGSBMP(imageFileName1, image1);

    for (int i = 0; i < 255; i++) {
        for (int j = 0; j < 255; j++) {
            image[i][j] = (image1[i][j] + image[i][j]) / 2;
        }
    }
}
//The Flip filter flips the image upside down or sides...
void Flip()
{
    cout << "1-sides " << endl << "2-flip" << endl;
    int sf; cin >> sf;
    if (sf == 1)
    {
        for (int i = 0; i <= 255; i++) {
            for (int j = 0; j <= 127; j++) {
                swap(image[i][j], image[i][255 - j]);
            }
        }
}
//The Rotate filter rotate 90, 180 ,270 degree as you chooses...
void Rotate()
{
    cout << "Choose the Angle: " << endl;
    cout << "1-90 degree" << endl;
    cout << "2-180 degree" << endl;
    cout << "3-270 degree" << endl;
    int Angle; cin >> Angle;

    for (int i = 0; i <= 255; i++) {
        for (int j = 0; j <= 255; j++) {
            imageR[i][j] = image[i][j];
        }
    }

    if (Angle == 1)
    {
        for (int i = 0; i <= 255; i++) {
            for (int j = 0; j <= 255; j++) {
                swap(image[255 - j][i], imageR[i][j]);
            }
        }
    }
    else if (Angle == 2)
    {
        for (int i = 0; i <= 255; i++) {
            for (int j = 0; j <= 255; j++) {
                swap(image[255 - i][255 - j], imageR[i][j]);
            }
        }
    }
    else if (Angle == 3)
    {
        for (int i = 0; i <= 255; i++) {
            for (int j = 0; j <= 255; j++) {
                swap(image[j][255 - i], imageR[i][j]);
            }
        }
    }
}
//The darken/Lighten filter darken or lighten the image as you chooses...
void Darken_or_Lighten()
{
    cout << "choose lighten or darken" << endl << "1-lighten" << endl << "2-darken" << endl;
    int ld; cin >> ld;
    if (ld == 1)
    {
        for (int i = 0; i < 255; i++) {
            for (int j = 0; j < 255; j++) {
                if (image[i][j] + 80 >= 256)
                    image[i][j] = 225;
                else
                    image[i][j] = image[i][j] + 80;
            }
        }
    }
    else
    {
        for (int i = 0; i <= 255; i++) {
            for (int j = 0; j <= 255; j++) {
                if (image[i][j] - 80 < 0)
                    image[i][j] = 0;
                else
                    image[i][j] = image[i][j] - 80;
            }
        }
    }
}